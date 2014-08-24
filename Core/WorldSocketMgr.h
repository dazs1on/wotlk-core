

#ifndef __WORLDSOCKETMGR_H
#define __WORLDSOCKETMGR_H

#include <ace/Basic_Types.h>
#include <ace/Singleton.h>
#include <ace/Thread_Mutex.h>

#include <string>

class WorldSocket;
class ReactorRunnable;
class ACE_Event_Handler;

/// Manages all sockets connected to peers and network threads
class WorldSocketMgr
{
    public:
        friend class WorldSocket;
        friend class ACE_Singleton<WorldSocketMgr, ACE_Thread_Mutex>;

        /// Start network, listen at address:port .
        int StartNetwork(ACE_UINT16 port, std::string& address);

        /// Stops all network threads, It will wait for all running threads .
        void StopNetwork();

        /// Wait untill all network threads have "joined" .
        void Wait();

        std::string& GetBindAddress() { return m_addr; }
        ACE_UINT16 GetBindPort() { return m_port; }

        /// Make this class singleton .
        static WorldSocketMgr* Instance();

    private:
        int OnSocketOpen(WorldSocket* sock);
        int StartReactiveIO(ACE_UINT16 port, const char* address);

        WorldSocketMgr();
        virtual ~WorldSocketMgr();

        ReactorRunnable* m_NetThreads;
        size_t m_NetThreadsCount;

        int m_SockOutKBuff;
        int m_SockOutUBuff;
        bool m_UseNoDelay;

        std::string m_addr;
        ACE_UINT16 m_port;

        ACE_Event_Handler* m_Acceptor;
};

#define sWorldSocketMgr WorldSocketMgr::Instance()

#endif
/// @}
