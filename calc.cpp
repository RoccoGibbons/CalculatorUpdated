#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

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

        double *pnumberArray = new double[numberOfNumbers];


        //Moves all the numbers in the character array into a separate array 
        int k = 0;
        for (int i = 0; i < numberOfNumbers; i++){
            bool boolean = true;
            string tempNumber;
            while (boolean == true){
                if ((isdigit(parray[k]) == 1) | (parray[k] == '.')){
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

        // Stores all operatives into their own array
        int j = 0;
        int numOfBrackets = 0;
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
            else if (parray[i] == '('){
                psymbols[j] = '(';
                numOfBrackets++;
                j++;
            }
            else if (parray[i] == ')'){
                psymbols[j] = ')';
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



        //This will perform the calculations hopefully
        for(int i = 0; i < numberOfOperations; i++){
            int tempIndex; //pass thru function
            if(pBIDMASOrder[i] == '+'){
                //add
                for(int j = 0; j < numberOfOperations; j++){
                    if(psymbols[j] == '+'){
                        tempIndex = j; //where + is in the normal symbols array
                        break;
                    }
                }
                pnumberArray[tempIndex] = pnumberArray[tempIndex] + pnumberArray[tempIndex + 1];
                for(int k = tempIndex+1; k < numberOfNumbers - 1; k++){
                    pnumberArray[k] = pnumberArray[k+1];
                }
                for(int l = tempIndex; l < numberOfOperations - 1; l++){        
                    psymbols[l] = psymbols[l+1];
                }
            }
            else if (pBIDMASOrder[i] == '-'){
                //subtract
                for(int j = 0; j < numberOfOperations; j++){
                    if(psymbols[j] == '-'){
                        tempIndex = j;  
                        break;
                    }
                }
                pnumberArray[tempIndex] = pnumberArray[tempIndex] - pnumberArray[tempIndex + 1];
                for(int k = tempIndex+1; k < numberOfNumbers - 1; k++){
                    pnumberArray[k] = pnumberArray[k+1];
                }                
                for(int l = tempIndex; l < numberOfOperations - 1; l++){
                    psymbols[l] = psymbols[l+1];
                }
            }
            else if (pBIDMASOrder[i] == '*'){
                //multiply
                for(int j = 0; j < numberOfOperations; j++){
                    if(psymbols[j] == '*'){
                        tempIndex = j; 
                        break;
                    }
                }
                pnumberArray[tempIndex] = pnumberArray[tempIndex] * pnumberArray[tempIndex + 1];
                for(int k = tempIndex+1; k < numberOfNumbers - 1; k++){
                    pnumberArray[k] = pnumberArray[k+1];
                }           
                for(int l = tempIndex; l < numberOfOperations - 1; l++){
                    psymbols[l] = psymbols[l+1];
                }     
            }
            else if (pBIDMASOrder[i] == '/'){
                //divide
                for(int j = 0; j < numberOfOperations; j++){
                    if(psymbols[j] == '/'){
                        tempIndex = j; 
                        break;
                    }
                }
                pnumberArray[tempIndex] = pnumberArray[tempIndex] / pnumberArray[tempIndex + 1];
                for(int k = tempIndex+1; k < numberOfNumbers - 1; k++){
                    pnumberArray[k] = pnumberArray[k+1];
                }                
                for(int l = tempIndex; l < numberOfOperations - 1; l++){
                    psymbols[l] = psymbols[l+1];
                }
            }
        }
        cout << pnumberArray[0];


        delete[] parray;
        delete[] pnumberArray;
        delete[] psymbols;
        delete[] pBIDMASOrder;

    }
    return 0;
}