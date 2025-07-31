#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 10; // 调整数组大小以适应需求
int l1[N], r1[N], l2[N], r2[N]; // 存储每个二元组的范围
vector<int> points; // 存储所有关键端点，用于离散化

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c, T;
    cin >> c >> T;
    while (T--) {
        int n;
        cin >> n;
        points.clear(); // 清空上一组测试数据的端点
        for (int i = 0; i < n; ++i) {
            // 正确读取每个二元组的四个参数，注意变量名拼写（l1[i]而非l[i]等）
            cin >> l1[i] >> r1[i] >> l2[i] >> r2[i];
            // 收集关键端点：l2[i]和r2[i]+1（划分区间的边界）
            points.push_back(l2[i]);
            points.push_back(r2[i] + 1);
        }
        // 离散化：排序并去重端点
        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());
        int ln = points.size();
        if (ln < 2) { // 若只有一个端点，无有效区间
            cout << 0 << '\n';
            continue;
        }
        // 差分数组：分别记录对b、a_min、a_max、c_min、c_max的贡献
        vector<long long> a(ln, 0), b(ln, 0), c(ln, 0), d(ln, 0), e(ln, 0), f(ln, 0);
        for (int i = 0; i < n; ++i) {
            // 找到l2[i]在points中的位置（左边界）
            int x = lower_bound(points.begin(), points.end(), l2[i]) - points.begin();
            // 找到r2[i]+1在points中的位置（右边界）
            int y = lower_bound(points.begin(), points.end(), r2[i] + 1) - points.begin();
            // 对b的贡献（[l2[i], r2[i]]区间内，取r1[i]个x）
            a[x] += r1[i];
            if (y < ln) a[y] -= r1[i];
            // 对a_min和a_max的贡献（x > r2[i]时，即[r2[i]+1, ∞)）
            int z = lower_bound(points.begin(), points.end(), r2[i] + 1) - points.begin();
            if (z < ln) {
                b[z] += l1[i]; // a_min（小于x的最小数量）
                c[z] += r1[i]; // a_max（小于x的最大数量）
            }
            // 对c_min和c_max的贡献（x < l2[i]时，即[1, l2[i})）
            int w = lower_bound(points.begin(), points.end(), l2[i]) - points.begin();
            d[0] += l1[i]; // c_min（大于x的最小数量）
            if (w < ln) d[w] -= l1[i];
            e[0] += r1[i]; // c_max（大于x的最大数量）
            if (w < ln) e[w] -= r1[i];
            // 标记当前区间是否有x的贡献
            f[x]++;
            if (y < ln) f[y]--;
        }
        long long ans = 0;
        // 前缀和计算：累计各差分数组的贡献
        long long ca = 0, cb = 0, cc = 0, cd = 0, ce = 0, cf = 0;
        for (int i = 0; i < ln - 1; ++i) {
            ca += a[i]; // 当前区间内b的值（等于x的数量）
            cb += b[i]; // 当前区间内a_min的值（小于x的最小数量）
            cc += c[i]; // 当前区间内a_max的值（小于x的最大数量）
            cd += d[i]; // 当前区间内c_min的值（大于x的最小数量）
            ce += e[i]; // 当前区间内c_max的值（大于x的最大数量）
            cf += f[i]; // 当前区间是否有x的贡献
            // 若当前区间x未出现，跳过
            if (cf == 0) continue;
            // 判断c的有效范围是否非空
            long long lower_c = max(cb - ca + 1, cd);
            long long upper_c = min(cc + ca, ce);
            if (lower_c <= upper_c) {
                ans += points[i + 1] - points[i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}