#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define LL long long
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
const int inf = 1e9 + 7;
int mp[30][30];
void floyd(int n) {
    for (int k = 0; k <= n; k++)
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++) {
                if (mp[i][k] + mp[k][j] < mp[i][j]) {
                    mp[i][j] = mp[i][k] + mp[k][j];
                }
            }
}
string G[100010];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int te;
    int cas = 1;
    cin >> te;
    while (te--) {
        cout << "Case #" << cas++ << ": ";
        int n, m;
        cin >> n >> m;
        memset(mp, 0x3f3f3f3f, sizeof mp);
        for (int t = 1; t <= n; t++) {
            string tmp; cin >> tmp;
            G[t] = tmp;
            int len = tmp.length();
            for (int i = 0; i < len; i++) {
                for (int j = i + 1; j < len; j++) {
                    mp[tmp[i] - 'A'][tmp[j] - 'A'] = 1;
                    mp[tmp[j] - 'A'][tmp[i] - 'A'] = 1;
                }
            }
        }
        for (int i = 0; i <= 28; i++)
            mp[i][i] = 0;
        floyd(28);
        while (m--) {
            int c, d; cin >> c >> d;
            string a = G[c], b = G[d];
            int spot = 1, ans = 0x3f3f3f3f;
            for (auto u : a) {
                for (auto v : b) {
                    ans = min(ans, mp[u - 'A'][v - 'A']);
                    ans = min(ans, mp[v - 'A'][u - 'A']);
                }
            }
            if (ans != 0x3f3f3f3f)cout << ans + 2 << " ";
            else cout << "-1 ";
        }
        cout << "\n";
    }
    return 0;
}
/*
3 5
0 1 0
1 0 1
0 1 0
*/