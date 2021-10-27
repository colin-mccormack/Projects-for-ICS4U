
#include "IO.h"

//All stored fractions
unsigned int NumStoredFractions = 0;
int          StoredFractions[IO_MAX_FRACTIONS][2];

int DataBase_canAddFraction() {
  return (NumStoredFractions + 1) == IO_MAX_FRACTIONS;
}

void DataBase_addToStoredFractions(int numerator, int denomerator) {
  
  StoredFractions[NumStoredFractions][0] = numerator;
  StoredFractions[NumStoredFractions][1] = denomerator;
  NumStoredFractions++;
}

// void getFromFractions(int Index, int *numerator, int *denominator) {
  
//   int *myArray = StoredFractions[Index];
  
//   *numerator = myArray[0];
//   *denominator = myArray[1];
// }

void DataBase_forEachValueInStoredFractions(void(*f)(int,int,int)) {
 
  for (unsigned int i = 0; i < NumStoredFractions; i++) {
    f(i,StoredFractions[i][0],StoredFractions[i][1]);
  }
  
}


// User History
unsigned int Num_History = 0;
int          History_Operand1[IO_MAX_FRACTIONS][2];
int          History_Operand2[IO_MAX_FRACTIONS][2];
int          History_Results [IO_MAX_FRACTIONS][2];
char          History_Operator[IO_MAX_FRACTIONS];


int DataBase_canAddToHistory() {
  return (Num_History + 1) == IO_MAX_FRACTIONS;
}

void DataBase_addToHistory(
  int num1, int den1, 
  int num2, int den2, 
  int rnum, int rden, 
  char Operator) {

  int *myArray;

  myArray = History_Operand1[Num_History];
  myArray[0] = num1;
  myArray[1] = den1;

  myArray = History_Operand2[Num_History];
  myArray[0] = num2;
  myArray[1] = den2;

  myArray = History_Results[Num_History];
  myArray[0] = rnum;
  myArray[1] = rden;

  History_Operator[Num_History] = Operator;
  
  Num_History++;
}


void DataBase_forEachValueStoredInHistory(
  void(*f)(
    int num1, int den1, 
    int num2, int den2, 
    int rnum, int rden, 
    char Operator)) {

  for (unsigned int i = 0; i < Num_History; i++) {
  
      int *myArray  = History_Operand1[i];
      int *myArray2 = History_Operand1[i];
      int *myArray3 = History_Results[i]; 

    f(
      myArray [0],myArray[1],
      myArray2[0],myArray2[1],
      myArray3[0],myArray3[1],
      History_Operator[i]
      );
   
  }
}


unsigned int DataBase_ProgramShouldRun = 1;

int DataBase_ProgramCanRun() {
  return DataBase_ProgramShouldRun;
}

int DataBase_SetFlagToStopProgram() {
  DataBase_ProgramShouldRun = 0;
}

