#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
using ii = pair <int, int>;
using li = pair <long long, int>;
using edge = pair <li, ii>;
int parent[100001], dsu[100001];
int u[1000001], v[1000001];
long long w[1000001];
bool visited[100001];
bool use[1000001];
int deep[100001];
long long weight[100001];
vector <ii> G[100001];

int root(int u) {
    if(dsu[u] == u) {
        return u;
    }
    return dsu[u] = root(dsu[u]);
}

bool Merge(int u, int v) {
    u = root(u);
    v = root(v);
    if(u != v) {
        dsu[u] = v;
        return 1;
    }
    return 0;
}

int main() {
    vector <edge> E;
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %lld", &u[i], &v[i], &w[i]);
        E.emplace_back(ii(w[i], i), ii(u[i], v[i]));
        G[u[i]].emplace_back(i, v[i]);
        G[v[i]].emplace_back(i, u[i]);
    }
    for(int i = 1; i <= n; i++) {
        dsu[i] = i;
    }
    long long sum = 0;
    sort(E.begin(), E.end());
    for(auto e : E) {
        if(Merge(e.second.first, e.second.second)) {
            sum += e.first.first;
            use[e.first.second] = 1;
        }
    }
    queue <ii> Q;
    Q.emplace(1, 1);
    while(!Q.empty()) {
        int u = Q.front().first;
        int depth = Q.front().second;
        Q.pop();
        if(visited[u]) {
            continue;
        }
        visited[u] = 1;
        deep[u] = depth;
        for(auto v : G[u]) {
            if(!visited[v.second] && use[v.first]) {
                parent[v.second] = u;
                weight[v.second] = w[v.first];
                Q.emplace(v.second, depth+1);
            }
        }
    }
    int q;
    scanf("%d", &q);
    int p;
    long long ans, dif;
    while(q--) {
        ans = sum;
        scanf("%d", &p);
        if(use[p]) {
            printf("%lld\n", ans);
            continue;
        }
        ans += w[p];
        int x, y;
        if(deep[u[p]] > deep[v[p]]) {
            x = v[p];
            y = u[p];
        }
        else {
            x = u[p];
            y = v[p];
        }
        dif = -1e9;
        while(deep[x] < deep[y]) {
            dif = max(dif, weight[y]);
            y = parent[y];
        }
        while(x != y) {
            dif = max(dif, max(weight[x], weight[y]));
            x = parent[x];
            y = parent[y];
        }
        ans -= dif;
        printf("%lld\n", ans);
    }
    return 0;
}
