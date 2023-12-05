#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    pair<int, int> cl[n];
    for(int i = 0; i < n; ++i)cin >> cl[i].s;
    for(int i = 0; i < n; ++i)cin >> cl[i].f;
    sort(cl, cl + n);
    int end = 0, ans = 0;
    for(pair<int, int> pi : cl){
        if(pi.s >= end){
            end = pi.f;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}