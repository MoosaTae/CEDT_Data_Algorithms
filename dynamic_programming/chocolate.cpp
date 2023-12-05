#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector <int> dp(n + 1, 0), how(m);
    for(int i = 0; i < m; ++i)
        cin >> how[i];
    // sort(how.begin(), how.begin() + m);
    dp[0] = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 0; j < m; ++j){
            if(i >= how[j])
                dp[i] = (dp[i] + dp[i - how[j]]) % 1000003;
        }
    }
    cout << dp[n];
    return 0;
}