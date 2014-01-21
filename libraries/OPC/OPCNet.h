#ifndef OPCNET_H
#define OPCNET_H

#if defined(ARDUINO) && ARDUINO >= 100
  #include <Arduino.h>
#else
  #include <WProgram.h>
#endif

#include "OPC.h"
#include <Ethernet.h>

class OPCNet : public OPC {
private:
  EthernetUDP Udp;  
  void internal_setup();
public:
  OPCNet();
  void setup(uint8_t *mac_address, IPAddress local_ip);
  void setup(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server);
  void setup(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway);
  void setup(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet);
  void processOPCCommands();  
};

#endif
