#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n, a, cnt, ans, u, v;
const int N = 1005;
vector <pair<int, pair<int, int> > > edge;
vector <int> parent(N, -1);
int find_parent(int v){
    if(parent[v] != -1)return parent[v] = find_parent(parent[v]);
    return v;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n - 1; ++i){
        for(int j = i + 1; j < n; ++j){
            cin >> a;
            edge.emplace_back(make_pair(a, make_pair(i, j)));
        }
    }
    sort(edge.begin(), edge.end());
    for(auto &e : edge){
        u = find_parent(e.s.f);
        v = find_parent(e.s.s);
        if(u != v){
            parent[v] = u;
            ans += e.f;
        }
    }
    cout << ans << '\n';

    return 0;
}