#include <bits/stdc++.h>


using namespace std;

using ll = long long;
using ull = unsigned long long;

const int MXN = 1e4 + 3;
ll hh_start, mm_start;
ll minutes;

void solve()
{
    ll hh = hh_start, mm = mm_start;
    int ans = 0;


    bool first = true;
    while(true) {
        if(hh == hh_start && mm == mm_start && !first) {
            cout << ans << '\n';
            return;
        }

        //cout << "hh = " << hh << " mm = " << mm << ' ';
        if(hh / 10 == mm % 10 && hh % 10 == mm / 10) {
            //cout << "YES" << '\n';
            ans++;
        }

        hh += minutes / 60;
        mm += minutes % 60;
        if(mm >= 60) {
            hh++;
        }
        hh %= 24;
        mm %= 60;

        first = false;
    }
}

int main()
{
    ll t, num;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        scanf("%lld:%lld %lld", &hh_start, &mm_start, &minutes);
        solve();
    }
}
