////////////////////////////////////////////////////////////////////////////////
//
// Topic    : Recursion problems
// Author   : Anh Tuan Do
// Created  : March 23rd, 2011
//
////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <string.h>
using namespace std;

// -----------------------------------------------------------------------------
// Calculate n! (n factoria)
// -----------------------------------------------------------------------------
int factoria(int n) {
  if (n == 0) {
    return 1;
  } else {
    return n * factoria(n - 1);
  }
}

// -----------------------------------------------------------------------------
// Permutation of a string
// -----------------------------------------------------------------------------
void permute(char* currentString, char* letters, int currentPos, int length) {
  if (strlen(currentString) == length) {
    cout << currentString << endl;
  }
  else {
    // Find an available letter
    for (int i = 0; i < 256; i++) {
      if (letters[i] == 1) {
        // set it to be the current character of the string
        // mark it as used
        currentString[currentPos] = i;
        letters[i] = 2;
        currentPos++;
        // Call recursive
        permute(currentString, letters, currentPos, length);

        // Mark it as available again!
        letters[i] = 1;
        currentString[currentPos] = 0;
        currentPos--;
      }
    }
  }
}

void permuteString(char* str) {
  // Initialize an array for marking
  char letters[256] = "";
  for (int i = 0; i < 256; i++) {
    letters[i] = 9; // 9 = not available, 1 = available, 2 = marked
  }
  for (int i = 0; i < strlen(str); i++) {
    letters[str[i]] = 1;
  }

  // Begin permutation
  char currentString[256] = "";
  permute(currentString, letters, 0, strlen(str));
}

// -----------------------------------------------------------------------------
// Print all () combinations
// -----------------------------------------------------------------------------
//void printParentheses(int n, char* str, int ) {
//  if (n == 1) {
//    cout << "()" << endl;
//  }
//  else {
//    cout << "()";
//    printParentheses(n - 1);
//  }
//}

void printPar(int l, int r, char* str, int count) {
  if (l < 0 || r < l) {
    return;
  }

  if (l == 0 && r == 0) {
    cout << str << endl;
  }
  else {
    if (l > 0) {
      str[count] = '(';
      printPar(l - 1, r, str, count + 1);
    }
    if (r > l) {
      str[count] = ')';
      printPar(l, r - 1, str, count + 1);
    }
  }
}

// -----------------------------------------------------------------------------
// Main function, nothing much in this one
// -----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//  char str[256] = "acbde";
//  permuteString(str);

//  printParentheses(3);
  char str[10] = "";
  printPar(4, 4, str, 0);

  return 0;
}
*/
