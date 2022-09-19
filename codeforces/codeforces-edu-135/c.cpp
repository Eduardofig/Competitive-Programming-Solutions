#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
int a[MXN];
int b[MXN];
//string s;

int n_digits(int num)
{
    int dig = 0;
    while(num > 0) {
        num /= 10;
        dig++;
    }

    return dig;
}
 
void solve()
{
    map<int, int> ma, mb;
    int ans = 0;

    for(int i = 0; i < n; ++i) {
        ma[a[i]]++;
        mb[b[i]]++;
    }

    //a[i] == b[i]
    for(auto &[num, qt]: ma) {
        int mn = min(qt, mb[num]);
        mb[num] -= mn;
        qt -= mn;
    }

    // apply digital logarithim to each array
    int ca[10]{}, cb[10]{};

    for(auto &[num, qt]: ma) {
        if(num >= 10) {
            ca[n_digits(num)] += qt;
            ans += qt;
        } else {
            ca[num] += qt;
        }
    }

    for(auto &[num, qt]: mb) {
        if(num >= 10) {
            cb[n_digits(num)] += qt;
            ans += qt;
        } else {
            cb[num] += qt;
        }
    }

    for(int i = 0; i < 10; ++i) {
        int mn = min(ca[i], cb[i]);
        cb[i] -= mn;
        ca[i] -= mn;
    }

    ans += accumulate(ca + 2, ca + 10, 0);
    ans += accumulate(cb + 2, cb + 10, 0);

    cout << ans << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for(int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        solve();
    }
}
