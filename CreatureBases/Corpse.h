

#ifndef MANGOSSERVER_CORPSE_H
#define MANGOSSERVER_CORPSE_H

#include "Common.h"
#include "Object.h"
#include "Database/DatabaseEnv.h"
#include "GridDefines.h"
#include "LootMgr.h"

enum CorpseType
{
    CORPSE_BONES             = 0,
    CORPSE_RESURRECTABLE_PVE = 1,
    CORPSE_RESURRECTABLE_PVP = 2
};
#define MAX_CORPSE_TYPE        3

// Value equal client resurrection dialog show radius.
#define CORPSE_RECLAIM_RADIUS 39

enum CorpseFlags
{
    CORPSE_FLAG_NONE        = 0x00,
    CORPSE_FLAG_BONES       = 0x01,
    CORPSE_FLAG_UNK1        = 0x02,
    CORPSE_FLAG_UNK2        = 0x04,
    CORPSE_FLAG_HIDE_HELM   = 0x08,
    CORPSE_FLAG_HIDE_CLOAK  = 0x10,
    CORPSE_FLAG_LOOTABLE    = 0x20
};

class Corpse : public WorldObject
{
    public:
        explicit Corpse(CorpseType type = CORPSE_BONES);
        ~Corpse();

        void AddToWorld() override;
        void RemoveFromWorld() override;

        bool Create(uint32 guidlow);
        bool Create(uint32 guidlow, Player* owner);

        void SaveToDB();
        bool LoadFromDB(uint32 guid, Field* fields);

        void DeleteBonesFromWorld();
        void DeleteFromDB();

        ObjectGuid const& GetOwnerGuid() const { return GetGuidValue(CORPSE_FIELD_OWNER); }

        time_t const& GetGhostTime() const { return m_time; }
        void ResetGhostTime() { m_time = time(NULL); }
        CorpseType GetType() const { return m_type; }

        bool IsHostileTo(Unit const* unit) const override;
        bool IsFriendlyTo(Unit const* unit) const override;

        GridPair const& GetGrid() const { return m_grid; }
        void SetGrid(GridPair const& grid) { m_grid = grid; }

        bool isVisibleForInState(Player const* u, WorldObject const* viewPoint, bool inVisibleList) const override;

        Loot loot;                                          // remove insignia ONLY at BG
        Player* lootRecipient;
        bool lootForBody;

        GridReference<Corpse>& GetGridRef() { return m_gridRef; }

        bool IsExpired(time_t t) const;
    private:
        GridReference<Corpse> m_gridRef;

        CorpseType m_type;
        time_t m_time;
        GridPair m_grid;                                    // gride for corpse position for fast search
};
#endif
