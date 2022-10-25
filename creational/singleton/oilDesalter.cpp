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
  // Singleton object
  static oilDesalter uniqueInstance;

  return uniqueInstance;
}
