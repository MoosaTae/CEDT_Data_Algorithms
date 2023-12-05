#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int f,w,n;
    cin >> f >> w >> n;
    w *= 2;
    vector<int>a(f);
    for(int i = 0; i < f; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    int idx = 0, cnt = 1, left = a[0];
    while(idx < f){
        if(a[idx] - left > w){
            left = a[idx];
            cnt++;
        }
        idx++;
    }
    cout << cnt << '\n';
    return 0;
}