#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int sz = 'k' - 'a' + 3 ;
    bool v[2]['k' - 'a' + 3]{};
    unordered_map<string, int> m;
    string s;

    int ans = 0;

    for(int i = 0; i < n; ++i) {
        cin >> s;
        if(m.find(s) != m.end()) {
            m[s] += s[0] != s[1]? 1 : 2;
        } else {
            m[s] = 0;
        }

        for(int j = 0; j < 2; ++j) {
            if(v[j ^ 1][s[j] - 'a']) {
                ans++;
            } else {
                v[j ^ 1][s[j] - 'a'] = true;
            }
        }
    }

    ans -= accumulate(m.begin(), m.end(), 0, 
        [](int acc, auto p) {
            return acc + p.second;
        });

    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        solve();
    }
}
