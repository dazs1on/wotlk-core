
#ifndef MANGOS_MOVEMENTGENERATOR_IMPL_H
#define MANGOS_MOVEMENTGENERATOR_IMPL_H

#include "MovementGenerator.h"

template<class MOVEMENT_GEN>
inline MovementGenerator*
MovementGeneratorFactory<MOVEMENT_GEN>::Create(void* data) const
{
    Creature* creature = reinterpret_cast<Creature*>(data);
    return (new MOVEMENT_GEN(*creature));
}
#endif
