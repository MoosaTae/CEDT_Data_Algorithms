#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
const int N = 15;
int table[N][N];
bool visited[N][N];
int r, c, cnt;

void solve(int i, int j, string mem){
    if(i == r && j == c){
        cout << mem << '\n';
        return;
    }
    visited[i][j] = true;
    if(j < c && !visited[i][j + 1] && !table[i][j + 1]){
        solve(i, j + 1, mem + "A");
    }
    if(i < r && !visited[i + 1][j] && !table[i + 1][j]){
        solve(i + 1, j, mem + "B");
    }
    if(i > 1 && !visited[i - 1][j]  && !table[i - 1][j]){
        solve(i - 1, j, mem + "C");
    }
    visited[i][j] = false;

}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            cin >> table[i][j];
        }
    }
    solve(1, 1, "");
    cout << "DONE";   
    return (0);
}