
#include "Phenotype.h"
#include "SimulationData.h"
Phenotype::Phenotype() {
    creatureOneBait=SimulationData::getInst()->creatureOneBait;
    energyFromFood=SimulationData::getInst()->energyFromFood;
    energyToMove=SimulationData::getInst()->energyToMove;
    fissionLoss=SimulationData::getInst()->fissionLoss;
    fissionThreshold=SimulationData::getInst()->fissionThreshold;
    hungryEdge=100;
    corpseSize=50;

    }

Phenotype::~Phenotype() {

    }
