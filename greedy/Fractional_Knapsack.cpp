#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
    cin.tie(0)->sync_with_stdio(false);
    double W, weight, ans = 0.0;
    int n;
    cin >> W >> n;
    vector <double> v(n);
    vector <pair <double, pair<double, double> > > frac;
    for(int i = 0; i < n; ++i)cin >> v[i];
    for(int i = 0; i < n; ++i){
        cin >> weight;
        frac.emplace_back(v[i]/weight, make_pair(weight, v[i]));
    }
    sort(frac.begin(), frac.end(), [](const pair<double, pair<double, double>>& a, const pair<double, pair<double, double>>& b) {
        return a.f > b.f;
    });
    for(int i = 0; i < n && W > 0; ++i){
        auto& current = frac[i];
        if(current.s.f <= W) ans += current.s.s;
        else ans += current.f * W;
        W -= current.s.f;
    }
    cout << fixed << setprecision(4) << ans << '\n';
    return 0;
}