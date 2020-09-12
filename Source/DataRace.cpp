/*
  ==============================================================================

    DataRace.cpp
    Created: 12 Sep 2020 12:26:38pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "DataRace.h"

void LockingStruct::threadAFunc()
{
    {
        const ScopedLock sl(criticalSection);
        dataMember = 2;
    }
    std::cout << "thread A Func " << dataMember << std::endl;
}

void LockingStruct::threadBFunc()
{
    {
        const ScopedLock sl(criticalSection);
        dataMember = 0;
    }
    std::cout << "thread B Func " << dataMember << std::endl;
}
