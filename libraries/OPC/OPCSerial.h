#ifndef OPCSerial_H
#define OPCSerial_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "OPC.h"

class OPCSerial : public OPC {
public:	
  OPCSerial();
  void setup();
  void processOPCCommands();
private:                       
  void sendOPCItemsMap();     
};

#endif
