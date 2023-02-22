/****************************************************
         ❤ Bsmellah El Rahman El Rahim ❤
****************************************************/

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define vi vector <int>
#define pii pair <int,int>
#define mii map <int,int>
#define si set <int>
#define ull unsigned long long
#define loop(i, x) for(int i = 0; i < x; i++)
#define U unsigned int
#define endl "\n"
#define MN 300005
#define INF 100000000000ll
#define all(v) v.begin(),v.end()
#define EPS 1e-6
#define sc2(n, m) cin >> n >> m;
#define sc(n) cin >> n;
#define di deque<int>
clock_t startTime;

double getCurrentTime() {
    return (double) (clock() - startTime) / CLOCKS_PER_SEC;
}


auto cmp = [](pii a, pii b) -> bool {
//            [  {5,6}      ,    {1,10}   ]
    return ((a.first < b.first) || ((a.first == b.first) && (a.second > b.second)));
};

void solve() {
    while (true) {
        int n;
        cin >> n;
        if (!n)
            return;
        vector<tuple<int, int, int, int>> v(n);
        loop(i, n)cin >> get<0>(v[i]) >> get<1>(v[i]) >> get<2>(v[i]) >> get<3>(v[i]);
        int ans = 0,days=0;
        vi mon = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (int i = 1; i < n; ++i) {
            bool isLeap = 0;
            int d1 = get<0>(v[i - 1]), m1 = get<1>(v[i - 1]), y1 = get<2>(v[i - 1]), c1 = get<3>(v[i - 1]);
            int d2 = get<0>(v[i]), m2 = get<1>(v[i]), y2 = get<2>(v[i]), c2 = get<3>(v[i]);
            if(y1 == y2)
            {
                if(m1 == m2 && d2 - d1 == 1)
                {
                    ans += c2 - c1;days++;
                }
                else if (m2 - m1 == 1){
                    if(((y2 % 4 == 0) && (y2%100 != 0))|| (y2 % 400 == 0))
                        isLeap=1;
                    int lastday = mon[m1];
                    if(m1 == 2 && isLeap)
                        lastday++;
                    if(lastday == d1 && d2 == 1) {
                        ans += c2 - c1;
                        days++;
                    }
                }
            }
            else if (y2 - y1 == 1)
            {
                if((d1 == 31 && d2 == 1) && (m1 == 12 && m2 == 1)) {
                    ans += c2 - c1;
                    days++;
                }
            }


        }

        cout << days << " " << ans << endl;

    }

}

signed main() {
//  =============================================================================
    fast;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//  =============================================================================
    startTime = clock();
//    int TC;
//    cin >> TC;
//    while (TC--) {
    solve();
//    }
    return 0;
}
