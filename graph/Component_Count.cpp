#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, ans;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    queue <int> q;
    cin >> n >> m;
    vector <vector <int> > e(n + 1);
    vector <int> visited(n + 1, 0);
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        e[b].emplace_back(a);
        e[a].emplace_back(b);
    }
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            ans++;
            q.emplace(i);
            while(!q.empty()){
                if(!visited[q.front()]){
                    visited[q.front()] = 1;
                    for(auto &v: e[q.front()]){
                        if(!visited[v]){
                            q.emplace(v);
                        }
                    }
                }
                q.pop();
            }
        }
    }
    cout << ans << "\n";

    return 0;
}