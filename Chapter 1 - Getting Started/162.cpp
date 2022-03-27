/*  @JUDGE_ID: 1274804  
    Problem Number: 110102/10189
    Language: C++
    "Minesweeper"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <string>

using std::string;

int main(){

    int rows,
        cols,
        fieldTracker = 0;
    
    while(std::cin >> rows >> cols){

        if(rows == 0 && cols == 0)
            break;

        fieldTracker++;
        if(fieldTracker != 1){
            std::cout << '\n';
        }
        rows += 2;
        cols += 2;
        char minesMap[rows][cols];  

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(i == 0 | j == 0 | i == rows-1 | j == cols-1){
                    minesMap[i][j] = '-';
                    continue;
                }
                char temp;
                std::cin >> temp;
                minesMap[i][j] = temp;
            }
        }
    
        std::cout << "Field #" << fieldTracker << ":" << std::endl;
    
        for(int i = 1; i < rows - 1; i++){
            for(int j = 1; j < cols - 1; j++){
                if(minesMap[i][j] == '*'){
                    std::cout << '*';
                }
                else{
                    int surroundMines = 0;
                    for(int k = -1; k <= 1; k++){
                        for(int l = -1; l <= 1; l++){
                            if(minesMap[i + k][j + l] == '*')
                                surroundMines++;
                        }   
                    }
                    std::cout << surroundMines;
                }                
            }
            std::cout << '\n';
        }
    }
    return 0;
}

/* @END_OF_SOURCE_CODE */