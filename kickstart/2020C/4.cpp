//#include "bits/stdc++.h"
//using namespace std;
//using ll = long long;
//
//ll Handle()
//{
//    // input
//    int N, Q; cin >> N >> Q;
//    vector<ll> arr(N);
//    for (int i = 0; i < N; ++i) cin >> arr[i];
//
//    // prefix sum
//    vector<ll> r(N); r[0] = arr[0];
//    vector<ll> m(N); m[0] = arr[0];
//    for (int i = 1; i < N; ++i) {
//        ll curVal = (i & 1 ? -1 : 1) * arr[i];
//        r[i] = r[i-1] + curVal;
//        m[i] = m[i-1] + curVal * (i+1);
//    }
//
////    for (const auto e : r) cout << e << ' '; cout << endl;
////    for (const auto e : m) cout << e << ' '; cout << endl;
////    cout << endl;
//
//    // handle query
//    ll sum = 0;
//    for (int i = 0; i < Q; ++i) {
//        char q; cin >> q;
//        if (q == 'Q') {
//            ll a, b; cin >> a >> b; --a; --b;      // a, b 인덱스 기준, 둘 다 inclusive
//            ll res;
//
//            if (a == 0) {
//                res = m[b];
//            } else {
//                res = m[b] - m[a-1] - (r[b] - r[a-1]) * a;
//            }
//
//            if (a & 1) res *= -1;
//
////            cout << "Q: " << res << endl << endl;
//            sum += res;
//
//        } else if (q == 'U') {
//            ll idx, val;
//            cin >> idx >> val;
////            auto prev = arr[a-1];
////            arr[a-1] = b;
////            for (int i = a; i < N+1; ++i) {
////                r[i] += (b - prev) * (a % 2 == 1 ? 1 : -1);
////                m[i] += (b - prev) * (a % 2 == 1 ? 1 : -1) * a;
////            }
//
//            arr[--idx] = val;
//            r[0] = m[0] = arr[0];
//            for (int i = 1; i < N; ++i) {
//                ll curVal = (i & 1 ? -1 : 1) * arr[i];
//                r[i] = r[i-1] + curVal;
//                m[i] = m[i-1] + curVal * (i+1);
//            }
//
////            for (const auto e : r) cout << e << ' '; cout << endl;
////            for (const auto e : m) cout << e << ' '; cout << endl;
////            cout << endl;
//
//        } else {
//            assert(false);
//        }
//    }
//
//    return sum;
//}
//
//int main()
//{
//    int T; cin >> T;
//    for (int t = 1; t <= T; ++t) {
//        printf("Case #%d: %lld\n", t, Handle());
//    }
//    return 0;
//}


#include "bits/stdc++.h"
using namespace std;
using ll = long long;

ll Handle()
{
    // input
    int N, Q; cin >> N >> Q;
    vector<ll> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    // prefix sum
    vector<ll> r(N+1); r[0] = 0;
    vector<ll> m(N+1); m[0] = 0;
    for (int i = 0; i < N; ++i) {
        r[i+1] = r[i] + (i % 2 == 0 ? 1 : -1) * arr[i];
        m[i+1] = m[i] + (i % 2 == 0 ? 1 : -1) * (i+1) * arr[i];
    }

//    for (const auto e : r) cout << e << ' '; cout << endl;
//    for (const auto e : m) cout << e << ' '; cout << endl;
//    cout << endl;

    // handle query
    ll sum = 0;
    for (int i = 0; i < Q; ++i) {
        char q; int a, b; cin >> q >> a >> b;
        if (q == 'Q') {
            ll res = m[b] - m[a-1] - (r[b] - r[a-1]) * (a-1);
            res *= (a % 2 == 0 ? -1 : 1);
//            cout << "Q: " << res << endl << endl;
            sum += res;

        } else if (q == 'U') {
            ll prev = arr[a-1];
            arr[a-1] = b;
            for (int i = a; i < N+1; ++i) {
                r[i] += (b - prev) * (a % 2 == 1 ? 1 : -1);
                m[i] += (b - prev) * (a % 2 == 1 ? 1 : -1) * a;
            }

//            for (const auto e : r) cout << e << ' '; cout << endl;
//            for (const auto e : m) cout << e << ' '; cout << endl;
//            cout << endl;

        } else {
            assert(false);
        }
    }

    return sum;
}

int main()
{
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: %lld\n", t, Handle());
    }
    return 0;
}

