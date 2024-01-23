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

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    string s;
    cin >> s;
    long sum = 0;
    int tmp = 1;
    for (int i = 0; i < N; i++) {
        sum += (s[i] - 'a' + 1) * tmp;
        tmp *= 31;
    }
    cout << sum;

    return 0;
}