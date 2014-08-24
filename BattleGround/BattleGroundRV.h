
#ifndef __BATTLEGROUNDRV_H
#define __BATTLEGROUNDRV_H

class BattleGround;

class BattleGroundRVScore : public BattleGroundScore
{
    public:
        BattleGroundRVScore() {};
        virtual ~BattleGroundRVScore() {};
        // TODO fix me
};

class BattleGroundRV : public BattleGround
{
        friend class BattleGroundMgr;

    public:
        BattleGroundRV();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* plr) override;
};
#endif
