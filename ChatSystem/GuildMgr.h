
#ifndef _GUILDMGR_H
#define _GUILDMGR_H

#include "Common.h"
#include "Policies/Singleton.h"

class Guild;
class ObjectGuid;

class GuildMgr
{
        typedef UNORDERED_MAP<uint32, Guild*> GuildMap;

        GuildMap m_GuildMap;
    public:
        GuildMgr();
        ~GuildMgr();

        void AddGuild(Guild* guild);
        void RemoveGuild(uint32 guildId);

        Guild* GetGuildById(uint32 guildId) const;
        Guild* GetGuildByName(std::string const& name) const;
        Guild* GetGuildByLeader(ObjectGuid const& guid) const;
        std::string GetGuildNameById(uint32 guildId) const;

        void LoadGuilds();
};

#define sGuildMgr MaNGOS::Singleton<GuildMgr>::Instance()

#endif // _GUILDMGR_H
