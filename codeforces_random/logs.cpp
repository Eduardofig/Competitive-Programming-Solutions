#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    int log, turns = 0;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        cin >> log;
        turns += log - 1;
    }

    if(turns % 2) {
        cout << "errorgorn" << endl;
    } else {
        cout << "maomao90" << endl;
    }

}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}
