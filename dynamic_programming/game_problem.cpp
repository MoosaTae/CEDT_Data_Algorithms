#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(a) (a).begin(), (a).end()
#define sz(x) ((int)x.size())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 1e5 + 5;

int optimalStrategyOfGame(int* arr, int n) 
{ 
    int table[n][n];
    for(int gap = 0; gap < n; ++gap){
        for(int i = 0, j = gap; j < n; ++i, ++j){ 
            int x = (i + 2 >= j) ? 0 : table[i + 2][j];
            int y = (i + 2 >= j) ? 0 : table[i + 1][j - 1];
            int z = (i + 2 >= j) ? 0 : table[i][j - 2];
            table[i][j] = max(arr[i] + min(x, y)
                            , arr[j] + min(y, z));
        }
    }
    return table[0][n - 1];
}

int main(){   
    cin.tie(0)->sync_with_stdio(0);
    int a[] = { 20, 30, 2, 2, 2, 10 }; 
    cout << optimalStrategyOfGame(a, sizeof(a)/sizeof(a[0]));
    return (0);
}