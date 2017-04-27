#include "WorkerFactory.h"
#include <SimulationData.h>
#include <AIWorker.h>
#include <CreatureActionWorker.h>
#include <CreatureSpawnWorker.h>
#include <CreatureRemoveWorker.h>
#include <ResourceWorker.h>
#include <WaiterWorker.h>

#ifndef HEADLESS
	#include <VisualWorker.h>
#endif


void WorkerFactory::build ( std::vector<WorldWorker*>&workers ) {
    addWorker <AIWorker> ( workers,SimulationData::getInst()->useAIWorker );
    addWorker<CreatureActionWorker> ( workers,SimulationData::getInst()->useCreatureActionWorker );
    addWorker <CreatureSpawnWorker> ( workers,SimulationData::getInst()->useCreatureSpawnWorker );
    addWorker <CreatureRemoveWorker> ( workers,SimulationData::getInst()->useCreatureRemoveWorker );
    addWorker<ResourceWorker> ( workers,SimulationData::getInst()->useResourceWorker );
	#ifndef HEADLESS
    addWorker<VisualWorker> ( workers, SimulationData::getInst()->useVisualWorker );
	#endif
    addWorker <WaiterWorker> ( workers,SimulationData::getInst()->useWaiterWorker );


    }

