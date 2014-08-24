
#include "IdleMovementGenerator.h"
#include "CreatureAI.h"
#include "Creature.h"

IdleMovementGenerator si_idleMovement;

void
IdleMovementGenerator::Reset(Unit& /*owner*/)
{
}

void
DistractMovementGenerator::Initialize(Unit& owner)
{
    owner.addUnitState(UNIT_STAT_DISTRACTED);
}

void
DistractMovementGenerator::Finalize(Unit& owner)
{
    owner.clearUnitState(UNIT_STAT_DISTRACTED);
}

void
DistractMovementGenerator::Reset(Unit& owner)
{
    Initialize(owner);
}

void
DistractMovementGenerator::Interrupt(Unit& /*owner*/)
{
}

bool
DistractMovementGenerator::Update(Unit& /*owner*/, const uint32& time_diff)
{
    if (time_diff > m_timer)
        return false;

    m_timer -= time_diff;
    return true;
}

void
AssistanceDistractMovementGenerator::Finalize(Unit& unit)
{
    unit.clearUnitState(UNIT_STAT_DISTRACTED);
    if (Unit* victim = unit.getVictim())
    {
        if (unit.isAlive())
        {
            unit.AttackStop(true);
            ((Creature*)&unit)->AI()->AttackStart(victim);
        }
    }
}
