#include <stdio.h>

char num[1000010], N;

int main()
{
        int i, a, b;

        scanf("%d", &N);
        for(i=0; i<N; i++) {
                getchar();
                num[i] = getchar();
                getchar();
                num[i] += getchar()-'0';
        }
        num[i] = 0;
        for(i=N-1; i>0; i--) {
                if(num[i]>'9') {
                        num[i] -= 10;
                        num[i-1] += 1;
                }
        }
        printf("%s\n", num);

        return 0;
}
