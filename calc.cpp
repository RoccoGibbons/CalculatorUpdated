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

//A subroutine that counts the number of symbols in the equation, this allows us to find how many times we need to run through the
//Calculation to combine all the numbers
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
                j++;
            }
            else if (parray[i] == '/'){
                psymbols[j] = '/';
                j++;
            }
            else if (parray[i] == '+'){
                psymbols[j] = '+';
                j++;
            }
            else if (parray[i] == '-'){
                psymbols[j] = '-';
                j++;
            }
        }

        char *pBIDMASOrder = new char[numberOfOperations];
        int counter = 0;

        //To put it in bidmas order, ik this is horrible and not good layout at all but it works for the moment - to make nicer later
        //If it aint broken, don't fix it
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

        //Ok, so what have we got so far?
        //We have an array containing all of our numbers inputted
        //We have 2 arrays for symbols -> one with them in the order inputted and the other in the order of BIDMAS

        //What do we need to do?
        //We need to take the ordered symbols and numbers and operate our calculation on them

        //How?
        //New temporary arrays?
        //Pointers?
        //Lets give it a go


        //This will perform the calculations hopefully
        int var = 0;
        for(int i = 0; i < numberOfOperations; i++){
            if(pBIDMASOrder[var] == '+'){
                //add
            }
            else if (pBIDMASOrder[var] == '-'){
                //subtract
            }
            else if (pBIDMASOrder[var] == '*'){
                //multiply
            }
            else if (pBIDMASOrder[var] == '/'){
                //divide
            }
            var++;
        }

    }
    return 0;
}