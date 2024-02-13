#include <iostream>
#include <math.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

//Operation Functions
int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

int multiply(int x, int y){
    return x * y;
}

int divide(int x, int y){
    return x / y;
}

int countOperations(string calculation){
    int numberOfOperations;
    numberOfOperations = std::count(calculation.begin(), calculation.end(), '+');
    numberOfOperations += std::count(calculation.begin(), calculation.end(), '-');
    numberOfOperations += std::count(calculation.begin(), calculation.end(), '*');
    numberOfOperations += std::count(calculation.begin(), calculation.end(), '/');
    return numberOfOperations;
}

int main(){
    while (true){
        cout << "\nEnter your calculation: ";       

        string calculation;
        cin >> calculation;

        int length;
        length = calculation.length();

        char *parray = new char[length];
        parray[length] = '\0';

        //Moves string calculation into an array of characters
        for (int i = 0; i < length; i++){
            parray[i] = calculation[i];
        }

        int numberOfOperations = countOperations(calculation);
        int numberOfNumbers = numberOfOperations + 1;

        int *pnumberArray = new int[numberOfNumbers];


        //Moves all the numbers in the character array into a separate array 
        int k = 0;
        for (int i = 0; i < numberOfNumbers; i++){
            bool boolean = true;
            string tempNumber;
            while (boolean == true){
                if (isdigit(parray[k]) == 1){
                    tempNumber += parray[k];
                    k++;
                }
                else{
                    k++;
                    boolean = false;
                    pnumberArray[i] = stoi(tempNumber);
                    tempNumber = "";
                }
            }
        }       
        
        char *psymbols = new char[numberOfOperations];
        psymbols[numberOfOperations] = '\0';

        //Stores all operatives into their own array
        int j = 0;
        for (int i = 0; i < length; i++){
            if (parray[i] == '*'){
                psymbols[j] = '*';
                // cout << "test (*)";
                // cout << psymbols[j];
                j++;
            }
            else if (parray[i] == '/'){
                psymbols[j] = '/';
                // cout << "test (/)";
                // cout << psymbols[j];
                j++;
            }
            else if (parray[i] == '+'){
                psymbols[j] = '+';
                // cout << "test (+)";
                // cout << psymbols[j];
                j++;
            }
            else if (parray[i] == '-'){
                psymbols[j] = '-';
                // cout << "test (-)";
                // cout << psymbols[j];
                j++;
            }
        }

        char *pBIDMASOrder = new char[numberOfOperations];
        int counter = 0;

        //To put it in bidmas order, ik this is horrible and not good layout at all but it works for the moment - to make nicer later
        for (int i = 0; i < numberOfOperations; i++){
            if (psymbols[i] == '*'){
                pBIDMASOrder[counter] = '*';
                counter++;
            }
        }
        for (int i = 0; i < numberOfOperations; i++){
            if (psymbols[i] == '/'){
                pBIDMASOrder[counter] = '/';
                counter++;
            }
        }
        for (int i = 0; i < numberOfOperations; i++){
            if (psymbols[i] == '+'){
                pBIDMASOrder[counter] = '+';
                counter++;
            }
        }
        for (int i = 0; i < numberOfOperations; i++){
            if (psymbols[i] == '-'){
                pBIDMASOrder[counter] = '-';
                counter++;
            }
        }

        for (int i = 0; i < numberOfOperations; i++){
            cout << pBIDMASOrder[i] << " ";
        }
        cout << '\n';
        for (int i = 0; i < numberOfNumbers; i++){
            cout << pnumberArray[i] << " ";
        }  
    }
    return 0;
}