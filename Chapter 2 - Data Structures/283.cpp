/*	@JUDGE_ID: 1274804
    Problem Number: 110203/10050
    Language: C++
    Hartals
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <vector>
using std::vector;

int main(){
    unsigned int numOfCases;
    std::cin >> numOfCases;

    for(unsigned int i = 0; i < numOfCases; i++){
        unsigned int numofDays, numOfParties;
        std::cin >> numofDays >> numOfParties;

        vector<unsigned int> hartalsPList(numOfParties);
        for(unsigned int j = 0; j < numOfParties; j++)
            std::cin >> hartalsPList[j];

        vector<unsigned int> hartalsDList = hartalsPList;
        unsigned int friday = 6, saturday = 7, currentWeek = 1, daysLost = 0;

        for(unsigned int day = 1; day <= numofDays; day++){
            bool isHartalDay = false;
            for(unsigned int hartal = 0; hartal < hartalsDList.size(); hartal++){
                if(hartalsDList[hartal] != day)
                    continue;
                if(hartalsDList[hartal] != friday && hartalsDList[hartal] != saturday && !isHartalDay){
                    isHartalDay = true;
                    daysLost++;
                }
                hartalsDList[hartal] += hartalsPList[hartal];
            }

            if(day % 7 == 0){
                saturday += 7;
                friday += 7;
            }
        }
        std::cout << daysLost << '\n';
    }
}

/* @END_OF_SOURCE_CODE */