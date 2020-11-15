#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 100000 + 1;
LL X[maxn], Y[maxn];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for(int tt = 1; tt <= T; tt += 1){
        cout << "Case #" << tt << ": ";
        int n;
        cin >> n;
        for(int i = 0; i < n; i += 1) cin >> X[i] >> Y[i];
        sort(X, X + n);
        sort(Y, Y + n);
        for(int i = 0; i < n; i += 1) X[i] -= i;
        sort(X, X + n);
        LL ans = 0;
        for(int i = 0; i < n; i += 1)
            ans += abs(X[i] - X[n / 2]) + abs(Y[i] - Y[n / 2]);
        cout << ans << "\n";
    }
    return 0;
}