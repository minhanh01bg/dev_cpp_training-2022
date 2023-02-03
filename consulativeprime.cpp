/**
                                        .-''-.
                                      .' .-.  )
                                     / .'  / /
    .-''` ''-.        .-''` ''-.    (_/   / /
  .'          '.    .'          '.       / /
 /              `  /              `     / /
'                ''                '   . '
|         .-.    ||         .-.    |  / /    _.-')
.        |   |   ..        |   |   ..' '  _.'.-''
 .       '._.'  /  .       '._.'  //  /.-'_.'
  '._         .'    '._         .'/    _.'
     '-....-'`         '-....-'` ( _.-'
 */
#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;
using ldb = long double;
using db = double;
using str = string; // yay python!

using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<db, db>;

using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<ll>;
using vd = vector<db>;
using vs = vector<str>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;

// pairs
#define mp make_pair
// #define fi first
#define se second

// vectors
#define sz(x) (int)(x).size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sor(x) sort(all(x))
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define null NULL
#define endl '\n'
// loops
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
// #define rep(i, a) rep(i, 0, a)
#define rof(i, a, b) for (int i = (b); i >= (a); --i)
#define r0f(i, a) rof(i, 0, a)
#define rtf(t) for (int _ = 1; _ <= (t); ++_)
#define trav(a, x) for (auto &a : x)
#define reset(x) memset(x, 0, sizeof(x))
const int mod = 1e9 + 7;
const int MX = 5e4 + 7;
const ll INF = 1e18;
const int NM = 1e6 + 7;
const ldb PI = acos((ldb)-1);
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; // for every grid problem!!
/*_______________________________________MY CODE_____________________________________*/
//
ll f[33][2][33][2], n[33];

typedef unsigned char bytes;

int count = 0; 
vector<int> primes;
void sieve(int lim)
{
    if (lim < 2) return ;
    int sqrt = std::sqrt(lim);
    int sieve_size = max(sqrt, (1 << 15));
    int segment_size = sieve_size * 16;

    vector<bytes> mark(sieve_size);
    vector<bytes> is_primes(sqrt + 1, true);
    vector<int> seg_prime;
    vector<int> seg_multi;

    for (int i = 3; i <= sqrt; i += 2)
        if (is_primes[i])
            for (int j = i * i; j <= sqrt; j += i)
                is_primes[j] = false;

    int reset[16];
    for (int i = 0; i < 8; ++i)
        reset[2 * i] = reset[2 * i + 1] = ~(1 << i);

    int popcnt[256];
    for (int i = 0; i < 256; ++i)
        popcnt[i] = __builtin_popcount(i);

    int s = 3;
    for (int low = 0; low <= lim; low += segment_size)
    {
        fill(mark.begin(), mark.end(), 0xff);
        int high = min(low + segment_size - 1, lim);
        sieve_size = (high - low) / 16 + 1;

        for (; s * s <= high; s += 2)
        {
            if (is_primes[s])
            {
                seg_prime.push_back(s);
                seg_multi.push_back(s * s - low);
            }
        }

        for (size_t i = 0; i < seg_prime.size(); ++i)
        {
            int j = seg_multi[i];
            for (int k = seg_prime[i] * 2; j < segment_size; j += k)
                mark[j >> 4] &= reset[j % 16];

            seg_multi[i] = j - segment_size;
        }

        if (high == lim)
        {
            int bits = 0xff << ((lim % 16) + 1) / 2;
            mark[sieve_size - 1] &= ~bits;
        }
        
        for (int n = 0; n < sieve_size; n++)
        {
//             count += popcnt[mark[n]]; continue;
            for (int i = 0; i < 8; i++)
                if (mark[n] & (1 << i))
                    primes.push_back(low + n * 16 + i * 2 + 1);
        }
    }
}

// miller rabin

inline uint64_t mod_mult64(uint64_t a, uint64_t b, uint64_t m) {
    return __int128_t(a) * b % m;
}
uint64_t mod_pow64(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t ret = (m > 1);
    for (;;) {
        if (b & 1) ret = mod_mult64(ret, a, m);
        if (!(b >>= 1)) return ret;
        a = mod_mult64(a, a, m);
    }
}

