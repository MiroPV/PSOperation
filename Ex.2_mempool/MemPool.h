//MemoryPool.h

class MemoryPool
{
private:
    struct Unit
    {
        struct Unit *pPrev, *pNext;
    };

    void* pMemBlockLocation; //addres of memPool

    struct Unit* pAllocateedMemBlockLocation;  //pointer to head of Allocated LinkedList
    struct Unit* pFreeMemBlockLocation;        //pointer to head of Free LinkedList

    long UnitSize;  //mem unit size
    long BlockSize; //mem block size

public:
    MemoryPool(long unitNum, long unitSize):
        pMemBlockLocation(nullptr),
        pAllocateedMemBlockLocation(nullptr),
        pFreeMemBlockLocation(nullptr),
        BlockSize(unitNum*(unitSize+sizeof(struct Unit))),
        UnitSize(unitSize)

        {
          pMemBlockLocation = malloc(BlockSize); //allocating mem block
          if(pMemBlockLocation == NULL)
          {
              for(long i=0; i<unitNum; i++) //create linked list
              {
                struct Unit *pCurrentUnit = (struct Unit *)(int *)pMemBlockLocation + i*(unitSize+sizeof(struct Unit));
                pCurrentUnit -> pPrev = nullptr;
                pCurrentUnit -> pNext = pFreeMemBlockLocation; //insert the new unit at head location

                if(pFreeMemBlockLocation != nullptr)
                {
                    pFreeMemBlockLocation ->pPrev = pCurrentUnit;
                }
                pFreeMemBlockLocation = pCurrentUnit;
              }
          }
        }
        ~MemoryPool()
        {
        free(pMemBlockLocation);
        }

        //allocate memory
        void* Allocate(long unitSize, bool UseMemPool = true)
        {
           if(unitSize > UnitSize || UseMemPool == false || pMemBlockLocation == nullptr || pFreeMemBlockLocation == nullptr)
           {
             return malloc(unitSize);
           }

            struct Unit *pCurrentUnit = pFreeMemBlockLocation;
            pFreeMemBlockLocation = pCurrentUnit -> pNext; // get a unit from free linkedlist
            if (pFreeMemBlockLocation != nullptr)
            {
                pFreeMemBlockLocation ->pPrev = nullptr;
            }

            pCurrentUnit ->pNext = pAllocateedMemBlockLocation;
            if(pAllocateedMemBlockLocation != nullptr)
            {
                pAllocateedMemBlockLocation ->pPrev = pCurrentUnit;
            }

            pAllocateedMemBlockLocation = pCurrentUnit;

            return (void *)((int *)pCurrentUnit + sizeof(struct Unit));
        }

        //function used to free a memory unit. If the pointer of parameter point to a memory unit
        //then insert it the "Free linked list". Otherwise, delete it
        void Free(void* p)
        {
            if(pMemBlockLocation< p && p<(void *)((int *)pMemBlockLocation+BlockSize))
            {
                struct Unit *pCurrentUnit = (struct Unit *)((int *)p-sizeof(struct Unit));
                struct Unit* pPrev = pCurrentUnit -> pPrev;
                struct Unit* pNext = pCurrentUnit -> pNext;

                if(pPrev == nullptr)
                {
                    pAllocateedMemBlockLocation = pCurrentUnit -> pNext;
                }
                else
                {
                    pPrev -> pNext = pNext;
                }
                if(nullptr != pNext)
                {
                    pNext -> pPrev = pPrev;
                }

                pCurrentUnit -> pNext = pFreeMemBlockLocation;
                if(pFreeMemBlockLocation)
                {
                    pFreeMemBlockLocation -> pPrev = pCurrentUnit;
                }
                pFreeMemBlockLocation = pCurrentUnit;
            }
            else
            {
                free(p);
            }
        }
};
