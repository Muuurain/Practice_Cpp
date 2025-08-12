#include<bits/stdc++.h>
using namespace std;

int sh, sm, ss;
int main() {
    int n;
    cin >> n;
    while(n--){
        int h, m, s;
        cin >> h >> m >> s;
        ss += s;
        sm += m;
        sh += h;
        int t1 = ss / 60;
        ss %= 60;
        sm == t1;
        int t2 = sm / 60;
        sm %= 60;
        sh += t2;
    }

    cout << sh << "时" << sm << "分" << ss << "秒" << endl;

    return 0;
}



