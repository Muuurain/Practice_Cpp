/*

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    vector<char> ch(n);
    int na = 0, nb = 0;
    for(char& c : ch) {
        cin >> c;
        if(c == 'a') na++;
        else nb++;
    }
    int maxa = 0, maxb = 0;
    for(int i = 0; i < na; i++) {
        if(ch[i] == 'a') maxa++;
    }
    for(int i = 0; i < nb; i++) {
        if(ch[i] == 'b') maxb++;
    }
    int ta = maxa, tb = maxb;
    int sta = 0, stb = 0;
    for(int i = 1; i + na - 1 < n; i++) {
        if(ch[i - 1] == 'a') ta--;
        if(ch[i + na - 1] == 'a') ta++;
        if(ta > maxa) {
            maxa = ta;
            sta = i;
        }
    }
    for(int i = 1; i + nb - 1 < n; i++) {
        if(ch[i - 1] == 'b') tb--;
        if(ch[i + nb - 1] == 'b') tb++;
        if(tb > maxb) {
            maxb = tb;
            stb = i;
        }
    }
    ll reta = 0, retb = 0;
    ll outa = 0, outb = 0;
    for(int i = 0; i < sta; i++) {
        if(ch[i] == 'a') outa += i;
    }
    for(int i = sta + na; i < n; i++) {
        if(ch[i] == 'a') outa += i;
    }
    for(int i = 0; i < stb; i++) {
        if(ch[i] == 'b') outb += i;
    }
    for(int i = stb + nb; i < n; i++) {
        if(ch[i] == 'b') outb += i;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while(t--) solve();

    return 0;
}