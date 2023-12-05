#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 10;
vector <int> v(N), dp(N, 0);
vector <bool> visited(N);

int max_suffix(int idx){
    if(idx == 1)
        return v[1];
    if(visited[idx]){
        return dp[idx];
    }
    dp[idx] = max(v[idx], v[idx] + max_suffix(idx - 1));
    visited[idx] = 1;
    return dp[idx];
}

int mss(int idx){
    if(idx == 1)
        return v[1];
    return max({mss(idx - 1), v[idx], v[idx] + max_suffix(idx - 1)});
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;    
    for(int i = 1; i <= n; ++i)cin >> v[i];


    return 0;
}