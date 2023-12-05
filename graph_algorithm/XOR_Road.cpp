#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n, cnt, u, v; 
unsigned long long ans;
const int N = 1005;
vector <pair<unsigned long long, pair<int, int> > > edge;
vector <int> parent(N, -1);
int find_parent(int v){
    if(parent[v] != -1)return parent[v] = find_parent(parent[v]);
    return v;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    vector <unsigned long long> road(n);
    for(int i = 0; i < n; ++i) cin >> road[i];
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            edge.emplace_back(road[i] ^ road[j], make_pair(i, j));
        }
    }
    sort(edge.begin(), edge.end(), [](const pair<unsigned long long, pair<int, int> > &a, const pair<unsigned long long, pair<int, int> > &b){
        return a.f > b.f;
    });
    for(auto &e : edge){
        u = find_parent(e.s.f);
        v = find_parent(e.s.s);
        if(u != v){
            parent[v] = u;
            ans += e.f;
            cnt++;
        }
        if(cnt == n - 1)break;
    }
    cout << ans << '\n';

    return 0;
}