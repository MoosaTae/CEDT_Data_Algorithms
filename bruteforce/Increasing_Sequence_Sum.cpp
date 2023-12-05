#include <bits/stdc++.h>
using namespace std;


void solve(int n, vector<int> &v, int &cnt, int len, int sum){
    if(sum < n){
        for(int i = len == 0 ? 1:v[len - 1]; i <= n - sum; ++i){
            v[len] = i;
            solve(n, v, cnt, len + 1, sum + i);
        }
    }
    else{
        // for(int i = 0; i < len; ++i)
        //     cout << v[i] << ' ';
        // cout << '\n';
        cnt++;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, cnt = 0;
    cin >> n;
    vector <int> v(n);
    solve(n,v,cnt, 0, 0);
    cout << cnt;
    return 0;
}