/*

  Operations

  This file is responsible for performing all types of calculations
  in our program, including Addition, Subtraction, Multiplication etc.

  How it works:

    callent function will provide getFunctionToRun() the option user has chosen,
    getFunctionToRun() will return pointer to the function based on userchoice to
    the main function. callent function will run that respective function.


  All functions follow a pattern, they return void (Nothing), and take in 0 
  arguments. To access data, they use functions from DataBase.h. To manipulate
  the data, even for that they use functions from DataBase.h

  ONLY getFunctionToRun() is visible outside of this file.

*/

// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "IO.h"
#include "DataBase.h"

/*

    User Choices

*/
#define OP_CLEAR                     256
#define OP_GENERATE_RANDOM_FRACTION  1
#define OP_GET_FRACTIONS             2  
#define OP_DISPLAY_FRACTIONS         3 

#define OP_ADD_FRACTIONS             4
#define OP_SUB_FRACTIONS             5
#define OP_DIV_FRACTIONS             6
#define OP_MUL_FRACTIONS             7

#define OP_DISPLAY_ALL_EQUATIONS     8

#define OP_QUIT_PROGRAM              9



/*

  Data type of our function, this is the data type
  to store the returned function used by the main function.

*/

typedef void function();

/*

  These are the function that perform all sorts of calculations.
  These are abstracted, and only the pointer to these are returned
  to the main function, and main function can indirectly use the pointer
  to run this function.

*/

void CreateRandomFraction();
void GetFractionFromUser();
void DisplayFractions();

void AddFractions();
void SubtractFractions();
void MultiplyFractions();
void DivideFractions();

void DisplayAllEquations();

void QuitProgram();

void invalidCase();

/*

  function *getFunctionToRun(int Choice);

  This function takes in user choice, and returns
  reference to the function that completes the task
  that user wants the program to do. 


*/

function *getFunctionToRun(int Choice) {

  switch (Choice) {

    case OP_CLEAR:
      return &ClearConsole;
    // If users wants to generat random fraction
    case OP_GENERATE_RANDOM_FRACTION:
      return &CreateRandomFraction;

    // If users wants the program to store a fraction
    case OP_GET_FRACTIONS:
      return &GetFractionFromUser;

    // If users wants to display stored fractions
    case OP_DISPLAY_FRACTIONS:
      return &DisplayFractions;

    // If users wants to add two fractions
    case OP_ADD_FRACTIONS: 
      return &AddFractions; 
      
    // If users wants to subtract two fractions
    case OP_SUB_FRACTIONS: 
      return  &SubtractFractions; 

    // If users wants to multiply two fractions
    case OP_MUL_FRACTIONS: 
      return &MultiplyFractions; 
      
    // If users wants to divide two fractions
    case OP_DIV_FRACTIONS: 
      return  &DivideFractions; 

    case OP_DISPLAY_ALL_EQUATIONS:
      return &DisplayAllEquations;

    // If users gives us an invalid input.
    default:
      return &invalidCase; 
    
  }

}

/*

  Code for All the functions starts from here

*/

/*

  Option 1

  Create RandomFraction

*/

void CreateRandomFraction() {
  
  /*
  
    Setting a random seed, so that everytime 
    this function is called, it generates numbers 
    randomly, since the seed is being changed evertime.

    If you didn't understand what this does,
    then read it hear:
    https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
  
  */
  
  srand((unsigned int)rand());
  
  /*
  
    Generating random numerator and Denomerator
  
  */

  int num, den;
  num = (rand()%100)-(IO_MAX_NUMERATOR*(rand()%2));
  den = (rand()%100)-(IO_MAX_DENOMINATOR*(rand()%2));
  
  /*
  
    Storing the generated fraction in our DataBase.
  
  */
  DataBase_addToStoredFractions(num, den);
  
}


/*

  Option 2

  Get Fraction From User

*/


void GetFractionFromUser() {
  
  
  int num, den;
  
  /*
  
    Prompt users for fractions
  
    (This function is from IO.h)

  */

  getUserFraction(&num, &den);
  
  
  /*
  
    Adding response to data base
  
    (This function is from DataBase.h)

  */

  DataBase_addToStoredFractions(num, den);

}


/*

    Helper functions which will be eventually used.

*/

/*

  Using eulicd's algorithm we efficently check for the gcd.
  This algorithm swaps the location of (a,b) each time,
  reducing the first term by the remainder from division of the second term each time.

*/

int getGCD(numRe, denRe) {

  
  if (numRe == 0) return denRe;
  if (denRe == 0) return numRe;

  /*

  Using recursion this function will call itself until it gets to a return value,
  but will never 'unfoald' recursivly since we are also returning the next function call.

  */

  return getGCD(denRe, numRe % denRe);
}


/*

  This will make the numerator negative if the numerator is originally positive and the denominator is negative (can't have a denomenator that is negative sicne it should just be represented as a completely negative fraction).

*/

