#include "SimulationConfig.h"


void SimulationConfig::addParams(){
    setSection("World");
    add<int>("height", mapHeightToSet, 5);
    add<int>("width", mapWidthToSet, 5);
    
    setSection("Workers");
    add<bool>("useAIWorker", useAIWorker, true);
    add<bool>("useCreatureActionWorker", useCreatureActionWorker, true);
    add<bool>("useCreatureRemoveWorker", useCreatureRemoveWorker, true);
    add<bool>("useCreatureSpawnWorker", useCreatureSpawnWorker, true);
    add<bool>("useResourceWorker", useResourceWorker, true);
    add<bool>("useVisualWorker", useVisualWorker, true);
    add<bool>("useVideoWriterWorker", useVideoWriterWorker, true);
    add<bool>("useWaiterWorker", useWaiterWorker, true);
        
    setSection("WaitingTime");
    add<int>("timeToWait", timeToWait, 1000);
    
    setSection("Resources");
    add<double>("gainPerCell", gainResourcePerCell, 0.0);
    
    setSection("CreatureParameters");
    add<double>("creatureOneBait", creatureOneBait, 1.0);
    add<double>("energyToMove", energyToMove, 1.0);
    add<double>("energyFromFood", energyFromFood, 1.0);
}