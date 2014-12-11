////////////////////////////////////////////////////////////////////////////////
//
// Topic    : Array and sorting problems
// Author   : Anh Tuan Do
// Created  : March 30th, 2011
//
////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <string.h>
using namespace std;

#define MAX 10
// -----------------------------------------------------------------------------
// Rotate an array MxN by 180 degrees
// NOTE: Can we combine 2 loops into 1??
// -----------------------------------------------------------------------------
void rotate180(int a[][MAX], int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j =0; j < n/2; j++) {
      int temp = a[i][j];
      a[i][j] = a[i][n - j - 1];
      a[i][n - j - 1] = temp;
    }
  }

  for (int i = 0; i < m/2; i++) {
    for (int j = 0; j < n; j++) {
      int temp = a[i][j];
      a[i][j] = a[m - i - 1][j];
      a[m - i - 1][j] = temp;
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }
}

// -----------------------------------------------------------------------------
// Dutch flag problem
// -----------------------------------------------------------------------------
void dutchFlagProblem(int* a, int n) {
  // Before
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  // Sort - begin
  int p = 0;
  while (a[p] == 0) {
    p++;
  }

  int q = n - 1;
  while (a[q] == 2) {
    q--;
  }

  int i = p;

  while (i < n && i <= q) {
    if (a[i] == 0) {
      a[i] = a[p];
      a[p] = 0;
      p++;
    }
    else if (a[i] == 2) {
      a[i] = a[q];
      a[q] = 2;
      q--;
      i--;
    }
    i++;
  }
  // Sort - end

  // After
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

// -----------------------------------------------------------------------------
// Kadane's algorithm
// -----------------------------------------------------------------------------
void kadane(int* a, int n) {
  int maxSum = -10000;
  int maxStartIndex = 0;
  int maxEndIndex = 0;
  int currentMaxSum = 0;
  int currentStartIndex = 0;
  for (int currentEndIndex = 0; currentEndIndex < n; currentEndIndex++) {
    cout << "------------------------------" << endl;
    cout << "currentEndIndex = " << currentEndIndex << endl;
    cout << "current a = " << a[currentEndIndex] << endl;
    currentMaxSum = currentMaxSum + a[currentEndIndex];
    cout << "currentMaxSum = " << currentMaxSum << endl;
    cout << "maxSum = " << maxSum << endl;
    if (currentMaxSum > maxSum) {
      cout << ".. Change maxSum" << endl;
      maxSum = currentMaxSum;
      maxStartIndex = currentStartIndex;
      maxEndIndex = currentEndIndex;

      cout << "maxSum = " << maxSum << endl;
      cout << "maxStartIndex = " << maxStartIndex << endl;
      cout << "maxEndIndex = " << maxEndIndex << endl;
    }

    if (currentMaxSum < 0) {
      cout << ".. currentMaxSum < 0" << endl;
      currentMaxSum = 0;
      currentStartIndex = currentEndIndex + 1;
      cout << "currentMaxSum = " << currentMaxSum << endl;
      cout << "currentStartIndex = " << currentStartIndex << endl;
      cout << "currentEndIndex = " << currentEndIndex << endl;
    }
  }

  cout << "Max sum = " << maxSum << ", maxStartIndex = " << maxStartIndex << ", maxEndIndex = " << maxEndIndex << endl;
}

// -----------------------------------------------------------------------------
// Rotate matrix by 90 degrees
// -----------------------------------------------------------------------------
void rotate90(int a[][MAX], int n) {

}

// -----------------------------------------------------------------------------
// Given an array A[i..j] find out maximum j-i such that a[i]<a[j] in O(n) time.
// -----------------------------------------------------------------------------
void celicom(int* a, int n) {
  int i = 0;
  int j = 0;

  cout << "--- A array ---" << endl;
  for (i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;

  int b[n];
  b[0] = a[0];
  for (i = 1; i < n; i++) {
    b[i] = a[i] < b[i - 1] ? a[i] : b[i - 1];
  }

  cout << "--- B array ---" << endl;
  for (i = 0; i < n; i++) {
    cout << b[i] << " ";
  }
  cout << endl;

  int c[n];
  c[n - 1] = a[n - 1];
  for (i = n - 2; i >= 0; i--) {
    c[i] = a[i] > c[i + 1] ? a[i] : c[i + 1];
  }

  cout << "--- C array ---" << endl;
  for (i = 0; i < n; i++) {
    cout << c[i] << " ";
  }
  cout << endl;

  int maxij = 0;
  i = 0;
  j = 0;
  while (j < n) {
    while (b[i] < c[j] && j < n - 1) {
      j = j + 1;
    }
    maxij = maxij > (j - i) ? maxij : (j - i);
    i++;
    j++;
  }

  cout << "--- Result ---" << endl;
  cout << i << ", " << j << ", " << maxij << endl;
}

// -----------------------------------------------------------------------------
// Main function
// -----------------------------------------------------------------------------
int main(int argc, char** argv) {
  // --- Rotate a matrix by 180 degrees --- //
//  int a[3][4] = {
//    {3, 7, 9, 8},
//    {1, 5, 7, 2},
//    {7, 4, 6, 3},
//  };
//  rotate180(a, 3, 4);

  // --- Dutch flag problem --- //
//  int a[10] = {1, 0, 2, 2, 0, 0, 1, 0, 1, 2};
//  dutchFlagProblem(a, 10);

  // --- Kadane's algorithm --- //
//  //int a[10] = {1, -5, 4, 7, -9, 0, 3, 6, 1, 2};
//  int a[5] = {-5, 80, -100, 20, 200};
//  kadane(a, 5);

  // --- Celicom --- //
  int a[10] = {10, 2, 7, 9, 0, 3, 1, 1, 1, 1};
  celicom(a, 10);

  return 1;
}
*/
