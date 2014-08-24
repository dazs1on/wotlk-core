
#ifndef __BATTLEGROUNDBE_H
#define __BATTLEGROUNDBE_H

class BattleGround;

class BattleGroundBEScore : public BattleGroundScore
{
    public:
        BattleGroundBEScore() {};
        virtual ~BattleGroundBEScore() {};
};

class BattleGroundBE : public BattleGround
{
        friend class BattleGroundMgr;

    public:
        BattleGroundBE();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* plr) override;
        virtual void StartingEventOpenDoors() override;

        void RemovePlayer(Player* plr, ObjectGuid guid) override;
        void HandleAreaTrigger(Player* source, uint32 trigger) override;
        virtual void FillInitialWorldStates(WorldPacket& d, uint32& count) override;
        void HandleKillPlayer(Player* player, Player* killer) override;
        bool HandlePlayerUnderMap(Player* plr) override;

        /* Scorekeeping */
        void UpdatePlayerScore(Player* source, uint32 type, uint32 value) override;
};
#endif
