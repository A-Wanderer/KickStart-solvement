#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int te;
    int cas = 1;
    cin >> te;
    while (te--) {
        long long  a, b, c;
        cin >> a >> b >> c;
        cout << "Case #" << cas++ << ": ";
        cout << min(b + a, (b - c) * 2 + a) << "\n";
    }
    return 0;
}