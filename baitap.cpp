#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int maxn = 1e5 + 1;
int n, q;

int count_for_max[maxn], count_for_min[maxn];
int stmax[4 * maxn], stmin[4 * maxn];
//-------------------for case 1 and 5-------
void build_max_tree(int id, int l, int r) {
    if(l == r) {
        stmax[id] = count_for_max[l];
        return;
    }

    int mid = (l + r) >> 1;
    build_max_tree(2 * id, l, mid);
    build_max_tree(2 * id + 1, mid + 1, r);

    stmax[id] = max(stmax[2 * id + 1], stmax[2 * id]);
}
void build_min_tree(int id, int l, int r) {
    if(l == r) {
        stmin[id] = count_for_min[l];
        return;
    }

    int mid = (l + r) >> 1;
    build_min_tree(2 * id, l, mid);
    build_min_tree(2 * id + 1, mid + 1, r);

    stmin[id] = min(stmin[2 * id + 1], stmin[2 * id]);
}
void update_max(int id, int l, int r, int i, int val) {
    if(l > i || r < i) return;

    if(l == r) {
        stmax[id] = val;
        return;
    }

    int mid = (l + r) >> 1;
    update_max(2 * id, l, mid, i, val);
    update_max(2 * id + 1, mid + 1, r, i, val);

    stmax[id] = max(stmax[2 * id + 1], stmax[2 * id]);
}
void update_min(int id, int l, int r, int i, int val) {
    if(l > i || r < i) return;

    if(l == r) {
        stmin[id] = val;
        return;
    }

    int mid = (l + r) >> 1;
    update_min(2 * id, l, mid, i, val);
    update_min(2 * id + 1, mid + 1, r, i, val);

    stmin[id] = min(stmax[2 * id + 1], stmax[2 * id]);
}
//--------------------------------------------
void case1(int x) {
    count_for_max[x] = x;
    count_for_min[x] = x;
    update_max(1, 1, n, x, x);
    update_min(1, 1, n, x, x);
}
void case2(int x) {
    count_for_max[x] = 0;
    count_for_min[x] = maxn + 1;
    update_max(1, 1, n, x, 0);
    update_min(1, 1, n, x, maxn + 1);
}
void case3(int x) {
    int l = 1, r = maxn, ans = 0;
    while(l <= r) {
int mid = (l + r) >> 1;
        if(count_for_min[mid] == mid && mid <= x) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if(ans == 0) cout << "No" << endl;
    else cout << ans << endl;
}
void case4(int x) {
    int l = 1, r = maxn, ans = 0;
    while(l <= r) {
        int mid = (l + r) >> 1;
        if(count_for_min[mid] == mid && mid >= x) {
            ans = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    if(ans == 0) cout << "No" << endl;
    else cout << ans << endl;
}

int main() {
    fastio
   // freopen("baitap.inp", "r", stdin);
//    freopen("baitap.out", "w", stdout);
    clog <<"LOVE M.NG SO MUCHHHHHHHHHHHHHHHHHHHH" << endl;  
    
    memset(count_for_max, 0, sizeof(count_for_max));
    for(int i = 0; i < maxn; i++)
        count_for_min[i] = maxn + 1;
        
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        count_for_max[x] = x;
        count_for_min[x] = x;
    }
    cin >> q;
    
    build_max_tree(1, 1, n);
    build_min_tree(1, 1, n);
    while(q--) {
        int t, x; cin >> t;
        if(t == 5) {
            cout << stmax[1] << " " << stmin[1] << endl;
        }
        else {
            cin >> x;
            switch (t){
            case 1:
                case1(x);
                break;
            case 2:
                case2(x);
                break;
            case 3:
                case3(x);
                break;
            default:
                case4(x);
                break;
            }
        }
    }
    return 0;
}