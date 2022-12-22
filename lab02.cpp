#include <iostream>
#include <string>
#include <vector>
#include "grammar.h"
using namespace std;
#define DEBUG 0
// Define the strip() and split() functions here...

#if DEBUG == 1
// Test the strip() function
void test_strip() {
  std::vector<std::pair<std::string, std::string> > test_cases = {
    { "   hello   ", "hello" },
    { "hello", "hello" },
    { "   ", "" },
    { "", "" },
    { "hello world", "hello world" },
    { "   hello world   ", "hello world" },
  };
    Grammar grammar;
  std::cout << "Testing strip()..." << std::endl;
  for (const auto& [src, expected] : test_cases) {
    std::string result = Grammar::mystrip(src);
    if (result != expected) {
        std::cout << "Failed:  => " <<  expected.length() << " " << result.length() << std::endl;
      std::cout << "Failed: strip(" << src << ") => " << result << std::endl;
    } else {
      std::cout << "Passed: strip(" << src << ")" << std::endl;
    }
  }
}

void run_tests() {
    // Test 1: Check that the function can split a string with multiple occurrences of the splitting character.
    string test_string = "This is a test";
    char splitting_char = ' ';
    vector<string> expected_output = {"This", "is", "a", "test"};
    vector<string> actual_output = Grammar::mysplit(test_string, splitting_char);
    if (actual_output != expected_output) {
        cout << "Test 1 failed: The function was unable to split the string correctly." << endl;
        cout << "Expected output: ";
        for (const auto& s : expected_output) {
            cout << s << " ";
        }
        cout << endl;
        cout << "Actual output: ";
        for (const auto& s : actual_output) {
            cout << s << " ";
        }
        cout << endl;
    }

    // Test 2: Check that the function can handle a string that contains only the splitting character.
    test_string = ",,,";
    splitting_char = ',';
    expected_output = {};
    actual_output = Grammar::mysplit(test_string, splitting_char);
    if (actual_output != expected_output) {
        cout << "Test 2 failed: The function was unable to split the string correctly." << endl;
        cout << "Expected output: ";
        for (const auto& s : expected_output) {
            cout << s << " ";
        }
        cout << endl;
        cout << "Actual output: ";
        for (const auto& s : actual_output) {
            cout << s << " ";
        }
        cout << endl;
    }

    // Test 3: Check that the function can handle a string that contains no occurrences of the splitting character.
    test_string = "This is a test";
    splitting_char = '|';
    expected_output = {"This is a test"};
    actual_output = Grammar::mysplit(test_string, splitting_char);
    if (actual_output != expected_output) {
        cout << "Test 3 failed: The function was unable to split the string correctly." << endl;
        cout << "Expected output: ";
        for (const auto& s : expected_output) {
            cout << s << " ";
        }
        cout << endl;
        cout << "Actual output: ";
        for (const auto& s : actual_output) {
            cout << s << " ";
        }
        cout << endl;
    }

    // Test 4: Check that the function can handle an empty string as input.
    test_string = "";
    splitting_char = ',';
    expected_output = {};
    actual_output = Grammar::mysplit(test_string, splitting_char);
    if (actual_output != expected_output) {
        cout << "Test 4 failed: The function was unable to split the string correctly." << endl;
        cout << "Expected output: ";
        for (const auto& s : expected_output) {
            cout << s << " ";
        }
        cout << endl;
        cout << "Actual output: ";
        for (const auto& s : actual_output) {
            cout << s << " ";
        }
        cout << endl;
    }

        // Test 5: Check that the function can handle a string with leading and trailing whitespace.
    test_string = "   This is a test   ";
    splitting_char = ' ';
    expected_output = {"This", "is", "a", "test"};
    actual_output = Grammar::mysplit(test_string, splitting_char);
    if (actual_output != expected_output) {
        cout << "Test 5 failed: The function was unable to split the string correctly." << endl;
        cout << "Expected output: ";
        for (const auto& s : expected_output) {
            cout << s << " ";
        }
        cout << endl;
        cout << "Actual output: ";
        for (const auto& s : actual_output) {
            cout << s << " ";
        }
        cout << endl;
    }

    // Test 6: Check that the function can handle a string with multiple consecutive occurrences of the splitting character.
    test_string = "This,,,is,a,test";
    splitting_char = ',';
    expected_output = {"This", "is", "a", "test"};
    actual_output = Grammar::mysplit(test_string, splitting_char);
    if (actual_output != expected_output) {
        cout << "Test 6 failed: The function was unable to split the string correctly." << endl;
        cout << "Expected output: ";
        for (const auto& s : expected_output) {
            cout << s << " ";
        }
        cout << endl;
        cout << "Actual output: ";
        for (const auto& s : actual_output) {
            cout << s << " ";
        }
        cout << endl;
    }
}
#endif 

int main()
{
    Grammar grammar;
    grammar.read_generator_list("grammar.txt");
    grammar.print_grammar();
    grammar.print_non_termial();
    grammar.print_termial();

    return 0;
}
