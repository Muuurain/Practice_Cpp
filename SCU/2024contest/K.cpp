#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    int cpa = 0, cpb = 0;
    n--;
    int a1, b1;
    cin >> a1 >> b1;
    int rest = 0;
    int plusa = 0, plusb = 0;
    if(a1 == b1) {
        ans = a1;
        cpa = cpb = a1;
        rest = 1;
    }
    else if(a1 > b1) {
        ans = a1 - 1;
        cpa = 0;
        cpb = ans - b1;
    }
    else {
        ans = b1 - 1;
        cpa = ans - a1;
        cpb = 0;
    }
    while(n--) {
        int ta, tb;
        cin >> ta >> tb;
        if(cpa >= ta && cpb >= tb) {
            cpa -= ta;
            cpb -= tb;
            rest++;
        }
        else if(cpa >= ta) {
            if(cpb + rest + 1 >= tb) {
                cpa -= ta;
                rest -= tb - cpb - 1;
                cpb = 0;
            }
            else {
                int nd = tb - (cpb + rest + 1);
                ans += nd;
                plusb += nd;
                cpa -= ta;
                cpa += nd;
                rest = 0;
                cpb = 0;
            }
        }
        else if(cpb >= tb) {
            if(cpa + rest + 1 >= ta) {
                cpb -= tb;
                rest -= ta - cpa - 1;
                cpa = 0;
            }
            else {
                int nd = ta - (cpa + rest + 1);
                ans += nd;
                plusa += nd;
                cpb -= tb;
                cpb += nd;
                rest = 0;
                cpa = 0;
            }
        }
        else {
            if(rest + 1 >= (ta - cpa + (tb - cpb))) {
                rest++;
                rest -= (ta - cpa + (tb - cpb));
                cpa = 0;
                cpb = 0;
            }
            else {
                rest++;
                int nda = ta - cpa;
                int ndb = tb - cpb;
                if(nda == ndb) {
                    int plus = nda - (rest / 2);
                    ans += plus;
                    plusa += plus;
                    plusb += plus;
                    if(rest & 1) {
                        rest = 1;
                    }
                    else {
                        rest = 0;
                    }
                    cpa = cpb = 0;
                }
                else if(nda > ndb) {
                    if(nda - rest >= ndb) {
                        nda -= rest;
                        rest = 0;
                        ans += nda;
                        cpa = 0;
                        cpb += nda;
                        cpb -= tb;
                    }
                    else {
                        rest -= nda - ndb;
                        nda = ndb;
                        if(rest & 1) {
                            nda -= rest / 2;
                            ans += nda;
                            cpa = cpb = 0;
                            rest = 1;
                        }
                        else {
                            nda -= rest / 2;
                            ans += nda;
                            cpa = cpb = 0;
                            rest = 0;
                        }
                    }
                }
                else {
                    if(ndb - rest >= nda) {
                        ndb -= rest;
                        rest = 0;
                        ans += ndb;
                        cpb = 0;
                        cpa += ndb;
                        cpa -= ta;
                    }
                    else {
                        rest -= ndb - nda;
                        ndb = nda;
                        if(rest & 1) {
                            ndb -= rest / 2;
                            ans += ndb;
                            cpb = cpa = 0;
                            rest = 1;
                        }
                        else {
                            ndb -= rest / 2;
                            ans += ndb;
                            cpb = cpa = 0;
                            rest = 0;
                        }
                    }
                }
            }
        }
        // cout << "n " << n << " cpa " << cpa << " cpb " << cpb << " rest " << rest << " ans " << ans << endl;
    }

    // cout << "plusa " << plusa << " plusb " << plusb << endl;
    int minus = 0;
    if(cpa) {
        if(plusa) {
            minus = min(plusa, cpa / 2);
        }
    }
    if(cpb) {
        if(plusb) {
            minus = min(plusb, cpb / 2);
        }
    }

    ans -= minus;

    cout << ans << '\n';
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