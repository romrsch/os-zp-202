#include <windows.h>
#include <process.h>
#include <stdio.h>


HANDLE hMutex1, hMutex2;
    double sh1=0.0;
    int sh2=0;

void Thread( void* pParams );

int main( void ) {
    hMutex1=CreateMutex(NULL,FALSE,NULL);
    hMutex2=CreateMutex(NULL,FALSE,NULL);
    _beginthread( Thread, 0, NULL );

while( 1 ){
    WaitForSingleObject(hMutex1, INFINITE);//������
    printf("%g\n",sh1);

    WaitForSingleObject(hMutex2, INFINITE);//������
    printf("%d\n",sh2);

    ReleaseMutex(hMutex2);//������������
    ReleaseMutex(hMutex1);//������������
}
return 0;
}

void Thread( void* pParams ){
// ����� ��������� ������� ������� Mutex'a
while ( 1 ){
    WaitForSingleObject(hMutex1, INFINITE);//������ �������� - ������ � hMutex2 �� hMutex1

    sh2++;
    WaitForSingleObject(hMutex2, INFINITE);//������ �������� - ������ � hMutex1 �� hMutex2

    sh1+=0.1;
    ReleaseMutex(hMutex1);        //������������ ��������
    ReleaseMutex(hMutex2);        //������������ ��������
}
}
