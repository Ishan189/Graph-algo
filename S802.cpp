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
ll fact(ll x) {
	ll ans = 1;
	for (ll i = 1; i <= x; i++) {
		ans = (ans * i) % MOD;
	}
	return ans;
}

ll nCr(ll n, ll r) {
	ll ans = fact(n);
	ll temp1 = fact(r);
	ll temp2 = fact(n - r);
	ll temp = (temp1 % MOD * temp2 % MOD + MOD) % MOD;
	ans = (ans * expo(temp, MOD - 2, MOD)) % MOD;
	return ans;
}

vector<int> factor(int n)
{
	vector<int> facts;
	for (long long d = 2; d * d <= n; d ++)
	{
		while (n % d == 0) {
			facts.push_back(d);
			n /= d;
		}
	}
	if (n > 1)
		facts.push_back(n);
}


void solve()
{

	cout << (5 ^ 4 ^ 11) << endl;

}


int32_t main()
{

	fastio();

	int t = 1;
	//cin >> t;
	while (t--)
		solve();

}