int safteyNum (num, den) {
  if (num > 0 && den < 0) return num*-1;
  return num;
}

/*

  This will make the denominator positive if it is origianlly negative since you can't have a denomenator that is negative.

*/

int safteyDen (den) {
  if (den < 0) return den*-1;
  return den;
}

/*

  Option 3

  Display Elements

*/

static void displayElements(int index, int num, int den) { 

  /*

    Print the fraction out in the format -> Fraction 1: 2/2 = 1/1

    Arguments in order are : 
      fraction number indexded from 0 (so +1),
      numerator,
      denomenator,
      numerator/gcd (reduced) multiplied by a saftey function to avoid negatives in denomenator,
      denomenator/gcd (reduced) multiplied by a saftey function to avoid negatives in denomenator.

  */

  printf(
    "Fraction %i: %i/%i = %i/%i\n", 
    index+1, num, den, safteyNum(num/getGCD(num,den),den), safteyDen(den/getGCD(num,den))); 
}

void DisplayFractions() {

  //For everything stored in databse file array excecute print to screen function
  DataBase_forEachValueInStoredFractions(&displayElements);

}

/*

  Calculations

*/

/*

  Option 4

  Add Fractions

*/

void DisplayBEDMAS(int num1,int den1,int num2,int den2,int num,int den,char operator) {

  /*

    Print the fraction out in the format -> Fraction 1: 2/2 = 1/1

    Arguments in order are : 
      numerator 1,
      denomenator 1,
      numerator 2,
      denomenator 2,
      resulting numerator,
      resulting denominator.

  */

  printf(
    "%i/%i %c %i/%i = %i/%i\n",
     num1, den1, operator, num2, den2, num, den
    ); 
}

void AddFractions() {
  
  int num1, den1, num2, den2, num, den, tempNum;

  //Get user input fraction 1
  getUserFraction(&num1, &den1);
  //Get user input fraction 2
  getUserFraction(&num2, &den2);
  
  //Make numerator of result numerator 
  num = num1*den2 + num2*den1;
  den = den1*den2;

  tempNum = num;

  num = safteyNum(num/getGCD(num, den), num);
  den = safteyDen(den/getGCD(tempNum, den));

  DataBase_addToHistory(num1, den1, num2, den2, num, den, '+');
  DisplayBEDMAS(num1, den1, num2, den2, num, den, '+');

}

/*

  Option 5

  Subtract Fractions

*/

void SubtractFractions() {
  
  int num1, den1, num2, den2, num, den, tempNum;

  //Get user input fraction 1
  getUserFraction(&num1, &den1);
  //Get user input fraction 2
  getUserFraction(&num2, &den2);
  
  //Make numerator of result numerator 
  num = num1*den2 - num2*den1;
  den = den1*den2;

  tempNum = num;

  num = safteyNum(num/getGCD(num, den), num);
  den = safteyDen(den/getGCD(tempNum, den));

  DataBase_addToHistory(num1, den1, num2, den2, num, den, '-');
  DisplayBEDMAS(num1, den1, num2, den2, num, den, '-');
}

/*

  Option 6

  Divide Fractions

*/

void DivideFractions() {

  int num1, den1, num2, den2, num, den, tempNum;

  //Get user input fraction 1
  getUserFraction(&num1, &den1);
  
  /*
  
    Get user input fraction 2
  
  */
  
  getUserFraction(&num2,&den2);
  

  /*
    
    If second numerator is 0,
    taking a reciprocal will make it from
    
    0 / x to x / 0
    
    which is invalid, aka undefined.

  */

  while (num2 == 0) {
    printf ("Invalid second fraction numerator.\n");
    getUserFraction(&num2,&den2);
  }


  //Multiply the reciprocals
  num = num1*den2;
  den = den1*num2;

  tempNum = num;

  num = num/getGCD(num, den);
  den = den/getGCD(tempNum, den);


  DataBase_addToHistory(num1, den1, num2, den2, num, den, '/');
  DisplayBEDMAS(num1, den1, num2, den2, num, den, '/');

}

/*

  Option 7

  Multiply Fractions

*/

void MultiplyFractions() {

  int num1, den1, num2, den2, num, den, tempNum;

  //Get user input fraction 1
  getUserFraction(&num1, &den1);
  
  //Get user input fraction 2
  getUserFraction(&num2, &den2);
  
  //Make numerator of result numerator 
  num = num1*num2;
  den = den1*den2;
 
  tempNum = num;

  num = num/getGCD(num, den);
  den = den/getGCD(tempNum, den);

  DataBase_addToHistory(num1, den1, num2, den2, num, den, 'x');
  DisplayBEDMAS(num1, den1, num2, den2, num, den, 'x');


}

void DisplayAllEquations() {
  DataBase_forEachValueStoredInHistory(&DisplayBEDMAS);
}

void QuitProgram() {
  DataBase_SetFlagToStopProgram();
}

void invalidCase() {
  printf("No working case. Retry.\n");

}
