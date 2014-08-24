
#include "SQLStorages.h"

const char CreatureInfosrcfmt[] = "iiiiiiiiiisssiiiiiiiiiiifffiffiifiiiiiiiiiiffiiiiiiiiiiiiiiisiiffliiiiiiiliiiiiis";
const char CreatureInfodstfmt[] = "iiiiiiiiiisssiiiiiiiiiiifffiffiifiiiiiiiiiiffiiiiiiiiiiiiiiisiiffliiiiiiiliiiiiii";
const char CreatureDataAddonInfofmt[] = "iiibbiis";
const char CreatureModelfmt[] = "iffbii";
const char CreatureInfoAddonInfofmt[] = "iiibbiis";
const char GameObjectInfoAddonInfofmt[] = "iffff";
const char EquipmentInfofmt[] = "iiii";
const char GameObjectInfosrcfmt[] = "iiissssiifiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiis";
const char GameObjectInfodstfmt[] = "iiissssiifiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiii";
const char ItemPrototypesrcfmt[] = "iiiisiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiffiffiiiiiiiiiifiiifiiiiiifiiiiiifiiiiiifiiiiiifiiiisiiiiiiiiiiiiiiiiiiiiiiiiifiiisiiiii";
const char ItemPrototypedstfmt[] = "iiiisiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiiffiffiiiiiiiiiifiiifiiiiiifiiiiiifiiiiiifiiiiiifiiiisiiiiiiiiiiiiiiiiiiiiiiiiifiiiiiiiii";
const char PageTextfmt[] = "isi";
const char InstanceTemplatesrcfmt[] = "iiiis";
const char InstanceTemplatedstfmt[] = "iiiii";
const char WorldTemplatesrcfmt[] = "is";
const char WorldTemplatedstfmt[] = "ii";
const char ConditionsSrcFmt[] = "iiii";
const char ConditionsDstFmt[] = "iiii";
const char SpellTemplatesrcfmt[] = "iiiiiiiiiiiiiiix";
//                                  0         10        20        30        40        50        60        70        80        90        100       110       120       130       140       150       160     170       180  185
const char SpellTemplatedstfmt[] = "ixxxiiixxxxxxxxxxxxxxxxxxxxxxxxxiixxxxixxxxxxFxxxxxxxxxxxxxxxxxxxxxxixxxxxFFFxxxxxxixxixxixxixxxxxFFFxxxxxxixxixxixxFFFxxxxxxxxxxxxxppppppppppppppppppppppppppppppppxxxxxxxxxxxFFFxxxxxx";
//                                  Id  attr                        proc  DurationIndex                 Effect0        tarA0    effectAura0          triggerSpell0      SpellName[16]   Rank[16]
const char VehicleAccessorySrcFmt[] = "iiix";
const char VehicleAccessoryDstFmt[] = "iii";
const char CreatureTemplateSpellsFmt[] = "iiiiiiiii";
const char SpellScriptTargetFmt[] = "iiii";

SQLStorage sCreatureStorage(CreatureInfosrcfmt, CreatureInfodstfmt, "entry", "creature_template");
SQLStorage sCreatureDataAddonStorage(CreatureDataAddonInfofmt, "guid", "creature_addon");
SQLStorage sCreatureModelStorage(CreatureModelfmt, "modelid", "creature_model_info");
SQLStorage sCreatureInfoAddonStorage(CreatureInfoAddonInfofmt, "entry", "creature_template_addon");
SQLStorage sEquipmentStorage(EquipmentInfofmt, "entry", "creature_equip_template");
SQLStorage sItemStorage(ItemPrototypesrcfmt, ItemPrototypedstfmt, "entry", "item_template");
SQLStorage sPageTextStore(PageTextfmt, "entry", "page_text");
SQLStorage sInstanceTemplate(InstanceTemplatesrcfmt, InstanceTemplatedstfmt, "map", "instance_template");
SQLStorage sWorldTemplate(WorldTemplatesrcfmt, WorldTemplatedstfmt, "map", "world_template");
SQLStorage sConditionStorage(ConditionsSrcFmt, ConditionsDstFmt, "condition_entry", "conditions");

SQLHashStorage sGameObjectDataAddonStorage(GameObjectInfoAddonInfofmt, "guid", "gameobject_addon");
SQLHashStorage sGOStorage(GameObjectInfosrcfmt, GameObjectInfodstfmt, "entry", "gameobject_template");
SQLHashStorage sSpellTemplate(SpellTemplatesrcfmt, SpellTemplatedstfmt, "id", "spell_template");
SQLHashStorage sCreatureTemplateSpellsStorage(CreatureTemplateSpellsFmt, "entry", "creature_template_spells");

SQLMultiStorage sVehicleAccessoryStorage(VehicleAccessorySrcFmt, VehicleAccessoryDstFmt, "vehicle_entry", "vehicle_accessory");
SQLMultiStorage sSpellScriptTargetStorage(SpellScriptTargetFmt, "entry", "spell_script_target");
