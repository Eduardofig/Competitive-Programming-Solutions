#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using l = long;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

int n;
ull w[MXN];
 
void solve()
{
    //for(int i = 0; i < n; ++i) {
        //cout << w[i] << ' ';
    //}
    //cout << endl;
    sort(w, w + n);
    reverse(w, w + n);
    ull tot = accumulate(w, w + n, 0LL);
    priority_queue<ull, vector<ull>, less<ull>> pq;

    pq.push(tot);
    for(int i = 0; i < n; ++i) {
        while(true) {
            //cout << pq.top() << '\n';
            if(pq.empty()) {
                cout << "NO\n";
                return;
            }
            if(w[i] == pq.top()) {
                pq.pop();
                break;
            } else {
                if(pq.top() == 1) {
                    cout << "NO\n";
                    return;
                } else {
                    ull a = (pq.top() / 2ULL), b = (pq.top() / 2ULL) + (pq.top() % 2ULL);
                    pq.pop();
                    if(a != 0) {
                        pq.push(a);
                    }
                    pq.push(b);
                }
            }
        }
    }
    cout << "YES\n";
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
            cin >> w[i];
        }
        solve();
    }
}
