#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pi;
const int N = 15;
const int M = 32717;
int k, n;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> k >> n;
    vector <int> c(k + 1), dp(n + 1, 0);
    for(int i = 1; i <= k; ++i)cin >> c[i];
    for(int i = 0; i < k; ++i){
        cin >> dp[i];
    }

    for(int i = k; i <= n; ++i){
        for(int j = 1; j <= k; ++j){
            dp[i] = (dp[i] + dp[i - j] * c[j]) % M;
        }
    }
    // for(int i = 1; i <= n; ++i){
    //     cout << dp[i] << ' ';
    // }
    // cout << '\n';
    cout << dp[n];
    return (0);
}