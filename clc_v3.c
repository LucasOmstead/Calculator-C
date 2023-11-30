#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//Reads the next character. If it isn't in the list of acceptable chars given, prompts the user to retry
int nextChar(char validChars[], int length) {  
  char returnChar;
  while (1) {
    scanf(" %c", &returnChar);
    while (getchar() != '\n');
    for (int i = 0; i < length; i++) {
      if (returnChar == validChars[i]) {
        return returnChar;
      }
    }
    printf("Invalid option! Try again!\n");
  
  }
}

//Gets the value in the variables array corresponding to the letter (a, b, c, d, e) given
float chartoint(char ch, float variables[5]) {
  return variables[(int)ch - 97];
}

//Returns the next floating-point number inputted by the user
float getNextFloat(int canBeChar, float variables[5]) {
  float returnFloat;
  char tempVal;
    //For outputs that can be chars or floats, check if it's either and if not try again
    while (1) {
      if (scanf(" %f", &returnFloat) < 1) {
        if (canBeChar) {
        if (scanf(" %c", &tempVal) < 1) {
          printf("Invalid number! Try again!\n");
        } else {
          while(getchar() != '\n');
          if (((int)(tempVal)-97 > 4) || ((int)(tempVal)-97 < 0)) {
            printf("Invalid variable! Try again!\n");
          } else {
          return chartoint(tempVal, variables);
          }
        }
        } else {
          printf("Invalid number! Try again!\n");
          while(getchar() != '\n');
        }
      } else {
        while(getchar() != '\n');
        return returnFloat;
      }
    }
    //For numeric inputs only; check if it's a float and if not try again
  
}

//Gets a character corresponding to an index in variables[]
float getIndexChar(void) {
  char indexChar;
  //For converting a character (a, b, c, d, e) to its corresponding index in the variables[] array
  while(1) {
    if (scanf(" %c", &indexChar) > 0) {
      while(getchar() != '\n');
      indexChar -= 97;
      if ((indexChar <= 4) && (indexChar >= 0)) {
        return indexChar;
      } else {
        printf("Invalid variable! Try again!\n");
      }
  } else {
    while(getchar() != '\n');
    printf("Invalid variable! Try again!\n");
  }
  }
}

//Gets the operation option selected by the user
char getOptionSelection(void) {
  printf("Please select your option (B, U, A, V, E): \n"); 
  return nextChar((char[]){'B', 'U', 'A', 'V', 'E'}, 5);
}

//Function for case B
float caseB(float num1, char operation, float num2) {
  switch(operation) { 
    case '+':
      return num1 + num2;
      break;
    case '-':
      return num1 - num2;
      break;
    case '*':
      return num1*num2;
      break;
    case '/':
      if (num2 != 0) {
        return  num1/num2;
      } else {
        printf("Error - divide by zero. Try again!\n");
        return NAN;
        
      }
      break;
    case '%':
      if (num2 != 0) {
        return (int)num1 % (int)num2;
      } else {
        printf("Error - divide by zero. Try again!\n"); 
        return NAN;
        
      }
      break;
    case 'P':
      return powf(num1, num2);
      break;
    case 'X':
      return ((num1 > num2) ? num1 : num2);
      break;
    case 'I':
      return ((num1 > num2) ? num2 : num1);
      break;
    default:
      printf("Invalid operation, please try again!\n");
      return NAN;
      break;
  }
}

//Function for case U
float caseU(float num1, char operation) {
  switch (operation) {
    case 'S':
      if (num1 >= 0) {
        return powf(num1, .5);
      } else {
        printf("Error - sqrt of negative number. Try again!\n");
        return NAN;
      }
      break;
    case 'L':
      if (num1 > 0) {
      return logf(num1);
      } else {
        printf("Error - base of log must be > 0. Try again!\n");
        return NAN;
      }
      break;
    case 'E':
      return expf(num1);
      break;
    case 'C':
      return ceilf(num1);
      break;
    case 'F':
      return floorf(num1);
      break;
    default:
      printf("Invalid operation, please try again!\n");
      return NAN;
      break;
  }
}     
 
int main(void) {
  printf("Welcome to my Command-Line Calculator (CLC) \nDeveloper: Lucas Omstead \nVersion: Assignment 1 \nDate: October 24th\n----------------------------------------------------------------\n \nSelect one of the following items: \nB) - Binary mathematical Operations, such as addition and subtraction \nU) - Unary Mathematical Operations , such as square roots and log \nA) - Advances Mathematical Operations, using variables, arrays. \nV) - Define variables and assign them values. \nE) - Exit \n"); 
  float num1, num2; 
  float result; 
  char operation;
  char option; 
  int valid;
  int index;
  float variables[5];
  while (option != 'E') { 
    option = getOptionSelection();
    valid = 1;
    num1 = 0;
    num2 = 0;
    switch (option) { 
      case 'B':
        printf("Please enter the first number: \n"); 
        num1 = getNextFloat(0, variables);
        printf("Please enter the operation (+, -, *, /, %%, P, X, I):\n");
        operation = nextChar((char[]){'+', '-', '*', '/', '%', 'P', 'X', 'I'}, 8);
        printf("Please enter the second number: \n");
        num2 = getNextFloat(0, variables);
        result = caseB(num1, operation, num2);
        break;
      case 'U':
        printf("Please enter the unary operation (S, L, E, C, F):\n");
        operation = nextChar((char[]){'S', 'L', 'E', 'C', 'F'}, 5);
        printf("Please enter the argument: \n"); 
        num1 = getNextFloat(0, variables);
        result = caseU(num1, operation);
        break;
      case 'V':
        printf("Please enter the variable to use: ");
        index = getIndexChar();
        printf("Please enter the value to change it to: ");
        variables[index] = getNextFloat(0, variables);
        valid = 0;
        break;
      case 'A':
        printf("Please select your option (B, U, E): \n"); 
        option = nextChar((char[]){'B', 'U', 'E'}, 3);
        valid = 1;
        num1, num2 = 0;
        switch (option) { 
          case 'B':
            printf("Please enter the first number: \n"); 
            num1 = getNextFloat(1, variables);
            printf("Please enter the operation (+, -, *, /, %%, P, X, I):\n");
            operation = nextChar((char[]){'+', '-', '*', '/', '%', 'P', 'X', 'I'}, 8);
            
            printf("Please enter the second number: \n");
            num2 = getNextFloat(1, variables);
            result = caseB(num1, operation, num2);
            break;
          case 'U':
            printf("Please enter the unary operation (S, L, E, C, F):\n");
            operation = nextChar((char[]){'S', 'L', 'E', 'C', 'F'}, 5);
            printf("Please enter the argument: \n"); 
            num1 = getNextFloat(1, variables);
            result = caseU(num1, operation);
            break;
          case 'E':
            option = 'P'; //Unused character so that it doesn't end the entire program
            result = NAN;
            break;  
        }
        break;
      case 'E':
        printf("Thanks for using my calculator. Hope to see you soon again, goodbye!\n");
        exit(0);
        break;
      default: 
        result = NAN;
        break;
    }
    if (!isnan(result)) {
      printf("The result is: %f\n", result);
    }
  }
}


