#include <stdio.h>
#include <time.h>
#include "utils.h"
#include "window.h"


int main()
{
    srand(time(NULL));

    State state = createState("QuikShort",WIDTH,HEIGHT);

    initState(&state);
    updateState(&state);
    closeState(&state);

}
