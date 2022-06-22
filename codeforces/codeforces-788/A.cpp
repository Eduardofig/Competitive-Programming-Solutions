#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 1e5 + 3;
const int INF = 0x3f3f3f3f;

ll n;
ll arr[MXN];
 
void solve()
{
    int i = 0; int j = n - 1;
    while(i < j) {
        while(arr[j] > 0) {
            j--;
        }
        while(arr[i] < 0) {
            i++;
        }
        
        if(i >= j) {
            break;
        }

        arr[i] *= -1;
        arr[j] *= -1;
    }

    vector<pair<ll, ll>> p;
    for(int i = 0; i < n; ++i) {
        p.emplace_back(arr[i], i);
    }
    sort(p.begin(), p.end());

    for(int i = 0; i < n; ++i) {
        if(p[i].second != i) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
}
 
int main()
{
    ll t;
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        solve();
    }
}
