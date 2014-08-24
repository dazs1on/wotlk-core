
#ifndef __BATTLEGROUNDAA_H
#define __BATTLEGROUNDAA_H

class BattleGround;

class BattleGroundAAScore : public BattleGroundScore
{
    public:
        BattleGroundAAScore() {};
        virtual ~BattleGroundAAScore() {};
        // TODO fix me
};

class BattleGroundAA : public BattleGround
{
        friend class BattleGroundMgr;

    public:
        BattleGroundAA();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* plr) override;
};
#endif
