#include <stdio.h>
#include "utils.h" 
#include "window.h"


int main()
{
    const char* title = "QUICK-SHORT";
    State state = createState(title,WIDTH,HEIGHT);

    initState(&state);
    updateState(&state);
    closeState(&state);

    /*char s[3]; i_toa(45,s);

    printf("\n%s",s);

    return 0;*/
}
