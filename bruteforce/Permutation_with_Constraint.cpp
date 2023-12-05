#include <bits/stdc++.h>
using namespace std;
int n, m, a, b;
vector<int> v, ctt;
vector <bool> flag;

void solve(int k){
    if(k == n){
        for(int i = 0; i < n; ++i)
            cout << v[i] << " ";
        cout << "\n";
        return;
    }
    
    for(int i = 0; i < n; ++i){
        if(!flag[i] && (ctt[i] == -1 || flag[ctt[i]])){
            flag[i] = true;
            v[k] = i;
            solve(k + 1);
            flag[i] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    v.reserve(n);
    flag.reserve(n);
    ctt.assign(n, -1);
    for(int i = 0; i < m; ++i){
        cin >> a >> b;
        ctt[b] = a;
    }
    solve(0);

    return 0;
}