#include <iostream>
#include <chrono>
#include "MemPool.h"
#include "without_pool.h"
#include "with_pool.h"
using namespace std;


int main()
{
    SimpleAllocation();
    PoolAllocation();
    long unitNum = 4;
    long unitSize = 32;
    MemoryPool* pool = new MemoryPool(unitNum,unitSize);

    void* p1 = pool-> Allocate(unitSize);
    pool -> Free(p1);

    delete pool;
}
