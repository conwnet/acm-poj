#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

int M, N, u[31000], v[31000], w[31000];
int d[31000], fir[31000], next[31000];

int dijkstra();

int main()
{
        memset(fir, -1, sizeof(fir));
        scanf("%d%d", &N, &M);
        for(int i=0; i<M; i++) {
                scanf("%d%d%d", &u[i], &v[i], &w[i]);
                next[i] = fir[u[i]];
                fir[u[i]] = i;
        }
        printf("%d\n", dijkstra());

        return 0;
}

typedef pair<int, int> P;

int dijkstra()
{
        priority_queue<P, vector<P>, greater<P> > pq;
        for(int i=0; i<=N; i++) d[i] = 99999999;
        d[1] = 0;
        pq.push(P(0, 1));
        while(!pq.empty()) {
                P t = pq.top(); pq.pop();
                int vv = t.second;
                if(d[vv]!=t.first) continue;
                for(int p=fir[vv]; p!=-1; p=next[p]) {
                        if(d[u[p]]+w[p] < d[v[p]]) {
                                d[v[p]] = d[u[p]] + w[p];
                                pq.push(P(d[v[p]], v[p]));
                        }
                }
        }
        return d[N];
}
