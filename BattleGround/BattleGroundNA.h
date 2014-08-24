
#ifndef __BATTLEGROUNDNA_H
#define __BATTLEGROUNDNA_H

class BattleGround;

class BattleGroundNAScore : public BattleGroundScore
{
    public:
        BattleGroundNAScore() {};
        virtual ~BattleGroundNAScore() {};
        // TODO fix me
};

class BattleGroundNA : public BattleGround
{
        friend class BattleGroundMgr;

    public:
        BattleGroundNA();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* plr) override;
        virtual void StartingEventOpenDoors() override;

        void RemovePlayer(Player* plr, ObjectGuid guid) override;
        void HandleAreaTrigger(Player* source, uint32 trigger) override;
        virtual void FillInitialWorldStates(WorldPacket& d, uint32& count) override;
        void HandleKillPlayer(Player* player, Player* killer) override;
        bool HandlePlayerUnderMap(Player* plr) override;
};
#endif
