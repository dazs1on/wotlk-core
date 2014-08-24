
#ifndef MANGOSSERVER_TEMPSUMMON_H
#define MANGOSSERVER_TEMPSUMMON_H

#include "Creature.h"
#include "ObjectAccessor.h"

class TemporarySummon : public Creature
{
    public:
        explicit TemporarySummon(ObjectGuid summoner = ObjectGuid());
        virtual ~TemporarySummon() {};

        void Update(uint32 update_diff, uint32 time) override;
        void Summon(TempSummonType type, uint32 lifetime);
        void MANGOS_DLL_SPEC UnSummon();
        void SaveToDB();
        ObjectGuid const& GetSummonerGuid() const { return m_summoner ; }
        Unit* GetSummoner() const { return ObjectAccessor::GetUnit(*this, m_summoner); }
    private:
        void SaveToDB(uint32, uint8, uint32) override       // overwrited of Creature::SaveToDB     - don't must be called
        {
            MANGOS_ASSERT(false);
        }
        void DeleteFromDB() override                        // overwrited of Creature::DeleteFromDB - don't must be called
        {
            MANGOS_ASSERT(false);
        }

        TempSummonType m_type;
        uint32 m_timer;
        uint32 m_lifetime;
        ObjectGuid m_summoner;
};
#endif
