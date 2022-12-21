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

int k;
//int k;
int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    if(k == 0) {
        cout << "0\n";
        return;
    }

    sort(a, a + 12);
    reverse(a, a + 12);

    int pref = 0;
    
    for(int i = 0; i < 12; ++i) {
        pref += a[i];
        if(pref >= k) {
            cout << i + 1 << '\n';
            return;
        }
    }

    cout << "-1\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> k;
    for(int i = 0; i < 12; ++i) {
        cin >> a[i];
    }
    solve();
}
