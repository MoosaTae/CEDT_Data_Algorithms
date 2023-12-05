#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, a, b;
ll k, used, color[55];
vector<int> adj[55];

bool trycolor(int i){
    if(i == n) return true;
    used = 0;
    for(auto &edge : adj[i]){
        used |= color[edge];
    }
    ll tmp, valid = (~used) & k;
    while(valid > 0){
        tmp = valid & (-valid);
        color[i] = tmp;
        if(trycolor(i + 1)) return true;
        valid -= tmp;
    }
    return false;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        adj[max(a, b)].emplace_back(min(a, b));
    }
    int left = 1, right = n;
    while(left < right){
        m = (left + right) >> 1;
        k = (1 << m) - 1;
        if(trycolor(0))right = m;
        else left = m + 1;
    }
    cout << left;

    return (0);
}