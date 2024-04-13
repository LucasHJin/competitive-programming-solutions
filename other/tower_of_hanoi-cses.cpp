#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;
 
//global variables
int counter=0;
vector<string> steps;

//recursively find
void calc(int n, char src, char dest, char temp) {
    //base case
    if (n == 1) {
        string move = "";
        //change to string + concatenation
        move += src;
        move += " ";
        move += dest;
        steps.push_back(move);
        counter+=1;
        return;
    }
    //move to spare peg -> same problem, just n-1 instead of n
    calc(n - 1, src, temp, dest);
    //move the biggest to 3
    string move = "";
    move += src;
    move += " ";
    move += dest;
    steps.push_back(move);
    counter+=1;
    //move back to original peg -> same problem, just n-1 instead of n
    calc(n - 1, temp, dest, src);
}


int main()
{
    int n;
    cin >> n;
    
    calc(n, '1', '3', '2');

    cout << counter << endl;
    for (auto it: steps) {
        cout << it << endl;
    }
    
    return 0;
}