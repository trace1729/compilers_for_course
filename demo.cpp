#include <iostream>
#include <set>

int main()
{
    using namespace std;
    set<int> s = {1,2,3,4};
    for (auto & ss : s) {
        if (ss % 2) s.insert(ss*2);
        else s.insert(ss*2 + 1);
        cout << ss << endl;
    }
}
