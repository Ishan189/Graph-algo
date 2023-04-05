#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define pb push_back
#define ppb pop_back
#define ff first
#define ss second
#define ll long long
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define MOD 1000000007
#define PI 3.141592653589793238462
#define INF 1e18
#define endl "\n"

/*---------------------------------------------------------------------------------------------------------------------------*/
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
ll gcd(ll a, ll b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
/*--------------------------------------------------------------------------------------------------------------------------*/

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool isVaild(int r, int c, int n, int m) {
	if (r >= 0 && r < n && c >= 0 && c < m) return true;

	return false;
}


void solve()
{

	int n, m;
	cin >> n >> m;

	vector<vector<char>>arr(n, vector<char>(m, '.'));

	int aa, ab;
	int ba, bb;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 'A') {
				aa = i;
				ab = j;
			}
			if (arr[i][j] == 'B') {
				arr[i][j] = '.';
				ba = i;
				bb = j;
			}
		}
	}

	vector<vector<int>> vis(n, vector<int>(m, 0));
	vector<vector<char >> dir(n, vector<char>(m, '.'));
	queue<pair<int, int>> q;

	q.push({aa, ab});
	vis[aa][ab] = 1;

	bool found = false;

	while (!q.empty()) {

		int r = q.front().ff;
		int c = q.front().ss;
		if (r == ba && c == bb) {
			found = true;
			break;
		}

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dx[i];
			int nc = c + dy[i];

			if (isVaild(nr, nc, n, m) && !vis[nr][nc] && arr[nr][nc] == '.') {
				if (dx[i] == 1 && dy[i] == 0) {
					vis[nr][nc] = 1;
					dir[nr][nc] = 'D';
					q.push({nr, nc});
				} else if (dx[i] == 0 && dy[i] == 1) {
					vis[nr][nc] = 1;
					dir[nr][nc] = 'R';
					q.push({nr, nc});
				} else if (dx[i] == -1 && dy[i] == 0) {
					dir[nr][nc] = 'U';
					q.push({nr, nc});
					vis[nr][nc] = 1;
				} else if (dx[i] == 0 && dy[i] == -1) {
					dir[nr][nc] = 'L';
					q.push({nr, nc});
					vis[nr][nc] = 1;

				}
			}

		}

		if (found) break;

	}

	if (!found) {
		cout << "NO" << endl;
		return;
	}

	cout << "YES" << endl;


	string ans = "";

	int sr = ba;
	int sc = bb;



	while (!(sr == aa && sc == ab)) {

		if (dir[sr][sc] == 'R') {
			ans += dir[sr][sc];
			sc--;
		} else if (dir[sr][sc] == 'L') {
			ans += dir[sr][sc];
			sc++;
		} else if (dir[sr][sc] == 'D') {
			ans += dir[sr][sc];
			sr--;
		} else if (dir[sr][sc] == 'U') {
			ans += dir[sr][sc];
			sr++;
		}
	}

	reverse(all(ans));
	cout << sz(ans) << endl;
	cout << ans << endl;



}


int32_t main()
{

	fastio();

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}