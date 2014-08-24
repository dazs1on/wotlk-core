

#ifndef MANGOS_TOTEMAI_H
#define MANGOS_TOTEMAI_H

#include "CreatureAI.h"
#include "ObjectGuid.h"
#include "Timer.h"

class Creature;
class Totem;

class MANGOS_DLL_DECL TotemAI : public CreatureAI
{
    public:

        explicit TotemAI(Creature* c);

        void MoveInLineOfSight(Unit*) override;
        void AttackStart(Unit*) override;
        void EnterEvadeMode() override;
        bool IsVisible(Unit*) const override;

        void UpdateAI(const uint32) override;
        static int Permissible(const Creature*);
    protected:
        Totem& getTotem();

    private:
        ObjectGuid i_victimGuid;
};
#endif
