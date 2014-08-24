

#include "Player.h"
#include "BattleGround.h"
#include "BattleGroundRB.h"
#include "Language.h"

BattleGroundRB::BattleGroundRB()
{
    // TODO FIX ME!
    m_StartMessageIds[BG_STARTING_EVENT_FIRST]  = 0;
    m_StartMessageIds[BG_STARTING_EVENT_SECOND] = LANG_BG_WS_START_ONE_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_THIRD]  = LANG_BG_WS_START_HALF_MINUTE;
    m_StartMessageIds[BG_STARTING_EVENT_FOURTH] = LANG_BG_WS_HAS_BEGUN;
}

void BattleGroundRB::AddPlayer(Player* plr)
{
    BattleGround::AddPlayer(plr);
    // create score and add it to map, default values are set in constructor
    BattleGroundABGScore* sc = new BattleGroundABGScore;

    m_PlayerScores[plr->GetObjectGuid()] = sc;
}

void BattleGroundRB::UpdatePlayerScore(Player* source, uint32 type, uint32 value)
{

    BattleGroundScoreMap::iterator itr = m_PlayerScores.find(source->GetObjectGuid());

    if (itr == m_PlayerScores.end())                        // player not found...
        return;

    BattleGround::UpdatePlayerScore(source, type, value);
}
