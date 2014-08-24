

#ifndef __BATTLEGROUNDABG_H
#define __BATTLEGROUNDABG_H

class BattleGround;

class BattleGroundABGScore : public BattleGroundScore
{
    public:
        BattleGroundABGScore() {};
        virtual ~BattleGroundABGScore() {};
};

class BattleGroundRB : public BattleGround
{
        friend class BattleGroundMgr;

    public:
        BattleGroundRB();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* plr) override;

        /* Scorekeeping */
        void UpdatePlayerScore(Player* source, uint32 type, uint32 value) override;

    private:
};
#endif
