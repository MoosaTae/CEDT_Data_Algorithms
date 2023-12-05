#include <bits/stdc++.h>
using namespace std;

const int N=21,K=10;
int g[N][N];
int n,m,k[K], sum;
bool vis[N],f[K];

void dfs(int nn, int nk, int idx){
    if (f[idx]) return;
    int tmp=0;
    for (int i = 0; i < n; i++) {
        if (!vis[i] && i != nn) {
            int max_weight = 0;
            for (int j = 0; j < n; j++) {
                if (!vis[j] || j == nn) {
                    max_weight = max(max_weight, g[i][j]);
                }
            }
            tmp += max_weight;
        }
    }
    if (sum + tmp < nk || sum > nk) return;
    if (sum == nk) {
        f[idx] = 1;
        return;
    }
    for (int j = 0; j < n; j++) {
        if (vis[j] || g[nn][j] == 0 || f[idx]) continue;
        vis[j] = 1;
        sum += g[nn][j];
        dfs(j, nk, idx);
        sum -= g[nn][j];
        vis[j] = 0;
    }
}

int main (){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i=0;i<8;i++) cin >> k[i];
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        g[u][v] = w;
        g[v][u] = w;
    }
    for (int j=0;j < 8; j++) for(int i=0;i<n;i++) vis[i]=1,dfs(i, k[j], j),vis[i]=0;

    for (int i = 0; i < 8; i++) {
        if (f[i]) cout << "YES\n";
        else cout << "NO\n";
    }
}


