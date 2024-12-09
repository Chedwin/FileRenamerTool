#include "Define.h"

int main()
{
    char filePath[512];

    printf("Enter the desired filepath: ");

    scanf("%s", filePath);

    printf("You entered: %s\n", filePath);

    DIR* pdir = opendir(filePath);
    if (pdir)
    {
        printf("Directory (%s) was found!", filePath);
        closedir(pdir);
    }
    else if (ENOENT == errno)
    {
        printf("Directory (%s) was not found.", filePath);
    }
    else
    {
        printf("opendir() failed for unknown reason.");
    }

    return 0;
}