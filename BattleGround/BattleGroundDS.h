
#ifndef __BATTLEGROUNDDS_H
#define __BATTLEGROUNDDS_H

class BattleGround;

class BattleGroundDSScore : public BattleGroundScore
{
    public:
        BattleGroundDSScore() {};
        virtual ~BattleGroundDSScore() {};
        // TODO fix me
};

class BattleGroundDS : public BattleGround
{
        friend class BattleGroundMgr;

    public:
        BattleGroundDS();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* plr) override;
};
#endif
