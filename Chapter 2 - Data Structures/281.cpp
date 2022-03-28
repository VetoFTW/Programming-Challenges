/*  @JUDGE_ID: 1274804  
    Problem Number: 110201/10038
    Language: C++
    "Jolly Jumpers"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <vector>
using std::vector;

bool isJumper(vector<int> sequence){
    vector<int> alreadyFound;
    for(unsigned int i = 0; i < sequence.size()-1; i++){
        unsigned int absDiff = abs(sequence[i]-sequence[i+1]);
        if(absDiff == 0 || absDiff > sequence.size()-1)
            return false;
        for(unsigned int j = 0; j < alreadyFound.size(); j++)
            if(alreadyFound[j] == absDiff)
                return false;
        alreadyFound.push_back(absDiff);
    }
    return true;
}

int main(){
    int lengthOfSequence;
    while(std::cin >> lengthOfSequence){
        vector<int> sequence;
        int input;
        for(unsigned int i = 0; i < lengthOfSequence; i++){
            std::cin >> input;
            sequence.push_back(input);
        }
        if(isJumper(sequence))
            std::cout << "Jolly" << '\n';
        else    
            std::cout << "Not jolly" << '\n';
    }    
}

/* @END_OF_SOURCE_CODE */