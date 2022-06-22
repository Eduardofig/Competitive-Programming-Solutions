#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int MXN = 2e5 + 3;
ll int_log[MXN];
ll n;
ll arr[MXN];
ll m[MXN][100];

void make_table()
{
    int_log[1] = int_log[0] = 0;
    for(ll i = 2; i < MXN; ++i) {
        int_log[i] = int_log[i / 2] + 1;
    }

    for(ll i = 1; i < n; ++i) {
        m[i][0] = arr[i];
    }

    for(ll i = 1; (1 << i) <= n; ++i) {
        for(ll j = 0; j + (1 << i) - 1 < n; ++j) {
            m[j][i] = max(m[j][i - 1], m[j + (1 << (i - 1))][i - 1]);
        }
    }
}

ll query(int l, int r)
{
    ll len = r - l + 1;
    ll p = int_log[len];

    return max(m[l][p], m[r - (1 << p) + 1][p]);
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    make_table();

    int l, r;
    cin >> l >> r;

    cout << query(l, r);
}
