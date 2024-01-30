#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <cmath>
using namespace std;

int T, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        string p;
        cin >> p;
        cin >> N;
        deque<int> d;
        string tmp;
        cin >> tmp;
        for (int j = 0; j < tmp.size(); j++) {
            int k = 0;
            int n = 0;
            while (isdigit(tmp[j + k])) {
                n = n * 10 + (tmp[j + k] - '0');
                k++;
            }
            if (isdigit(tmp[j])) {
                d.push_back(n);
            }
            j += k;
        }
        int err = 0;
        bool f = 0;
        for (int j = 0; j < p.size(); j++) {
            if (p[j] == 'R') {
                if (f == 0) f = 1;
                else f = 0;
            } else {
                if (d.empty()) {
                    cout << "error\n";
                    err = 1;
                    break ;
                } else if (!f) {
                    d.pop_front();
                } else {
                    d.pop_back();
                }
            }
        }
        if (!err) {
            cout << "[";
            while (!d.empty()) {
                if (!f) {
                    cout << d.front();
                    if (d.size() != 1)
                        cout << ",";
                    d.pop_front();
                } else {
                    cout << d.back();
                    if (d.size() != 1)
                        cout << ",";
                    d.pop_back();
                }
            }
            cout << "]\n";
        }
    }
    return 0;
}