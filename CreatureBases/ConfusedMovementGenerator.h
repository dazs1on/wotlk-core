
#ifndef MANGOS_CONFUSEDMOVEMENTGENERATOR_H
#define MANGOS_CONFUSEDMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

template<class T>
class MANGOS_DLL_SPEC ConfusedMovementGenerator
    : public MovementGeneratorMedium< T, ConfusedMovementGenerator<T> >
{
    public:
        explicit ConfusedMovementGenerator() : i_nextMoveTime(0) {}

        void Initialize(T&);
        void Finalize(T&);
        void Interrupt(T&);
        void Reset(T&);
        bool Update(T&, const uint32&);

        MovementGeneratorType GetMovementGeneratorType() const { return CONFUSED_MOTION_TYPE; }
    private:
        TimeTracker i_nextMoveTime;
        float i_x, i_y, i_z;
};
#endif
