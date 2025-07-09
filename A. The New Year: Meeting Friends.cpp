A. The New Year: Meeting Friends
time limit per test1 second
memory limit per test256 megabytes
There are three friend living on the straight line Ox in Lineland. The first friend lives at the point x1, the second friend lives at the point x2, and the third friend lives at the point x3. They plan to celebrate the New Year together, so they need to meet at one point. What is the minimum total distance they have to travel in order to meet at some point and celebrate the New Year?

It's guaranteed that the optimal answer is always integer.

Input
The first line of the input contains three distinct integers x1, x2 and x3 (1 ≤ x1, x2, x3 ≤ 100) — the coordinates of the houses of the first, the second and the third friends respectively.

Output
Print one integer — the minimum total distance the friends need to travel in order to meet together.

Examples
InputCopy
7 1 4
OutputCopy
6
InputCopy
30 20 10
OutputCopy
20
Note
In the first sample, friends should meet at the point 4. Thus, the first friend has to travel the distance of 3 (from the point 7 to the point 4), the second friend also has to travel the distance of 3 (from the point 1 to the point 4), while the third friend should not go anywhere because he lives at the point 4.

  cpp solution on my given template yesterday


#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int, int>
#define pll pair<long long, long long>

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vi friends(3);
    cin >> friends[0] >> friends[1] >> friends[2];

    sort(friends.begin(), friends.end());

    int totalDistance = (friends[2] - friends[1]) + (friends[1] - friends[0]);

    cout << totalDistance << '\n';

    return 0;
}
