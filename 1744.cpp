#include <bits/stdc++.h>
using namespace std;
#define INF 1<<30
#define endl '\n'
#define maxn 100005
#define tc printf("Case %d: ", cs)
#define tcn printf("Case %d:\n", cs);
#define FASTIO ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
typedef long long ll;
const double PI = acos(-1.0);
#define dbg(x) cerr << #x << " = " << x << endl;
#define dbg2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl;
#define dbg3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;
#define dbg4(w,x, y, z) cerr << #w << " = " << w << ", " <<#x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl;


int main()
{
    FASTIO
    ///*
    //double start_time = clock();
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
//*/
    int T;
    //cin >> T;
    T = 1;
    for (int cs = 1; cs <= T; cs++) {
        int w, h;
        cin >> w >> h;
        vector<vector<int>> dp(w + 1, vector<int> (h + 1));

        for (int i = 0; i <= w; i++) {
            for (int j = 0; j <= h; j++) {
                if (i == j) {
                    dp[i][j] = 0;
                }
                else {
                    dp[i][j] = 1e9;
                    for (int k = 1; k < i; k++) {
                        dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                    }
                    for (int k = 1; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                    }
                }
            }
        }
        //for (int i = 0; i <= w; i++) {
          //  for (int j = 0; j <= h; j++)
            //    cerr << dp[i][j] << " ";
            //cerr << endl;
        ///}
        cout << dp[w][h] << endl;
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}
