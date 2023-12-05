#include <bits/stdc++.h>
using namespace std;
void recur(vector<vector<int> > &v, int a, int b, int top, int bottom, int left, int right){
    if(a == 0){
        v[top][left] = b; 
    }
    else{
        int s = 1 << (a - 1);
        recur(v, a - 1, b, top, top + s, left, left + s);
        recur(v, a - 1, b - 1, top, top + s, left + s, right);
        recur(v, a - 1, b + 1, top + s, bottom, left, left + s);
        recur(v, a - 1, b, top + s, bottom, left + s, right);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A, B, s;
    cin >> A >> B;
    vector<vector<int> > v(1 << A, vector <int> (1 << A, 0));
    recur(v, A, B, 0, 1 << A, 0, 1 << A);
    for(int i = 0; i < 1 << A; ++i){
        for(int j = 0; j < 1 << A; ++j){
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    return (0);
}