ArduinoOPCServer
================

Arduino OPC Server is a library that is used by the OPC Server for Arduino for sharing information but can be used alone.

It provide to you with a easy way to interchange information between Arduino and Serial or Ethernet ports in a unified way.

How to use it
-------------

First of all you have to have in mind what do you want provide to the external world using Serial, Ethernet or even Wifi.

At this moment you can publish your items using serial or http ways. To do this you have some objects that you can use.

Declare OPCSerial aOPC; for serial use
Declare OPCNet aOPC; for http use

Declare your items
------------------

An item can be a real or virtual input/output pin of your Arduino. For example, you would want to publish your analog input A0 to the external world or a virtual value based in some operations made with your Arduino using real pins or calculations.



At this moment you can visit the project page at http://www.st4makers.com and download it.

Here you can find the libraries and samples sketchs to start learning and get fun.
