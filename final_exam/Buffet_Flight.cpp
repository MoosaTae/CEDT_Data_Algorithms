#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pii;
const int N = 2005;
const int INF = 1e9;
bool vis[N];
int n, m, cnt, a, b, w;
vector <int> g[N], ci(N), co(N), dis(N, INF);

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 0; i < n; ++i)cin >> ci[i];
    for(int i = 0; i < n; ++i)cin >> co[i];
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        g[a].emplace_back(b);
    }
    priority_queue <pii, vector<pii>, greater<pii> > pq;
    dis[0] = 0;
    pq.emplace(0, 0);
    while(!pq.empty()){
        a = pq.top().s;
        w = pq.top().f;
        pq.pop();
        for(auto &e : g[a]){
            if(dis[e] > w + co[a] + ci[e]){
                dis[e] = w + co[a] + ci[e];
                pq.emplace(dis[e], e);
            }
        }
    }
    for(int i = 0; i < n; ++i)cout << (dis[i] == INF ? -1 : dis[i]) << ' ';
    return (0);
}