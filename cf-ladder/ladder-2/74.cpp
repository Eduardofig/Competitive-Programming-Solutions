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
vector<int> g[MXN];
 
void solve()
{
    set<int> pr;
    set<int> single;

    for(int i = 0; i < n; ++i) {
        pr.insert(i);
    }

    for(int i = 0; i < n; ++i) {
        
        bool found = false;
        for(int next: g[i]) {
            if(pr.find(next) != pr.end()) {
                pr.erase(next);
                found = true;
                break;
            }
        }

        if(!found) {
            single.insert(i);
        }
    }

    if(pr.empty() || single.empty()) {
        cout << "OPTIMAL\n";
        return;
    }
    cout << "IMPROVE\n" << *single.begin() + 1 << ' ' << *pr.begin() + 1 << '\n';

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
            int k;
            cin >> k;
            g[i].resize(k);
            for(int &it: g[i]) {
                cin >> it;
                it--;
            }
        }
        solve();
    }
}
