#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fname "baitap"
using namespace std;

int main() {
    fastio
    freopen(fname".inp", "r", stdin);
    freopen(fname".out", "w", stdout);
    clog <<"LOVE M.NG SO MUCHHHHHHHHHHHHHHHHHHHH" << endl;  
    
    int n, m; cin >>  n >> m;
    int a[n + 1][m + 1];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++) cin >> a[i][j];
    
    int pr[n + 1][m + 1];
    for(int i = 0; i <= n; i++) pr[i][0] = 0;
    for(int i = 0; i <= m; i++) pr[0][i] = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            pr[i][j] = pr[i - 1][j] + pr[i][j - 1] - pr[i - 1][j - 1] + a[i][j];
    }

    int ans = INT_MIN, h1, h2, c1, c2;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            for(int x = 1; x <= m; x++)
                for(int y = x; y <= m; y++) {
                    int t = pr[j][y] - pr[i - 1][y] - pr[j][x - 1] + pr[i - 1][x - 1];
                        if(t > ans) {
                            ans = t;
                            h1 = i;
                            h2 = j;
                            c1 = x;
                            c2 = y;
                        }
                }
    cout << ans << "\n";
    cout << h1 << " " << h2 << " " << c1 << " " << c2; 
    return 0;
}
