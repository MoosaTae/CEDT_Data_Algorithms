#include <bits/stdc++.h>
using namespace std;
int n, m, a, b, ans, d[3];
vector <vector <int> > e;
vector <int> v;
void dfs(int i){
    d[0]++;
    v[i] = 1;
    if(e[i].size() > 0 && e[i].size() < 3)
        d[e[i].size()]++;
    for(auto &E : e[i])
        if(!v[E])
            dfs(E);
}
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    e.resize(n);
    v.assign(n, 0);
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        e[b].push_back(a);
        e[a].push_back(b);
    }
    for(int i = 0; i < n; ++i){
        if(!v[i]){
            fill(d, d + 3, 0);
            dfs(i);
            if(d[0] == 1 || (d[1] == 2 && d[2] == d[0] - 2))ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}