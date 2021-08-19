#include "Environment.h"

int main(int argc, char *argv[], char *envp[])
{
    if (argc != 2)
    {
        return -1;
    }

    listEnvStartingWith(envp, argv[1]);
    return 0;
}