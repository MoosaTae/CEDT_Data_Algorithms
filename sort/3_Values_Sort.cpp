#include <bits/stdc++.h>
using namespace std;
int n, c0, c1, ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    vector <int> v(n), v2;
    int c[4][4] = {};
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }
    v2 = v;
    sort(v2.begin(), v2.end());
    for(int i = 0; i < n; ++i)c[v2[i]][v[i]]++;
    if(c[2][1] > c[1][2])ans = c[2][1] + c[3][1] + c[3][2];
    else ans = c[1][2] + c[1][3] + c[2][3];
    cout << ans << '\n';
    return (0);
}
