#include <iostream>
#include <string>

using namespace std;

class Solution {};

class Test {
   public:
    void checkResult( const string testName ) {}

    void runTest() {}

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}