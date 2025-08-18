#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> f;
int p;

ll cal(vector<int> &f) {
    long long ret = 0;
    for(int i = 0; i <= f.size() / 2; i++) {
        ret += abs(abs(f[i]) - abs(f[f.size() - 1 - i]));
    }
    return ret;
}

int main() {
    scanf("%d", &p);
    for(int i = 0; i < p; i++) {
        int temp;
        scanf("%d", &temp);
        f.push_back(temp);
    }
    ll v1 = cal(f);
    vector<int> a1(p), a2(p);
    for(int i = 0; i <= f.size() / 2; i++) {
        a1[i] = (f[i] + f[f.size() - 1 - i]) / 2;
        a1[a1.size() - 1 - i] = a1[i];
        a2[i] = f[i] - a1[i];
        a2[a2.size() - 1 - i] = f[f.size() - 1 - i] - a1[a1.size() - 1 - i];
    }
    ll v2 = cal(a1) + cal(a2) + p;
    if(v1 < v2) {
        printf("1 %lld\n", v1);
        for(int i = 0; i < f.size(); i++) {
            printf("%d", f[i]);
            if(i != f.size() - 1) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }
        
    }
    else {
        printf("2 %lld\n", v2);
        for(int i = 0; i < a1.size(); i++) {
            printf("%d", a1[i]);
            if(i != a1.size() - 1) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }
        for(int i = 0; i < a2.size(); i++) {
            printf("%d", a2[i]);
            if(i != a2.size() - 1) {
                printf(" ");
            }
            else {
                printf("\n");
            }
        }
    }

    return 0;
}