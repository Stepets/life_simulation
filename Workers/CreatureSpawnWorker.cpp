#include "CreatureSpawnWorker.h"
#include <iostream>

#ifndef HEADLESS
	#include <GenomeVisualizer.h>
#endif

CreatureSpawnWorker::CreatureSpawnWorker() {
    this->name = "CreatureSpawnWorker";

    }

void CreatureSpawnWorker::work ( World *world ) {

    for ( Creature *creature : world->creatures ) {
        if ( creature->getEnergy() > creature->phenotype->fissionThreshold) {
            creature->setEnergy ( creature->getEnergy() - creature->phenotype->fissionLoss );
      //      Creature *second = CreatureBuilder::build (creature->getPosX(),creature->getPosY());
	      Creature *second = CreatureBuilder::build (*creature);
#ifndef HEADLESS
		cv::Mat vis = GenomeVisualizer::visualize ( second->getGenome() );
		cv::imwrite ( "genomes/" + std::to_string ( second->getId() ) + ".png", vis );
#endif
            world->creatures.push_back ( second );
            }
        }
    }

CreatureSpawnWorker::~CreatureSpawnWorker() {
    }

