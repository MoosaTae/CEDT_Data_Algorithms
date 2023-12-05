#include <bits/stdc++.h>
using namespace std;
int ans, n;
bool table[12][12], coled[12];

bool check(int row, int col){
    for(int i = 1; row >= i && col >= i; ++i)
        if(table[row - i][col - i])
            return false;
    for(int i = 1; row >= i && col + i < n; ++i)
        if(table[row - i][col + i])
            return false;
    return true;
}

void solve(int k){
    if(k == n){
        ans++;
        return;
    }
    for(int col = 0; col < n; ++col){
        if(!coled[col] && check(k, col)){
            // cout << k << ' ' << col << '\n';
            table[k][col] = 1;
            coled[col] = 1;
            solve(k + 1);
            table[k][col] = 0;
            coled[col] = 0;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    solve(0);
    cout << ans << '\n';
    return (0);
}