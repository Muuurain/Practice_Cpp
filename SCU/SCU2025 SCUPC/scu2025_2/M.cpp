#include <bits/stdc++.h>

using namespace std;

struct pai{
    int a;
    int c;
    int id;
}p[300000];
bool cmp1(pai x, pai y) {
    return x.a > y.a;
}
bool cmp2(pai x, pai y) {
    return x.c < y.c;
}
vector<pai> ret;
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%d%d", &p[i].a, &p[i].c);
        p[i].id = i;
    }
    sort(p + 1, p + n + 1, cmp1);
    ret.push_back(p[1]);
    for(int i = 2; i <= n; i++) {
        sort(ret.begin(), ret.end(), cmp2);
        if(p[i].c < ret.front().c) {
            ret.push_back(p[i]);
        }
        
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << endl;
    for(pai i : ret) {
        printf("%d ", i.id);
    }
    cout << endl;

    return 0;
}