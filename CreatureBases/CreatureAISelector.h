
#ifndef MANGOS_CREATUREAISELECTOR_H
#define MANGOS_CREATUREAISELECTOR_H

class CreatureAI;
class Creature;
class MovementGenerator;

namespace FactorySelector
{
    CreatureAI* selectAI(Creature*);
    MovementGenerator* selectMovementGenerator(Creature*);
}
#endif
