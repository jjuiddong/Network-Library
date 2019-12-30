# Network-Library
Network Library with VS2017 C++, WinSock


- TCP, UDP/IP Network Library using C++
- Protocol Generator
  - Automate Generate C++ Code for Send/Recv Packet Parser and Maker
- Automate Call Packet Receive Function
  - inherit packet handler inteface
  - using realtime type information, call packet handling function
- Tool
  - Protocol Generator
    - need boost library build
    - change STL debug level option for debug mode
    - ex) c:\tools\bjam toolset=msvc link=static threading=multi define="_ITERATOR_DEBUG_LEVEL=0" define="_HAS_ITERATOR_DEBUGGING=0" debug stage
- Sample
  - TCP Server/Client
  - UDP Server/Client
  - TCP Transaction Test Client
  - UDP Transaction Test Client
  - Chatting Server/Client
  
