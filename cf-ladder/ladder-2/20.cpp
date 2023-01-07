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
int h[MXN];
int k;
//int a[MXN];
//int b[MXN];
//string s;
 
void solve()
{
    int curr = 0;

    for(int i = 0; i < k; ++i) {
        curr += h[i];
    }
    int mn = curr;
    int curri = 0;

    for(int i = 1; i + k - 1 < n; ++i) {
        curr += h[i + k - 1] - h[i - 1];
        if(curr < mn) {
            mn = curr;
            curri = i;
        }
    }

    cout << curri + 1 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    solve();
}
