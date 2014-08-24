

#ifndef MANGOS_REACTORAI_H
#define MANGOS_REACTORAI_H

#include "CreatureAI.h"
#include "ObjectGuid.h"

class Unit;

class MANGOS_DLL_DECL ReactorAI : public CreatureAI
{
    public:

        explicit ReactorAI(Creature* c) : CreatureAI(c) {}

        void MoveInLineOfSight(Unit*) override;
        void AttackStart(Unit*) override;
        void EnterEvadeMode() override;
        bool IsVisible(Unit*) const override;

        void UpdateAI(const uint32) override;
        static int Permissible(const Creature*);

    private:
        ObjectGuid i_victimGuid;
};
#endif
