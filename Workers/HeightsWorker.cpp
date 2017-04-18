#include "HeightsWorker.h"
#include "../SimulationData.h"
#include <cmath>
#include <stdexcept>

#include <iostream>
HeightsWorker::HeightsWorker() {
	mapHeight = 0;
	mapWidth = 0;
	step = 0;

}
HeightsWorker::~HeightsWorker() {
}

void HeightsWorker::setDepth(World*world) {

	int maxH = 0;
	int minH = 0;
	float cellHeight = 0;
	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight; j++) {
			cellHeight = world->map[j][i].heightValue;
			if (cellHeight > maxH) {
				maxH = cellHeight;
			}
			if (cellHeight < minH) {
				minH = cellHeight;
			}

		}

	}
	world->heightsRange = maxH - minH;

}

void HeightsWorker::work(World*world) {
	init(world);
	diamondSquare(world, SimulationData::getInst()->scale);
	setDepth(world);

}
void HeightsWorker::init(World*world) {
	mapHeight = world->mapHeight;
	mapWidth = world->mapWidth;

	float cornerHeight = SimulationData::getInst()->cornerHeight;
	int firstStepDecrease = SimulationData::getInst()->firstStepDecrease;
	int lesserSide = std::min(mapHeight, mapWidth);
	float rawStep = std::log2(lesserSide);

	if (std::abs(rawStep) < 0.0001) {
		step = pow(2, (int) (rawStep) - 1);

	} else {
		step = pow(2, (int) std::floor(rawStep));

	}
//	std::cout << step << " step;" << lesserSide << "lesser side;" << std::endl;
	if (step > 0) {
		for (int y = 0; y < mapHeight; y += step) {
			for (int x = 0; x < mapWidth; x += step) {
				world->map[y][x].heightValue = cornerHeight;

			}
		}
	}
	int firstStepDecerease = SimulationData::getInst()->firstStepDecrease;
	if (firstStepDecrease==1 ||(!firstStepDecerease & (firstStepDecerease - 1)) ) {
		step = step / firstStepDecrease;

	} else {
		throw std::runtime_error("firstStepDecrease must be 1 or power of 2 ");
	}
	if (lesserSide<=1){
		throw std::runtime_error("world's sides size must be greater than 1");
	}
}

bool HeightsWorker::checkBorder(World *world, int y, int x) {
	mapHeight = world->mapHeight;
	mapWidth = world->mapWidth;
	if (y >= 0 && x >= 00 && y < mapHeight && x < mapWidth)
		return true;
	else
		return false;

}
void HeightsWorker::diamondStep(World *world, int y, int x, float range) {
	Cell &cell = world->map[y][x];
	int n = 0;
	float sumOfHeights = 0;

	if (checkBorder(world, y, x - step / 2)) {
		sumOfHeights += world->map[y][x - step / 2].heightValue;
		n++;
	}
	if (checkBorder(world, y, x + step / 2)) {
		sumOfHeights += world->map[y][x + step / 2].heightValue;
		n++;
	}
	if (checkBorder(world, y - step / 2, x)) {
		sumOfHeights += world->map[y - step / 2][x].heightValue;
		n++;
	}
	if (checkBorder(world, y + step / 2, x)) {
		sumOfHeights += world->map[y + step / 2][x].heightValue;
		n++;
	}

	/*	for (int j = x - step / 2; j <= x + step / 2; j += step) {
	 if (j >= 0 && j <= mapWidth - 1) {
	 sumOfHeights += world->map[y][j].heightValue;
	 n++;
	 }
	 }
	 for (int i = y - step / 2; i <= y + step / 2; i += step) {
	 if (i >= 0 && i <= mapHeight - 1) {
	 sumOfHeights += world->map[i][x].heightValue;
	 n++;
	 }
	 }*/
	cell.heightValue = sumOfHeights / n + range * rangedRandom();
}

void HeightsWorker::squareStep(World *world, int y, int x, float scale) {

	float sumOfHeights = world->map[y][x].heightValue;
	sumOfHeights += world->map[y + step][x].heightValue;
	sumOfHeights += world->map[y][x + step].heightValue;
	sumOfHeights += world->map[y + step][x + step].heightValue;
	world->map[y + step / 2][x + step / 2].heightValue = (sumOfHeights) / 4
			+ rangedRandom() * scale;

}

void HeightsWorker::diamondSquare(World*world, float scale) {
	if (step < 2)
		return;
	int borderY = mapHeight - step;
	int borderX = mapWidth - step;

	for (int i = 0; i < borderY; i += step)
		for (int j = 0; j < borderX; j += step) {
			squareStep(world, i, j, scale);

		}

	borderY = mapHeight;
	borderX = mapWidth - step / 2;
	for (int i = 0; i < borderY; i += step) {
		for (int j = step / 2; j < borderX; j += step) {
			diamondStep(world, i, j, scale);
		}
	}
	borderY = mapHeight - step / 2;
	borderX = mapWidth;
	for (int i = step / 2; i < borderY; i += step) {
		for (int j = 0; j < borderX; j += step) {

			diamondStep(world, i, j, scale);

		}
	}

	step /= 2;
	scale /= SimulationData::getInst()->smooth;
	diamondSquare(world, scale);

}

float HeightsWorker::rangedRandom() {
	return 2 * (float) rand() / RAND_MAX - 1;

}
