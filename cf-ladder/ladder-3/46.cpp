#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 5e5 + 3;
const int INF = 0x3f3f3f3f;
const int MOD = 1e7 + 9;

int n;
//int k;
int a[MXN];
//int b[MXN];
//string s;

map<int, int> mp = {
    {4, 0},
    {8, 1},
    {15, 2},
    {16, 3},
    {23, 4},
    {42, 5}
};
 
void solve()
{
    int cnt[6]{};


    for(int i = 0; i < n; ++i) {
        if(a[i] == 0) {
            cnt[0]++;
        } else {
            if(cnt[a[i] - 1] > 0) {
                cnt[a[i] - 1]--;
                cnt[a[i]]++;
            }
        }
    }

    cout << n - cnt[5] * 6 << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        a[i] = mp[x];
    }
    solve();
}
