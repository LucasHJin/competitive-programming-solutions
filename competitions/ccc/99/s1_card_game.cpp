#include <bits/stdc++.h>
#include <iostream>
 
typedef long long ll;
 
using namespace std;

bool isHighCard(const string &card) {
    return card == "jack" || card == "queen" || card == "king" || card == "ace";
}

int pointsConv(const string &card) {
    if (card == "ace") return 4;
    if (card == "king") return 3;
    if (card == "queen") return 2;
    if (card == "jack") return 1;
    return 0;
}

bool noHigh(const vector<string> &deck, int currentIndex, int k) {
    int deckSize = deck.size();
    for (int i=currentIndex+1; i<currentIndex+1+k && i<deckSize; i++) {
        if (isHighCard(deck[i])) return false;
    }
    return true;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    vector<string> deck;
    string card;

    for (int i=0; i<52; i++) {
        cin >> card;
        deck.push_back(card);
    }

    int playerA_score = 0, playerB_score = 0;
    bool playerA_turn = true; 

    for (int i=0; i<deck.size(); i++) {
        string currentCard = deck[i];
        int points = pointsConv(currentCard);

        if (points > 0) { 
            bool scored = false;

            if (currentCard == "ace" && i+4 < deck.size() && noHigh(deck, i, 4)) {
                scored = true;
            } else if (currentCard == "king" && i+3 < deck.size() && noHigh(deck, i, 3)) {
                scored = true;
            } else if (currentCard == "queen" && i+2 < deck.size() && noHigh(deck, i, 2)) {
                scored = true;
            } else if (currentCard == "jack" && i+1 < deck.size() && noHigh(deck, i, 1)) {
                scored = true;
            }

            if (scored) {
                if (playerA_turn) {
                    cout << "Player A scores " << points << " point(s)." << endl;
                    playerA_score += points;
                } else {
                    cout << "Player B scores " << points << " point(s)." << endl;
                    playerB_score += points;
                }
            }
        }

        playerA_turn = !playerA_turn;
    }

    cout << "Player A: " << playerA_score << " point(s)." << endl;
    cout << "Player B: " << playerB_score << " point(s)." << endl;

    return 0;
}
