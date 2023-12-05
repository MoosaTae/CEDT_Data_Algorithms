#include <bits/stdc++.h>
using namespace std;

int n, e, a, b;
const int N = 1002;
int color[N];
vector<vector<int> > v;

bool check_cycle(int k, int parent){
    if(color[k] == 1)return true;
    else if(color[k] == 2)return false;
    color[k] = 1;
    for(auto &it : v[k]){
        if(it == parent)continue;
        if(check_cycle(it, k))return true;
    }
    color[k] = 2;
    return false;
}

void solve(){
    cin >> n >> e;
    vector<vector<int> >(N).swap(v);
    while(e--){
        cin >> a >> b;
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    memset(color, 0, sizeof(color));
    bool found = false;
    for(int i = 0; i < n && !found; ++i){
        if(!color[i] && 1){
            if(check_cycle(i, i)){
                found = true;
                cout << i << '\n';
            }
        }
    }
    if(!found) cout << "NO\n";
    else cout << "YES\n";
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int k;
    cin >> k;
    while(k--){
        solve();
    }
    return 0;
}