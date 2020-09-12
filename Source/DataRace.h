/*
  ==============================================================================

    DataRace.h
    Created: 12 Sep 2020 12:26:38pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

struct LockingStruct
{
    void threadAFunc();
    void threadBFunc();
    
    int dataMember = 0;
    CriticalSection criticalSection;
};
