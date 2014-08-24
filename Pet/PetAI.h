
#ifndef MANGOS_PETAI_H
#define MANGOS_PETAI_H

#include "CreatureAI.h"
#include "ObjectGuid.h"
#include "Timer.h"

class Creature;
class Spell;

class MANGOS_DLL_DECL PetAI : public CreatureAI
{
    public:

        explicit PetAI(Creature* c);

        void MoveInLineOfSight(Unit*) override;
        void AttackStart(Unit*) override;
        void EnterEvadeMode() override;
        void AttackedBy(Unit*) override;
        bool IsVisible(Unit*) const override;

        void UpdateAI(const uint32) override;
        static int Permissible(const Creature*);

    private:
        bool _isVisible(Unit*) const;
        bool _needToStop(void) const;
        void _stopAttack(void);

        void UpdateAllies();

        TimeTracker i_tracker;
        bool inCombat;

        GuidSet m_AllySet;
        uint32 m_updateAlliesTimer;
};
#endif
