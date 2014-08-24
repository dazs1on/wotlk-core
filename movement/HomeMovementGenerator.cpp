
#include "HomeMovementGenerator.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"
#include "movement/MoveSplineInit.h"
#include "movement/MoveSpline.h"

void HomeMovementGenerator<Creature>::Initialize(Creature& owner)
{
    _setTargetLocation(owner);
}

void HomeMovementGenerator<Creature>::Reset(Creature&)
{
}

void HomeMovementGenerator<Creature>::_setTargetLocation(Creature& owner)
{
    if (owner.hasUnitState(UNIT_STAT_NOT_MOVE))
        return;

    Movement::MoveSplineInit init(owner);
    float x, y, z, o;
    // at apply we can select more nice return points base at current movegen
    if (owner.GetMotionMaster()->empty() || !owner.GetMotionMaster()->top()->GetResetPosition(owner, x, y, z))
    {
        owner.GetRespawnCoord(x, y, z, &o);
        init.SetFacing(o);
    }

    init.MoveTo(x, y, z, true);
    init.SetWalk(false);
    init.Launch();

    arrived = false;
    owner.clearUnitState(UNIT_STAT_ALL_DYN_STATES);
}

bool HomeMovementGenerator<Creature>::Update(Creature& owner, const uint32& time_diff)
{
    arrived = owner.movespline->Finalized();
    return !arrived;
}

void HomeMovementGenerator<Creature>::Finalize(Creature& owner)
{
    if (arrived)
    {
        if (owner.GetTemporaryFactionFlags() & TEMPFACTION_RESTORE_REACH_HOME)
            owner.ClearTemporaryFaction();

        owner.SetWalk(!owner.hasUnitState(UNIT_STAT_RUNNING_STATE) && !owner.IsLevitating(), false);
        owner.LoadCreatureAddon(true);
        owner.AI()->JustReachedHome();
    }
}
