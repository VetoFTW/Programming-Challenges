/*  @JUDGE_ID: 1274804  
    Problem Number: 110103/10137
    Language: C++
    "The Trip"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <iomanip>

int main() {
    
    int numOfCosts;
    while(std::cin >> numOfCosts, numOfCosts){
        
        int costsList[numOfCosts],
            totalCost = 0;

        for(int i = 0; i < numOfCosts; i++){
            int dollars, cents;
            char temp;
            std::cin >> dollars >> temp >> cents;
            costsList[i] = (dollars * 100) + cents;
            totalCost += costsList[i];
        }

        int lowerAverage = totalCost / numOfCosts,
            higherAverage = lowerAverage + (totalCost % numOfCosts ? 1 : 0),
            minExchangeTaken = 0,
            minExchangeGiven = 0;

        for(int i = 0; i < numOfCosts; i++){
            if(costsList[i] > higherAverage)
                minExchangeTaken += costsList[i] - higherAverage;
            if(costsList[i] < lowerAverage)
                minExchangeGiven += -(costsList[i] - lowerAverage);
        }
        int minExchange =  (minExchangeTaken > minExchangeGiven ? minExchangeTaken : minExchangeGiven);
        std::cout << "$" << minExchange / 100 << '.' << std::setw(2) << std::setfill('0') << minExchange % 100 << std::endl;

    }   

    return 0;
}

/* @END_OF_SOURCE_CODE */