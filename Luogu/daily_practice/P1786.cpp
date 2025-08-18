#include <bits/stdc++.h>

using namespace std;

int pl[] = {0, 2, 4, 7, 25, 120};
struct people{
    string name;
    string place;
    int devotion;
    int rank;
    int order;
}s[120];

bool cmp1(const people& a, const people& b) {
    return a.devotion > b.devotion;
}
bool cmp2(const people& a, const people& b) {
    if(a.rank != b.rank) return a.rank > b.rank;
    else return a.order < b.order;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> s[i].name >> s[i].place >> s[i].devotion >> s[i].rank;
        s[i].order = i;
    }
    stable_sort(s + 3, s + n, cmp1);
    int plac = 3;
    for(int i = 1; i <= 5; i++) {
        if(n > plac + pl[i]) {
            stable_sort(s + plac, s + plac + pl[i], cmp2);
            plac += pl[i];
        }
        else {
            stable_sort(s + plac, s + n, cmp2);
            break;
        }
    }
    for(int i = 0; i < n; i++) {
        if(i == 0) {
            cout << s[i].name << " BangZhu " << s[i].rank << endl;
        }
        else if(i == 1 || i == 2) {
            cout << s[i].name << " FuBangZhu " << s[i].rank << endl;
        }
        else if(i > 2 && i <= 4) {
            cout << s[i].name << " HuFa " << s[i].rank << endl;
        }
        else if(i > 4 && i <= 8) {
            cout << s[i].name << " ZhangLao " << s[i].rank << endl;
        }
        else if(i > 8 && i <= 15) {
            cout << s[i].name << " TangZhu " << s[i].rank << endl;
        }
        else if(i > 15 && i <= 40) {
            cout << s[i].name << " JingYing " << s[i].rank << endl;
        }
        else {
            cout << s[i].name << " BangZhong " << s[i].rank << endl;
        }
    }
    return 0;
}