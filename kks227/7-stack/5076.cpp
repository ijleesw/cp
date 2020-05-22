//
// XXX: WA
//
#include "bits/stdc++.h"
using namespace std;

bool isLegal(const string& html) {
    stack<string> ss;
    bool legal = true;
    int cur = 0;

    while (cur < html.size()) {
        if (html[cur] != '<') {
            ++cur;
            break;
        }
        // now cur == '<'

        int r = cur+1;
        while (r < html.size() && html[r] != '>') ++r;
        if (r == html.size()) {
            legal = false;
            break;
        }
        // now r == '>'

        string tag = html.substr(cur+1, r-cur-1);
        cur = r+1;

        int tag_sz = tag.size();

        if (tag_sz == 0) {
            legal = false;
            break;
        }

        if (tag[0] != '/') {        // start tag or single tag
            if (tag_sz < 2 || tag[tag_sz-2] != ' ' || tag[tag_sz-1] != '/')  {  // start tag
                ss.push(tag);
            }
        } else {        // end tag
            tag = tag.substr(1);

            if (ss.top() == tag) {
                ss.pop();
            } else {
                legal = false;
                break;
            }
        }
    }

    return ss.empty() && legal;
}

int main() {
    while (true) {
        string html; getline(cin, html);
        if (html == "#") break;

        if (isLegal(html)) cout << "legal" << endl;
        else cout << "illegal" << endl;
    }

    return 0;
}