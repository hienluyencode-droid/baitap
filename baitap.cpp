#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define fname "baitap"
using namespace std;
void print(int a[][101], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << a[i][j] << " ";            
        cout << "\n";
    }
}
void A(int n) {
    if(n < 2) {
        cout << n << "\n";
        return;
    }
    int ans = 1, a[n + 1][101];
        for(int i = 0; i < n; i++) {
            if(i & 1) {
                for(int j = n - 1; j >= 0; j--) {
                    a[i][j] = ans;
                    ans++;
                }
            }
            else {
                for(int j = 0; j < n; j++) {
                    a[i][j] = ans;
                    ans++;
                }
            }
        }
    print(a, n);
}
void B(int n) {
    if(n < 2) {
        cout << n << "\n";
        return;
    }
    int ans = n * n, a[n + 1][101];
    for(int j = 0; j < n; j++) {
        if(j & 1) {
            for(int i = n - 1; i >= 0; i--) {
                a[i][j] = ans;
                ans--;
            }
        }
        else {
            for(int i = 0; i < n; i++) {
                a[i][j] = ans;
                ans--;
            }
        }
    }
    print(a, n);
}
void D(int n) {
    if(n < 2) {
        cout << n << "\n";
        return;
    }
    int a[n + 1][101];
    int cur = 1;
    for (int s = 0; s <= 2*(n-1); ++s) {
        int i_min = max(0, s - (n-1));
        int i_max = min(n-1, s);
        if (s % 2 == 0) {
            for (int i = i_max; i >= i_min; --i) {
                int j = s - i;
                a[i][j] = cur++;
            }
        }
        else {
            for (int i = i_min; i <= i_max; ++i) {
                int j = s - i;
                a[i][j] = cur++;
            }
        }
    }
    print(a, n);
}
void C(int n) {
    if(n < 2) {
        cout << n << "\n";
        return;
    }
    int h1 = 0, h2 = n - 1, c1 = 0, c2 = n - 1;
    int a[n + 1][101], ans = 1;
    while(h1 <= h2 && c1 <= c2) {
        for(int i = c1; i <= c2; i++) {
            a[h1][i] = ans;
            ans++;
        }
        h1++;
        for(int i = h1; i <= h2; i++) {
            a[i][c2] = ans;
            ans++;
        }
        c2--;
        for(int i = c2; i >= c1; i--) {
            a[h2][i] = ans;
            ans++;
        }
        h2--;
        for(int i = h2; i >= h1; i--) {
            a[i][c1] = ans;
            ans++;
        }
        c1++;
    }
    print(a, n);
}
int main() {
    fastio
    freopen(fname".inp", "r", stdin);
    freopen(fname".out", "w", stdout);
    clog <<"LOVE M.NG SO MUCHHHHHHHHHHHHHHHHHHHH" << endl;  
    
    int n; cin >> n;
    A(n);
    B(n);
    C(n);
    D(n);
    return 0;
}
