#ifndef CREATURELOGIC_H_
#define CREATURELOGIC_H_
#include "../Creature.h"
#include "../World.h"
#include "../Actions/Action.h"
class CreatureLogic {
public:

	CreatureLogic();
	virtual ~CreatureLogic();
	void logicActions (World*world,Creature &creature);
	virtual void logicMove(World*world,Creature&creature) =0;
	virtual void logicEat(Creature &creature)=0;
};

#endif
