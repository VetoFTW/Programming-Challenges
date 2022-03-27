/*  @JUDGE_ID: 1274804  
    Problem Number: 110107/10196
    Language: C++
    "Check the Check"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <vector>
#include <string>
using std::string;
using std::vector;

struct Point{
    int xCoord;
    int yCoord;
};

Point makePoint(int x, int y){
    Point myPoint = {x, y};
    return myPoint;
}

bool isValidPoint(Point point){
    if((0 <= point.xCoord && point.xCoord < 8) &&
        (0 <= point.yCoord && point.yCoord < 8))
        return true;
    return false;
}

void setBoard(vector<string> &board){
    string line;
    board.clear();
    while(std::getline(std::cin, line, '\n')){
        if(line == "")
            break;
        board.push_back(line);
    }
}

bool isDone(vector<string> &board){
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[i].size(); j++)
            if(board[i][j] != '.')
                return false;
    return true;
}

void getLocationOfKings(vector<string> &board, Point kingLocations[]){
    for(int i = 0; i < board.size(); i++)
        for(int j = 0; j < board[i].size(); j++){
            if(board[i][j] == 'K')
                kingLocations[0] = makePoint(j, i);
            if(board[i][j] == 'k')
                kingLocations[1] = makePoint(j,i);
        }
}

bool checkByPawn(vector<string> &board, bool isWhite, Point kingPoint){
    int x1 = kingPoint.xCoord - 1;
    int x2 = kingPoint.xCoord + 1;
    int y = kingPoint.yCoord + (isWhite ? -1 : 1);
    if(isValidPoint(makePoint(x1, y)) && board[y][x1] == (isWhite ? 'p' : 'P'))
        return true;
    if(isValidPoint(makePoint(x2, y)) && board[y][x2] == (isWhite ? 'p' : 'P'))
        return true;
    return false;
}

bool checkByKnight(vector<string> &board, bool isWhite, Point kingPoint){
    Point possiblePoints[8] = {
        makePoint(kingPoint.xCoord-2, kingPoint.yCoord-1),
        makePoint(kingPoint.xCoord-1, kingPoint.yCoord-2),
        makePoint(kingPoint.xCoord+1, kingPoint.yCoord-2),
        makePoint(kingPoint.xCoord+2, kingPoint.yCoord-1),
        makePoint(kingPoint.xCoord-2, kingPoint.yCoord+1),
        makePoint(kingPoint.xCoord-1, kingPoint.yCoord+2),
        makePoint(kingPoint.xCoord+1, kingPoint.yCoord+2),
        makePoint(kingPoint.xCoord+2, kingPoint.yCoord+1)
    };

    for(int i = 0; i < 8; i++){
        if((isValidPoint(possiblePoints[i])) &&
           (board[possiblePoints[i].yCoord][possiblePoints[i].xCoord] == (isWhite ? 'n' : 'N')))
                return true;
    }
    return false;
}

bool checkVertically(vector<string> &board, Point point, char opponent){
    for(int i = point.yCoord-1; i >= 0; i--){
        if(board[i][point.xCoord] == '.')
            continue;
        else if(board[i][point.xCoord] == opponent)
            return true;
        else
            break;
    }
    for(int i = point.yCoord+1; i < 8; i++){
        if(board[i][point.xCoord] == '.')
            continue;
        else if(board[i][point.xCoord] == opponent)
            return true;
        else
            break;
    }
    return false;
}

bool checkHorizontally(vector<string> &board, Point point, char opponent){
    for(int i = point.xCoord-1; i >= 0; i--){
        if(board[point.yCoord][i] == '.')
            continue;
        else if(board[point.yCoord][i] == opponent)
            return true;
        else
            break;
    }
    for(int i = point.xCoord+1; i < 8; i++){
        if(board[point.yCoord][i] == '.')
            continue;
        else if(board[point.yCoord][i] == opponent)
            return true;
        else
            break;
    }
    return false;
}

bool checkDiagnally(vector<string> &board, Point point, char opponent){
    for(int i = 1; i <= 8; i++){    // Bottom Right
        if(point.xCoord + i < 8 && point.yCoord + i < 8){
            if(board[point.yCoord+i][point.xCoord+i] == '.')
                continue;
            else if(board[point.yCoord+i][point.xCoord+i] == opponent)
                return true;
            else
                break;
        }
    }
    for(int i = 1; i <= 8; i++){    // Bottom Left
        if(point.xCoord - i >= 0 && point.yCoord + i < 8){
            if(board[point.yCoord+i][point.xCoord-i] == '.')
                continue;
            else if(board[point.yCoord+i][point.xCoord-i] == opponent)
                return true;
            else
                break;
        }
    }
    for(int i = 1; i <= 8; i++){    // Top Left
        if(point.xCoord - i >= 0 && point.yCoord - i >= 0){
            if(board[point.yCoord-i][point.xCoord-i] == '.')
                continue;
            else if(board[point.yCoord-i][point.xCoord-i] == opponent)
                return true;
            else
                break;
        }
    }
    for(int i = 1; i <= 8; i++){    // Top right
        if(point.xCoord + i < 8 && point.yCoord - i >= 0){
            if(board[point.yCoord-i][point.xCoord+i] == '.')
                continue;
            else if(board[point.yCoord-i][point.xCoord+i] == opponent)
                return true;
            else
                break;
        }
    }
    return false;
}

bool checkByRook(vector<string> &board, bool isWhite, Point kingPoint){
    return (checkVertically(board, kingPoint, (isWhite ? 'r' : 'R')) || checkHorizontally(board, kingPoint, (isWhite ? 'r' : 'R')));
}

bool checkByBishop(vector<string> &board, bool isWhite, Point kingPoint){
    return (checkDiagnally(board, kingPoint, (isWhite ? 'b' : 'B')));
}

bool checkByQueen(vector<string> &board, bool isWhite, Point kingPoint){
    return ((checkVertically(board, kingPoint, (isWhite ? 'q' : 'Q'))) ||
            (checkHorizontally(board, kingPoint, (isWhite ? 'q' : 'Q'))) ||
            (checkDiagnally(board, kingPoint, (isWhite ? 'q' : 'Q'))));
}

bool isCheck(vector<string> &board, bool isWhite, Point kingPoint){
    return (checkByPawn(board, isWhite, kingPoint) ||
            checkByKnight(board, isWhite, kingPoint) ||
            checkByRook(board, isWhite, kingPoint) ||
            checkByBishop(board, isWhite, kingPoint) ||
            checkByQueen(board, isWhite, kingPoint));
}

int checkForCheck(vector<string> &board){
    Point locationOfKings[2];
    getLocationOfKings(board, locationOfKings);
    
    if(isCheck(board, true, locationOfKings[0]))
        return 1;
    if(isCheck(board, false, locationOfKings[1]))
        return 2;
    return 0;
}

int main(){
    vector<string> myChessBoard;
    unsigned int counter = 0;
    bool isRunning = true;
    while(isRunning){
        setBoard(myChessBoard);
        if(isDone(myChessBoard))
            break;
        counter++;

        unsigned int winner = checkForCheck(myChessBoard);

        std::cout << "Game #" << counter << ": ";
        if(winner == 0)
            std::cout << "no king is in check." << '\n';
        else if(winner == 1)
            std::cout << "white king is in check." << '\n';
        else if(winner == 2)
            std::cout << "black king is in check." << '\n';
    }
}

/* @END_OF_SOURCE_CODE */