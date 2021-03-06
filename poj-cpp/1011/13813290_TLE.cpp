#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int low, high, n, stk[64], use[64], sum, ok, Max, yes;

int dfs(int a, int b);

int cmp(int a, int b){
    return a>b;
}

int main(){
    int i;

    while(scanf("%d", &n)!=EOF){
        if(n==0) break;
        memset(use, 0, 256);
        high = 0;
        for(i=0; i<n; i++){
            scanf("%d", &stk[i]);
            high += stk[i];
        }
        sort(stk, stk+n, cmp);
        low = stk[0];
        for(i=low; i<high; i++){
            if(stk[0]+stk[n-1]>i) continue;
            if(high%i) continue;
            sum = 0;
            ok = 0;
            Max = stk[0];
            dfs(i, 0);
            if(ok==1) break;
        }
        printf("%d\n", i);
    }

    return 0;
}

int dfs(int a, int b){
    int j, k;
    if(b==n){
        yes = 1;
        ok = 1;
        return 1;
    }
    else{
        for(int i=0; i<n; i++){
            if(i>0 && use[i-1]==0 && stk[i]==stk[i-1]) continue;
            for(k=0; use[k]==1; k++) Max = stk[k];
            if(use[i]==1) continue;
            if(sum>a){
                yes = 0;
                return 0;
            }
            if(sum==a){
                sum = 0;
                yes = 1;
            }
            sum += stk[i];
            use[i] = 1;
            dfs(a, b+1);
            use[i] = 0;
            sum -= stk[i];
            if(i==0 && yes==0) return 0;
        }
    }
    return 0;
}

