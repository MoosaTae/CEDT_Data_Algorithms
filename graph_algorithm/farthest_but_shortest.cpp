#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define rep(i, a, b) for(int i = a; i < b; ++i)
typedef pair <int, int> pii;
typedef vector<int> vi;
const int N = 1005;
const int INF = 1e9;
int n, cnt, a, b, w;
vector <pii> adj[N];
bool visited[N];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 0, n){
        rep(j, 0, n){
            cin >> w;
            if(w > 0){
                adj[i].emplace_back(w, j);
            }
        }
    }
    priority_queue <pii, vector<pii>, greater<pii> > pq;
    pq.emplace(0, 0);
    vi dis(n, INF);
    dis[0] = 0;
    while(!pq.empty()){
        a = pq.top().s;
        w = pq.top().f;
        pq.pop();
        for(auto &e : adj[a]){
            if(dis[e.s] <= e.f + w) continue;
            dis[e.s] = e.f + w;
            pq.emplace(dis[e.s], e.s);
        }
    }
    int ans = 0;
    for(int i = 0; i < n; ++i){
        if(dis[i] == INF){
            ans = 0;
            break;
        }
        if(dis[i] > ans)ans = dis[i];
     }
    cout << (ans != 0 ? ans : -1) << '\n';

    return 0;
}