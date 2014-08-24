
#ifndef MANGOSSERVER_DYNAMICOBJECT_H
#define MANGOSSERVER_DYNAMICOBJECT_H

#include "Object.h"
#include "DBCEnums.h"
#include "Unit.h"

enum DynamicObjectType
{
    DYNAMIC_OBJECT_PORTAL           = 0x0,      // unused
    DYNAMIC_OBJECT_AREA_SPELL       = 0x1,
    DYNAMIC_OBJECT_FARSIGHT_FOCUS   = 0x2,
};

struct SpellEntry;

class DynamicObject : public WorldObject
{
    public:
        explicit DynamicObject();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool Create(uint32 guidlow, Unit* caster, uint32 spellId, SpellEffectIndex effIndex, float x, float y, float z, int32 duration, float radius, DynamicObjectType type);
        void Update(uint32 update_diff, uint32 p_time) override;
        void Delete();
        uint32 GetSpellId() const { return m_spellId; }
        SpellEffectIndex GetEffIndex() const { return m_effIndex; }
        uint32 GetDuration() const { return m_aliveDuration; }
        ObjectGuid const& GetCasterGuid() const { return GetGuidValue(DYNAMICOBJECT_CASTER); }
        Unit* GetCaster() const;
        float GetRadius() const { return m_radius; }
        DynamicObjectType GetType() const { return (DynamicObjectType)GetByteValue(DYNAMICOBJECT_BYTES, 0); }
        bool IsAffecting(Unit* unit) const { return m_affected.find(unit->GetObjectGuid()) != m_affected.end(); }
        void AddAffected(Unit* unit) { m_affected.insert(unit->GetObjectGuid()); }
        void RemoveAffected(Unit* unit) { m_affected.erase(unit->GetObjectGuid()); }
        void Delay(int32 delaytime);

        bool IsHostileTo(Unit const* unit) const override;
        bool IsFriendlyTo(Unit const* unit) const override;

        float GetObjectBoundingRadius() const override      // overwrite WorldObject version
        {
            return 0.0f;                                    // dynamic object not have real interact size
        }

        bool isVisibleForInState(Player const* u, WorldObject const* viewPoint, bool inVisibleList) const override;

        GridReference<DynamicObject>& GetGridRef() { return m_gridRef; }

    protected:
        uint32 m_spellId;
        SpellEffectIndex m_effIndex;
        int32 m_aliveDuration;
        float m_radius;                                     // radius apply persistent effect, 0 = no persistent effect
        bool m_positive;
        GuidSet m_affected;
    private:
        GridReference<DynamicObject> m_gridRef;
};
#endif
