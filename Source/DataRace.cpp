/*
  ==============================================================================

    DataRace.cpp
    Created: 11 Sep 2020 10:16:15pm
    Author:  Spencer Ward

  ==============================================================================
*/

#include "DataRace.h"

bool Data::operator==(const Data& other)
{
    return a == other.a && b == other.b;
}

bool Data::operator!=(const Data& other)
{
    return !(*this == other);
}

//=============================================
void A::run()
{
    while (true)
    {
        if( threadShouldExit() )
            break;
        
        x = a;
        
        //compare
        if( x != a && x != b)
        {
            auto _local = x;
            std::cout << "A: " << "x = { a.=" << String::toHexString(_local.a) <<
            ", .b=" << String::toHexString(_local.b) << " }" << std::endl;
        }
        wait(10);
    }
}

void B::run()
{
    while (true)
    {
        if( threadShouldExit() )
            break;
        
        x = b;
        
        //compare
        if( x != a && x != b)
        {
            auto _local = x;
            std::cout << "B: " << "x = { a.=" << String::toHexString(_local.a) <<
            ", .b=" << String::toHexString(_local.b) << " }" << std::endl;
        }
        wait(10);
    }
}
