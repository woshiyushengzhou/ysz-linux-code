#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, const char *argv[])
{
    srand(time(NULL));
    printf("%d\n",rand());
    return 0;
}
