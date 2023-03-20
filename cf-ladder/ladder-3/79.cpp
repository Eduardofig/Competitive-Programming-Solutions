#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n, m, k;
//int a[MXN];
int b[MXN];
int diff[MXN];
//string s;

void solve()
{
    for(int i = 1; i < n; i++) {
        diff[i - 1] = b[i] - b[i - 1] - 1;
    }

    sort(diff, diff + n - 1);
    reverse(diff, diff + n - 1);

    int cut = 0;

    for(int i = 0; i < min(n - 1, k - 1); i++) {
        cut += diff[i];
    }

    cout << m - cut - (m - b[n - 1] - 1) - b[0] << '\n';
}

void read()
{
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}
