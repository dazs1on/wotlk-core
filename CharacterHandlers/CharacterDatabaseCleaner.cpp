
#include "Common.h"
#include "CharacterDatabaseCleaner.h"
#include "World.h"
#include "Database/DatabaseEnv.h"
#include "DBCStores.h"
#include "ProgressBar.h"

void CharacterDatabaseCleaner::CleanDatabase()
{
    // config to disable
    if (!sWorld.getConfig(CONFIG_BOOL_CLEAN_CHARACTER_DB))
        return;

    sLog.outString("Cleaning character database...");

    // check flags which clean ups are necessary
    QueryResult* result = CharacterDatabase.PQuery("SELECT cleaning_flags FROM saved_variables");
    if (!result)
        return;
    uint32 flags = (*result)[0].GetUInt32();
    delete result;

    // clean up
    if (flags & CLEANING_FLAG_ACHIEVEMENT_PROGRESS)
        CleanCharacterAchievementProgress();
    if (flags & CLEANING_FLAG_SKILLS)
        CleanCharacterSkills();
    if (flags & CLEANING_FLAG_SPELLS)
        CleanCharacterSpell();
    if (flags & CLEANING_FLAG_TALENTS)
        CleanCharacterTalent();
    CharacterDatabase.Execute("UPDATE saved_variables SET cleaning_flags = 0");
}

void CharacterDatabaseCleaner::CheckUnique(const char* column, const char* table, bool (*check)(uint32))
{
    QueryResult* result = CharacterDatabase.PQuery("SELECT DISTINCT %s FROM %s", column, table);
    if (!result)
    {
        sLog.outString("Table %s is empty.", table);
        return;
    }

    bool found = false;
    std::ostringstream ss;
    BarGoLink bar(result->GetRowCount());
    do
    {
        bar.step();

        Field* fields = result->Fetch();

        uint32 id = fields[0].GetUInt32();

        if (!check(id))
        {
            if (!found)
            {
                ss << "DELETE FROM " << table << " WHERE " << column << " IN (";
                found = true;
            }
            else
                ss << ",";
            ss << id;
        }
    }
    while (result->NextRow());
    delete result;

    if (found)
    {
        ss << ")";
        CharacterDatabase.Execute(ss.str().c_str());
    }
}

bool CharacterDatabaseCleaner::AchievementProgressCheck(uint32 criteria)
{
    return sAchievementCriteriaStore.LookupEntry(criteria);
}

void CharacterDatabaseCleaner::CleanCharacterAchievementProgress()
{
    CheckUnique("criteria", "character_achievement_progress", &AchievementProgressCheck);
}

bool CharacterDatabaseCleaner::SkillCheck(uint32 skill)
{
    return sSkillLineStore.LookupEntry(skill);
}

void CharacterDatabaseCleaner::CleanCharacterSkills()
{
    CheckUnique("skill", "character_skills", &SkillCheck);
}

bool CharacterDatabaseCleaner::SpellCheck(uint32 spell_id)
{
    return sSpellStore.LookupEntry(spell_id) && !GetTalentSpellPos(spell_id);
}

void CharacterDatabaseCleaner::CleanCharacterSpell()
{
    CheckUnique("spell", "character_spell", &SpellCheck);
}

bool CharacterDatabaseCleaner::TalentCheck(uint32 talent_id)
{
    TalentEntry const* talentInfo = sTalentStore.LookupEntry(talent_id);
    if (!talentInfo)
        return false;

    return sTalentTabStore.LookupEntry(talentInfo->TalentTab);
}

void CharacterDatabaseCleaner::CleanCharacterTalent()
{
    CharacterDatabase.DirectPExecute("DELETE FROM character_talent WHERE spec > %u OR current_rank > %u", MAX_TALENT_SPEC_COUNT, MAX_TALENT_RANK);

    CheckUnique("talent_id", "character_talent", &TalentCheck);
}
