#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

const int maxn = 1024;
const int INF = 0x3f3f3f3f;
struct Edge {
        int to, cost, next;
} edge[maxn*200];
int fir[maxn], ec, N, ML, MD;

void add_edge(int u, int v, int w)
{
        edge[ec] = (Edge){v, w, fir[u]};
        fir[u] = ec++;
}

int cnt[maxn], dis[maxn];
int spfa(int s)
{
        queue<int> que;
        memset(dis, 0x3f, sizeof(dis));
        memset(cnt, 0, sizeof(cnt));
        dis[s] = 0; que.push(s);
        while(!que.empty()) {
                int u = que.front(); que.pop();
                for(int i=fir[u]; i!=-1; i=edge[i].next) {
                        Edge &e = edge[i];
                        if(dis[u]+e.cost < dis[e.to]) {
                                dis[e.to] = dis[u]+e.cost;
                                que.push(e.to);
                                cnt[u]++;
                                if(cnt[u]>N) return 0;
                        }
                }
        }
        ///for(int i=0; i<=N; i++) printf("%d ", dis[i]); printf("\n");
        return 1;
}


int main()
{
        int u, v, w;
        memset(fir, -1, sizeof(fir)); ec = 0;
        scanf("%d%d%d", &N, &ML, &MD);
        while(ML--) {
                scanf("%d%d%d", &u, &v, &w);
                add_edge(u, v, -w);
                add_edge(v, u, w);
        }
        while(MD--) {
                scanf("%d%d%d", &u, &v, &w);
                add_edge(u, v, -w);
        }
        for(int i=1; i<N; i++)
                add_edge(i, i+1, 0);
        for(int i=1; i<=N; i++)
                add_edge(0, i, 0);
        if(!spfa(0)) printf("-1\n");
        else {
                spfa(N);
                int ans = dis[1];
                if(ans<INF) printf("%d\n", ans);
                else printf("-2\n");
        }

        return 0;
}
