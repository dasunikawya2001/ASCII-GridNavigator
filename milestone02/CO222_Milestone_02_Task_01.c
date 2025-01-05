#include <stdio.h>
#include <stdbool.h>

//An array to store calculated fibonacchi numbers
//Initially assining all the values to 0
long int storedArray[200]= {0};

int fib(int);
bool findEqualty(int number, int target01, int target02);

int main(){
    int number , target01 , target02;
    scanf("%i %i %i" , &number , &target01 , &target02);

    int fibNumber = fib(number);

    int result = findEqualty(fibNumber, target01, target02);
    if (result==1){
        printf("TRUE");
    }
    else{
        printf("FALSE");
    }
    
    return 0;
}

//Recursion function to calculate fibonacchi numbers
int fib(int num){
    if (num<=1)
    {
        return num;
    }
    else if (storedArray[num] != 0)
    {
        return storedArray[num];
    }
    else{
        storedArray[num] = fib(num-1)+fib(num-2);
        return storedArray[num];
    }
    return storedArray[num];
}

//Function to matching the calculated fibonacci number
bool findEqualty(int number, int target01, int target02){
    if (number==target01 || number==target02)
        {
            return true;
        }
    else{
        return false;
    }
    return true;
}   