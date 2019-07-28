#include <stdio.h>    
#include <winsock2.h>   
#include<fstream>
#include <iostream>
#include <string>
#include <sstream> 
using namespace std;

#pragma comment(lib,"ws2_32.lib")    

int main(int argc, char* argv[])
{
	//initialize WSA    
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}

	//build socket    
	SOCKET slisten = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (slisten == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}

	//IP and port    
	sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
	if (bind(slisten, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	}

	//Start listening  
	if (listen(slisten, 5) == SOCKET_ERROR)
	{
		printf("listen error !");
		return 0;
	}

	//Recycle receiving data  
	SOCKET sClient;
	sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	char revData[255];

	cout << "Server: " << endl;
	while (true)
	{
		printf("Waiting for connection...\n");
		sClient = accept(slisten, (SOCKADDR *)&remoteAddr, &nAddrlen);
		if (sClient == INVALID_SOCKET)
		{
			printf("accept error !");
			continue;
		}
		printf("Receive a connection£º%s \r\n", inet_ntoa(remoteAddr.sin_addr));

		
		string Name = "Server: rutgers";
		const char * sendName;
		sendName = Name.c_str();
		//const char * sendData = "BOUNCE FROM SERVER\n";
		send(sClient, sendName, strlen(sendName), 0);
		
		//receive data 		
		int ret = recv(sClient, revData, 255, 0);
		if (ret > 0)
		{
			revData[ret] = 0x00;
			cout << "received:";
			printf(revData);
			cout << endl;
		}

		string revCompare = revData;
		string GET = "GET<";
		string BOUNCE = "BOUNCE<";
		string EXIT = "EXIT<";
		int index;
		int length;
		index = revCompare.find_last_of(">") + 1;
		length = revCompare.length();
		string result;
		if (!revCompare.compare(0, 4, GET, 0, 4) && index==length) {		
			string filename = revData + 4;
			filename.erase(filename.end() - 1);
			cout << "Filename is: " << filename << endl;
			fstream file_read;
			file_read.open(filename, ios::in);
			if (!file_read)
			{
				result = "ERROR: no such file";
				cout << "ERROR: no such file" << endl;
			}
			else
			{
				//read connect data
				ifstream t(filename);
				stringstream buffer;
				buffer << t.rdbuf();
				string temp(buffer.str());	
				result = temp;
				cout << "Send " << filename << " to client." << endl;
			}
		}
		else {
			if (!revCompare.compare(0, 7, BOUNCE, 0, 7) && index == length) {
				string temp = revData + 7;
				temp.erase(temp.end() - 1);
				cout << "Bounce contents: " << temp << endl;
				result = temp;
			}
			else {
				if (!revCompare.compare("EXIT")) {
					result = "EXIT";
					cout << "Normal_Exit" << endl;
				}
				else {
					if (!revCompare.compare(0, 5, EXIT, 0, 5) && index == length) {
						string temp = revData + 5;
						temp.erase(temp.end() - 1);
						cout << temp << endl;
						result = "EXIT";
					}
					else {
						result = "The syntax and arguments of input commands are not appropriate.";
					}
				}									
			}
		}
		

		//send data 
		const char * sendData;
		sendData = result.c_str();
		//const char * sendData = "BOUNCE FROM SERVER\n";
		send(sClient, sendData, strlen(sendData), 0);
		closesocket(sClient);
		cout << endl;
	}

	closesocket(slisten);
	WSACleanup();
	return 0;
}