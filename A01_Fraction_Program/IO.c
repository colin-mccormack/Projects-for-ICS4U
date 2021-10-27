/*

  IO

  IO also stands for Input/Output, as its name suggests, this library
  contains functions that allow the program to interact with user, and
  vice versa.

  This library forms an interface between user and the computer

*/

#include <stdio.h>
#include <stdlib.h>
#include "IO.h"

/*

    void showMenu(int *choice);
  
    This function is responsible for showing available
    options on the screen.

    It takes in an pointer to a variable local to the 
    callent function and assigns the value (or option)
    given by the user.
  
*/

void showMenu(int *choice) {

  // Printing the options.
  printf("Options:\n");
  printf ("1. Create Random Fraction\n");
  printf ("2. Get Fraction From User\n");
  printf ("3. Display Fractions\n");
  printf ("4. Add Fractions\n");
  printf ("5. Subtract Fractions\n");
  printf ("6. Divide Fractions\n");
  printf ("7. Multiply\n");
  printf ("8. Display All Equations\n");
  printf ("9. Quit\n");


  printf ("Please enter a numeric value for the following possible options provided above: \n\n>");
  scanf ("%i", choice);
  fflush(stdin);
}

/*

  void ClearConsole();

*/

void ClearConsole() {

    fflush(stdin);

  printf("\e[1;1H\e[2J");
}


/*

  Getting Fraction From User

*/


/*

  Function for validating fraction

*/


static int ValidateFraction(int numerator, int denominator) {
  return (
    numerator   > IO_MIN_NUMERATOR   && // These symbolic constatns are in IO.h
    numerator   < IO_MAX_NUMERATOR   &&
    denominator > IO_MIN_DENOMINATOR &&
    denominator < IO_MAX_DENOMINATOR );

}

/*

  void getUserFraction (int *numer, int *denom);
  
    This function is responsible for prompting user to
    enter values for the fraction.

    Makes sure that the user provides valid values.
  
*/


void getUserFraction (int *numer, int *denom) {
  
  int Valid;
  
  do {
    

    // Prompt user and store results
    printf ("Please enter fraction numerator : ");
    scanf  ("%i", numer);
    printf ("Please enter fraction denomenator : ");
    scanf  ("%i", denom);

    // Clear Buffer
    fflush(stdin);

    // Check if Valid
    Valid = ValidateFraction(*numer,*denom);

    // If invalid, then print its in valid. 
    if(!Valid)
      printf("Invalid Fraction Please Retry \n\n");


  } while (!Valid);
}
