
#ifndef MANGOS_NULLCREATUREAI_H
#define MANGOS_NULLCREATUREAI_H

#include "CreatureAI.h"

class MANGOS_DLL_DECL NullCreatureAI : public CreatureAI
{
    public:

        explicit NullCreatureAI(Creature* c) : CreatureAI(c) {}
        ~NullCreatureAI();

        void MoveInLineOfSight(Unit*) override {}
        void AttackStart(Unit*) override {}
        void AttackedBy(Unit*) override {}
        void EnterEvadeMode() override {}

        bool IsVisible(Unit*) const override { return false;  }

        void UpdateAI(const uint32) override {}
        static int Permissible(const Creature*) { return PERMIT_BASE_IDLE;  }
};
#endif
