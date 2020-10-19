/******************************************************************************

Davis Van Luven
CS161 Assignment 4
Due Oct 18 2020
Sources: I Googled the general math (after trying/failing several of 
my own approaches) but the code is all mine.

*******************************************************************************/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//I didn't want to make a mess of variable variants so I skipped ahead
//a little and made a couple of functions in order to use the same 
//algebraic variables in scope of seperate functions
double traditionalRatioCalc(double diag) {
    
    double x=0, width, height, diagSquared, area;
    
    //I cut out all of the original algebra until I found the sweet spot
    //number 25 for this one...
    diagSquared = pow(diag,2.0); //square the diagonal
    x = diagSquared/25; //divide by 16x^2+9x^2 aka 25
    x = sqrt(x); //take the square root 
    width = x*4; //multiply by the side of the ratio
    height = x*3;
    area = width * height; //multiply for area
    
    cout << fixed << setprecision(2) << "Traditional: Width: " << width << ", Height: " 
    << height << ", Area: " << area << endl;
}

double lcdRatioCalc(double diag) {
    
    double x=0, width, height, diagSquared, area;
    
    //...and 337 for this one
    diagSquared = pow(diag,2.0); 
    x = diagSquared/337;
    x = sqrt(x);
    width = x*16;
    height = x*9;
    area = width * height;
    
    cout << fixed << setprecision(2) << "LCD: Width: " << width << ", Height: " 
    << height << ", Area: " << area << endl;
}

int main()
{
    int type;
    double diagonalLength;
    
    cout << "Enter the diagonal length of the TV screen: " << endl;
    cin >> diagonalLength;
    
    cout << "Enter which type of TV screen: " << endl 
    << "    1. Traditional TV 4:3 aspect ratio" << endl
    << "    2. LCD TV 16:9 aspect ratio" << endl
    << "    3. Both types of TV (4:3 and 16:9)" << endl;
    cin >> type;
    
    if (type == 1) {
        traditionalRatioCalc(diagonalLength);
    } else if (type == 2) {
        lcdRatioCalc(diagonalLength);
    } else if (type == 3) {
        traditionalRatioCalc(diagonalLength);
        lcdRatioCalc(diagonalLength);
    } else {
        cout << "Please type a number between 1 and 3 then press enter. Start again.";
    }
    
    cout << "Goodbye." << endl;


    return 0;
}


