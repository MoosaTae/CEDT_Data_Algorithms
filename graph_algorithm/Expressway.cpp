#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(v) v.begin(), v.end()
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 707;
const int INF = 1e9;
int n, a, b, w, k;
vector <pii> c[N];
priority_queue <pii, vector<pii>, greater<pii> > pq;
vector <int> dist;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> w;
    c[1].emplace_back(w, 2);
    for(int year = 3; year <= n; ++year){
        dist.assign(year + 1, INF);
        cin >> k;
        for(int i = 0; i < k; ++i){
            cin >> a >> w;
            c[a].emplace_back(w, year);
            c[year].emplace_back(w, a);
        }
        dist[1] = 0;
        pq.emplace(0, 1);
        while(!pq.empty()){
            a = pq.top().s;
            w = pq.top().f;
            pq.pop();
            for(auto &e : c[a]){
                if(dist[e.s] > w + e.f){
                    dist[e.s] = w + e.f;
                    pq.emplace(dist[e.s], e.s);
                }
            }
        }
        cout << dist[2] << ' ';
    }

    return (0);
}