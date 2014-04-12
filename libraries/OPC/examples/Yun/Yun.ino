#include <OPC.h>

/*
 * Declaring the OPC object
 */
OPCNet aOPCNet;

void setup() {
  /*
   * OPC Object initialization
   */
  aOPCSerial.setup();
}

void loop() {
  /*
   * OPC process commands
   */
  aOPCSerial.processOPCCommands();
}