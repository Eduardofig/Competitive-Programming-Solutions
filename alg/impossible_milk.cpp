#include <bits/stdc++.h>

using namespace std;

const int MXN = 1e6;
int m, n, t, biggest_vessel, total_milk, vessels[MXN];

void solve()
{
    int st = biggest_vessel, e = total_milk, mid, ans = 0, total, count;

    while(st <= e) {
        mid = st + (e - st)/2;
        
        total = 0, count = 1;

        for(int i = 0; i < n; ++i) {
            total += vessels[i];
            if(total > mid) {
                count++;
                total = vessels[i];
            }
        }

        if(count <= m) {
            ans = mid;
            e = mid - 1;
        } else st = mid + 1;
    }

    cout << ans << endl;
}

int main()
{
    while(cin >> n) {
        biggest_vessel = total_milk = 0;
        cin >> m;
        for(int i = 0; i < n; ++i) {
            cin >> vessels[i];
            biggest_vessel = max(biggest_vessel, vessels[i]);
            total_milk += vessels[i];
        }

        solve();
    }
}
