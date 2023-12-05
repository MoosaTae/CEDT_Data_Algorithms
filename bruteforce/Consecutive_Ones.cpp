#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int>v;
void solve(int len, int repeat, bool ok){
    if(len < n){
        v[len] = 0;
        solve(len + 1, 0, ok);
        v[len] = 1;
        if(repeat + 1 == m)
            solve(len + 1, repeat + 1, 1);
        else
            solve(len + 1, repeat + 1, ok);
    }
    else if(len == n && ok){
        for(int i = 0; i < n; ++i)
            cout << v[i];
        cout << '\n';
    }
}
int main(){
    cin >> n >> m;
    v.resize(n);
    solve(0, 0, 0);
    return 0;
}