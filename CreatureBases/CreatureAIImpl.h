
#ifndef CREATUREAIIMPL_H
#define CREATUREAIIMPL_H

#include "CreatureAI.h"

template<class REAL_AI>
inline CreatureAI*
CreatureAIFactory<REAL_AI>::Create(void* data) const
{
    Creature* creature = reinterpret_cast<Creature*>(data);
    return (new REAL_AI(creature));
}
#endif
