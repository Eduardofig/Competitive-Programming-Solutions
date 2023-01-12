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
const int MXA = 2e4;

int n;
//int k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int cnt[MXA]{};

    for(int i = 0; i < 4 * n; ++i) {
        cnt[a[i]]++;
    }

    vector<int> v;
    for(int i = 0; i < MXA; ++i) {
        if(cnt[i] % 2 == 1) {
            cout << "NO\n";
            return;
        }
        for(int j = 0; j < cnt[i] / 2; ++j) {
            v.push_back(i);
        }
    }

    int A = v.back() * v.front();

    for(int i = 0; i < v.size() / 2; ++i) {
        if(v[i] * v[v.size() - 1 - i] != A) {
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
        cin >> n;
        for(int i = 0; i < 4 * n; ++i) {
            cin >> a[i];
        }
        solve();
    }
}
