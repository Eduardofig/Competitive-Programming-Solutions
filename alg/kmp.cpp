#include <bits/stdc++.h>

using namespace std;

string s, sub;

void solve()
{
    if(s.find(sub) != string::npos) cout << "y";
    else cout << "n";
    cout << endl;
}

int main()
{
    int t, n;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> s >> n;
        for(int j = 0; j < n; ++j) {
            cin >> sub;
            solve();
        }
    }
}
