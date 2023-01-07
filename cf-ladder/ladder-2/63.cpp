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
//int b[MXN];
//string s;
 
void solve()
{
    set<int> se;

    for(int i = 0; i < n; ++i) {
        se.insert(a[i]);
    }

    if(se.size() == 1) {
        cout << "0\n";
        return;
    } else if(se.size() == 2) {
        int diff = *(++se.begin()) - *(se.begin());
        if(diff % 2 == 0) {
            cout << diff / 2;
        } else {
            cout << diff;
        }
        cout << '\n';
        return;
    } else if(se.size() == 3) {
        int high = *(--se.end());
        int low = *(se.begin());
        int mid = *(++se.begin());

        if(high - mid == mid - low) {
            cout << high - mid << '\n';
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

    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    solve();
}
