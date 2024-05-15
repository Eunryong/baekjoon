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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        int x, y, z;
        cin >> x >> y >> z;
        if (!x && !y && !z) break;
        if (x + y <= z || y + z <= x || x + z <= y) cout << "Invalid\n";
        else if (x == y && y == z) cout << "Equilateral\n";
        else if (x != y && y != z && x != z) cout << "Scalene\n";
        else cout << "Isosceles\n";
    }

    return 0;
}