// Works for all primes p < 2^64
bool is_prime(uint64_t n) {
    if (n <= 3) return (n >= 2);
    static const uint64_t small[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67,
        71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139,
        149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199,
    };
    for (size_t i = 0; i < sizeof(small) / sizeof(uint64_t); ++i) {
        if (n % small[i] == 0) return n == small[i];
    }

    // Makes use of the known bounds for Miller-Rabin pseudoprimes.
    static const uint64_t millerrabin[] = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
    };
    static const uint64_t A014233[] = {  // From OEIS.
        2047LL, 1373653LL, 25326001LL, 3215031751LL, 2152302898747LL,
        3474749660383LL, 341550071728321LL, 341550071728321LL,
        3825123056546413051LL, 3825123056546413051LL, 3825123056546413051LL, 0,
    };
    uint64_t s = n-1, r = 0;
    while (s % 2 == 0) {
        s /= 2;
        r++;
    }
    for (size_t i = 0, j; i < sizeof(millerrabin) / sizeof(uint64_t); i++) {
        uint64_t md = mod_pow64(millerrabin[i], s, n);
        if (md != 1) {
            for (j = 1; j < r; j++) {
                if (md == n-1) break;
                md = mod_mult64(md, md, n);
            }
            if (md != n-1) return false;
        }
        if (n < A014233[i]) return true;
    }
    return true;
}

vector<ll> candis;
void init_(ll n)
{
    const unsigned long long LIMIT = 10'000'000'000'000'000'000ULL;
    rep(start, 0, n)
    {
        ll cur = 1ULL;
        rep(endN, start, n)
        {
            if (cur > LIMIT / primes[endN])
                break;
            cur *= primes[endN];
            candis.pb(cur);
        }
    }
    sort(candis.begin(), candis.end());
}

ll safe_sqrt(ll n)
{
    ll tmp = sqrt(n) + 3;
    while (1ULL * tmp * tmp > n)
        tmp--;
    return tmp;
}
ll next_prime(ll n)
{
    if (n <= 2)
        return 2;
    if (n % 2 == 0) // even
        n++;
    while (!is_prime(n))
        n += 2;
    return n;
}
ll prev_prime(ll n)
{
    if(n==1) return 1;
    if (n == 2)
        return 2;
    if (n % 2 == 0) // even
        n--;
    while (n > 3 && !is_prime(n)) n -= 2;
    return n;
}
bool check_candis(ll n)
{
    if (n == 1)
        return false;
    if (is_prime(n))
        return true;
    if (binary_search(candis.begin(), candis.end(), n))
        return true;

    // 2 number
    ll tmp = safe_sqrt(n);
    // cout<<(ll)sqrt(n)<<endl;
    ll next = next_prime(tmp+1);
    if(n % next != 0)
        return false;
    ll small = n/next;
    if(small == next)
        return false;
    return n == next * prev_prime(next-1);
}

void process(ll n)
{
    cin >> n;
    if (check_candis(n))
    {
        cout << "NICE" << endl;
        return;
    }
    cout << "UGLY" << endl;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t, n;
    sieve(3000010);
    init_(primes.size() - 1);
    // cout<<primes.size()<<endl;
    // cout<<candis.size()<<endl;
    cin >> t;
    rtf(t){
        process(n);
        // cin>>n;
        // cout<<prev_prime(n-1)<<endl<<next_prime(n+1);
        // cout<<sqrt(n)<<endl;
    }
    return 0;
}
// 10007
//  10009
//  10037
/*
50
1000000016000000063
1000000054000000693
1000000180000008091
1000000200000009991
1000000304000022263
1000000430000046161
1000000512000065311
1000000586000085833
1000000670000112029
1000000766000146289
1000000820000168099
1000000860000184891
1000000886000196233
1000000912000207927
1000000996000247779
1000001110000307449
1000001220000372091
1000001300000422331
1000001464000535383
1000001588000630387
1000001690000713769
1000001762000776061
1000001820000828019
1000001864000868623
1000002004001003923
1000002074001075113
1000002186001194613
1000002298001320057
1000002416001459239
1000002500001562331
1000002542001615437
1000002590001676769
1000002662001771557
1000002722001852221
1000002806001968309
1000002896002096703
1000002992002237991
1000003068002353147
1000003120002433159
1000003238002621157
1000003280002689551
1000003340002788851
1000003458002988541
1000003562003171897
1000003592003225591
1000003622003279657
1000003744003504159
1000003844003694059
1000003920003841591
1000004012004022667
*/
// 1000003
// 1000033
//  1000037