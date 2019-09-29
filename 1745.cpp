
/// Solution 01:

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

void solve(vector<int>& v, int sum)
{
    int n = v.size();
    bool subset[n + 1][sum + 1];
    set<int> ans;
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;
    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < v[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= v[i - 1])
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - v[i - 1]];
        }
    }

    for (int i = 1; i <= sum; i++) {
        if (subset[n][i] && i) ans.insert(i);
    }
    cout << (int)ans.size() << endl;
    for (auto x : ans)
        cout << x << " ";
    cout << endl;
}

int main()
{
    FASTIO
    /*
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
        int n;
        cin >> n;
        vector<int> v(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            sum += v[i];
        }
        solve(v, sum);
    }

    //double end_time = clock();
    //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
    return 0;
}

///solution 02:
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
  /*
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
    int n;
    cin >> n;
    int max_sum = n * 1000;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<vector<bool>>dp(n + 1, vector<bool> (max_sum + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j <= max_sum; j++) {
        dp[i][j] = dp[i - 1][j];
        int lft = j - v[i - 1];
        if (lft >= 0 && dp[i - 1][lft])
          dp[i][j] = true;
      }
    }

    vector<int> ans;
    for (int i = 1; i <= max_sum; i++)
      if (dp[n][i]) ans.push_back(i);

    cout << (int) ans.size() << endl;
    for (auto x : ans)
      cout << x << " ";
    cout << endl;
  }

  //double end_time = clock();
  //printf( "Time = %lf ms\n", ( (end_time - start_time) / CLOCKS_PER_SEC)*1000);
  return 0;
}
