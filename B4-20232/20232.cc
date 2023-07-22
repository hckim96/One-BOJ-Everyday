#include <bits/stdc++.h>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define ll long long
#define ld long double
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pair<int, int> > vpi;
typedef vector<vector<int>> vvi;
typedef pair<ll, ll> pl;
typedef tuple<ll, ll, ll> t;
typedef vector<ll> vl;
typedef vector<pair<ll, ll>> vpl;
typedef vector<vector<ll>> vvl;
typedef vector<string> vs;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
// loops
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto &a : x)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  #if !defined(ONLINE_JUDGE)
  freopen("../input.txt", "r", stdin);
  freopen("../output.txt", "w", stdout);
  #endif // ONLINE_JUDGE

map<int, string> mp = {
  {1995, "ITMO"},
{1996, "SPbSU"},
{1997, "SPbSU"},
{1998, "ITMO"},
{1999, "ITMO"},
{2000, "SPbSU"},
{2001, "ITMO"},
{2002, "ITMO"},
{2003, "ITMO"},
{2004, "ITMO"},
{2005, "ITMO"},
{2006, "PetrSU, ITMO"},
{2007, "SPbSU"},
{2008, "SPbSU"},
{2009, "ITMO"},
{2010, "ITMO"},
{2011, "ITMO"},
{2012, "ITMO"},
{2013, "SPbSU"},
{2014, "ITMO"},
{2015, "ITMO"},
{2016, "ITMO"},
{2017, "ITMO"},
{2018, "SPbSU"},
{2019, "ITMO"}
};
int n;
cin >> n;
cout << mp[n];
}