#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

ull n;
//ull a[MXN];
//ull b[MXN];
//string s;

set<ull> divisors(ull x)
{
    set<ull> divs = {1, x};

    for(ull d = 2; d * d <= x; d++) {
        if(x % d == 0) {
            divs.insert(d);
            divs.insert(x / d);
        }
    }

    return divs;
}

void solve()
{
    set<ull> fnums{{1, ((1 + n) * n) / 2}};
    for(ull k: divisors(n)) {
        ull num = n / k;

        ull last_num = k * (num - 1) + 1;

        ull ans = ((1 + last_num) * num) / 2;

        fnums.insert(ans);
    }

    for(ull x: fnums) {
        cout << x << '\n';
    }
}

void read()
{
    cin >> n;
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
