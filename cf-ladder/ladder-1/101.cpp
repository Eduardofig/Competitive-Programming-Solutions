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
    int cnt = 0;
    vector<int> vans;
    for(int i = 0; i < n; ++i) {
        if(a[i] < 0) {
            if(cnt == 2) {
                cnt = 1;
                vans.push_back(i);
            } else {
                cnt++;
            }
        }
    }
    vans.push_back(n);

    cout << vans.size() << '\n';
    int prev = 0;
    for(int i: vans) {
        cout << i - prev << ' ';
        prev = i;
    }
    cout << '\n';
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
