#include "CreatureLogic.h"
#include "SimulationData.h"
CreatureLogic::CreatureLogic() {
}
CreatureLogic::~CreatureLogic() {
}

void CreatureLogic::logicActions(World *world, Creature &creature) {

	logicEat(creature);
	int x = creature.getPosX();
	int y = creature.getPosY();
	if (world->map[y][x].food <= SimulationData::getInst()->creatureOneBait) {
		logicMove(world, creature);
	}


}

