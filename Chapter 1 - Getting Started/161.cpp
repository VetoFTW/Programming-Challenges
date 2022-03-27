/*  @JUDGE_ID: 1274804
    Problem Number: 110101/100
    Language: C++
    "The 3n + 1 Problem"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>

int numOfCycles(int num){
    
    int numOfCycles = 0;

    if(num != 1){
        if (num % 2 == 0)
            num /= 2;
        else
            num = num * 3 + 1;
        numOfCycles++;
    }

    return numOfCycles + 1;
}

int main(){

    int firstInput,
        secondInput;
        
    while (std::cin >> firstInput >> secondInput){
        int maximumRunCycles = 0;

        for (int i = firstInput < secondInput ? firstInput : secondInput; i <= firstInput < secondInput ? secondInput : firstInput; i++){
            int myNumOfCycles = numOfCycles(i);
            maximumRunCycles = maximumRunCycles < myNumOfCycles ? myNumOfCycles : maximumRunCycles;
        }
        std::cout << firstInput << " " << secondInput << " " << maximumRunCycles << std::endl;
    }
    return 0;
}

/* @END_OF_SOURCE_CODE */