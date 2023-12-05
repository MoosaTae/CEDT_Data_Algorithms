#include <bits/stdc++.h>
using namespace std;
int n, a, b, ans;
const int N = 1e5 + 5;
int d[N];
vector <int> adj[N];

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
        d[a]++;d[b]++;
    }
    // for(int z = 0; z < n; ++z){
    //     for(int i = 0; i < n; ++i){
    //         if(d[i] < 2 && d[i] != 0){
    //             for(auto &it : adj[i])
    //                 if(d[it])d[it]--;
    //             d[i] = 0;
    //         }
    //     }
    // }
    queue <int> q;
    for(int i = 0; i < n; ++i){
        if(d[i] < 2){
            q.emplace(i);
        }
    }

    


    for(int i = 0; i < n; ++i){
        if(d[i] > 1){
            ans++;
        }
    }
    cout << ans << '\n';


    return 0;
}