/*  @JUDGE_ID: 1274804  
    Problem Number: 110106/10033
    Language: C++
    "Interpreter"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;

void setRegister(vector<int> &myRegisters, int location, int value){
    myRegisters[location] = value;
}

void setRam(vector<int> &myRam, int location, int value){
    myRam[location] = value;
}

void getInstructions(vector<int> &myRam){
    string inputLine;
    myRam.clear();
    while(std::getline(std::cin, inputLine, '\n')){
        if(inputLine == "")
            break;
        myRam.push_back(std::stoi(inputLine));
    }
}

int main(){
        unsigned int numOfCases;
        string inputLine;
        std::cin >> numOfCases;
        std::getline(std::cin, inputLine, '\n');
        std::getline(std::cin, inputLine, '\n');

        for(int i = 0; i < numOfCases; i++){
            vector<int> myRam;
            vector<int> myRegisters(10, 0);
            getInstructions(myRam);

            unsigned int commandExecutionCounter = 0;
            unsigned int currentRamInstruction = 0;
            bool haltFlag = false;

            while(!haltFlag){
                int command = myRam[currentRamInstruction] / 100;
                int paramter1 = myRam[currentRamInstruction] % 100 / 10;
                int paramter2 = myRam[currentRamInstruction] % 10;

                switch(command){
                    case 1:
                        if(paramter1 == paramter2 && paramter1 == 0)
                            haltFlag = true;
                        break;
                    case 2:
                        setRegister(myRegisters, paramter1, paramter2);
                        commandExecutionCounter++;
                        break;
                    case 3:
                        setRegister(myRegisters, paramter1, (myRegisters[paramter1] + paramter2) % 1000);
                        commandExecutionCounter++;
                        break;
                    case 4:
                        setRegister(myRegisters, paramter1, (myRegisters[paramter1] * paramter2) % 1000);
                        commandExecutionCounter++;
                        break;
                    case 5:
                        setRegister(myRegisters, paramter1, myRegisters[paramter2]);
                        commandExecutionCounter++;
                        break;
                    case 6:
                        setRegister(myRegisters, paramter1, (myRegisters[paramter1] + myRegisters[paramter2]) % 1000);
                        commandExecutionCounter++;
                        break;
                    case 7:
                        setRegister(myRegisters, paramter1, (myRegisters[paramter1] * myRegisters[paramter2]) % 1000);
                        commandExecutionCounter++;
                        break;
                    case 8:
                        setRegister(myRegisters, paramter1, myRam[myRegisters[paramter2]]);
                        commandExecutionCounter++;
                        break;
                    case 9:
                        setRam(myRam, myRegisters[paramter2], myRegisters[paramter1]);
                        commandExecutionCounter++;
                        break;
                    case 0:
                        if(myRegisters[paramter2] != 0)
                            currentRamInstruction = myRegisters[paramter1]-1;
                        else
                            commandExecutionCounter++;
                        break;
                    default:
                        break;
                }
                currentRamInstruction++;
            }
            std::cout << commandExecutionCounter % 1000 << '\n';
        }
}

/* @END_OF_SOURCE_CODE */