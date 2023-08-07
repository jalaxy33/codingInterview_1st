// 面试题33：二叉搜索树的后序遍历序列
// 题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。
// 如果是则返回true，否则返回false。假设输入的数组的任意两个数字都互不相同。

#include <cstdint>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
   public:
    // 二叉搜索树的后序遍历序列：{左子树(小于根), 右子树(大于根), 根}
    bool verifyPostorder( vector<int>& postorder, bool use_recur = false ) {
        if ( postorder.empty() ) return true;
        if ( use_recur )
            return withRecur( postorder );
        else
            return withStack( postorder );
    }

   private:
    // 递归法
    bool withRecur( vector<int>& postorder ) {
        return recur( postorder, 0, postorder.size() - 1 );
    }

    // 递归[i,j]区间，后序中j为根节点
    bool recur( vector<int>& postorder, int i, int j ) {
        // 终止条件：i>=j
        if ( i >= j ) return true;
        // 划分左右子树
        // 找到第一个大于根节点的节点，记为m
        int p = i;
        while ( postorder[ p ] < postorder[ j ] ) p++;
        int m = p;
        // 右区间内所有元素都应该大于根节点
        while ( postorder[ p ] > postorder[ j ] ) p++;
        // 在左右子树递归
        return p == j && recur( postorder, i, m - 1 ) &&
               recur( postorder, m, j - 1 );
    }

    // 利用辅助单调栈。
    // 左子树<根<右子树，满足一定的单调性。
    // 倒序遍历后序列表，按顺序根节点和右子树先入栈
    // 此时栈内元素单调递增，栈顶永远是当前最大。
    // 每当遇到递减的节点（即进入左子树），则使栈顶出栈并成为新的curMax。
    // 每轮遍历判断当前节点ri与root的关系：
    // 1）若ri>curMax，说明不符合搜索树定义，return false。
    // 2）否则，继续遍历
    bool withStack( vector<int>& postorder ) {
        stack<int> stk;  // 维护一个单调栈
        int curMax = INT32_MAX;
        // 倒序遍历后序列表
        for ( int i = postorder.size() - 1; i >= 0; i-- ) {
            if ( postorder[ i ] > curMax ) return false;
            while ( !stk.empty() && stk.top() > postorder[ i ] ) {
                curMax = stk.top();
                stk.pop();
            }
            stk.push( postorder[ i ] );
        }
        return true;
    }
};

class Test {
   public:
    void checkResult( const string testName, vector<int>& postorder,
                      bool expected ) {
        cout << testName;
        bool result = solution.verifyPostorder( postorder );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    //            10
    //         /      \
    //        6        14
    //       /\        /\
    //      4  8     12  16
    void Test1() {
        vector<int> postorder{ 4, 8, 6, 12, 16, 14, 10 };
        checkResult( "Test1", postorder, true );
    }

    //           5
    //          / \
    //         4   7
    //            /
    //           6
    void Test2() {
        vector<int> postorder{ 4, 6, 7, 5 };
        checkResult( "Test2", postorder, true );
    }

    //               5
    //              /
    //             4
    //            /
    //           3
    //          /
    //         2
    //        /
    //       1
    void Test3() {
        vector<int> postorder{ 1, 2, 3, 4, 5 };
        checkResult( "Test3", postorder, true );
    }

    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    //        \
    //         5
    void Test4() {
        vector<int> postorder{ 5, 4, 3, 2, 1 };
        checkResult( "Test4", postorder, true );
    }

    // 树中只有1个结点
    void Test5() {
        vector<int> postorder{ 5 };
        checkResult( "Test5", postorder, true );
    }

    // 不是后序遍历
    void Test6() {
        vector<int> postorder{ 7, 4, 6, 5 };
        checkResult( "Test6", postorder, false );
    }

    // 不是后序遍历
    void Test7() {
        vector<int> postorder{ 4, 6, 12, 8, 16, 14, 10 };
        checkResult( "Test7", postorder, false );
    }

    // 空列表
    void Test8() {
        vector<int> postorder;
        checkResult( "Test8", postorder, true );
    }

    void runTest() {
        Test1();
        Test2();
        Test3();
        Test4();
        Test5();
        Test6();
        Test7();
        Test8();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}