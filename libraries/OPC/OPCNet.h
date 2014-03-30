#ifndef OPCNET_H
#define OPCNET_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "OPC.h"
#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h> 

class OPCNet : public OPC {
public:
  OPCNet();
  void setup();
  void processOPCCommands();  
};

#endif
