#include <stdio.h>

char S1[39] = {"1234567890QWERTYUIOPASDFGHJKLZXCVBNM,."};
char S2[39] = {"234567890-WERTYUIOP[SDFGHJKL;XCVBNM,./"};
int maps[128];

int main()
{
        for(int i=0; i<38; i++)
                maps[S2[i]] = i;
        while(int ch=getchar()) {
                if(EOF==ch) break;
                if(ch==' ' || ch=='\n') putchar(ch);
                else putchar(S1[maps[ch]]);
        }

        return 0;
}
