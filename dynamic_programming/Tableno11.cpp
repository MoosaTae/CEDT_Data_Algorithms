#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    int n;
    const int N = 1e8+7;
    cin >> n;
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 3;
    for(int i = 2; i <= n; ++i)
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % N;
    cout << dp[n] << '\n';
    return (0);
}