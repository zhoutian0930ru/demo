
#include<WINSOCK2.H>
#include<STDIO.H>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;
#pragma comment(lib, "ws2_32.lib")

int main()
{
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;

	cout << "COMMANDS:" << endl
		<< "  GET<>: (example GET<test.txt>)" << endl
		<< "  BOUNCE<>: (example BOUNCE<contents>)" << endl
		<< "  EXIT<>:" << endl
		<< "********************************" << endl;

	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}
	string round = "a";
	while (true && round.compare(0,4,"EXIT")) {
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (sclient == INVALID_SOCKET)
		{
			printf("invalid socket!");
			return 0;
		}

		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;
		serAddr.sin_port = htons(8888);
		serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
		if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
		{  //fail connection
			printf("connect error !");
			closesocket(sclient);
			return 0;
		}

		char revName[255];
		int reName = recv(sclient, revName, 255, 0);
		if (reName > 0)
		{
			revName[reName] = 0x00;
			printf(revName);
			cout << endl;
		}
		
		
		
		
		string data;
		cin >> data;
		const char * sendData;
		sendData = data.c_str();   
		send(sclient, sendData, strlen(sendData), 0);

		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		round = recData;
		if (ret>0) {
			recData[ret] = 0x00;
			printf(recData);
			cout << endl;
		}		
		closesocket(sclient);
		cout << endl;
	}


	WSACleanup();
	return 0;

}


