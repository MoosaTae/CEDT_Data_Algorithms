#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef pair<int, pair<int, int> > pi;
int n,m,y,x,w,a,b;
const int INF = 1e9;
priority_queue <pi, vector<pi>, greater<pi> > q;
int mv[5] = {0, 1, 0, -1, 0};

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    vector<vector<int> > dis(n, vector<int> (m, INF));
    int g[n][m];
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> g[i][j];
    q.emplace(0, make_pair(0, 0));
    dis[0][0] = 0;
    while(!q.empty()){
        y = q.top().s.f;
        x = q.top().s.s;
        w = q.top().f;
        q.pop();
        if(w <= dis[y][x]){
            for(int i = 0; i < 4; ++i){
                a = y + mv[i];
                b = x + mv[i + 1];
                if(a < 0 || a >= n || b < 0 || b >= m)continue;
                if(dis[a][b] > dis[y][x] + g[a][b]){
                    dis[a][b] = dis[y][x] + g[a][b];
                    q.emplace(dis[a][b], make_pair(a, b));
                }
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j)
            cout << dis[i][j] << ' ';
        cout << '\n';
    }

    return (0);
}

/*
4 4
1 1 1 1
9 8 7 1
1 1 1 1
1 2 4 9

0 1 2 3
9 9 9 4
8 7 6 5
9 9 10 14
*/