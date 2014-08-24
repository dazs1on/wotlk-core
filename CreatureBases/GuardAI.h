

#ifndef MANGOS_GUARDAI_H
#define MANGOS_GUARDAI_H

#include "CreatureAI.h"
#include "ObjectGuid.h"
#include "Timer.h"

class Creature;

class MANGOS_DLL_DECL GuardAI : public CreatureAI
{
        enum GuardState
        {
            STATE_NORMAL = 1,
            STATE_LOOK_AT_VICTIM = 2
        };

    public:

        explicit GuardAI(Creature* c);

        void MoveInLineOfSight(Unit*) override;
        void AttackStart(Unit*) override;
        void EnterEvadeMode() override;
        void JustDied(Unit*) override;
        bool IsVisible(Unit*) const override;

        void UpdateAI(const uint32) override;
        static int Permissible(const Creature*);

    private:
        ObjectGuid i_victimGuid;
        GuardState i_state;
        TimeTracker i_tracker;
};
#endif
