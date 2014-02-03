#include "OPC.h"

OPC::OPC() : OPCItemList(NULL) ,  OPCItemsCount(0) {
}

void OPC::addItem(const char *itemID, opcAccessRights opcAccessRight, opctypes opctype, bool (*function)(const char *itemID, const opcOperation opcOP, const bool value))
{ 
  internaladdItem(itemID, opcAccessRight, opctype, int(function));
}

void OPC::addItem(const char *itemID, opcAccessRights opcAccessRight, opctypes opctype, byte (*function)(const char *itemID, const opcOperation opcOP, const byte value))
{
  internaladdItem(itemID, opcAccessRight, opctype, int(function));  
}

void OPC::addItem(const char *itemID, opcAccessRights opcAccessRight, opctypes opctype, int (*function)(const char *itemID, const opcOperation opcOP, const int value))
{ 
  internaladdItem(itemID, opcAccessRight, opctype, int(function));
}

void OPC::addItem(const char *itemID, opcAccessRights opcAccessRight, opctypes opctype, float  (*function)(const char *itemID, const opcOperation opcOP, const float value))
{
  internaladdItem(itemID, opcAccessRight, opctype, int(function));
}

void OPC::internaladdItem(const char *itemID, opcAccessRights opcAccessRight, opctypes opctype, int callback_function)  
{
  //extern int __heap_start, *__brkval; 
  //int v; 
  //Serial.print(F("Free memory:"));
  //Serial.println( (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval));
  
  OPCItemList = (OPCItemType *) realloc(OPCItemList, (OPCItemsCount + 1) * sizeof(OPCItemType));
  if (OPCItemList != NULL) {
    OPCItemList[OPCItemsCount].itemType = opctype; 

    OPCItemList[OPCItemsCount].itemID = (char *) malloc(strlen(itemID)+1);
    strncpy(&OPCItemList[OPCItemsCount].itemID[0], itemID, strlen(itemID)+1);

    Serial.println(OPCItemList[OPCItemsCount].itemID);
    OPCItemList[OPCItemsCount].opcAccessRight = opcAccessRight; 
    OPCItemList[OPCItemsCount].ptr_callback = callback_function;
    OPCItemsCount++;
  } else {
     Serial.println(F("Not enough memory")); 
  }
  
}
