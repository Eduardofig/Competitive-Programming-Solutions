#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;

    if(s[0] == 'B' || s.back() == 'A' || s.size() < 2) {
        cout << "NO\n";
        return;
    }

    int a{}, b{};
    for(char c: s) {
        if(c == 'A') {
            a++;
        } else {
            b++;
        }

        if(b > a) {
            cout << "NO\n";
            return;
        }

    }

    cout << "YES\n";
}

int main()
{

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}
