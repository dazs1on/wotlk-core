

#ifndef MANGOS_CREATURE_EAI_MGR_H
#define MANGOS_CREATURE_EAI_MGR_H

#include "Common.h"
#include "CreatureEventAI.h"

class CreatureEventAIMgr
{
    public:
        CreatureEventAIMgr() {};
        ~CreatureEventAIMgr() {};

        void LoadCreatureEventAI_Texts(bool check_entry_use);
        void LoadCreatureEventAI_Summons(bool check_entry_use);
        void LoadCreatureEventAI_Scripts();

        CreatureEventAI_Event_Map  const& GetCreatureEventAIMap()       const { return m_CreatureEventAI_Event_Map; }
        CreatureEventAI_Summon_Map const& GetCreatureEventAISummonMap() const { return m_CreatureEventAI_Summon_Map; }
        CreatureEventAI_TextMap    const& GetCreatureEventAITextMap()   const { return m_CreatureEventAI_TextMap; }

    private:
        void CheckUnusedAITexts();
        void CheckUnusedAISummons();

        CreatureEventAI_Event_Map  m_CreatureEventAI_Event_Map;
        CreatureEventAI_Summon_Map m_CreatureEventAI_Summon_Map;
        CreatureEventAI_TextMap    m_CreatureEventAI_TextMap;
};

#define sEventAIMgr MaNGOS::Singleton<CreatureEventAIMgr>::Instance()
#endif
