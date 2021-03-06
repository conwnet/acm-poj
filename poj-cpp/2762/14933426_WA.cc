#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

const int maxn = 1024;
int fir[maxn], to[maxn*6], next[maxn*6], ec, N, M;

int add_edge(int u, int v)
{
        to[ec] = v; next[ec] = fir[u]; fir[u] = ec++;
}

int dfn[maxn], low[maxn], sta[maxn], ins[maxn], bel[maxn], ti, cnt, top;
void dfs(int u)
{
        dfn[u] = low[u] = ti++;
        sta[++top] = u; ins[u] = 1;
        for(int i=fir[u]; i!=-1; i=next[i]) {
                int v = to[i];
                if(!dfn[v]) {
                        dfs(v);
                        if(low[v]<low[u]) low[u] = low[v];
                } else if(ins[v] && dfn[v]<low[u]) {
                        low[u] = dfn[v];
                }
        }
        if(dfn[u]==low[u]) {
                int v; cnt++;
                do {
                        v = sta[top--];
                        bel[v] = cnt;
                        ins[v] = 0;
                } while(u!=v);
        }
}

int tarjan()
{
        memset(dfn, 0, sizeof(dfn));
        memset(low, 0, sizeof(low));
        memset(ins, 0, sizeof(ins));
        memset(bel, 0, sizeof(bel));
        top = ti = cnt = 0;
        for(int u=1; u<=N; u++) {
                if(!dfn[u]) dfs(u);
        }
        return cnt;
}

int outd[maxn];
vector<int> G[maxn];
int main()
{
        int T, u, v;
        scanf("%d", &T);
        while(T--) {
                memset(fir, -1, sizeof(fir)); ec = 0;
                scanf("%d%d", &N, &M);
                while(M--) {
                        scanf("%d%d", &u, &v);
                        add_edge(u, v);
                }
                tarjan();
                for(int i=1; i<=cnt; i++) G[i].clear();
                memset(outd, 0, sizeof(outd));
                for(int u=1; u<=N; u++) {
                        for(int i=fir[u]; i!=-1; i=next[i]) {
                                if(bel[u]==bel[to[i]]) continue;
                                G[bel[u]].push_back(bel[to[i]]);
                        }
                }
                int cnt0 = 0, i, u;
                for(u=1; u<=cnt; u++) {
                        if(G[u].size()==0) { cnt0++; continue; }
                        if(G[u].size()==1) continue;
                        for(i=0; i<G[u].size(); i++) {
                                if(G[u][i]!=G[u][i-1]) break;
                        }
                        if(i<G[u].size()) break;
                }

                if(cnt0>1 || u<=cnt) printf("No\n");
                else printf("Yes\n");
        }

        return 0;
}
