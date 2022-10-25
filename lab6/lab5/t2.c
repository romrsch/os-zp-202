#include <windows.h>
typedef int (*fun)(int);
int main(){
HINSTANCE hInst;
fun pf,pg;
int* pa;
hInst=LoadLibrary("td2.dll");
pa=(int*)GetProcAddress(hInst, "a");
pf=(fun)GetProcAddress(hInst, "f");
pg=(fun)GetProcAddress(hInst, "g");
printf("%i %i %i\n",*pa,pf(3),pg(3));
FreeLibrary(hInst);
return 0;
}
