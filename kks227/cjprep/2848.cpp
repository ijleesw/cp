#include "bits/stdc++.h"
using namespace std;

int main()
{
    int N;
    cin >> N;

    unordered_map<char, vector<char>> graph;
    unordered_map<char, int> indegree;
    unordered_set<char> seen;

    vector<string> words(N);
    for (auto& w : words) {
        cin >> w;
        for_each(begin(w), end(w), [&](auto c) { seen.insert(c); });
    }
    if (N == 1) {
        if (seen.size() == 1) {
            cout << words[0][0] << endl;
        } else {
            cout << "?" << endl;
        }
        return 0;
    }
    for (int i = 1; i < N; ++i) {
        const auto& last = words[i - 1];
        const auto& cur = words[i];
        const int min_sz = min(last.size(), cur.size());
        bool diff = false;
        for (int i = 0; i < min_sz; ++i) {
            if (last[i] != cur[i]) {
                graph[last[i]].push_back(cur[i]);
                ++indegree[cur[i]];
                diff = true;
                break;
            }
        }
        if (!diff && last.size() > cur.size()) {
            puts("!");
            return 0;
        }
    }

    queue<char> q;
    for(const auto c : seen) {
        if (indegree[c] == 0) {
            q.push(c);
        }
    }
    string res;
    bool multiple = false;
    for (int i = 0; i < seen.size(); ++i) {
        if (q.size() >= 2) {
            multiple = true;
        } else if (q.size() == 0) {
            puts("!");
            return 0;
        }
        const auto cur = q.front();
        q.pop();
        res.push_back(cur);
        for (const auto child : graph[cur]) {
            if (--indegree[child] == 0) {
                q.push(child);
            }
        }
    }
    puts(multiple ? "?" : res.c_str());

    return 0;
}
