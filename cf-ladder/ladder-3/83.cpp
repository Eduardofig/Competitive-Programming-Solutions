#include <bits/stdc++.h>
 
using namespace std;
 
using ui = unsigned int;
using ul = unsigned long;
using ll = long long;
using ull = unsigned long long;
 
const int MXN = 2e5 + 3;
const int INF = 0x3f3f3f3f;

const bool MULTIPLE_TESTCASES = 0;

int n;
int a[MXN];
//int b[MXN];
//string s;

void solve()
{
    vector<int> part;

    int i = 0;
    while(i < n) {
        part.push_back(i);
        set<int> left;
        set<int> office;
        while(i < n) {

            if(office.size() == 0 && left.size() > 0) {
                break;
            }

            if(a[i] > 0) {
                if(left.find(a[i]) != left.end() || office.find(a[i]) != office.end()) {
                    break;
                }
                office.insert(a[i]);
            } else {
                auto it = office.find(abs(a[i]));

                if(it == office.end()) {
                    cout << "-1\n";
                    return;
                }

                left.insert(abs(a[i]));
                office.erase(it);
            }
            i++;
        }
        if(office.size() > 0) {
            cout << "-1\n";
            return;
        }
    }

    cout << part.size() << '\n';
    for(int i = 1; i < part.size(); i++) {
        cout << part[i] - part[i - 1] << ' ';
    }
    if(part.back() < n) {
        cout << n - part.back() << '\n';
    }

}

void read()
{
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    if(MULTIPLE_TESTCASES) {
        int t;
        cin >> t;
        while(t--) {
            read();
            solve();
        }
    } else {
        read();
        solve();
    }
}
