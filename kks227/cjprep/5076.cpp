#include "bits/stdc++.h"
using namespace std;

bool parse(vector<string_view>* res, const string_view& line)
{
    int l = 0;
    while (l < line.size()) {
        if (line[l] != '<') {
            ++l;
            continue;
        }

        auto r = l + 1;
        while (r < line.size() && line[r] != '>') {
            ++r;
        }
        if (r == line.size() || r - l == 1) {
            return false;
        }

        res->push_back(line.substr(l, r - l + 1));
        //cout << res->back() << endl;
        ++l;
    }

    return true;
}

bool is_standalone(const string_view& tag)
{
    return tag.size() >= 4 && tag[tag.size() - 2] == '/';
}

bool is_opening(const string_view& tag)
{
    return tag.size() >= 3 && tag[1] != '/';
}

string_view get_keyword(const string_view& tag)
{
    int l = 1;
    while (l < tag.size() && !isalpha(tag[l])) {
        ++l;
    }
    int r = l;
    while (r < tag.size() && isalpha(tag[r])) {
        ++r;
    }
    return tag.substr(l, r - l);
}

bool is_valid(const string_view& line) {
    vector<string_view> tagVec;
    if (!parse(&tagVec, line)) {
        return false;
    }

    stack<string_view> tagStack;

    for (const auto& tag : tagVec) {
        const auto keyword = get_keyword(tag);
        if (keyword.empty()) {
            return false;
        }

        if (is_standalone(tag)) {
            //cout << "standalone : " << tag << endl;
            continue;
        }

        if (is_opening(tag)) {
            //cout << "opening : " << tag << endl;
            tagStack.push(keyword);
        } else {
            //cout << "closing : " << tag << endl;
            if (tagStack.empty() || tagStack.top() != keyword) {
                return false;
            }
            tagStack.pop();
        }
    }

    return tagStack.empty();
}

int main()
{
    string line;
    while (getline(cin, line)) {
        if (line == "#") {
            break;
        }
        cout << (is_valid(line) ? "legal" : "illegal") << endl;
    }
    return 0;
}