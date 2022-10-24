#pragma once

class oilDesalter
{
public:
  oilDesalter(oilDesalter const&) = delete;
  void operator=(oilDesalter const&)  = delete;

  virtual ~oilDesalter();

  // Get method for singleton object
  static oilDesalter& getInstance();

  void fillMachine();
  void doProcessing();
  void removeSalt();

  bool isMachineEmpty() const;
  bool isSaltRemoved() const;

private:
  // Private constructor
  oilDesalter();

  bool saltRemovingMachineEmpty;
  bool oilDesalted;
};
