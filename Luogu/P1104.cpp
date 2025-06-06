#include <bits/stdc++.h>

using namespace std;

struct student{
    char s[30];
    int y, m, d;
    int id;
}st[110];
bool cmp(student a, student b) {
    if(a.y != b.y) return a.y < b.y;
    else if(a.m != b.m) return a.m < b.m;
    else if(a.d != b.d) return a.d < b.d;
    else return a.id > b.id;
}
int main() {
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        scanf("%s %d %d %d", st[i].s, &st[i].y, &st[i].m, &st[i].d);
        st[i].id = i;
    }
    sort(st + 1, st + n + 1, cmp);
    for(int i = 1; i <= n; i++) {
        printf("%s\n", st[i].s);
    }

    return 0;
}