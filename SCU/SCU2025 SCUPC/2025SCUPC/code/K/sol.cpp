#include <bits/stdc++.h>
using namespace std;
//#define double long double
typedef long long ll;
const double pi = acos(-1.0);
const double esp = 1e-7;
const double inf = 1e100;
 
bool cmp0(double x) { return fabs(x) < esp; }
int cmp(double x) { return cmp0(x) ? 0 : x > 0 ? 1 : -1; }
double acs(double x) { return acos(max((double)-1.0, min((double)1.0, x))); }
 
struct point {
    double x, y;
    void in() { scanf("%lf %lf", &x, &y); }
    void out() { printf("%lf %lf\n", x, y); }
    point(double x = 0, double y = 0) : x(x), y(y) {}
    point operator + (const point& a) const { return point(x + a.x, y + a.y); }
    point operator - (const point& a) const { return point(x - a.x, y - a.y); }
    double operator * (const point& a) const { return x * a.x + y * a.y; }
    double operator ^ (const point& a) const { return x * a.y - y * a.x; }
    point operator * (const double& a) const { return point(x * a, y * a); }
    point operator / (const double& a) const { return point(x / a, y / a); }
    bool operator < (const point& a) const { return x == a.x ? y < a.y : x < a.x; }
};
 
double len1(const point& a) { return sqrt(a * a); }
double len2(const point& a) { return a * a; }
double cro(const point& a, const point& b, const point& o) { return (a - o) ^ (b - o); }
 
struct circle {
    point o;
    double r;
    circle(point oo = point(0, 0), double rr = 0) { o = oo, r = rr; }
    double area() const { return r * r * pi; }
    bool in(const point& a) { return len1(a - o) - r <= esp; }
};
 
// 计算弓形面积
double area_bo(const circle& a, double angs, double angt) {
    point s(a.o.x + a.r * cos(angs), a.o.y + a.r * sin(angs));
    point t(a.o.x + a.r * cos(angt), a.o.y + a.r * sin(angt));
    double ans = a.r * a.r * (angt - angs) - cro(s, t, a.o) + (s ^ t);
    return ans / 2;
}
 
// 圆与圆关系
int re_cir(const circle& a, const circle& b) {
    double d = len1(a.o - b.o);
    if (cmp(d - a.r - b.r) == 1) return 4;  // 相离
    if (cmp(d - a.r - b.r) == 0) return 3;  // 相切
    if (cmp(d - a.r - b.r) == -1) {
        if (cmp(d - fabs(a.r - b.r)) == 0) return 1;  // 内切
        if (cmp(d - fabs(a.r - b.r)) == 1) return 2;  // 相交
        if (cmp(d - fabs(a.r - b.r)) == -1) return 0;  // 包含
    }
    return 0;
}
 
// 计算圆面积并
double calc_area_union(const vector<circle>& circles, int n, int m) {
    vector<pair<double, int>> v;
    v.reserve(2005);
    double ans = 0;
    
    for (int i = 0; i < n; i++) {
        v.clear();
        v.push_back(make_pair(-pi, 1));
        v.push_back(make_pair(pi, -1));
        
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            int re = re_cir(circles[i], circles[j]);
            //cout<<re<<" ";
            if (re == 3 || re == 4) continue;  // 相离或相切
            if (re == 0 || re == 1) {  // 包含或内切
                if (circles[i].r > circles[j].r) continue;
                if (circles[i].r == circles[j].r && i > j) continue;  // 同圆处理
                v.push_back(make_pair(-pi, 1));
                v.push_back(make_pair(pi, -1));
            } else {  // 相交
                double d = len1(circles[j].o - circles[i].o);
                double alph = acos((circles[j].o.x - circles[i].o.x) / d);
                if (circles[j].o.y - circles[i].o.y < 0) alph = -alph;
                double deta = acos((d * d + circles[i].r * circles[i].r - circles[j].r * circles[j].r) / (2 * d * circles[i].r));
                double angs = alph - deta;
                double angt = alph + deta;
                
                if (angs < -pi) angs += 2 * pi;
                if (angt > pi) angt -= 2 * pi;
                
                if (angt < angs) {
                    v.push_back(make_pair(pi, -1));
                    v.push_back(make_pair(-pi, 1));
                }
                v.push_back(make_pair(angs, 1));
                v.push_back(make_pair(angt, -1));
            }
        }
        
        sort(v.begin(), v.end());
        //cout<<circles[i].o.x<<" "<<circles[i].o.y<<" "<<endl;
        //cout<<v.size()<<endl;
        int cur = 0;
        for (int j = 1; j < v.size(); j++) {
            cur += v[j-1].second;
            if (cur == m) {
                ans += area_bo(circles[i], v[j-1].first, v[j].first);
            }
        }
    }
    return ans;
}
 
// 二分查找最小半径
double find_min_radius(const vector<point>& points, int n, int m) {
    double l = 0, r = 1e7;
    double ans = r;
    
    while (r - l > esp) {
        double mid = (l + r) / 2;
        vector<circle> circles(n);
        for (int i = 0; i < n; i++) {
            circles[i] = circle(points[i], mid);
        }
        
        double area = calc_area_union(circles, n, m);
        //cout<<mid<<" "<<area<<endl;
        if (area > 0) {
            ans = mid;
            r = mid;
        } else {
            l = mid;
        }
    }
    
    return ans;
}
 
int main() {
    int n, m;
    cin >> n >> m;
    if(m==0) 
    {
    	printf("0\n");
    	return 0;
    }
    vector<point> points(n);
    for (int i = 0; i < n; i++) {
        points[i].in();
    }
    
    double radius = find_min_radius(points, n, m);
    printf("%.15lf",radius);
    
    return 0;
}
