//***********************************************************
//Davis Van Luven Due 10/25
//CS-161-0-44367 - Computer Science I
//Assignment 5
//Sources: None
//
//***********************************************************


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

//prompt for file path - check
//pull text from file - check
//Return error if file is missing - check
//Print file contents to screen - check
//Close/Reopen File to get back to beginning - check
//Loop while there are values available (!inData.eof) - check
//Assign first three numbers to variables - check
//Calculate - Check
//Output to file - check
//Close file (in and out) - Check
//Comment everything
//Test to see if file can be pulled from onlinegdb


int main ()
{
    
    ifstream inData;
    ofstream outData;
    string filePath, desktopFilePath;
    double a,b,t,sum=0;
    int i;

     //Prompt for file path
	 cout << "Please enter full file path of existing file." << endl;
	 cin >> filePath;
    
    //open file
	inData.open(filePath);
    
    //breaks and returns error
    if(!inData){
            cout << "File not found." << endl
            << "Please try another file path." << endl;
            return 1;
        }
    
    //I noticed that you have to provide a file path or the write goes nowhere
    //I guess there are methods that rep generic file paths accross
    //different OS but this seems like a simpler solution
    cout << "Please enter full file path to your desktop." << endl;
    cin >> desktopFilePath;
   
    
    
    //prime
    inData >> a >> b >> t;

    //Write values to console
    //End of file (.eof) was the key.
	while (!inData.eof( )) {
        
        
        
        cout << "a: " << a << endl
             << "b: " << b << endl
             << "t: " << t << endl << endl;
        
        
         inData >> a >> b >> t;
        
        
        }
    
    //Close/open to reset doc
    inData.close();
    inData.open(filePath);
    
    //breaks and returns error
    if(!inData){
            cout << "File not found." << endl
            << "Please try another file path." << endl;
            return 1;
        }
    
    //Opens outfile using user input file path
    outData.open(desktopFilePath + "/output.txt");
    
    //prime
    inData >> a >> b >> t;
    
    while (!inData.eof( )) {
        
        //Writes A,b, and T to outfile
        outData << a << " minutes to prepare first dish." << endl
             << b << " minutes longer than first dish." << endl
             << t << " minutes to prepare dishes." << endl;
        
        //sums running tally of added values
        for (i=0; sum <= t; i++) {
            a = a + b;
            sum = sum + a;
        
        }
        
        //Writes number of iterations, or dishes in this case
        outData << i << " is the number of dishes." << endl << endl << endl;;
        
        //pulls in the next line of values
         inData >> a >> b >> t;
        
        //resets sum to 0 so it doesnt add previous value
        sum=0;
        
        
    }
    
    //close in and out
    outData.close();
    inData.close();

	return 0;

    



}
