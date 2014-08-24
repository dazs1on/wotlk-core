
#ifndef __BATTLEGROUNDSA_H
#define __BATTLEGROUNDSA_H

class BattleGround;

#define BG_SA_EVENT_START_BATTLE_1      23748       // Ally / Horde likely
#define BG_SA_EVENT_START_BATTLE_2      21702

class BattleGroundSAScore : public BattleGroundScore
{
    public:
        BattleGroundSAScore() {};
        virtual ~BattleGroundSAScore() {};
};

class BattleGroundSA : public BattleGround
{
        friend class BattleGroundMgr;

    public:
        BattleGroundSA();

        /* inherited from BattlegroundClass */
        virtual void AddPlayer(Player* plr) override;

        /* Scorekeeping */
        void UpdatePlayerScore(Player* source, uint32 type, uint32 value) override;

    private:
};
#endif
