
#ifndef MANGOS_FLEEINGMOVEMENTGENERATOR_H
#define MANGOS_FLEEINGMOVEMENTGENERATOR_H

#include "MovementGenerator.h"
#include "ObjectGuid.h"

template<class T>
class MANGOS_DLL_SPEC FleeingMovementGenerator
    : public MovementGeneratorMedium< T, FleeingMovementGenerator<T> >
{
    public:
        FleeingMovementGenerator(ObjectGuid fright) : i_frightGuid(fright), i_nextCheckTime(0) {}

        void Initialize(T&);
        void Finalize(T&);
        void Interrupt(T&);
        void Reset(T&);
        bool Update(T&, const uint32&);

        MovementGeneratorType GetMovementGeneratorType() const override { return FLEEING_MOTION_TYPE; }

    private:
        void _setTargetLocation(T& owner);
        bool _getPoint(T& owner, float& x, float& y, float& z);

        ObjectGuid i_frightGuid;
        TimeTracker i_nextCheckTime;
};

class MANGOS_DLL_SPEC TimedFleeingMovementGenerator
    : public FleeingMovementGenerator<Creature>
{
    public:
        TimedFleeingMovementGenerator(ObjectGuid fright, uint32 time) :
            FleeingMovementGenerator<Creature>(fright),
            i_totalFleeTime(time) {}

        MovementGeneratorType GetMovementGeneratorType() const override { return TIMED_FLEEING_MOTION_TYPE; }
        bool Update(Unit&, const uint32&) override;
        void Finalize(Unit&) override;

    private:
        TimeTracker i_totalFleeTime;
};

#endif
