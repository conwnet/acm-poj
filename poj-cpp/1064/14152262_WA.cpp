#include <stdio.h>

double arr[11000];
int N, K;

int judge(double len);

int main()
{
        int i, j, cnt;
        double m;

        scanf("%d%d", &N, &K);
        for(i=0; i<N; i++) scanf("%lf", &arr[i]);

        double l=0, r=999999;
        for(i=0; i<200; i++) {
                m = (l+r)/2;
                if(judge(m)) l = m;
                else r = m;
        }
        printf("%.2lf\n", m);

        return 0;
}

int judge(double len)
{
        int i, cnt;

        cnt = 0;
        for(i=0; i<N; i++) {
                cnt += (int)(arr[i]/len);
        }
        if(cnt>=K) return 1;
        else return 0;
}
