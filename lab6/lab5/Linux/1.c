#include <stdio.h>
#include <stdlib.h>

extern double a;

int sh_fun(int);

int main(int argc, char* argv[])
{
    if(argc>1)
    a=atof(argv[1]);
        printf("%g\n",a);
        printf("%i\n", sh_fun(3));
return 0;
}
