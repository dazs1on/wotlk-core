
#ifndef MANGOSSERVER_TOTEM_H
#define MANGOSSERVER_TOTEM_H

#include "Creature.h"

enum TotemType
{
    TOTEM_PASSIVE    = 0,
    TOTEM_ACTIVE     = 1,
    TOTEM_STATUE     = 2
};

class Totem : public Creature
{
    public:
        explicit Totem();
        virtual ~Totem() {};
        bool Create(uint32 guidlow, CreatureCreatePos& cPos, CreatureInfo const* cinfo, Unit* owner);
        void Update(uint32 update_diff, uint32 time) override;
        void Summon(Unit* owner);
        void UnSummon();
        uint32 GetSpell() const { return m_spells[0]; }
        uint32 GetTotemDuration() const { return m_duration; }
        Unit* GetOwner();
        TotemType GetTotemType() const { return m_type; }
        void SetTypeBySummonSpell(SpellEntry const* spellProto);
        void SetDuration(uint32 dur) { m_duration = dur; }
        void SetOwner(Unit* owner);

        bool UpdateStats(Stats /*stat*/) override { return true; }
        bool UpdateAllStats() override { return true; }
        void UpdateResistances(uint32 /*school*/) override {}
        void UpdateArmor() override {}
        void UpdateMaxHealth() override {}
        void UpdateMaxPower(Powers /*power*/) override {}
        void UpdateAttackPowerAndDamage(bool /*ranged*/) override {}
        void UpdateDamagePhysical(WeaponAttackType /*attType*/) override {}

        bool IsImmuneToSpellEffect(SpellEntry const* spellInfo, SpellEffectIndex index, bool castOnSelf) const override;

    protected:
        TotemType m_type;
        uint32 m_duration;
};
#endif
