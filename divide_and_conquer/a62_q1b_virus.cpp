#include <bits/stdc++.h>
using namespace std;
int n, k, power;
bool virus[(2 << 10) + 5];

bool solve(int l, int r){
    // cout << l << ' ' << r << '\n';
    int mid = (l + r) >> 1;
    if(mid - l == 1){
        if(virus[mid] && !virus[l])
            return true;
        return false;
    }
    else if(solve(mid, r)){
        if(solve(l, mid))
            return true;
        reverse(virus + l, virus + mid);
        if(solve(l, mid))
            return true;
        reverse(virus + l, virus + mid);
        return false;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> k >> n;
    power = 1 << n;
    while(k--){
        for(int i = 0; i < power; ++i){
            cin >> virus[i];
        }
        if(solve(0, power))
            cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}