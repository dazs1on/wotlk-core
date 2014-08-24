
#ifndef MANGOSSERVER_CHANNELMGR_H
#define MANGOSSERVER_CHANNELMGR_H

#include "Common.h"
#include "Channel.h"
#include "Policies/Singleton.h"

#include <map>
#include <string>

class ChannelMgr
{
    public:
        typedef std::map<std::wstring, Channel*> ChannelMap;
        ChannelMgr() {}
        ~ChannelMgr();

        Channel* GetJoinChannel(std::string name, uint32 channel_id);
        Channel* GetChannel(std::string name, Player* p, bool pkt = true);
        void LeftChannel(std::string name);
    private:
        ChannelMap channels;
        void MakeNotOnPacket(WorldPacket* data, std::string name);
};

class AllianceChannelMgr : public ChannelMgr {};
class HordeChannelMgr    : public ChannelMgr {};

ChannelMgr* channelMgr(Team team);

#endif
