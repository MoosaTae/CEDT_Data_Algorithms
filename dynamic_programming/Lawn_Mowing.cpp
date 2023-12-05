#include <bits/stdc++.h>
using namespace std;
int n, a;
vector <int> adj[1005];

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < n - i; ++j){
            cin >> a;
            adj[i - 1].emplace_back(a);
        }
    }

    return 0;
}