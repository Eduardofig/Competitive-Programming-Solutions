#include <bits/stdc++.h>

using namespace std;
const int MXN = 1e5;
int n, i = 0, moves[MXN], jumps[MXN];

void solve()
{
    int k = 0;
    jumps[0] = moves[0];

    for(int i = 1; i <= n; ++i)
        jumps[i] = moves[i] - moves[i - 1];

    for(int i = n - 1; i >= 0; i--) {
        if(jumps[i] == k) k++;
        k = max(k, jumps[i]);
    }

    cout << "Case " << i + 1 << ": " << k << endl;
}

int main()
{
    int t;
    cin >> t;
    for( i = 0; i < t; ++i) {
        cin >> n;
        for(int j = 0; j < n; ++j) cin >> moves[j];

        solve();
    }
}
