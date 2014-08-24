
#ifndef MANGOSSERVER_PACKET_BUILDER_H
#define MANGOSSERVER_PACKET_BUILDER_H

class ByteBuffer;
class WorldPacket;

namespace Movement
{
    class MoveSpline;
    class PacketBuilder
    {
            static void WriteCommonMonsterMovePart(const MoveSpline& mov, WorldPacket& data);
        public:

            static void WriteMonsterMove(const MoveSpline& mov, WorldPacket& data);
            static void WriteCreate(const MoveSpline& mov, ByteBuffer& data);
    };
}
#endif // MANGOSSERVER_PACKET_BUILDER_H
