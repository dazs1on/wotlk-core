
#include "NullCreatureAI.h"
#include "ReactorAI.h"
#include "AggressorAI.h"
#include "GuardAI.h"
#include "PetAI.h"
#include "TotemAI.h"
#include "CreatureEventAI.h"
#include "RandomMovementGenerator.h"
#include "CreatureAIImpl.h"
#include "MovementGeneratorImpl.h"
#include "CreatureAIRegistry.h"
#include "WaypointMovementGenerator.h"

namespace AIRegistry
{
    void Initialize()
    {
        (new CreatureAIFactory<NullCreatureAI>("NullAI"))->RegisterSelf();
        (new CreatureAIFactory<AggressorAI>("AggressorAI"))->RegisterSelf();
        (new CreatureAIFactory<ReactorAI>("ReactorAI"))->RegisterSelf();
        (new CreatureAIFactory<GuardAI>("GuardAI"))->RegisterSelf();
        (new CreatureAIFactory<PetAI>("PetAI"))->RegisterSelf();
        (new CreatureAIFactory<TotemAI>("TotemAI"))->RegisterSelf();
        (new CreatureAIFactory<CreatureEventAI>("EventAI"))->RegisterSelf();

        (new MovementGeneratorFactory<RandomMovementGenerator<Creature> >(RANDOM_MOTION_TYPE))->RegisterSelf();
        (new MovementGeneratorFactory<WaypointMovementGenerator<Creature> >(WAYPOINT_MOTION_TYPE))->RegisterSelf();
    }
}
