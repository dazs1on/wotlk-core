
#ifndef MANGOS_CELL_H
#define MANGOS_CELL_H

#include "GameSystem/TypeContainer.h"
#include "GameSystem/TypeContainerVisitor.h"
#include "GridDefines.h"
#include <cmath>

class Map;
class WorldObject;

struct MANGOS_DLL_DECL CellArea
{
    CellArea() {}
    CellArea(CellPair low, CellPair high) : low_bound(low), high_bound(high) {}

    bool operator!() const { return low_bound == high_bound; }

    void ResizeBorders(CellPair& begin_cell, CellPair& end_cell) const
    {
        begin_cell = low_bound;
        end_cell = high_bound;
    }

    CellPair low_bound;
    CellPair high_bound;
};

struct MANGOS_DLL_DECL Cell
{
        Cell() { data.All = 0; }
        Cell(const Cell& cell) { data.All = cell.data.All; }
        explicit Cell(CellPair const& p);

        void Compute(uint32& x, uint32& y) const
        {
            x = data.Part.grid_x * MAX_NUMBER_OF_CELLS + data.Part.cell_x;
            y = data.Part.grid_y * MAX_NUMBER_OF_CELLS + data.Part.cell_y;
        }

        bool DiffCell(const Cell& cell) const
        {
            return(data.Part.cell_x != cell.data.Part.cell_x ||
                   data.Part.cell_y != cell.data.Part.cell_y);
        }

        bool DiffGrid(const Cell& cell) const
        {
            return(data.Part.grid_x != cell.data.Part.grid_x ||
                   data.Part.grid_y != cell.data.Part.grid_y);
        }

        uint32 CellX() const { return data.Part.cell_x; }
        uint32 CellY() const { return data.Part.cell_y; }
        uint32 GridX() const { return data.Part.grid_x; }
        uint32 GridY() const { return data.Part.grid_y; }
        bool NoCreate() const { return data.Part.nocreate; }
        void SetNoCreate() { data.Part.nocreate = 1; }

        GridPair gridPair() const { return GridPair(GridX(), GridY()); }

        CellPair cellPair() const
        {
            return CellPair(
                       data.Part.grid_x * MAX_NUMBER_OF_CELLS + data.Part.cell_x,
                       data.Part.grid_y * MAX_NUMBER_OF_CELLS + data.Part.cell_y);
        }

        Cell& operator=(const Cell& cell)
        {
            data.All = cell.data.All;
            return *this;
        }

        bool operator==(const Cell& cell) const { return (data.All == cell.data.All); }
        bool operator!=(const Cell& cell) const { return !operator==(cell); }
        union
        {
            struct
            {
                unsigned grid_x : 6;
                unsigned grid_y : 6;
                unsigned cell_x : 6;
                unsigned cell_y : 6;
                unsigned nocreate : 1;
                unsigned reserved : 7;
            } Part;
            uint32 All;
        } data;

        template<class T, class CONTAINER> void Visit(const CellPair& cellPair, TypeContainerVisitor<T, CONTAINER>& visitor, Map& m, float x, float y, float radius) const;
        template<class T, class CONTAINER> void Visit(const CellPair& cellPair, TypeContainerVisitor<T, CONTAINER>& visitor, Map& m, const WorldObject& obj, float radius) const;

        static CellArea CalculateCellArea(float x, float y, float radius);

        template<class T> static void VisitGridObjects(const WorldObject* obj, T& visitor, float radius, bool dont_load = true);
        template<class T> static void VisitWorldObjects(const WorldObject* obj, T& visitor, float radius, bool dont_load = true);
        template<class T> static void VisitAllObjects(const WorldObject* obj, T& visitor, float radius, bool dont_load = true);

        template<class T> static void VisitGridObjects(float x, float y, Map* map, T& visitor, float radius, bool dont_load = true);
        template<class T> static void VisitWorldObjects(float x, float y, Map* map, T& visitor, float radius, bool dont_load = true);
        template<class T> static void VisitAllObjects(float x, float y, Map* map, T& visitor, float radius, bool dont_load = true);

    private:
        template<class T, class CONTAINER> void VisitCircle(TypeContainerVisitor<T, CONTAINER>&, Map&, const CellPair& , const CellPair&) const;
};

#endif
