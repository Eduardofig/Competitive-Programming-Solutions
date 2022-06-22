#include <bits/stdc++.h>

using namespace std;

int t, n;

void solve()
{
    // optimize with pA
    int acc = 0;
    for(int i = n + 1; true; ++i) {
        acc += i;
        int acc2 = 0;
        for(int j = i + 1; j < acc - i - 1; ++j) {
            acc2 += j;

            if(acc2 == acc) {
                // print answer
            }
        }
    }
}

int main()
{
    cin >> t >> n;

    for(int i = 0; i < n; ++i) {
        cin >> n;
        solve();
    }
}
