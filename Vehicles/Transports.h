
#ifndef TRANSPORTS_H
#define TRANSPORTS_H

#include "GameObject.h"

#include <map>
#include <set>
#include <string>

class Transport : public GameObject
{
    public:
        explicit Transport();

        bool Create(uint32 guidlow, uint32 mapid, float x, float y, float z, float ang, uint8 animprogress, uint16 dynamicHighValue);
        bool GenerateWaypoints(uint32 pathid, std::set<uint32>& mapids);
        void Update(uint32 update_diff, uint32 p_time) override;
        bool AddPassenger(Player* passenger);
        bool RemovePassenger(Player* passenger);

        typedef std::set<Player*> PlayerSet;
        PlayerSet const& GetPassengers() const { return m_passengers; }

    private:
        struct WayPoint
        {
            WayPoint() : mapid(0), x(0), y(0), z(0), teleport(false) {}
            WayPoint(uint32 _mapid, float _x, float _y, float _z, bool _teleport, uint32 _arrivalEventID = 0, uint32 _departureEventID = 0)
                : mapid(_mapid), x(_x), y(_y), z(_z), teleport(_teleport),
                  arrivalEventID(_arrivalEventID), departureEventID(_departureEventID)
            {
            }

            uint32 mapid;
            float x;
            float y;
            float z;
            bool teleport;
            uint32 arrivalEventID;
            uint32 departureEventID;
        };

        typedef std::map<uint32, WayPoint> WayPointMap;

        WayPointMap::const_iterator m_curr;
        WayPointMap::const_iterator m_next;
        uint32 m_pathTime;
        uint32 m_timer;

        PlayerSet m_passengers;

    public:
        WayPointMap m_WayPoints;
        uint32 m_nextNodeTime;
        uint32 m_period;

    private:
        void TeleportTransport(uint32 newMapid, float x, float y, float z);
        void UpdateForMap(Map const* map);
        void DoEventIfAny(WayPointMap::value_type const& node, bool departure);
        void MoveToNextWayPoint();                          // move m_next/m_cur to next points
};
#endif
