
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll dp[20][2];
int dit[20];
ll n, m;
int next_state(int state, int pos, int i, bool lead) {
    if (state == 0) {
        return 0;
    }
    if (lead == 1 && i == 0) {
        return 1;
    }
    return (pos % 2) == (i % 2);
}
 
ll dfs(int pos, int ps, int state, bool lead, bool limit) {
    if (pos == -1) {
        return state != 0;
    }
    if (!limit && !lead && dp[pos][state] != -1) {
        return dp[pos][state];
    }
    int up = limit ? dit[pos] : 9;
    ll ans = 0;
    for (int i = 0; i <= up; ++i) {
        if (lead) {
            if (i == 0) {
                ans += dfs(pos - 1, ps - 1, 1, 1, limit && (i == up));
            }
            else {
                ans += dfs(pos - 1, ps, next_state(state, ps - pos, i, 0), 0, limit && (i == up));
            }
        }
        else {
            ans += dfs(pos - 1, ps, next_state(state, ps - pos, i, 0), 0, limit && (i == up));
        }
    }
    if (!limit && !lead) {
        dp[pos][state] = ans;
    }
    return ans;
}
 
ll solve(ll k) {
    int pos = 0;
    while (k) {
        dit[pos++] = (int)(k % 10);
        k /= 10;
    }
    return dfs(pos - 1, pos, 1, 1, 1);
}
 
int main() {
    int te; cin >> te; int cas = 1;
    memset(dp, -1, sizeof(dp));
    while (te--) {
        cin >> n >> m;
        cout << "Case #" << cas++ << ": ";
        cout << solve(m) - solve(n - 1) << '\n';
    }
    return 0;
}