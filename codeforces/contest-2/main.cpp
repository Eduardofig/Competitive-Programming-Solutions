#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ll a, b, c, d;
string s;

void solve()
{
    ll na{}, nb{};
    for(char c: s) {
        if(c == 'A') {
            na++;
        } else {
            nb++;
        }
    }

    if(na != a + c + d) {
        cout << "NO\n";
        return;
    } 

    if(nb != b + c + d) {
        cout << "NO\n";
        return;
    }

    vector<pair<char, int>> v;

    v.push_back({s[0], 0});
    for(int i = 1; i < s.size(); ++i) {
        if(s[i] == s[i - 1]) {
            v.push_back({s[i], i});
        }
    }
    v.emplace_back(s.back(), s.size());

    ll max_abs, max_bas, n = v.size() - 1;
    vector<vector<pair<ll, ll>>> abs(n);

    for(int i = 1; i < v.size(); ++i) {
        if(v[i].first == v[i - 1].first) {
          max_abs = (v[i].second - v[i - 1].second) / 2;
          max_bas = max_abs;
        } else {
            if(v[i - 1].first == 'A') {
              max_abs = (v[i].second - v[i - 1].second) / 2;
              max_bas = ((v[i].second - v[i - 1].second) / 2) - 1;

            } else {
              max_abs = ((v[i].second - v[i - 1].second) / 2) - 1;
              max_bas = (v[i].second - v[i - 1].second) / 2;
            }
        }

        for(int conj = 0; max_abs - 2 * conj > 0; ++conj) {
            abs[i - 1].push_back({max_abs - 2 * conj, conj});
        }

        for(int conj = 0; max_bas - 2 * conj > 0; ++conj) {
            abs[i - 1].push_back({conj, max_bas - 2 * conj});
        }

    }

    bool dp[n + 1][c + 1][d + 1];
    memset(dp, false, sizeof dp);
    dp[0][0][0] = true;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j <= c; ++j) {
            for(int k = 0; k <= d; ++k) {
                if(dp[i][j][k]) {
                    for(auto &[ab_add, ba_add]: abs[i]) {
                        for(int increment = 0; increment <= ab_add; ++increment) {
                            if(j + increment <= c) {
                                dp[i + 1][j + increment][k] = true;
                            }
                        }
                        for(int increment = 0; increment <= ba_add; ++increment) {
                            if(k + increment <= d) {
                                dp[i + 1][j][k + increment] = true;
                            }
                        } 
                    }
                }
            }
        }
    }

    for(int i = 0; i <= n; ++i) {
        if(dp[i][c][d]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> a >> b >> c >> d;
        cin >> s;
        solve();
    }
}
