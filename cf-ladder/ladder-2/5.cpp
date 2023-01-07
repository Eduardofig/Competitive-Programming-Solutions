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
int cnt[10]{};
 
void solve()
{
    bool found = false;
    for(int i = 1; i <= 9; ++i) {
        if(cnt[i] >= 4) {
            cnt[i] -= 4;
            found = true;
        }
    }

    if(!found) {
        cout << "Alien\n";
        return;
    }

    vector<int> v;
    for(int i = 1; i <= 9; ++i) {
        for(int j = 0; j < cnt[i]; ++j) {
            v.push_back(i);
        }
    }

    if(v[0] == v[1]) {
        cout << "Elephant\n";
    } else {
        cout << "Bear\n";
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    for(int i = 0; i < 6; ++i) {
        int num;
        cin >> num;

        cnt[num]++;
    }
    solve();
}
