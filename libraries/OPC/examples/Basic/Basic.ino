#include <OPCSerial.h>
#include <SPI.h>        
#include <Ethernet.h>
/*
 * Declaring the OPC object
 */
OPCSerial aOPCSerial;

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




