// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 借用一个辅助栈，模拟压入/弹出操作是否成功
    bool validateStackSequences( vector<int>& pushed, vector<int>& popped ) {
        if ( pushed.empty() && popped.empty() ) return true;
        if ( pushed.empty() || popped.empty() ) return false;

        stack<int> stk;
        int i = 0;
        for ( int num : pushed ) {
            stk.push( num );
            while ( !stk.empty() && stk.top() == popped[ i ] ) {
                stk.pop();
                i++;
            }
        }
        return stk.empty();  // 所有压入模拟栈的都能出栈则成功
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& pushed,
                      vector<int>& popped, bool expected ) {
        cout << testName;
        bool result = solution.validateStackSequences( pushed, popped );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void Test1() {
        vector<int> pushed{ 1, 2, 3, 4, 5 };
        vector<int> popped{ 4, 5, 3, 2, 1 };

        checkResult( "Test1", pushed, popped, true );
    }

    void Test2() {
        vector<int> pushed{ 1, 2, 3, 4, 5 };
        vector<int> popped{ 3, 5, 4, 2, 1 };

        checkResult( "Test2", pushed, popped, true );
    }

    void Test3() {
        vector<int> pushed{ 1, 2, 3, 4, 5 };
        vector<int> popped{ 4, 3, 5, 1, 2 };

        checkResult( "Test3", pushed, popped, false );
    }

    void Test4() {
        vector<int> pushed{ 1, 2, 3, 4, 5 };
        vector<int> popped{ 3, 5, 4, 1, 2 };

        checkResult( "Test4", pushed, popped, false );
    }

    // push和pop序列只有一个数字
    void Test5() {
        vector<int> pushed{ 1 };
        vector<int> popped{ 2 };

        checkResult( "Test5", pushed, popped, false );
    }

    void Test6() {
        vector<int> pushed{ 1 };
        vector<int> popped{ 1 };

        checkResult( "Test6", pushed, popped, true );
    }

    void Test7() {
        vector<int> pushed;
        vector<int> popped;
        checkResult( "Test7", pushed, popped, true );
    }

    void Test8() {
        vector<int> pushed;
        vector<int> popped = {1};
        checkResult( "Test8", pushed, popped, false );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
