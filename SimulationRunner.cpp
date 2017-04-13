#include "SimulationRunner.h"
#include <time.h>
#include "../Factories/WorkerFactory.h"
#include <cstdlib>
#include <iostream>
#include <fstream>
#include "Workers/HeightsWorker.h"

SimulationRunner::SimulationRunner() {
	srand(7 * clock() + time(NULL));
	world = new World(SimulationData::getInst()->mapHeightToSet,
			SimulationData::getInst()->mapWidthToSet);

	HeightsWorker heightsWorker;
	heightsWorker.work(world);

}

SimulationRunner::~SimulationRunner() {
	delete world;
}

void SimulationRunner::run() {
	WorkerFactory::build(workers);

	while (true) {

		for (WorldWorker *worker : workers) {
			std::cout << worker->getName() << std::endl;
			worker->work(world);

		}

	}
}
