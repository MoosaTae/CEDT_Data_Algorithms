#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 10;
vector <int> v(N), dp(N, 0);
vector <bool> visited(N);

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;    
    for(int i = 1; i <= n; ++i)cin >> v[i];
    int suf = v[1];
    int mss = v[1];
    for(int i = 2; i <= n; ++i){
        suf = max(v[i], v[i] + suf);
        mss = max(mss, suf);
    }
    cout << mss;

    return 0;
}