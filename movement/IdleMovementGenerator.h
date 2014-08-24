

#ifndef MANGOS_IDLEMOVEMENTGENERATOR_H
#define MANGOS_IDLEMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

class MANGOS_DLL_SPEC IdleMovementGenerator : public MovementGenerator
{
    public:

        void Initialize(Unit&) override {}
        void Finalize(Unit&) override {}
        void Interrupt(Unit&) override {}
        void Reset(Unit&) override;
        bool Update(Unit&, const uint32&) override { return true; }
        MovementGeneratorType GetMovementGeneratorType() const override { return IDLE_MOTION_TYPE; }
};

extern IdleMovementGenerator si_idleMovement;

class MANGOS_DLL_SPEC DistractMovementGenerator : public MovementGenerator
{
    public:
        explicit DistractMovementGenerator(uint32 timer) : m_timer(timer) {}

        void Initialize(Unit& owner) override;
        void Finalize(Unit& owner) override;
        void Interrupt(Unit&) override;
        void Reset(Unit&) override;
        bool Update(Unit& owner, const uint32& time_diff) override;
        MovementGeneratorType GetMovementGeneratorType() const override { return DISTRACT_MOTION_TYPE; }

    private:
        uint32 m_timer;
};

class MANGOS_DLL_SPEC AssistanceDistractMovementGenerator : public DistractMovementGenerator
{
    public:
        AssistanceDistractMovementGenerator(uint32 timer) :
            DistractMovementGenerator(timer) {}

        MovementGeneratorType GetMovementGeneratorType() const override { return ASSISTANCE_DISTRACT_MOTION_TYPE; }
        void Finalize(Unit& unit) override;
};

#endif
