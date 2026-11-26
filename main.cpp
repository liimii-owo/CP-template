// https://github.com/liimii-owo/CP-template
#include<bits/stdc++.h>
#include<cassert>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define repv(i, n) for(int i = (n) - 1; i >= 0; i--)
#define repv1(i, n) for(int i = (n); i >= 1; i--)
#define FOR(i, l, r) for(int i = (l); i <= (r); i++)
#define FORv(i, r, l) for(int i = (r); i >= (l); i--)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128_t;
using u128 = __uint128_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>
using vec = vector<T>;
template<class T>
using vvec = vector<vector<T>>;
template<class T>
using maxpq = priority_queue<T>;
template<class T>
using minpq = priority_queue<T, vector<T>, greater<T>>;
template<class T, class Cmp = less<T>>
using ordered_set = __gnu_pbds::tree<
    T,
    __gnu_pbds::null_type,
    Cmp,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

#ifdef LOCAL

#define DBG_FIELDS(...) \
    auto debug_fields() const { \
        return std::tie(__VA_ARGS__); \
    }

namespace cp_debug {
    template<class T>
    void print(const T& x, int depth = 0) {
        if constexpr (requires { cerr << x; }) {
            cerr << x;
        }
        else if constexpr (ranges::input_range<const T>) {
            using V = remove_cvref_t<ranges::range_reference_t<const T>>;

            constexpr bool multiline =
                ranges::input_range<const V> &&
                !requires(const V& v) { cerr << v; };

            cerr << '[';
            bool first = true;

            for (const auto& v : x) {
                if (!first) cerr << (multiline ? "," : ", ");

                if constexpr (multiline) {
                    cerr << '\n' << string(4 * (depth + 1), ' ');
                }

                first = false;
                cp_debug::print(v, depth + 1);
            }

            if (multiline && !first) {
                cerr << '\n' << string(4 * depth, ' ');
            }

            cerr << ']';
        }
        else if constexpr (requires { x.debug_fields(); }) {
            cp_debug::print(x.debug_fields(), depth);
        }
        else if constexpr (requires { typename tuple_size<T>::type; }) {
            cerr << '{';
            int i = 0;

            std::apply([&](const auto&... v) {
                ((cerr << (i++ ? ", " : ""),
                  cp_debug::print(v, depth)), ...);
            }, x);

            cerr << '}';
        }
        else if constexpr (is_class_v<T> && is_aggregate_v<T>) {
            const auto& [...members] = x;
            cp_debug::print(std::tie(members...), depth);
        }
        else {
            cerr << "<unsupported>";
        }
    }

    template<class... Ts>
    void log(const Ts&... args) {
        int i = 0;
        ((cerr << (i++ ? ", " : ""),
          cp_debug::print(args)), ...);
        cerr << '\n';
    }
}

#define dbg(...) \
    do { \
        cerr << "[" << #__VA_ARGS__ << "]: "; \
        cp_debug::log(__VA_ARGS__); \
    } while (false)

#else

#define dbg(...) ((void)0)
#define DBG_FIELDS(...)

#endif

template<class X, class Y>
bool chmin(X& a, const Y& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class X, class Y>
bool chmax(X& a, const Y& b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
void sort_unique(vector<T>& a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
}

void yesno(bool ok) {
    cout << (ok ? "Yes" : "No") << '\n';
}

constexpr int INF = 1 << 30;
constexpr ll LINF = 1LL << 60;
constexpr int MOD99 = 998244353;
constexpr int MOD10 = 1000000007;
constexpr long double PI = 3.141592653589793238462643383279502884L;
constexpr long double EPS = 1e-9L;

void solve() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T = 1;
    // cin >> T;
    while(T--) solve();

    return 0;
}