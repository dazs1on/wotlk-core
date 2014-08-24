
#ifndef MANGOS_SQLSTORAGES_H
#define MANGOS_SQLSTORAGES_H

#include "Common.h"
#include "Database/SQLStorage.h"

extern SQLStorage sCreatureStorage;
extern SQLStorage sCreatureDataAddonStorage;
extern SQLStorage sCreatureInfoAddonStorage;
extern SQLStorage sCreatureModelStorage;
extern SQLStorage sEquipmentStorage;
extern SQLStorage sPageTextStore;
extern SQLStorage sItemStorage;
extern SQLStorage sInstanceTemplate;
extern SQLStorage sWorldTemplate;
extern SQLStorage sConditionStorage;

extern SQLHashStorage sSpellTemplate;
extern SQLHashStorage sGOStorage;
extern SQLHashStorage sGameObjectDataAddonStorage;
extern SQLHashStorage sCreatureTemplateSpellsStorage;

extern SQLMultiStorage sVehicleAccessoryStorage;
extern SQLMultiStorage sSpellScriptTargetStorage;

#endif
