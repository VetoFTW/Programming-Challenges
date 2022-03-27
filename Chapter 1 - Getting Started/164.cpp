/*  @JUDGE_ID: 1274804  
    Problem Number: 110104/706
    Language: C++
    "LDC Display"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <string>
#include <vector>
using std::vector;
using std::string;

int numOfRows,
    numOfCols,
    sizeOfGap = 1;

string drawHorizontalLine(){
    string horizontalLine(::numOfCols, '-');
    horizontalLine[0] = ' ';
    horizontalLine[::numOfCols-1] = ' ';
    return horizontalLine;
}

vector<char> drawVerticalLine(){
    vector<char> verticalLine(::numOfRows, '|');
    verticalLine[0] = ' ';
    verticalLine[::numOfRows - 1] = ' ';
    verticalLine[::numOfRows / 2] = ' ';
    return verticalLine;
}

vector<string> getSpacerCol(){
    vector<string> mySpacer(::numOfRows, string(::sizeOfGap, ' '));
    return mySpacer;
}

vector<string> getZero(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    string horizontalLine = drawHorizontalLine();
    for(int i = 0; i < ::numOfRows; i++){
        myNumber[i][::numOfCols-1] = verticalLine[i];
        myNumber[i][0] = verticalLine[i];
    }
    myNumber[0] = horizontalLine;
    myNumber[::numOfRows-1] = horizontalLine;
    return myNumber;
}

vector<string> getOne(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    for(int i = 0; i < ::numOfRows; i++)
        myNumber[i][::numOfCols-1] = verticalLine[i];
    return myNumber;
}

vector<string> getTwo(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    string horizontalLine = drawHorizontalLine();
    for(int i = 0; i < ::numOfRows/2; i++)
        myNumber[i][::numOfCols-1] = verticalLine[i];
    for(int i = ::numOfRows/2; i < ::numOfRows; i++)
        myNumber[i][0] = verticalLine[i];
    myNumber[0] = horizontalLine;
    myNumber[::numOfRows-1] = horizontalLine;
    myNumber[::numOfRows/2] = horizontalLine;
    return myNumber;
}

vector<string> getThree(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    string horizontalLine = drawHorizontalLine();
    for(int i = 0; i < ::numOfRows; i++)
        myNumber[i][::numOfCols-1] = verticalLine[i];
    myNumber[0] = horizontalLine;
    myNumber[::numOfRows-1] = horizontalLine;
    myNumber[::numOfRows/2] = horizontalLine;
    return myNumber;
}

vector<string> getFive(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    string horizontalLine = drawHorizontalLine();
    for(int i = 0; i < ::numOfRows/2; i++)
        myNumber[i][0] = verticalLine[i];
    for(int i = ::numOfRows/2; i < ::numOfRows; i++)
        myNumber[i][::numOfCols-1] = verticalLine[i];
    myNumber[0] = horizontalLine;
    myNumber[::numOfRows-1] = horizontalLine;
    myNumber[::numOfRows/2] = horizontalLine;
    return myNumber;
}

vector<string> getFour(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    string horizontalLine = drawHorizontalLine();
    for(int i = 0; i < ::numOfRows; i++)
        myNumber[i][::numOfCols-1] = verticalLine[i];
    for(int i = 0; i < ::numOfRows / 2; i++)
        myNumber[i][0] = verticalLine[i];
    myNumber[::numOfRows/2] = horizontalLine;
    return myNumber;
}

vector<string> getSix(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    string horizontalLine = drawHorizontalLine();
    myNumber[0] = horizontalLine;
    for(int i = 0; i < ::numOfRows; i++)
        myNumber[i][0] = verticalLine[i];
    for(int i = ::numOfRows / 2; i < ::numOfRows; i++)
        myNumber[i][::numOfCols-1] = verticalLine[i];
    myNumber[::numOfRows-1] = horizontalLine;
    myNumber[::numOfRows/2] = horizontalLine;
    return myNumber;
}

vector<string> getSeven(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    string horizontalLine = drawHorizontalLine();
    myNumber[0] = horizontalLine;
    for(int i = 0; i < ::numOfRows; i++)
        myNumber[i][::numOfCols-1] = verticalLine[i];
    return myNumber;
}

vector<string> getEight(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    string horizontalLine = drawHorizontalLine();
    for(int i = 0; i < ::numOfRows; i++){
        myNumber[i][::numOfCols-1] = verticalLine[i];
        myNumber[i][0] = verticalLine[i];
    }
    myNumber[0] = horizontalLine;
    myNumber[::numOfRows-1] = horizontalLine;
    myNumber[::numOfRows/2] = horizontalLine;
    return myNumber;
}

vector<string> getNine(){
    vector<string> myNumber(::numOfRows, string(::numOfCols, ' '));
    vector<char> verticalLine = drawVerticalLine();
    string horizontalLine = drawHorizontalLine();
    for(int i = 0; i < ::numOfRows; i++)
        myNumber[i][::numOfCols-1] = verticalLine[i];
    for(int i = 0; i < ::numOfRows / 2; i++)
        myNumber[i][0] = verticalLine[i];
    myNumber[0] = horizontalLine;
    myNumber[::numOfRows/2] = horizontalLine;
    myNumber[::numOfRows-1] = horizontalLine;
    return myNumber;
}

int main() {
    int size;
    while(std::cin >> size, size){
        ::numOfRows = 2*size+3;
        ::numOfCols = size+2;
        vector< vector<string> > myVector;
        string listOfNums;
        std::cin >> listOfNums;
        
        for(int i = 0; i < listOfNums.size(); i++){
            if(listOfNums[i] == '0')
                myVector.push_back(getZero());
            if(listOfNums[i] == '1')
                myVector.push_back(getOne());
            if(listOfNums[i] == '2')
                myVector.push_back(getTwo());
            if(listOfNums[i] == '3')
                myVector.push_back(getThree());
            if(listOfNums[i] == '4')
                myVector.push_back(getFour());
            if(listOfNums[i] == '5')
                myVector.push_back(getFive());
            if(listOfNums[i] == '6')
                myVector.push_back(getSix());
            if(listOfNums[i] == '7')
                myVector.push_back(getSeven());
            if(listOfNums[i] == '8')
                myVector.push_back(getEight());
            if(listOfNums[i] == '9')
                myVector.push_back(getNine());
            if(i != listOfNums.size()-1)
                myVector.push_back(getSpacerCol());
        }

        for(int i = 0; i < numOfRows; i++){
            for(int j = 0; j < myVector.size(); j++)
                std::cout << myVector[j][i];
            std::cout << '\n';
        }
        std::cout << '\n';
    }
    return 0;
}

/* @END_OF_SOURCE_CODE */