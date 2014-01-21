#include <EthernetUdp.h> 

#include "OPCNet.h"

unsigned int localPort = 8888;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "acknowledged";       // a string to send back

OPCNet::OPCNet() {
      
}

void OPCNet::internal_setup() {
  Udp.begin(localPort);
}

void OPCNet::setup(uint8_t *mac_address, IPAddress local_ip) {
  Ethernet.begin(mac_address,local_ip);
  internal_setup();
}

void OPCNet::setup(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server) {
  Ethernet.begin(mac_address,local_ip,dns_server);
  internal_setup();
}

void OPCNet::setup(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway) {
  Ethernet.begin(mac_address,local_ip,dns_server,gateway);
  internal_setup();
}

void OPCNet::setup(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet) {
  Ethernet.begin(mac_address,local_ip,dns_server,gateway,subnet);
  internal_setup();
}  
  
void OPCNet::processOPCCommands() {
    // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  if(packetSize)
  {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
    Serial.print("From ");
    IPAddress remote = Udp.remoteIP();
    for (int i =0; i < 4; i++)
    {
      Serial.print(remote[i], DEC);
      if (i < 3)
      {
        Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Contents:");
    Serial.println(packetBuffer);

    // send a reply, to the IP address and port that sent us the packet we received
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    Udp.endPacket();
  }
  delay(10);
}


