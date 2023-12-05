#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, m, k, a;
    ll b;
    cin >> n >> m >> k;
    vector <ll> v(n + 1);
    vector <ll>::iterator l;
    v[0] = k;
    for(int i = 1; i <= n; ++i){
        cin >> v[i];
        v[i] += v[i - 1] + k;
    }
    while(m--){
        cin >> a >> b;
        l = upper_bound(v.begin(), v.end(), v[a] + b);
        if(l != v.end())l--;
        else l = v.begin() + n;
        cout << *l - v[a] - (l - v.begin() - a) * k << '\n';
    }
    return 0;
}