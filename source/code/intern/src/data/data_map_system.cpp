
#include "data_map_system.h"
#include "data_entity_list.h"

namespace Data
{
    class CDataMapSystem
    {
        public:

            static CDataMapSystem& GetInstance();

        public:

            CEntityIterator Begin(const Core::AABB2Float& _rAABB);


        private:

            struct STicket
            {

            };



    };

    CEntityIterator CDataMapSystem::Begin(const Core::AABB2Float& _rAABB)
    {
        int SectorMinX = static_cast<int>(_rAABB[0][0] / 8.0f); // 8 - Sectorgröße
        int SectorMinY = static_cast<int>(_rAABB[0][1] / 8.0f);
        int SectorMaxX = static_cast<int>(_rAABB[1][0] / 8.0f);
        int SectorMaxY = static_cast<int>(_rAABB[1][1] / 8.0f);

        float OffsetMinX = _rAABB[0][0] - SectorMinX * 8.0f; // 8 - Sectorgröße
        float OffsetMinY = _rAABB[0][1] - SectorMinY * 8.0f;
        float OffsetMaxX = _rAABB[1][0] - SectorMaxX * 8.0f;
        float OffsetMaxY = _rAABB[1][1] - SectorMaxY * 8.0f;

        if (OffsetMinX < 1.0f) -- SectorMinX; // 1 -> Min Überhang
        if (OffsetMinY < 1.0f) -- SectorMinY;
        if (OffsetMaxX > 7.0f) ++ SectorMaxX; // 7 -> Max Überhang
        if (OffsetMaxY > 7.0f) ++ SectorMaxY;

        if (SectorMinX < 0) SectorMinX = 0;
        if (SectorMinY < 0) SectorMinY = 0;
        if (SectorMaxX > 4) SectorMaxX = 4;  // 4 -> Maximale Sectorkoordinate in X-Richtung
        if (SectorMinY > 1) SectorMinY = 1;  // 1 -> Maximale Sectorkoordinate in Y-Richtung

        int SectorX = SectorMinX;
        int SectorY = SectorMinY;

        int Category = 0;

        for (;;)
        {
            // Hole Sector von Position SectorX, SectorY
            // Hole EntityFolder mit Category
                
                // Innere Schleife
                // Iteriere durch alle Entitäten im EntityFolder
                // Überprüfe ob AABB der Entität sich mit _rAABB schneidet
                // Wenn Ja, beende Methode und gebe Iterator auf Entität zurück

            ++ Category;

            if (Category == 3)
            {
                Category = 0;

                ++ SectorX;

                if (SectorX > SectorMaxX)
                {
                    SectorX = SectorMinX;
                    
                    ++ SectorY;

                    if (SectorY > SectorMaxY)
                    {
                        return Data::MapSystem::End();
                    }
                }

            }
        }
    }
}