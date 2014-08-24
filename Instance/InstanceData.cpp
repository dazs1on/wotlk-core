
#include "InstanceData.h"
#include "Database/DatabaseEnv.h"
#include "Map.h"
#include "Log.h"

void InstanceData::SaveToDB() const
{
    // no reason to save BGs/Arenas
    if (instance->IsBattleGroundOrArena())
        return;

    if (!Save())
        return;

    std::string data = Save();
    CharacterDatabase.escape_string(data);

    if (instance->Instanceable())
        CharacterDatabase.PExecute("UPDATE instance SET data = '%s' WHERE id = '%u'", data.c_str(), instance->GetInstanceId());
    else
        CharacterDatabase.PExecute("UPDATE world SET data = '%s' WHERE map = '%u'", data.c_str(), instance->GetId());
}

bool InstanceData::CheckAchievementCriteriaMeet(uint32 criteria_id, Player const* /*source*/, Unit const* /*target*/ /*= NULL*/, uint32 /*miscvalue1*/ /*= 0*/) const
{
    sLog.outError("Achievement system call InstanceData::CheckAchievementCriteriaMeet but instance script for map %u not have implementation for achievement criteria %u",
                  instance->GetId(), criteria_id);
    return false;
}

bool InstanceData::CheckConditionCriteriaMeet(Player const* /*source*/, uint32 instance_condition_id, WorldObject const* /*conditionSource*/, uint32 conditionSourceType) const
{
    sLog.outError("Condition system call InstanceData::CheckConditionCriteriaMeet but instance script for map %u not have implementation for player condition criteria with internal id %u (called from %u)",
                  instance->GetId(), instance_condition_id, uint32(conditionSourceType));
    return false;
}
