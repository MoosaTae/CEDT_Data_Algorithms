#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int > pi;
typedef pair<int, pair<int, int > > pii;
int n,e,k,a,b,w;
const int INF = 1e9;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> e >> k;
    vector <int> hacked_server;
    for(int i = 0; i < k; ++i){
        cin >> a;
        hacked_server.emplace_back(a);
    }
    vector <int> c(n);
    for(int i =0 ;i < n; ++i)
        cin >> c[i];
    vector <int> edge[n];
    for(int i = 0; i < e; ++i){
        cin >> a >> b;
        edge[a].emplace_back(b);
        edge[b].emplace_back(a);
    }
    vector <int> dis(n, INF);
    priority_queue <pi, vector<pi>, greater<pi> > pq;
    for(auto &x : hacked_server){
        dis[x] = c[x];
        pq.emplace(0, x);
    }
    while(!pq.empty()){
        a = pq.top().s;
        pq.pop();
        for(auto &x : edge[a]){
            if(dis[x] > dis[a] + c[x]){
                dis[x] = dis[a] + c[x];
                pq.emplace(dis[x], x);
            }
        }
    }
    int mx = 0;
    for(int i = 0; i < n; ++i)
        mx = max(mx, dis[i]);
    cout << mx << '\n';
    return (0);
}