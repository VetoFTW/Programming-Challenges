/*  @JUDGE_ID: 1274804  
    Problem Number: 110105/10267
    Language: C++
    "Graphical Editor"
*/

/* @BEGIN_OF_SOURCE_CODE */

#include <iostream>
#include <vector>
#include <string>
using std::vector;
using std::string;
using std::cin;
using std::cout;

void swap(int &a, int &b){
    if(a > b){
        int c = b;
        b = a;
        a = c;
    }
}

void createImage(vector<vector<char>> &canvas){
    int M, N;
    cin >> M >> N;    
    canvas.clear();
    for(int i = 0; i < N; i++)
        canvas.push_back(vector<char>(M, 'O'));
}

void clearImage(vector<vector<char>> &canvas){
    for(int i = 0; i < canvas.size(); i++)
        for(int j = 0; j < canvas[i].size(); j++)
            canvas[i][j] = 'O';
}

void colorPixel(vector<vector<char>> &canvas){
    int x, y;
    char c;
    cin >> x >> y >> c;
    canvas[y-1][x-1] = c;
}

void drawVerticalSegment(vector<vector<char>> &canvas){
    int x, y1, y2;
    char c;
    cin >> x >> y1 >> y2 >> c;
    swap(y1, y2);
    for(int i = y1; i <= y2; i++)
        canvas[i-1][x-1] = c;
}

void drawHorizontalSegment(vector<vector<char>> &canvas){
    int x1, x2, y;
    char c;
    cin >> x1 >> x2 >> y >> c;
    swap(x1, x2);
    for(int i = x1; i <= x2; i++)
        canvas[y-1][i-1] = c;
}

void drawRectangle(vector<vector<char>> &canvas){
    int x1, y1, x2, y2;
    char c;
    cin >> x1 >> y1 >> x2 >> y2 >> c;
    swap(x1, x2);
    swap(y1, y2);
    for(int i = y1; i <= y2; i++)
        for(int j = x1; j <= x2; j++)
            canvas[i-1][j-1] = c;
}

void fill(vector<vector<char>> &canvas, int x, int y, char newColor, char oldColor){
    canvas[y][x] = newColor;

    if(0 <= y-1 && canvas[y-1][x] == oldColor)
        fill(canvas, x, y-1, newColor, oldColor);
    if(y+1 < canvas.size() && canvas[y+1][x] == oldColor)
        fill(canvas, x, y+1, newColor, oldColor);
    if(0 <= x-1 && canvas[y][x-1] == oldColor)
        fill(canvas, x-1, y, newColor, oldColor);
    if(x+1 < canvas[y].size() && canvas[y][x+1] == oldColor)
        fill(canvas, x+1, y, newColor, oldColor);

}

void fillRegion(vector<vector<char>> &canvas){
    int x, y;
    char oldColor, newColor;
    cin >> x >> y >> newColor;
    oldColor = canvas[y-1][x-1];
    if(oldColor != newColor)
        fill(canvas, x-1, y-1, newColor, oldColor);
}

void printCanvas(vector<vector<char>> &canvas){
    string fileName;
    cin >> fileName;
    cout << fileName << '\n';
    for(int i = 0; i < canvas.size(); i++){
        for(int j = 0; j < canvas[i].size(); j++)
            cout << canvas[i][j];
        cout << '\n';
    }
}
int main(){
    char operation;
    vector<vector<char>> canvas;
    while(cin >> operation){
        switch (operation){
        case 'X':
            return 0;
            break;
        case 'I':
            createImage(canvas);
            break;
        case 'C':
            clearImage(canvas);
            break;
        case 'L':
            colorPixel(canvas);
            break;
        case 'V':
            drawVerticalSegment(canvas);
            break;
        case 'H':
            drawHorizontalSegment(canvas);
            break;
        case 'K':
            drawRectangle(canvas);
            break;
        case 'F':
            fillRegion(canvas);
            break;
        case 'S':
            printCanvas(canvas);
            break;
        default:
            break;
        }
    }
}

/* @END_OF_SOURCE_CODE */