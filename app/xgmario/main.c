#include "dyn.h"
#include "os/os.h"

int main(int argc, char **argv)
{
    dynJSON *dj = djParse("false");
    if(dj)
    {
        djDestroy(dj);
    }
    return 0;
}
