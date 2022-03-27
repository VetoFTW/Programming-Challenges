/*  @JUDGE_ID: 1274804  
    Problem Number: 110108/10142
    Language: C++
    "Australian Voting"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

struct Candidate{
    string name;
    int votes;
    bool isEliminated;
};

Candidate makeCandidate(string name, int Votes, bool isEliminated){
    Candidate myCandidate = {name, Votes, isEliminated};
    return myCandidate;
}

vector<int> ballotsToListInt(string &original){
    vector<int> list;
    string numberAssembler = "";
    for(int i = 0; i < original.size(); i++){
        if(original[i] != ' ')
            numberAssembler += original[i];
        else{
            list.push_back(std::stoi(numberAssembler));
            numberAssembler = "";
        }
    }
    list.push_back(std::stoi(numberAssembler));
    return list;
}

void removeCandidate(vector<vector<int>> &ballots, int loser){
    for(int i = 0; i < ballots.size(); i++)
        for(int j = 0; j < ballots[i].size(); j++)
            if(ballots[i][j] == loser)
                ballots[i].erase(ballots[i].begin()+j);
}

void tallyVotes(vector<Candidate> &candidates, vector<vector<int>> &ballots){
    for(int i = 0; i < ballots.size(); i++)
        candidates[ballots[i][0]-1].votes++;
}

bool isVictor(vector<Candidate> &candidates, int minNeeded){
    for(int i = 0; i < candidates.size(); i++){
        if(candidates[i].isEliminated == false)
            continue;
        if(candidates[i].votes > minNeeded)
            return true;
    }
    return false;
}

bool isTie(vector<Candidate> &candidates){
    int newHigh = -1;
    for(int i = 0; i < candidates.size(); i++){
        if(candidates[i].isEliminated == true)
            continue;
        if(newHigh == -1)
            newHigh = candidates[i].votes;
        else
            if(newHigh != candidates[i].votes)
                return false;
    }
    return true;
}

void eliminationRound(vector<Candidate> &candidates, vector<vector<int>> &ballots){
    int losingNumOfBallots = 1000;
    for(int i = 0; i < candidates.size(); i++)
        if(candidates[i].isEliminated == false)
            if(candidates[i].votes < losingNumOfBallots)
                losingNumOfBallots = candidates[i].votes;
    for(int i = 0; i < candidates.size(); i++)
        if(candidates[i].isEliminated == false)
            if(candidates[i].votes == losingNumOfBallots){
                candidates[i].isEliminated = true;
                removeCandidate(ballots, i+1);
            }
    for(int i = 0; i < candidates.size(); i++)
        candidates[i].votes = 0;
}

void printVictors(vector<Candidate> &candidates, vector<vector<int>> &listOfBallots){
    int minimumNeeded = listOfBallots.size() / 2;
    
    tallyVotes(candidates, listOfBallots);

    while(!isVictor(candidates, minimumNeeded) && !isTie(candidates)){
        eliminationRound(candidates, listOfBallots);
        tallyVotes(candidates, listOfBallots);
    }
    for(int i = 0; i < candidates.size(); i++)
        if(candidates[i].isEliminated == false)
            std::cout << candidates[i].name << '\n';
}

int main(){

    unsigned int numOfCases;
    string inputLine;
    std::cin >> numOfCases;
    getline(std::cin, inputLine, '\n');
    getline(std::cin, inputLine, '\n');

    for(int i = 0; i < numOfCases; i++){
        vector<string> listOfCandidates;
        vector<string> listOfBallotsString;
        vector<vector<int>> listOfBallotsInt;
        vector<Candidate> candidates;

        unsigned int numOfCandidates;
        getline(std::cin, inputLine, '\n');
        numOfCandidates = std::stoi(inputLine);

        for(int j = 0; j < numOfCandidates; j++){
            getline(std::cin, inputLine, '\n');
            listOfCandidates.push_back(inputLine);
        }
        for(int j = 0; j < listOfCandidates.size(); j++)
            candidates.push_back(makeCandidate(listOfCandidates[j], 0, false));

        while(getline(std::cin, inputLine, '\n'), inputLine != "")
            listOfBallotsString.push_back(inputLine);

        for(int j = 0; j < listOfBallotsString.size(); j++)
            listOfBallotsInt.push_back(ballotsToListInt(listOfBallotsString[j]));

        printVictors(candidates, listOfBallotsInt);
        
        if(i != numOfCases-1)
            std::cout << '\n';
    }
}

/* @END_OF_SOURCE_CODE */