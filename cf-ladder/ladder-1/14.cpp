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
//string s;
vector<pair<int, int>> v;
 
void solve()
{
    sort(v.begin(), v.end());


    cout << v.back().second + 1 << ' ';

    if(v.size() > 1) {
        v.pop_back();
    }

    cout << v.back().first << '\n';
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        pair<int, int> p;
        cin >> p.first;
        p.second = i;

        v.push_back(p);
    }
    solve();
}
