#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long long int> VLL;
typedef long long int ll;
typedef long double ld;

int main() {
    string input, result;
    cin >> input;
    map<char, int> alph;
    int oddCount = 0;
    int leftIndex = 0, rightIndex = input.size() - 1;
    result.append(input.size(), ' '); 

    for (char c : input) {
        alph[c]=alph[c]+1;
    }

    for (auto num : alph) {
        if (num.second%2==1) { //odd
            oddCount++;
            if (oddCount > 1)
                break; 
            //middle char
            result[input.size() / 2] = num.first;
            num.second--;
        }
        while (num.second) { //2 pointers
            result[leftIndex] = num.first;
            result[rightIndex] = num.first;
            leftIndex++;
            rightIndex--;
            num.second -= 2; 
        }
    }

    //output
    if (oddCount>1) {
        cout << "NO SOLUTION" << endl;
    }
    else {
        cout << result << endl;
    }
    return 0;
}
