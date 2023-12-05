#include <bits/stdc++.h>
using namespace std;

int n, k, a, b, c, d;
vector<int> v(4);
vector<int> matrix_multiply(const vector<int> &M,const vector<int> &N){
    vector <int> result(2 * 2, 0);
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            for(int x = 0; x < 2; ++x){
                result[i * 2 + j] += (M[i * 2 + x] * N[j + 2 * x]) % k;
                result[i * 2 + j] %= k;
            }
        }
    }
    return result;
}
vector<int> solve(int exp){
    if(exp == 1) return v;
    vector <int> tmp;
    tmp = solve(exp / 2);
    tmp = matrix_multiply(tmp, tmp);
    if(exp % 2){
        return matrix_multiply(tmp, v);
    }
    return tmp;
}

int main(){
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> k;
    for(int i = 0; i < 4; ++i) cin >> v[i];
    v = solve(n);
    for(int i = 0; i < 4; ++i)cout << v[i] << ' ';
}