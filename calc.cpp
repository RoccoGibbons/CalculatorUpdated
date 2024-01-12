#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <tuple>
using namespace std;

//Operation Functions
double add(double x, double y){
    return x + y;
}

double subtract(double x, double y){
    return x - y;
}

double multiply(double x, double y){
    return x * y;
}

double divide(double x, double y){
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

        char array[length];
        array[length] = '\0';

        //Moves string calculation into an array of characters
        for (int i = 0; i < length; i++){
            array[i] = calculation[i];
        }

        int numberOfOperations = countOperations(calculation);
        int numberOfNumbers = numberOfOperations + 1;

        int numberArray[numberOfNumbers];

        //Moves all the numbers in the character array into a separate array 
        int k = 0;
        for (int i = 0; i < numberOfNumbers; i++){
            bool boolean = true;
            string tempNumber;
            while (boolean == true){
                if (isdigit(array[k]) == 1){
                    tempNumber += array[k];
                    k++;
                }
                else{
                    k++;
                    boolean = false;
                    numberArray[i] = stoi(tempNumber);
                    tempNumber = "";
                }
            }
        }       

        char symbols[numberOfOperations];
        symbols[numberOfOperations] = '\0';

        //Stores all operatives into their own array
        int j = 0;
        for (int i = 0; i < length; i++){
            if (array[i] == '*'){
                symbols[j] = '*';
                j++;
            }
            else if (array[i] == '/'){
                symbols[j] = '/';
                j++;
            }
            else if (array[i] == '+'){
                symbols[j] = '+';
                j++;
            }
            else if (array[i] == '-'){
                symbols[j] = '-';
                j++;
            }
        }
        

        //Managed to do 2 number operations, doing 2< operations returns 2 numbers instead of using previous number
        // to operate

        //[23, 4, 13]
        //[23, 17, ?]       
    }
    return 0;
}