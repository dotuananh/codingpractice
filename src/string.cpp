////////////////////////////////////////////////////////////////////////////////
//
// Topic    : String problems
// Author   : Anh Tuan Do
// Created  : March 21st, 2011
//
////////////////////////////////////////////////////////////////////////////////
/*
#include <iostream>
#include <string.h>
using namespace std;

// -----------------------------------------------------------------------------
// Find the first nonrepeated character in a string.
// For instance, the first nonrepeated character in 'total' is 'o'
// and the first nonrepeated character in'teeter' is 'r'
// Note: This function assumes that our string is an ASCII string,
// for Unicode strings, we should use hass table instead of array
// -----------------------------------------------------------------------------
void firstNonRepeated(char* s) {
  // SPECIAL CASE: The string is null
  if (s == NULL) {
    return;
  }

  // Reset all the counters
  int letters[256];
  for (int i = 0; i < 256; i++) {
    letters[i] = 0;
  }

  // Count the appearance number of each letter in the string
  int pos = 0;
  while (s[pos] != 0) {
    letters[s[pos]]++;
    pos++;
  }

  // Find the first nonrepeated character
  pos = 0;
  while (s[pos] != 0) {
    if (letters[s[pos]] == 1) {
      int x = s[pos];
      cout << "The first non repeated letter is " << s[pos] << ", " << x << endl;
      return;
    }
    pos++;
  }

  // Cannot find any nonrepeated character
  cout << "All the letters are repeated!" << endl;
}

// -----------------------------------------------------------------------------
// Remove specified characters from a string
// For example, given a string "Battle of the Vowels: Hawaii vs. Gronzy." and
// the remove of "aeiou", the function should transform str to
// "Bttl f th Vwls: Hw vs. Grnzy."
// -----------------------------------------------------------------------------
void removeCharacters(char* str, char* remove) {
  // Create the lookup table
  // The lookup table has 256 BOOLEAN elements
  // 0 = not remove
  // 1 = remove
  int letters[256];
  for (int i = 0; i < 256; i++) {
    letters[i] = 0;
  }
  int pos = 0;
  while (remove[pos] != 0) {
    letters[remove[pos]] = 1;
    pos++;
  }

  // Go through each letter and remove the specified characters
  int pos1 = 0;
  int pos2 = 0;
  while (str[pos1] != 0) {
    // If the current letter in NOT on the remove list,
    // copy the current letter to pos2
    // pos2 increases 1 step
    if (letters[str[pos1]] == 0) {
      str[pos2] = str[pos1];
      pos2++;
    }
    pos1++;
  }

  // End the new string
  str[pos2] = 0;

  cout << str << endl;
}

// -----------------------------------------------------------------------------
// Reverse a whole string
// -----------------------------------------------------------------------------
void reverseString(char* str, int startPos, int endPos) {
  int n = endPos - startPos + 1;

  int i = 0;
  while (i < n/2) {
    char temp = str[startPos + i];
    str[startPos + i] = str[endPos - i];
    str[endPos - i] = temp;
    i++;
  }
}

// -----------------------------------------------------------------------------
// Reverse the order of words in a string.
// For example, your function should transform the string
// "Do or do not, there is no try." to
// "try. no is there not, do or Do"
// -----------------------------------------------------------------------------
void reserveWords(char* str) {
  // Reserve the whole string
  reverseString(str, 0, strlen(str) - 1);

  // Reverse each word
  int startPos = 0;
  int endPos = 0;
  while (endPos < strlen(str)) {
    if (str[endPos] == ' ') {
      reverseString(str, startPos, endPos - 1);
      startPos = endPos + 1;
    }
    // SPECIAL CASE: The end of the string
    else if (endPos == strlen(str) - 1) {
      reverseString(str, startPos, endPos);
    }
    endPos++;
  }

  cout << str << endl;
}

// -----------------------------------------------------------------------------
// Convert a string to signed integer
// -----------------------------------------------------------------------------
int convertStringToInteger(char* str) {
  int startPos = 0;
  // Check whether this is a negative number
  if (str[0] == '-') {
    startPos = 1;
  }

  int i = startPos;
  int n = 0;
  while(i < strlen(str)) {
    n = n * 10 + str[i] - '0';
    i++;
  }

  // Negative number
  if (startPos == 1) {
    n *= -1;
  }

  cout << n << endl;
  return n;
}

// -----------------------------------------------------------------------------
// Convert a signed integer to a string
// -----------------------------------------------------------------------------
char* convertIntegerToString(int n) {
  char str[10] = "";
  // SPECIAL CASE
  if (n == 0) {
    str[0] = '0';
  }
  else {
    int startPos = 0;
    if (n < 0) {
      startPos = 1;
      str[0] = '-';
      n *= -1;
    }
    char temp[10];
    int digits = 0;
    while (n > 0) {
      temp[digits] = n % 10 + '0';
      digits++;
      n /= 10;
    }

    for (int i = digits - 1; i >= 0; i--) {
      str[startPos + digits - i - 1] = temp[i];
    }
  }

  cout << str;
}

// -----------------------------------------------------------------------------
// Implement an algorithm to determine if a string has all unique characters.
// -----------------------------------------------------------------------------
int hasAllUniqueCharacters(char* str) {
  // Reset table
  char letters[256];
  for (int i = 0; i < 256; i++) {
    letters[i] = 0;
  }

  for (int i = 0; i < strlen(str); i++) {
    // If the letter has never appeared, mark it as appeared
    if (letters[str[i]] == 0) {
      letters[str[i]] = 1;
    }
    // The letter has appeared before, it's now duplicated!
    else {
      cout << str[i] << " is duplicated!" << endl;
      return false;
    }
  }

  cout << "This string has all unique characters." << endl;
  return true;
}

// -----------------------------------------------------------------------------
// Implement an algorithm to determine if a string has all unique characters.
// Without using additional data structures
// -----------------------------------------------------------------------------
int hasAllUniqueCharacters2(char* str) {
  for (int i = 0; i < strlen(str) - 1; i++) {
    for (int j = i + 1; j < strlen(str); j++) {
      if (str[i] == str[j]) {
        cout << str[i] << " is duplicated!" << endl;
        return false;
      }
    }
  }

  cout << "This string has all unique characters." << endl;
  return true;
}

// -----------------------------------------------------------------------------
// Design an algorithm and write code to remove the duplicate characters
// in a string without using any additional buffer.
// NOTE: One or two additional variables are fine. An extra copy of the array
// is not.
// -----------------------------------------------------------------------------
void removeDuplicate(char* str) {
//  for (int i = 0; i < strlen(str) - 1; i++) {
//    for (int j = i + 1; j < strlen(str); j++) {
//      if (str[i] == str[j]) {
//        for (int k = j; k < strlen(str); k++) {
//          str[k] = str[k+1];
//        }
//        j--;
//      }
//    }
//  }
//  cout << str << endl;

  // SPECIAL CASE: string is empty or has only 1 character
  if (str == NULL || strlen(str) <= 1) {
    return;
  }

  int p = 1;
  for (int i = 1; i < strlen(str); i++) {
    bool dup = false;
    for (int j = 0; j < p; j++) {
      if (str[j] == str[i]) {
        dup = true;
        break;
      }
    }
    if (!dup) {
      str[p] = str[i];
      p++;
    }
  }
  str[p] = '\0';
  cout << str;
}

// -----------------------------------------------------------------------------
// Check anagrams
// -----------------------------------------------------------------------------
void checkAnagrams(char* str1, char* str2) {
  char letters[256];

  // SPECIAL CASES: Null strings or the lengths are not equal
  if (str1 == NULL || str2 == NULL || strlen(str1) != strlen(str2)) {
    cout << "Not anagrams" << endl;
    return;
  }

  // Reset check array
  for (int i = 0; i < 256; i++) {
    letters[i] = 0;
  }

  // Count the number of letters in str1 & str2
  for (int i = 0; i < strlen(str1); i++) {
    letters[str1[i]]++;
    letters[str2[i]]--;
  }

  // Check if they are anagrams
  for (int i = 0; i < 256; i++) {
    if (letters[i] != 0) {
      cout << "Not anagrams" << endl;
      return;
    }
  }

  cout << "Anagrams" << endl;
}

// -----------------------------------------------------------------------------
// Write a method to replace all spaces in a string with "%20"
// -----------------------------------------------------------------------------
void replaceSpace(char* str) {
  // SPECIAL CASE: null string and empty string
  if (str == NULL || strlen(str) == 0) {
    return;
  }

  char newstr[1024];
  int currentPosition = 0;
  for (int i = 0; i < strlen(str); i++) {
    if (str[i] != ' ') {
      newstr[currentPosition++] = str[i];
    }
    else {
      newstr[currentPosition++] = '%';
      newstr[currentPosition++] = '2';
      newstr[currentPosition++] = '0';
    }
  }
  newstr[currentPosition] = 0;
  cout << newstr << endl;
}

// -----------------------------------------------------------------------------
// Find the longest palindrome in a string
// -----------------------------------------------------------------------------
void findLongestPalindrome(char* str) {
  // Get the length of the input string
  int n = strlen(str);

  // Palindrome information
  int maxBegin = 0; // The beginning position
  int maxEnd = 0; // The ending position
  int maxLength = 0; // The length of the palindrome

  for (int i = 0; i < n; i++) { // i will go from left --> right
    for (int j = n - 1; j >= i; j--) { // j will go from right --> left
      // a[i] and a[j] are the same,
      // now check if the characters in between can create a palindrome
      if (str[j] == str[i]) {
        int p1 = i + 1;
        int p2 = j - 1;

        // there are 2 cases here
        // 1. Palindrome with odd number of characters (abbAbba)
        // 2. Palindrome with even number of characters (abbbba)
        bool isPalindrome = true;
        while (p1 < p2) {
          if (str[p1] == str[p2]) {
            p1++;
            p2--;
          }
          else {
            isPalindrome = false;
            break;
          }
        }

        // if we find a palindrome, check with the current one
        if (isPalindrome) {
          int length = j - i + 1;
          if (length > maxLength) {
            maxBegin = i;
            maxEnd = j;
            maxLength = j - i + 1;
          }
        }
      }
    }
  }

  cout << "Max palindrome: " << maxBegin << " --> " << maxEnd <<
    ", " << "length = " << maxLength << endl;
}

// -----------------------------------------------------------------------------
// Main function, nothing much in this one
// -----------------------------------------------------------------------------
int main(int argc, char* argv[]) {
//  firstNonRepeated(NULL);

//  char str[256] = "Battle of the Vowels: Hawaii vs. Gronzy.";
//  char remove[256] = "aeiou";
//  removeCharacters(str, remove);

//  char str[256] = "Do or do not, there is no try.";
//  reserveWords(str);

//  char str[256] = "1";
//  convertStringToInteger(str);

//  convertIntegerToString(-545);

//  char str[256] = "acbf g";
//  hasAllUniqueCharacters2(str);

  char str[256] = "abacdbcaeaf abccd";
  removeDuplicate(str);

//  char str1[256] = "dog";
//  char str2[256] = "god ";
//  checkAnagrams(str1, str2);

//  char str[256] = " test if you can replace me ";
//  replaceSpace(str);

//  findLongestPalindrome("abcdbce");

  return 0;
}
*/
