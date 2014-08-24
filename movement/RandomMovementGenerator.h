
#ifndef MANGOS_RANDOMMOTIONGENERATOR_H
#define MANGOS_RANDOMMOTIONGENERATOR_H

#include "MovementGenerator.h"

template<class T>
class MANGOS_DLL_SPEC RandomMovementGenerator
    : public MovementGeneratorMedium< T, RandomMovementGenerator<T> >
{
    public:
        explicit RandomMovementGenerator(const Creature&);
        explicit RandomMovementGenerator(float x, float y, float z, float radius, float verticalZ = 0.0f) :
            i_nextMoveTime(0), i_x(x), i_y(y), i_z(z), i_radius(radius), i_verticalZ(verticalZ) {}

        void _setRandomLocation(T&);
        void Initialize(T&);
        void Finalize(T&);
        void Interrupt(T&);
        void Reset(T&);
        bool Update(T&, const uint32&);
        MovementGeneratorType GetMovementGeneratorType() const override { return RANDOM_MOTION_TYPE; }
    private:
        ShortTimeTracker i_nextMoveTime;
        float i_x, i_y, i_z;
        float i_radius;
        float i_verticalZ;
};

#endif
