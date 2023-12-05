#include <bits/stdc++.h>
using namespace std;
int n, a, tmp, mn = 2e9;
long long c, l, h, mid, cnt;
vector <int> t;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> a;
    for(int i = 0; i < n; ++i){
        cin >> tmp;
        t.emplace_back(tmp);
        if(t[i] < mn) mn = t[i];
    }
    for(int i = 0; i < a; ++i){
        cin >> c;
        l = 0;
        h = mn * c;
        while(l < h){
            mid = (l + h) >> 1;
            cnt = n;
            for(int i = 0; i < n; ++i)
                cnt += mid / t[i];
            if(cnt >= c) h = mid;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
    return (0);
}