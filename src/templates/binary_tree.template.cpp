/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

#include <iostream>
#include <string>
#include <vector>

#include "../Utilities/BinaryTree.h"

using namespace std;

using TreeNode = BinaryTreeNode;

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