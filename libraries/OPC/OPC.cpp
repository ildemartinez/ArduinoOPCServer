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
  OPCItemList = (OPCItemType *) realloc(OPCItemList, (OPCItemsCount + 1) * sizeof(OPCItemType));
  strncpy(OPCItemList[OPCItemsCount].itemID, itemID, MAXOPCITEMNAME);
  OPCItemList[OPCItemsCount].itemType = opctype; 
  OPCItemList[OPCItemsCount].opcAccessRight = opcAccessRight; 
  OPCItemList[OPCItemsCount].ptr_callback = callback_function; 
  OPCItemsCount++;
}
