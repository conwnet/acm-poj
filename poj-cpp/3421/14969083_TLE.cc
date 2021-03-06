#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

using namespace std;

typedef pair<int, int> P;
const int INF = (1<<20)+3;
int len[INF], cnt[INF];

void bfs()
{
        queue<P> que;
        que.push(P(1, 0));
        while(!que.empty()) {
                P tmp = que.front(); que.pop();
                int u = tmp.first;
                if(tmp.second > len[u]) {
                        len[u] = tmp.second;
                        cnt[u] = 1;
                } else if(tmp.second==len[u]) {
                        cnt[u]++;
                }
                for(int i=2; i*u<INF; i++) {
                        que.push(P(i*u, tmp.second+1));
                }
        }
}

void solve()
{
        len[1] = 0; cnt[1] = 1;
        for(int i=1; i*2<INF; i++) {
                for(int k=i*2; k<INF; k+=i) {
                        int t = len[i] + 1;
                        if(t > len[k]) {
                                len[k] = t;
                                cnt[k] = cnt[i];
                        } else if(t==len[k])
                                cnt[k] += cnt[i];
                }
        }
}

int main()
{
        int n;
        //bfs();
        solve();
        //return 0;
        //freopen("out2", "w", stdout);
        //for(int n=1; n<INF; n++) {
        while(~scanf("%d", &n)) {
                printf("%d %d\n", len[n], cnt[n]);
        }

        return 0;
}
