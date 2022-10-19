#ifndef UNIT_TEST_H
#define UNIT_TEST_H

#include <stdbool.h>
#include <stdio.h>

bool assert_equals_double_Array(const char* msg, double expected[], double actual[], int n);
bool assert_equals_int_Array(const char* msg, int expected[], int actual[], int n);
bool assert_equals_char_Array(const char* msg, char expected[], char actual[], int n);

bool assert_true(const char* msg, bool actual);
bool assert_equals_char(const char* msg, char expected, char actual);
bool assert_equals_int(const char* msg, int expected, int actual);

#endif