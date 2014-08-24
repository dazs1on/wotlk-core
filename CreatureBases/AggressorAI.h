
#ifndef MANGOS_AGGRESSORAI_H
#define MANGOS_AGGRESSORAI_H

#include "CreatureAI.h"
#include "Timer.h"
#include "ObjectGuid.h"

class Creature;

class MANGOS_DLL_DECL AggressorAI : public CreatureAI
{
        enum AggressorState
        {
            STATE_NORMAL = 1,
            STATE_LOOK_AT_VICTIM = 2
        };

    public:

        explicit AggressorAI(Creature* c);

        void MoveInLineOfSight(Unit*) override;
        void AttackStart(Unit*) override;
        void EnterEvadeMode() override;
        bool IsVisible(Unit*) const override;

        void UpdateAI(const uint32) override;
        static int Permissible(const Creature*);

    private:
        ObjectGuid i_victimGuid;
        AggressorState i_state;
        TimeTracker i_tracker;
};

#endif
