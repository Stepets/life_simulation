#include <iostream>
#include <math.h>
#include "World.h"
#include "Factories/CreatureBuilder.h"
using namespace std;

World::World() {
	init();
}

World::~World() {
}

int World::getWidth() const {
	return mapWidth;

}

int World::getHeight() const {
	return mapHeight;
}

void World::init() {

	map.resize(mapHeight);

	for (int y = 0; y < mapHeight; y++) {
		map[y].resize(mapWidth);
	}

	for (int y = 0; y < mapHeight; y++) {
		for (int x=0;x<mapWidth; x++){
			map[y][x].setCellFood();
		}
	}

	visualization = cv::Mat(cv::Size(mapWidth,mapHeight), CV_8UC3,cv::Scalar(0, 0, 0));
	creatures.reserve(100);
        creatures.push_back(CreatureBuilder::build(1, 1));
}

