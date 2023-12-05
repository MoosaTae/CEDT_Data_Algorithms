#include <bits/stdc++.h>
using namespace std;
int z,n;
int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> z;
    while(z--){
        cin >> n;
        double table[n][n];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cin >> table[i][j];
            }
        }
        for(int k = 0; k < n; ++k){
            for(int i = 0; i < n; ++i){
                for(int j = 0; j < n; ++j){
                    table[i][j] = max(table[i][j], table[i][k] * table[k][j]);
                }
            }
        }
        bool found = false;
        for(int i = 0; i < n; ++i)
            if(table[i][i] > 1)
                found = true;
        if(found)cout << "YES\n";
        else cout << "NO\n";
    }
    
    return (0);
}