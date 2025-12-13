// template_pre_standard

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define debug(x) (cout << "debug(" << #x << "): " << x << '\n')

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int ans1 = x1 + y1;
    int ans2 = max(x2, y2);
    if(ans1 <= ans2 || (x1 <= x2 && y1 <= y2)) cout << "Polycarp" << endl;
    else cout << "Vasiliy" << endl;
    return 0;
}