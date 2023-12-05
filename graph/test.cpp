#include<bits/stdc++.h>
using namespace std;

bool found = false;
int ans = 0;
void dfs(vector<vector<int>> &adj , vector<int> &color , vector<int> &d , int v , int depth , int p){
    color[v] = 1;
    d[v] = depth;
    for(int i =0 ; i<adj[v].size() ;i++){
        if(color[adj[v][i]] == 0){
            dfs(adj , color ,d ,adj[v][i] , depth+1 , v);
        }
        else if(color[adj[v][i]]  == 1 && adj[v][i] != p){
            if(!found){
                ans = (depth+1) - (d[adj[v][i]]);
                found = true;
            }
            return ; 
        }
    }
    color[v] = 2;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for(int i = 0 ; i < n ; i++){
        int a , b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> d(n);
    vector<int> color(n);
    dfs(adj , color ,d ,0 , 0 ,-1);
    cout << ans;

}

