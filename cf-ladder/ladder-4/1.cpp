#include <bits/stdc++.h>

#define For(i, n) for(int (i) = 0; (i) < (int)(n); ++(i))
#define Foro(i, n) for(int (i) = 1; (i) < (int)(n); ++(i))
#define Forr(i, n) for(int (i) = (int)(n) - 1; (i) >= 0; --(i))
#define Forl(i, n) for(ll (i) = 0; (i) < (ll)(n); ++(i))
#define Fore(v, ...) for(auto &[__VA_ARGS__]: (v))
#define All(x) (x).begin(), (x).end()
#define Mini(x, y) (x) = min((x), (y))
#define Maxi(x, y) (x) = max((x), (y))
#define Pb push_back
#define Eb emplace_back
#define Lb(x, y) lower_bound(x, (y))
#define Ub(x, y) upper_bound(x, (y))
#define Rz(x) resize((x))
#define Rzz(x, y) resize((x), (y))
#define Read(x) generate(All((x)), nxt)
#define Pr(x) cout << (x) << ' '
#define Prn(x) cout << (x) << '\n'

// #define int ll

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ii = pair<int, int>;
using pll = pair<ll, ll>;
using tll = tuple<ll, ll, ll>;
using iii = tuple<int, int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpll = vector<pll>;
using vvpll = vector<vpll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vvvi = vector<vvi>;
using vvvii = vector<vvii>;

const int MXN = 5e5 + 100;
const int INF = INT_MAX;

const bool MULTIPLE_TESTCASES = 0;

int n, m;
// vi a(MXN);
// vi b(MXN);
// vi v(MXN);
// vvi g(MXN, vi());
// string s;

map<string, int> mp1, mp2;
vector<pair<string, int>> events;

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

void solve()
{
    Fore(events, name, p) {
        mp1[name] += p;
    }

    int mx = -INF;
    int cnt = 0;
    string winner;

    Fore(mp1, name, p) {
        Maxi(mx, p);
    }

    set<string> winners;
    Fore(mp1, name, p) {
        if(p == mx) {
            winners.insert(name);
        }
    }

    if(winners.size() == 1) {
        Prn(*winners.begin());
        return;
    }

    Fore(events, name, p) {
        mp2[name] += p;
        if(mp2[name] >= mx and winners.find(name) != winners.end()) {
            Prn(name);
            return;
        }
    }

}

void read()
{
    cin >> n;
    events.Rz(n);
    Fore(events, name, p) {
        cin >> name >> p;
    }
}

int32_t main()
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
