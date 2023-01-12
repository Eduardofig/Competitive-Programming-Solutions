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
//int a[MXN];
//int b[MXN];
string a, b;
 
void solve()
{
    vector<pair<char, int>> va, vb;

    char curr = a.front();
    int cnt = 0;
    for(char c: a) {
        if(c == curr) {
            cnt++;
        } else {
            va.emplace_back(curr, cnt);
            cnt = 1;
            curr = c;
        }
    }
    va.emplace_back(a.back(), cnt);

    curr = b.front();
    cnt = 0;
    for(char c: b) {
        if(c == curr) {
            cnt++;
        } else {
            vb.emplace_back(curr, cnt);
            cnt = 1;
            curr = c;
        }
    }
    vb.emplace_back(b.back(), cnt);

    if(va.size() != vb.size()) {
        cout << "NO\n";
        return;
    }

    n = va.size();

    for(int i = 0; i < n; ++i) {
        auto &[ca, cnta] = va[i];
        auto &[cb, cntb] = vb[i];

        if(cb != ca || cntb < cnta) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        solve();
    }
}
