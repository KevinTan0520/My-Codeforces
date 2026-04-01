#include <bits/stdc++.h>
using namespace std;


static inline long long rowBudget(long long n, long long rK, long long rD) {
    if (rK > rD) return n - rK;       
    if (rK < rD) return rK;
    return max(rK, n - rK);           
}
static inline long long colBudget(long long n, long long cK, long long cD) {
    if (cK > cD) return n - cK;       
    if (cK < cD) return cK;           
    return max(cK, n - cK);           
}

void solve() {
    long long n, rK, cK, rD, cD;
    cin >> n >> rK >> cK >> rD >> cD;

    long long dr = llabs(rK - rD);
    long long dc = llabs(cK - cD);
    long long a  = max(dr, dc);       
    long long Bp = 0;
    if (dr > dc) {
        Bp = (rK > rD) ? (n - rK) : rK;
    } else if (dc > dr) {
        Bp = (cK > cD) ? (n - cK) : cK;
    } else { 
        long long Brow = rowBudget(n, rK, rD);
        long long Bcol = colBudget(n, cK, cD);
        Bp = max(Brow, Bcol);
    }

    cout << (a + Bp) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if (!(cin >> t)) return 0;
    while (t--) solve();
    return 0;
}