/*

  A01 Fraction Program

  Program Structure:

    - This file:
      Runs fnctions from various header files.
    
    - IO.h
      Header file containing IO functions, 
      Interface between User and Program 

    - Operations.h
      Header file containing all functions created for specific operations,
      Including Addition, Subtraction, Multiplication, and so on...
      All those functions are abstracted away.
      The only visible functions are decideWhatToDo, and doWhatIsToBeDone.
      decideWhatToDo will return a function pointer that doWhatIsToBeDone runs.

    - DataBase.h
      Contains MultiDimensional Arrays that can be used to store data.
      Syntax Sugar: Just include this header file to access these arrays instead
      of passing them by reference each time.


  @author Abdul Mannan Syed, asyed24@ocdsb.ca
  @author Collin  McMcormack, cmcco3@ocdsb.ca

  @date  10/26/2021

*/

// Header files
#include "IO.h"
#include "Operations.h"
#include "DataBase.h"


// Entry Point of Program
int main() {

  ClearConsole();

  //
  while(DataBase_ProgramCanRun()) {

    // Holds User Choice 
    int UserChoice;

    // Showing Option Menu, and getting user response
    showMenu(&UserChoice);
    
    // Deciding what function to run, based on user choice
    getFunctionToRun(UserChoice)();
  
    return 0;
  }

}