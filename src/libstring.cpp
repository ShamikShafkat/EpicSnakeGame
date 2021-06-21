#include "libstring.h"

void number_to_string(int y,char points[])
{
    int i;
    for(i=0; y!=0; i++)
    {
        points[i] = y % 10 +'0';
        y = y/10;
    }
    if(i==0)
    {
        points[i++] = '0';
    }
    points[i] = '\0';

}

void string_reverse(char ch[])
{
    int len  = strlen(ch);
    char temp;
    int i,j;

    for(i=0,j=len-1; i<=(len/2)-1; i++,j--)
    {
        temp = ch[i];
        ch[i] = ch[j];
        ch[j] = temp;
    }
}

