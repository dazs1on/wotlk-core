
#ifndef MANGOS_HOMEMOVEMENTGENERATOR_H
#define MANGOS_HOMEMOVEMENTGENERATOR_H

#include "MovementGenerator.h"

class Creature;

template < class T >
class MANGOS_DLL_SPEC HomeMovementGenerator;

template <>
class MANGOS_DLL_SPEC HomeMovementGenerator<Creature>
    : public MovementGeneratorMedium< Creature, HomeMovementGenerator<Creature> >
{
    public:

        HomeMovementGenerator() : arrived(false) {}
        ~HomeMovementGenerator() {}

        void Initialize(Creature&);
        void Finalize(Creature&);
        void Interrupt(Creature&) {}
        void Reset(Creature&);
        bool Update(Creature&, const uint32&);
        MovementGeneratorType GetMovementGeneratorType() const override { return HOME_MOTION_TYPE; }

    private:
        void _setTargetLocation(Creature&);
        bool arrived;
};
#endif
