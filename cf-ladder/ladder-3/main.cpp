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

#define int ll
 
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
vi a(MXN);
// vi b(MXN);
// vi v(MXN);
// vvi g(MXN, vi());
// string s;

ll nxt()
{
    ll x;
    cin >> x;
    return x;
}

bool cmp(int a, int b)
{
    int cnt3a = 0;
    int cnt3b = 0;
    int cnt2a = 0;
    int cnt2b = 0;

    while(a % 3 == 0) {
        a /= 3;
        cnt3a++;
    }

    while(b % 3 == 0) {
        b /= 3;
        cnt3b++;
    }

    while(a % 2 == 0) {
        a /= 2;
        cnt2a++;
    }

    while(b % 2 == 0) {
        b /= 2;
        cnt2b++;
    }

    if(cnt3a == cnt3b) {
        return cnt2a < cnt2b;
    }

    return cnt3a > cnt3b;
}

void solve()
{
    sort(All(a), cmp);

    for(int i: a) {
        Pr(i);
    }
    Prn("");
}

void read()
{
    cin >> n;
    a.Rz(n);
    Read(a);
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
