
#ifndef MANGOSSERVER_TYPEDEFS_H
#define MANGOSSERVER_TYPEDEFS_H

#include "Common.h"

namespace G3D
{
    class Vector2;
    class Vector3;
    class Vector4;
}

namespace Movement
{
    using G3D::Vector2;
    using G3D::Vector3;
    using G3D::Vector4;

    inline uint32 SecToMS(float sec)
    {
        return static_cast<uint32>(sec * 1000.f);
    }

    inline float MSToSec(uint32 ms)
    {
        return ms / 1000.f;
    }

    template<class T, T limit>
    class counter
    {
        public:
            counter() { init();}

            void Increase()
            {
                if (m_counter == limit)
                    init();
                else
                    ++m_counter;
            }

            T NewId() { Increase(); return m_counter;}
            T getCurrent() const { return m_counter;}

        private:
            void init() { m_counter = 0; }
            T m_counter;
    };

    typedef counter<uint32, 0xFFFFFFFF> UInt32Counter;

    extern double gravity;
    extern float computeFallElevation(float t_passed, bool isSafeFall, float start_velocity);
}

#endif // MANGOSSERVER_TYPEDEFS_H
