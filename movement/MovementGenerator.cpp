
#include "MovementGenerator.h"
#include "Unit.h"

MovementGenerator::~MovementGenerator()
{
}

bool MovementGenerator::IsActive(Unit& u)
{
    // When movement generator list modified from Update movegen object erase delayed,
    // so pointer still valid and be used for check
    return !u.GetMotionMaster()->empty() && u.GetMotionMaster()->top() == this;
}
