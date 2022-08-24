#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

ll n, mx;
ll arr[MXN];
 
void solve()
{
    bool eq = true;
    for(int i = 1; i < n; ++i) {
        if(arr[i] != arr[i - 1]) {
            eq = false;
        }
    }

    if(eq) {
        cout << 0 << '\n';
        return;
    }

    ll high = 0, low = 0;
    for(int i = 0; i < n; ++i) {
        high += mx + 1 - arr[i];
    }
    high *= 2;
    high += 10;

    while(high - low > 1) {
        ll mid = low + (high - low) / 2;
        
        ll odd = mid / 2 + (mid % 2), ev = mid / 2;
        bool check = false;

        int need_ev = 0, need_odd = 0;
        for(int i = 0; i < n; ++i){
            int need = mx - arr[i];
            need_ev += need - (need % 2);
            need_odd += need % 2;
        }

        need_ev = max(need_ev - 2 * ev, 0LL);
        if(need_ev + need_odd <= odd) {
            check = true;
        }

        need_ev = 0, need_odd = 0;
        for(int i = 0; i < n; ++i){
            int need = mx + 1 - arr[i];
            need_ev += need - (need % 2);
            need_odd += need % 2;
        }

        need_ev = max(need_ev - 2 * ev, 0LL);
        if(need_ev + need_odd <= odd) {
            check = true;
        }

        if(!check) {
            low = mid;
        } else {
            high = mid;
        }
    }
    
    cout << high << '\n';
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
        mx = 0;
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
            mx = max(mx, arr[i]);
        }
        solve();
    }
}
