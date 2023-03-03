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

vector<int> p;
 
int numdiv = 0;
int divisor;

bool is_prime(int x) {
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) {
            return false;
        }
    }

    return true;
}

void solve()
{
    for(int x = 2; x <= 50; ++x) {
        if(is_prime(x)) {
            p.push_back(x);
        }
    }

    string q;
    for(int x: p) {
        cout << x << endl;
        cin >> q;

        if(q == "yes") {
            numdiv++;
            divisor = x;
        }
    }

    if(numdiv < 2) {

        if(numdiv > 0 && divisor * divisor < 100) {
            cout << divisor * divisor << endl;
            cin >> q;

            if(q == "yes") {
                cout << "composite" << endl;
                return;
            }
        } 

        cout << "prime" << endl;
        return;
    } 

    cout << "composite" << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
}
