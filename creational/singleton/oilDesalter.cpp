#include "oilDesalter.hpp"
#include <iostream>

oilDesalter::oilDesalter()
{
  std::cout << "Creating singleton object!" << std::endl;

  saltRemovingMachineEmpty = true;
  oilDesalted = false;
}

oilDesalter::~oilDesalter()
{
}

void oilDesalter::fillMachine()
{
  if (isMachineEmpty())
  {
    saltRemovingMachineEmpty = false;
    oilDesalted = false;

    // fill the boiler with a milk/chocolate mixture
  }
}

void oilDesalter::doProcessing()
{
  if (isMachineEmpty() && isSaltRemoved())
  {
    saltRemovingMachineEmpty = true;
  }
}

void oilDesalter::removeSalt()
{
  if (!isMachineEmpty() && !isSaltRemoved())
  {
    oilDesalted = true;
  }
}

bool oilDesalter::isMachineEmpty() const
{
  return saltRemovingMachineEmpty;
}

bool oilDesalter::isSaltRemoved() const
{
  return oilDesalted;
}

oilDesalter& oilDesalter::getInstance()
{
  // Note: This so called "lazy initialization" (Meyers' Singleton)
  // is thread-safe since C++11 and GCC 4.3!

  // Singleton object
  static oilDesalter uniqueInstance;

  return uniqueInstance;
}
