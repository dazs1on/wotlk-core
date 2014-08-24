
#ifndef _OBJECT_POS_SELECTOR_H
#define _OBJECT_POS_SELECTOR_H

#include<Common.h>

#include<map>

enum UsedAreaSide { USED_POS_PLUS, USED_POS_MINUS };

inline UsedAreaSide operator ~(UsedAreaSide side)
{
    return side == USED_POS_PLUS ? USED_POS_MINUS : USED_POS_PLUS;
}

inline float SignOf(UsedAreaSide side)
{
    return side == USED_POS_PLUS ? 1.0f : -1.0f;
}

struct ObjectPosSelector
{
    typedef std::multimap<float, float> UsedAreaList;       // angle pos -> angle offset
    typedef UsedAreaList::value_type UsedArea;

    ObjectPosSelector(float x, float y, float dist, float searcher_size);

    void AddUsedArea(float size, float angle, float dist);

    bool CheckOriginalAngle() const;

    void InitializeAngle();

    bool NextAngle(float& angle);
    bool NextUsedAngle(float& angle);

    bool CheckAngle(UsedArea const& usedArea, UsedAreaSide side, float angle) const;
    bool CheckSideAngle(UsedAreaSide side, float angle) const;
    void InitializeAngle(UsedAreaSide side);
    void UpdateNextAreaStart(UsedAreaSide side);
    bool NextSideAngle(UsedAreaSide side, float& angle);

    float m_centerX;
    float m_centerY;
    float m_searcherDist;                                   // distance for searching pos (including searcher size and target object size)
    float m_searcherSize;                                   // searcher object radius
    float m_searcherHalfSize;                               // angle size/2 of searcher object (at dist distance)

    UsedAreaList m_UsedAreaLists[2];                        // list left/right side used angles (with angle size)

    UsedAreaList::const_iterator m_nextUsedAreaItr[2];      // next used used areas for check at left/right side, possible angles selected in range m_smallStepAngle..m_nextUsedAreaItr
    float m_nextUsedAreaStart[2];                           // cached angle for next used area from m_nextUsedAreaItr or another side

    float m_stepAngle[2];                                   // current checked angle position at sides (less m_nextUsedArea), positive value
};
#endif
