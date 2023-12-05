#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, int> pii;
const int N = 5005;
const int INF = 1e9;
int g[N][N];
bool vis[N];
int dis[2][N][N];
int r, c, cnt, row, col, y, x, ans = INF;
queue <pii> q, q2;
int mov[5] = {0, 1, 0, -1, 0};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c;
    for(int i = 1; i <= r; ++i){
        for(int j = 1; j <= c; ++j){
            cin >> g[i][j];
            dis[0][i][j] = INF;
            dis[1][i][j] = INF;
            if(g[i][j] == 1)q.emplace(i, j),dis[0][i][j] = 0;
            else if(g[i][j] == 2)q2.emplace(i, j),dis[1][i][j] = 0;
        }
    }
    while(!q.empty()){
        y = q.front().f;
        x = q.front().s;
        q.pop();
        if(g[y][x] == 2 && dis[0][y][x] != INF)ans = min(ans, dis[0][y][x]);
        for(int m = 0; m < 5; ++m){
            row = y + mov[m];
            col = x + mov[m + 1];
            if(row < 1 || col < 1 || row > r || col > c || g[row][col] == 3)continue;
            if(dis[0][row][col] > dis[0][y][x] + 1){
                dis[0][row][col] = dis[0][y][x] + 1;
                q.emplace(row, col);
            }
        }
    }
    // cout << '\n';
    // for(int i = 1; i <= r; ++i){
    //     for(int j = 1; j <= c; ++j){
    //         cout << dis[0][i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << ans + 1 << '\n';

    return (0);
}