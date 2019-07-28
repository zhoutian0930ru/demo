Language: C++
Operating system: Microsoft Windows 8
local


The commands for Client contains "GET", "BOUNCE" and "EXIT".
Syntax and Arguments£º
GET£º"GET<test.txt>" command could read the "test.txt" file. 
     The filename locates behind "GET" directly.
     If the file is not exist, server will return ERROR.
BOUNCE: "BOUNCE<contents>" command could bounce "sample" from the server.
        The contents locates behind "BOUNCE" directly.
EXIT: "BOUNCE<contents>" command would return "contents" in server and the client would EXIT.
      Only "EXIT" command would have a default EXIT and return "Normal_Exit" in server.


