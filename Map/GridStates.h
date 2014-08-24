

#ifndef MANGOS_GRIDSTATES_H
#define MANGOS_GRIDSTATES_H

#include "Map.h"

class MANGOS_DLL_DECL GridState
{
    public:

        virtual void Update(Map&, NGridType&, GridInfo&, const uint32& x, const uint32& y, const uint32& t_diff) const = 0;
};

class MANGOS_DLL_DECL InvalidState : public GridState
{
    public:

        void Update(Map&, NGridType&, GridInfo&, const uint32& x, const uint32& y, const uint32& t_diff) const override;
};

class MANGOS_DLL_DECL ActiveState : public GridState
{
    public:

        void Update(Map&, NGridType&, GridInfo&, const uint32& x, const uint32& y, const uint32& t_diff) const override;
};

class MANGOS_DLL_DECL IdleState : public GridState
{
    public:

        void Update(Map&, NGridType&, GridInfo&, const uint32& x, const uint32& y, const uint32& t_diff) const override;
};

class MANGOS_DLL_DECL RemovalState : public GridState
{
    public:

        void Update(Map&, NGridType&, GridInfo&, const uint32& x, const uint32& y, const uint32& t_diff) const override;
};

#endif
