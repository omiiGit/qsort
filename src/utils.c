#include "utils.h" 

static void itoa(int num,char* s,int* i)
{
    if(num / 10)
    {
        itoa(num/10,s,i);
        s[(*i)++] = num % 10 + '0';
    }
    else
    {
        s[(*i)++] = num % 10 + '0';
    }
}

void i_toa(int num,char* s)
{
    int i = 0;

    /*for(i = 0;num != 0;i++)
    {
        s[i] = num%10 + '0';
        num /= 10;
    }*/ 
    
    itoa(num,s,&i);

    s[i] = '\0';

}
