#include "bits/stdc++.h"
using namespace std;
using pii = pair<int, int>;

unordered_map<string, size_t> cache;

// arr sorted
// spse left < right
size_t asFarAsPossible(vector<int>& arr, size_t left, size_t right) {
    //cout << "[asFarAsPossible] arr: " << arr.size() << ", left: " << left << ", right: " << right << endl;
    assert(left < right);

    if (arr.empty()) {
        return right - left;
    }

    const auto half = arr.size() / 2;
    for (int i = arr.size() - 1; i >= half; --i) {
        left = left * 10 + arr[i];
    }
    for (int i = 0; i < half; ++i) {
        right = right * 10 + arr[i];
    }
    return right - left;
}

// arr sorted
size_t asSameAsPossible(vector<int>& arr, size_t left, size_t right, const bool leading_zero) {
    //cout << "[asSameAsPossible] arr: " << arr.size() << ", left: " << left << ", right: " << right << endl;
    assert(left <= right);

    if (arr.empty()) {
        return right - left;
    }

    string cat;
    for (const auto n : arr) {
        cat.push_back('0' + n);
    }
    const auto it = cache.find(cat);
    if (it != end(cache)) {
        return it->second;
    }

    int start = 0;
    if (!leading_zero) {
        while (start < arr.size() && arr[start] == 0) {
            ++start;
        }
        assert(start < arr.size() - 1);
    }
    pii last_pair = {-1, -1};

    size_t res = SIZE_MAX;

    for (int l = start; l < arr.size() - 1; ++l) {
        const int r = l + 1;
        if (last_pair == make_pair(arr[l], arr[r])) {
            continue;
        }
        last_pair = {arr[l], arr[r]};

        vector<int> narr;
        for (int i = 0; i < arr.size(); ++i) {
            if (i != l && i != r) {
                narr.push_back(arr[i]);
            }
        }

        size_t cur_left = left * 10 + arr[l];
        size_t cur_right = right * 10 + arr[r];

        size_t diff;
        if (arr[l] != arr[r]) {
            diff = asFarAsPossible(narr, cur_left, cur_right);
        } else {
            diff = asSameAsPossible(narr, cur_left, cur_right, true);
        }

        if (diff < res) {
            res = diff;
            //cout << "new diff : " << diff << endl;
        }
    }

    return cache[cat] = res;
}

size_t vec2val(const vector<int>& arr) {
    size_t res = 0;
    for (const auto n : arr) {
        res = res * 10 + n;
    }
    return res;
}

size_t solve() {
    cache = unordered_map<string, size_t>{};

    string s;
    cin >> s;
    vector<int> arr;
    for (const auto c : s) {
        arr.push_back(c - '0');
    }
    sort(begin(arr), end(arr));

    if (arr.size() % 2 == 1) {
        const auto short_sz = arr.size() / 2;
        auto n_zeros = count(begin(arr), end(arr), 0);
        arr.resize(remove(begin(arr), end(arr), 0) - begin(arr));

        vector<int> short_arr;
        for (int i = arr.size() - 1; short_arr.size() < short_sz && i > 0; --i) {
            short_arr.push_back(arr[i]);
            arr.pop_back();
        }

        n_zeros -= (short_sz - short_arr.size());
        while (short_arr.size() < short_sz) {
            short_arr.push_back(0);
        }

        vector<int> long_arr;
        long_arr.push_back(arr[0]);
        while (n_zeros--) {
            long_arr.push_back(0);
        }
        for (int i = 1; i < arr.size(); ++i) {
            long_arr.push_back(arr[i]);
        }
        const auto long_val = vec2val(long_arr);
        const auto short_val = vec2val(short_arr);
        //cout << long_val << ", " << short_val << endl;
        return long_val - short_val;

    } else {
        size_t left = 0;
        size_t right = 0;
        size_t res = asSameAsPossible(arr, left, right, false);
        return res;
    }

}

int main()
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": " << solve() << endl;
        //cout << endl;
    }

    return 0;
}

