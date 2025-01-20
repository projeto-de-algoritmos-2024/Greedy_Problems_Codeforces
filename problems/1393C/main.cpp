/*8<{==========~ BEGIN TEMPLATE ~============>8*/
#include <bits/stdc++.h>

#include <algorithm>
using namespace std;
#ifdef LOCAL
#include "debug.cpp"
#else
#define dbg(...)
#endif
#define fastio                                                                 \
  ios_base::sync_with_stdio(0);                                                \
  cin.tie(0);
#define all(j) j.begin(), j.end()
#define rall(j) j.rbegin(), j.rend()
#define len(j) (int)j.size()
#define rep(i, a, b)                                                           \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i < (b); i++)
#define rrep(i, a, b)                                                          \
  for (common_type_t<decltype(a), decltype(b)> i = (a); i > (b); i--)
#define trav(xi, xs) for (auto &xi : xs)
#define rtrav(xi, xs) for (auto &xi : ranges::views::reverse(xs))
using ll = long long;
#define endl '\n'
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second
#define emp emplace
#define ins insert
#define divc(a, b) ((a) + (b) - 1ll) / (b)
using str = string;
using ull = unsigned long long;
using ld = long double;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using vll2d = vector<vll>;
using vi = vector<int>;
using vi2d = vector<vi>;
using pii = pair<int, int>;
using vpii = vector<pii>;
using vc = vector<char>;
using vs = vector<str>;
template <typename T, typename T2> using umap = unordered_map<T, T2>;
template <typename T> using pqmn = priority_queue<T, vector<T>, greater<T>>;
template <typename T> using pqmx = priority_queue<T, vector<T>>;
template <typename T, typename U> inline bool chmax(T &a, U const &b) {
  return (a < b ? a = b, 1 : 0);
}
template <typename T, typename U> inline bool chmin(T &a, U const &b) {
  return (a > b ? a = b, 1 : 0);
}
/*8<============~ END TEMPLATE ~============}>8*/
void run();

int32_t main() {
#ifndef LOCAL
  fastio;
#endif

  int T = 1;

  cin >> T;

  rep(t, 0, T) {
    dbg(t);
    run();
  }
}

/*8<
  @Title: Max \& Min Check

  @Description: Returns the min/max value in range
  [l, r] that satisfies the lambda function check,
  if there is no such value the 'nullopt' is
  returned.

  @Usage: check must be a function that receives
  an integer and return a boolean.

  @Time: $O(\log{r-l+1})$
>8*/

template <typename T> optional<T> maxCheck(T l, T r, function<bool(T)> check) {
  optional<T> ret;
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      ret ? chmax(ret, m) : ret = m, l = m + 1;
    else
      r = m - 1;
  }
  return ret;
}

template <typename T> optional<T> minCheck(T l, T r, function<bool(T)> check) {
  optional<T> ret;
  while (l <= r) {
    T m = midpoint(l, r);
    if (check(m))
      ret ? chmin(ret, m) : ret = m, r = m - 1;
    else
      l = m + 1;
  }
  return ret;
}

void run() {
  int N;
  cin >> N;
  vi AS(N);
  trav(ai, AS) cin >> ai;
  vi hist(N + 1);
  trav(ai, AS) hist[ai]++;

  if (*max_element(all(hist)) == 1) {
    cout << N << endl;
    return;
  }

  function<bool(ll)> check = [&](ll sz) {
    ll full_chunks = N / sz;
    ll incomplete_chunks = ((N % sz) ? 1 : 0);
    ll tot_chunks = full_chunks + incomplete_chunks;
    ll need_extra = 0;
    ll left_over = N % sz;
    bool ok = true;

    rep(i, 0, N + 1) {
      if (hist[i]) {
        ll spc = hist[i] + (hist[i] - 1) * (sz - 1);
        dbg(spc);
        ok &= (spc <= N);
        ok &= (hist[i] <= tot_chunks);
        need_extra += (hist[i] > full_chunks);
      }
    }

    ok &= (need_extra <= left_over);

    return ok;
  };

  auto ans = maxCheck(1ll, (ll)N, check);
  cout << *ans - 1 << endl;
}

/*8<
>8*/
