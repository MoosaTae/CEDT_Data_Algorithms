#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int > pi;
typedef pair<int, pair<int, int > > pii;
int n,e,s,a,b,w;
const int INF = 1e9;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> e >> s;
    vector <pii> edge;
    for(int i = 0; i < e; ++i){
        cin >> a >> b >> w;
        edge.emplace_back(w, make_pair(a, b));
    }
    vector <int> dis(n, INF);
    dis[s] = 0;
    int i;
    bool isupdate;
    for(i = 0; i < n; ++i){
        isupdate = 0;
        for(auto &e : edge){
            if(dis[e.s.s] > dis[e.s.f]+ e.f){
                dis[e.s.s] = dis[e.s.f]+ e.f;
                isupdate = 1;
            }
        }
        if(!isupdate)break;
    }
    if(i != n) for(int i = 0; i < n; ++i)cout << dis[i] << ' ';
    else cout << "-1";
    return (0);
}