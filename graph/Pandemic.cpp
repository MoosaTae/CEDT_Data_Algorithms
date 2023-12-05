#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
    cin.tie(0)->sync_with_stdio(false);
    int r, c, T, cnt = 0, a, b;
    cin >> r >> c >> T;
    int t[r][c];
    queue<pair<int, pair<int, int> > > q;
    bool visited[r][c];
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < r; ++i){
        for(int j = 0; j < c; ++j) {
            cin >> t[i][j];
            if(t[i][j] == 1){
                q.emplace(0, make_pair(i, j));
            }
            else if(t[i][j] == 2)visited[i][j] = 1;
        }
    }
    int move[5] = {0, 1, 0, -1, 0};
    while(!q.empty()){
        if(!visited[q.front().s.f][q.front().s.s] && q.front().f <= T){
            visited[q.front().s.f][q.front().s.s] = true;
            cnt++;
            for(int i = 0; i < 4; ++i){
                a = q.front().s.f + move[i];
                b = q.front().s.s + move[i + 1];
                if(a < 0 || b < 0 || a >= r || b >= c)continue;
                if(!visited[a][b])
                    q.emplace(q.front().f + 1, make_pair(a, b));
            }
        }
        q.pop();
    }
    cout << cnt << '\n';
    

    return (0);
}