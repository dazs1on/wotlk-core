

#ifndef __BATTLEGROUNDIC_H
#define __BATTLEGROUNDIC_H

class BattleGround;

class BattleGroundICScore : public BattleGroundScore
{
    public:
        BattleGroundICScore() {};
        virtual ~BattleGroundICScore() {};
};

class BattleGroundIC : public BattleGround
{
        friend class BattleGroundMgr;

    public:
        BattleGroundIC();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* plr) override;

        /* Scorekeeping */
        void UpdatePlayerScore(Player* source, uint32 type, uint32 value) override;

    private:
};
#endif
