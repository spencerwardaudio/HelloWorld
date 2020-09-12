/*
  ==============================================================================

    DataRace.h
    Created: 11 Sep 2020 10:16:15pm
    Author:  Spencer Ward

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

//Data obj is 16 bytes in size
struct Data
{
    uint64 a = 0;
    uint64 b = 0;
    
    bool operator==(const Data& other);
    bool operator!=(const Data& other);
};

const Data a = { 0xaaaaaaaa, 0xaaaaaaaa };
const Data b = { 0xffffffff, 0xffffffff };

struct A : Thread
{
    A(Data& _x) : Thread("A"), x(_x) { startThread(); }
    ~A() { stopThread(100); }
    void run() override;
    Data& x;
};

struct B : Thread
{
    B(Data& _x) : Thread("B"), x(_x) { startThread(); }
    ~B() { stopThread(100); }
    void run() override;
    Data& x;
};

struct Test
{
    Data data;
    A a { data };
    B b { data };
};
