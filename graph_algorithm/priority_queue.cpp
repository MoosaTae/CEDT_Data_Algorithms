    #include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int n, a, cnt, ans;
const int N = 1005;
vector <pair <int, int> > adj[N];
vector <int> parent(N);
vector <bool> used(N, 0);
priority_queue <pair <int, int>, vector<pair <int, int> >, greater<pair<int, int> > > pq;

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; ++i){
        parent[i] = i;
        for(int j = i + 1; j < n; ++j){
            cin >> a;
            adj[i].emplace_back(a, j);
        }
    }
    pq.emplace(0, 0);
    while(!pq.empty() && cnt < n){
        if(!used[pq.top().s]){
            cnt++;
            ans += pq.top().f;
            used[pq.top().s] = 1;
            for(auto &it : adj[pq.top().s]){
                if(!used[it.s])pq.emplace(it.f, it.s);
            }
            cout << pq.top().s << ' ' << pq.top().f << '\n';
        }
        pq.pop();
    }
    cout << ans << '\n';


    return 0;
}