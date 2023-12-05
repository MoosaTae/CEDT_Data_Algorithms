#include <bits/stdc++.h>
using namespace std;
int  n, m, k, w, ans, sum;
vector <int> p, h, t, target, hit;

void solve(int num){
    if(num < k){
        for(int i = 0; i < m; ++i){
            target[num] = i;
            solve(num + 1);
        }
    }
    else{
        hit.assign(sizeof(hit), 0);
        for(int i = 0; i < k; ++i)
            if(abs(p[target[i]] - t[i]) <= w)
                hit[target[i]] = min(hit[target[i]] + 1, h[target[i]]);
        sum = 0;
        for(int i = 0; i < m; ++i)
            sum += max(0, h[i] - hit[i]);
        ans = min(ans, sum);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> k >> w;
    p.resize(m);   
    h.resize(m);
    t.resize(k);
    target.resize(k);
    hit.resize(k);

    for(int i = 0;i < m; ++i)cin >> p[i];
    for(int i = 0; i < m; ++i){
        cin >> h[i];
        ans += h[i];
    }
    for(int i = 0;i < k; ++i)cin >> t[i];
    solve(0);
    cout << ans << '\n';
    return (0);
}