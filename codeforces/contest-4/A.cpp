#include <bits/stdc++.h>

using namespace std;

int x;

void solve()
{
    int ans{};

    for(int i = 0; true; i++) {
        if(((1 << i) & x) != 0) {
            ans |= 1 << i;
            break;
        } 
    }

    if(__builtin_popcount(x) == 1) {
        for(int i = 0; true; i++) {
            if(((1 << i) & x) == 0) {
                ans |= 1 << i;
                break;
            } 
        }
    }

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> x;
        solve();
    }
}
