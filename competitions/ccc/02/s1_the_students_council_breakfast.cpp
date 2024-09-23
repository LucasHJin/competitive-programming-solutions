#include <bits/stdc++.h>
#include <iostream>
#include <queue>
 
typedef long long ll;
 
using namespace std;


int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    int p, g, r, o;
    cin >> p >> g >> r >> o;
    int goal;
    cin >> goal;

    int valid = 0;
    int min_tickets = 10000000;

    for (int pink=0; pink<=goal/p; pink++) {
        for (int green=0; green<=goal/g; green++) {
            for (int red=0; red<=goal/r; red++) {
                for (int orange=0; orange<=goal/o; orange++) {
                    int totalAmount=pink * p + green * g + red * r + orange * o;
                    
                    if (totalAmount==goal) {
                        valid++;
                        int numTickets = pink + green + red + orange;
                        min_tickets = min(min_tickets, numTickets);

                        cout << "# of PINK is " << pink << " # of GREEN is " << green << " # of RED is " << red << " # of ORANGE is " << orange << endl;
                    }
                }
            }
        }
    }

    cout << "Total combinations is " << valid << "." << endl;
    cout << "Minimum number of tickets to print is " << min_tickets << "." << endl;


    return 0;
}

