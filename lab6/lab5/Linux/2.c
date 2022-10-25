#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>


typedef int (*fun)(int);
extern double a;
int main(int argc, char* argv[]){
    fun f;
    printf("Dynamic library test\n");
    void* h=dlopen("lib1d.so",RTLD_LAZY);
    printf("%g\n",a);
    f=(fun)dlsym(h,"sh_fun");
    printf("%i\n", f(5));
    dlclose(h);
return 0;
}
