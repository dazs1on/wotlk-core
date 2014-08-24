
#ifndef __BATTLEGROUNDRL_H
#define __BATTLEGROUNDRL_H

class BattleGround;

class BattleGroundRLScore : public BattleGroundScore
{
    public:
        BattleGroundRLScore() {};
        virtual ~BattleGroundRLScore() {};
        // TODO fix me
};

class BattleGroundRL : public BattleGround
{
        friend class BattleGroundMgr;

    public:
        BattleGroundRL();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* plr) override;
        virtual void FillInitialWorldStates(WorldPacket& d, uint32& count) override;
        virtual void StartingEventOpenDoors() override;

        void RemovePlayer(Player* plr, ObjectGuid guid) override;
        void HandleAreaTrigger(Player* source, uint32 trigger) override;
        void HandleKillPlayer(Player* player, Player* killer) override;
        bool HandlePlayerUnderMap(Player* plr) override;
};
#endif
