#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int w, d, h;
        int a, b, f, g;
        scanf("%d%d%d", &w, &d, &h);
        scanf("%d%d%d%d", &a, &b, &f, &g);
        int ret = 0;
        int ans1 = a + h + f + abs(b - g);
        ret = ans1;
        int ans2 = b + h + g + abs(a - f);
        ret = min(ret, ans2);
        int ans3 = (w - a) + h + (w - f) + abs(b - g);
        ret = min(ret, ans3);
        int ans4 = (d - b) + h + (d - g) + abs(a - f);
        ret = min(ret, ans4);
        printf("%d\n", ret);
    }

    return 0;
}