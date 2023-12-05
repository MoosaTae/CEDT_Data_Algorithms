#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n, m, k, a, b, ans, d, mx;
vector <vector <int> > e;
vector <int> visited;
queue <pair <int, int> > q;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m >> k;
    e.resize(n);
    visited.assign(n, 0);
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        e[b].push_back(a);
        e[a].push_back(b);
    }
    for(int i = 0; i < n; ++i){
        d = 0;
        fill(visited.begin(), visited.end(), 0);
        q.emplace(i, 0);
        while(!q.empty()){
            if(!visited[q.front().f] && q.front().s <= k){
                d++;
                visited[q.front().f] = 1;
                for(auto &E : e[q.front().f]){
                    if(!visited[E])
                        q.emplace(E, q.front().s + 1);
                }
            }
            q.pop();
        }
        // cout << i << "->" << d << '\n';
        if(d > mx){
            mx = d;
        }
    }
    cout << mx << "\n";

    return 0;
}