#include <windows.h>
#include <imagehlp.h>

int main(int argc, char* argv[]){
    LOADED_IMAGE LoadedImage;
    PUCHAR BaseAddress;
    DWORD RVAExpDir, VAExpAddress;
    IMAGE_EXPORT_DIRECTORY* ExpTable;

char* sName;
DWORD nNames;
char* pName;
char** pNames;
DWORD i;


