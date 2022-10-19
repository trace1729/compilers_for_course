#include <stdio.h>
#include <unit_test.h>

bool assert_true(const char* msg, bool actual) {
  if (!actual) {
    printf("Assertion error: expected %s to be true, but got false\n", msg);
    return false;
  } else {
    return true;
  }
}

bool assert_equals_char(const char* msg, char expected, char actual) {
  if (expected != actual) {
    printf("Assertion error: expected %s to be %c but got %c\n", msg, expected, actual);
    return false;
  } else {
    return true;
  }
}

bool assert_equals_int(const char* msg, int expected, int actual) {
  if (expected != actual) {
    printf("Assertion error: expected %s to be %d but got %d\n", msg, expected, actual);
    return false;
  } else {
    return true;
  }
}

bool assert_equals_double_Array(const char* msg, double expected[], double actual[], int n) {

  for (int i = 0; i < n; i++)
  {
    if (expected[i] != actual[i])
    {
      printf("%s\nAssertion error: expected %d th to be %lf but got %lf\n", msg, i,  expected[i], actual[i]);
      return false;
    }
  }
  return true;
}

bool assert_equals_int_Array(const char* msg, int expected[], int actual[], int n) {

  for (int i = 0; i < n; i++)
  {
    if (expected[i] != actual[i])
    {
      printf("%s\nAssertion error: expected %d th to be %dbut got %d\n", msg, i,  expected[i], actual[i]);
      return false;
    }
  }
  return true;
}   

bool assert_equals_char_Array(const char* msg, char expected[], char actual[], int n) {

  for (int i = 0; i < n; i++)
  {
    if (expected[i] != actual[i])
    {
      printf("%s\nAssertion error: expected %d th to be %cbut got %c\n", msg, i,  expected[i], actual[i]);
      return false;
    }
  }
  return true;
}   
