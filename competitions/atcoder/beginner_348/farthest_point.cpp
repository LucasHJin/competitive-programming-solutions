#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long long int> VLL;
typedef long long int ll;
typedef long double ld;

int main()
{
    int n;
    double max = 0.0;
    cin >> n;
    vector<vector<double>> points;
    vector<int> answer;
    for (int i=0; i < n; i++) {
        answer.push_back(0);
    }

    for (int i = 0; i < n; i++)
    {
        vector<double> temp;
        double x, y;
        cin >> x >> y;
        temp.push_back(x);
        temp.push_back(y);
        points.push_back(temp);
    }

    for (int k = 0; k < n; k++)
    {
        for (int j = 0; j < n; j++)
        {
            if (k!=j) {
                double inside = (points[k][0] - points[j][0]) * (points[k][0] - points[j][0]) + (points[k][1] - points[j][1]) * (points[k][1] - points[j][1]);
                double distance = sqrt(inside);
                //cout << k << " " << j << " " << distance << endl;
                if (distance > max)
                {
                    max = distance;
                    answer[k] = j+1;
                }
                else if (distance == max)
                {
                    if (answer[k] > j+1)
                    {
                        answer[k] = j+1;
                    }
                }
                //cout << "AAAAAA" << endl;
            }
        }
        max = 0.0;
    }
    for (auto it : answer)
    {
        cout << it << endl;
    }
}