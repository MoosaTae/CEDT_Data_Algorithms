#include <iostream>
using namespace std;

int ans, upperlim, n;

void solve(int row, int ld, int rd) {
    if (row != upperlim) {
        int pos = upperlim & ~(row | ld | rd);
        while (pos) {
            int p = pos & -pos;
            pos -= p;
            solve(row | p, (ld | p) << 1, (rd | p) >> 1);
        }
    } else {
        ans++;
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    upperlim = (1 << n) - 1;
    solve(0, 0, 0);
    cout << ans << '\n';
    return 0;
}
