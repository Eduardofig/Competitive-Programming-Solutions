#include <bits/stdc++.h>

using namespace std;

int main()
{
    ofstream file("rom.txt");

    file << "v2.0 raw" << endl;

    for(int i = 0; i < 0xffff; ++i) {
        file << hex << rand() % 0xff << endl;
    }
}
