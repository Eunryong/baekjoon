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
int T;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int i = 0; i < T; i++) {
        int p, m;
        cin >> p >> m;
        int a = 1;
        int b = 1;
        long long s = 1;
        while (1) {
            int tmp = (a + b) % m;
            a = b;
            b = tmp;
            s++;
            if (a == 0 && b == 1) {
                cout << i + 1 << " " << s << "\n";
                break;
            }
        }
    }
    return 0;
}