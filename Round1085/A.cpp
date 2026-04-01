#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int len;
        char s[MAXN];
        cin >> len >> s;
        int max_ans, min_ans, cnt = 0;;
        for (int i = 0; i < len; i++) {
            if (s[i] == '1') cnt++;
        }
        max_ans = min_ans = cnt;
        for (int i = 1; i < len - 1; i++) {
            if (s[i - 1] == '1' && s[i + 1] == '1') {
                if (s[i] == '0') {
                    max_ans++;
                    s[i] = '1';
                }
            }
        }
        min_ans = max_ans;
        for (int i = 1; i < len - 1; i++) {
            if (s[i - 1] == '1' && s[i + 1] == '1') {
                min_ans--;
                s[i] = '0';
            }
        }
        cout << min_ans << ' ' << max_ans << endl;
    }
    return 0;
}