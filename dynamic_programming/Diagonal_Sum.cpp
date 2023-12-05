#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n, a, ans = -2e9, mx;
    cin >> n;
    vector<vector<int> > v(2 * n - 1);
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a;
            v[i - j + n - 1].emplace_back(a);
            ans = max(ans, a);
        }
    }
    for(int i = 0; i < 2 * n - 1; ++i){
        mx = v[i][0];
        for(int j = 1; j < v[i].size(); ++j){
            mx = max(mx + v[i][j], v[i][j]);
            ans = max(ans, mx);
        }
    }
    cout << ans << '\n';
    return (0);
}