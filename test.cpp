#include "iostream"
#include "set"
using namespace std;
int main()
{
    set<int> s1 {1, 2, 3, 100};
    set<int> s2 {1, 2, 3};
    
    s1.erase(s2.cbegin(), s2.cend());
    cout << s1.size();

}
