#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MXN = 2e5 + 3;

ll arr[MXN];
ll n, biggest;

void solve()
{
    map<int, pair<int, int>> m;

    for(int i = 0; i < n; ++i) {
        for(int j = i; j < n; ++j) {
            if(j != i) {
                m[(arr[i] + arr[j]) % 10] = {i, j};
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        if(m.find(13 - (arr[i] % 10)) != m.end()) {
            auto p = m[13 - (arr[i] % 10)];
            if(p.first != i && p.second != i) {
                cout << "YES\n";
                return;
            }
        }
        if(m.find(3 - (arr[i] % 10)) != m.end()) {
            auto p = m[3 - (arr[i] % 10)];
            if(p.first != i && p.second != i) {
                cout << "YES\n";
                return;
            }
        }
}

cout << "NO\n";
}

int main()
{
    ll t, num;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        cin >> n;
        for(int j = 0; j < n; ++j) {
            cin >> arr[j];
        }
        solve();
    }
}
