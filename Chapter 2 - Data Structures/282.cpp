/*  @JUDGE_ID: 1274804  
    Problem Number: 110202/10315
    Language: C++
    "Poker Hands"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using std::string;
using std::vector;

const unsigned int handSize = 5;

struct Card{
    unsigned int value;
    char suite;
};

bool sortCardComparator(const Card &firstCard, const Card &secondCard){
    return firstCard.value < secondCard.value;
}

struct Player{
    string name;
    vector<Card> hand;
    unsigned int highCard;
    vector<unsigned int> handResults;
};

Card makeCard(char value, char suite){
    unsigned int cardValue;
    switch (value){
        case 'T':
            cardValue = 10;
            break;
        case 'J':
            cardValue = 11;
            break;
        case 'Q':
            cardValue = 12;
            break;
        case 'K':
            cardValue = 13;
            break;
        case 'A':
            cardValue = 14;
            break;
        default:
            cardValue = (unsigned int) value - 48;
            break;
    }
    return Card {cardValue, suite};
}

unsigned int isHighCard(Player &p){
    return p.hand[::handSize-1].value;
}

unsigned int isPair(Player &p){
    for(unsigned int i = ::handSize; i > 0; i--)
        if(p.hand[i].value == p.hand[i-1].value)
            return p.hand[i].value;
    return 0;
}

unsigned int isTwoPair(Player &p){
    unsigned int firstPair = isPair(p);
    if(firstPair == 0) return 0;
    unsigned int secondPair = 0;
    for(unsigned int i = 0; i < p.hand.size()-1; i++)
        if(p.hand[i].value == p.hand[i+1].value && p.hand[i].value != firstPair)
            return p.hand[i].value;
    return 0;
}

unsigned int isThreeOfAkind(Player &p){
    for(unsigned int i = 0; i <= 2; i++)
        if(p.hand[i].value == p.hand[i+1].value && p.hand[i].value == p.hand[i+2].value)
            return p.hand[i].value;
    return 0;
}

unsigned int isStraight(Player &p){
    for(unsigned int i = 0; i < p.hand.size()-1; i++)
        if(p.hand[i].value+1 != p.hand[i+1].value)
            return 0;
    return p.hand[::handSize-1].value;
}

unsigned int isFlush(Player &p){
    for(Card c : p.hand) 
        if(c.suite != p.hand[0].suite)
            return 0;
    return p.hand[::handSize-1].value;
}

unsigned int isFullHouse(Player &p){
    if(isPair(p) == 0) return 0;
    return isThreeOfAkind(p);
}

unsigned int isFourOfAkind(Player &p){ // return 0 if none is found, else return the value of the highest card
    for(unsigned int i = 0; i <= 1; i++)
        if(p.hand[i].value == p.hand[i+1].value && p.hand[i].value == p.hand[i+2].value && p.hand[i].value == p.hand[i+3].value)
            return p.hand[i].value;
    return 0;
}

unsigned int isStraightFlush(Player &p){ // return 0 if none is found, else return the value of the highest card
    if(isFlush(p) == 0)
        return 0;
    return isStraight(p);
}

vector<unsigned int> calculateHand(Player &p){
    std::sort(p.hand.begin(), p.hand.end(), sortCardComparator);
    p.highCard = isHighCard(p);
    vector<unsigned int> handResults;
    handResults.push_back(isStraightFlush(p));
    handResults.push_back(isFourOfAkind(p));
    handResults.push_back(isFullHouse(p));
    handResults.push_back(isFlush(p));
    handResults.push_back(isStraight(p));
    handResults.push_back(isThreeOfAkind(p));
    handResults.push_back(isTwoPair(p));
    handResults.push_back(isPair(p));
    handResults.push_back(isHighCard(p));
    return handResults;
}

unsigned int isTieOrWinner(vector<Card> &set1, vector<Card> &set2){ 
    for(int i = ::handSize-1; i >= 0; i--)
        if(set1[i].value != set2[i].value) 
            return (set1[i].value > set2[i].value ? 1 : 2);
    return 0;
}

void returnWinner(Player &player1, Player &player2){
    unsigned int winner = 0; // 0 tie, 1 player 1, 2 player 2.
    player1.handResults = calculateHand(player1);
    player2.handResults = calculateHand(player2);
    
    for(unsigned int i = 0; i < player1.handResults.size(); i++){
        if(player1.handResults[i] == player2.handResults[i] && player1.handResults[i] == 0)
            continue;
        if(player1.handResults[i] != player2.handResults[i]){
            winner = player1.handResults[i] > player2.handResults[i] ? 1 : 2;
            break;
        }
    }

    if(winner == 0) winner = isTieOrWinner(player1.hand, player2.hand);
    if(winner == 0) std::cout << "Tie." << '\n';
    if(winner == 1) std::cout << player1.name << " wins." << '\n';
    if(winner == 2) std::cout << player2.name << " wins." << '\n';
}

int main(){
    string inputLine;

    while(std::getline(std::cin, inputLine, '\n')){
        Player player1;
        Player player2;
        player1.name = "Black";
        player2.name = "White";

        std::stringstream tableCards(inputLine);
        char suit, value;
        
        while(tableCards >> value >> suit)
            if(player1.hand.size() != ::handSize)  player1.hand.push_back(makeCard(value, suit));
            else                          player2.hand.push_back(makeCard(value, suit));

        returnWinner(player1, player2);
    }    
}

/* @END_OF_SOURCE_CODE */
