#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;

ll n;
ll c, n_diff;

void query1(ll i)
{
    fflush(stdout);
    cout << "? 1 " << i << '\n';
    fflush(stdout);
    cin >> c;
    fflush(stdout);
}

void query2(ll l, ll r)
{
    fflush(stdout);
    cout << "? 2 " << l << " " << r << '\n';
    fflush(stdout);
    cin >> n_diff;
    fflush(stdout);
}

void solve()
{
    string ans = "";
    query1(0);
    ans.push_back(c);
    ll prev_diff = 0;
    for(int i = 1; i < n; ++i) {
        query2(0, i);

        //ja tem o caracter antes
        if(prev_diff == n_diff) {
            ll low = 0, high = i;
            //achar primeira ocorrencia do caracter
            while(true) {
                if(high == low) {
                    ans.push_back(ans[low]);
                    break;
                }

                ll mid = low + (high - low) / 2;

                query2(mid, high);

                if(prev_diff - n_diff < mid - low) {
                    high = mid;
                } else {
                    low = mid;
                }
            }
        } else {
            query1(i);
            ans.push_back(c);
            prev_diff = n_diff;
        }
    }

    cout << "! " << ans << '\n';
    fflush(stdout);
}

int main()
{
    cin >> n;
    solve();
}
