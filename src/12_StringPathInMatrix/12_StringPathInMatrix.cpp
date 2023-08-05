// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

using Vec = vector<char>;
using Mat = vector<Vec>;

class Solution {
   public:
    // DFS+可行性剪枝
    bool exist( Mat& board, string word ) {
        rows = board.size(), cols = board[ 0 ].size();
        for ( int i = 0; i < rows; i++ ) {
            for ( int j = 0; j < cols; j++ ) {
                if ( dfs( board, word, i, j, 0 ) ) return true;
            }
        }
        return false;
    }

   private:
    int rows, cols;  // 全局变量，保存矩阵的行列数

    // 深度优先遍历，递归回溯搜索。搜索成功返回true，否则返回false。
    // i, j是当前搜索的矩阵坐标，k是当前搜索的s字符序号
    bool dfs( Mat& board, string& word, int i, int j, int k ) {
        // 递归的终止条件：
        // 失败条件：1) 越界, 2) 当前字符不合要求
        if ( i < 0 || i >= rows || j < 0 || j >= cols ||
             board[ i ][ j ] != word[ k ] )
            return false;
        // 成功条件：k抵达字符串末尾
        if ( k == word.size() - 1 ) return true;

        // 将访问过的坐标置为空，防止重复搜索
        board[ i ][ j ] = '\0';
        // 访问周围四个方向
        bool result = dfs( board, word, i - 1, j, k + 1 ) ||
                      dfs( board, word, i + 1, j, k + 1 ) ||
                      dfs( board, word, i, j - 1, k + 1 ) ||
                      dfs( board, word, i, j + 1, k + 1 );
        // 还原坐标初始值
        board[ i ][ j ] = word[ k ];
        return result;
    }
};

class Test {
   public:
    void checkResult( const string testName, Mat& board, string word,
                      bool expected ) {
        if ( !testName.empty() ) cout << testName;

        bool result = solution.exist( board, word );
        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    // ABCE
    // SFCS
    // ADEE

    // SEE
    void Test1() {
        Mat board{
            { 'A', 'B', 'C', 'E' },
            { 'S', 'F', 'C', 'S' },
            { 'A', 'D', 'E', 'E' },
        };
        string word = "SEE";
        checkResult( "Test1", board, word, true );
    }

    // ABTG
    // CFCS
    // JDEH

    // BFCE
    void Test2() {
        Mat board{
            { 'A', 'B', 'T', 'G' },
            { 'C', 'F', 'C', 'S' },
            { 'J', 'D', 'E', 'H' },
        };
        string word = "BFCE";
        checkResult( "Test2", board, word, true );
    }

    // ABTG
    // CFCS
    // JDEH

    // ABFB
    void Test3() {
        Mat board{
            { 'A', 'B', 'T', 'G' },
            { 'C', 'F', 'C', 'S' },
            { 'J', 'D', 'E', 'H' },
        };
        string word = "ABFB";
        checkResult( "Test3", board, word, false );
    }

    // ABCEHJIG
    // SFCSLOPQ
    // ADEEMNOE
    // ADIDEJFM
    // VCEIFGGS

    // SLHECCEIDEJFGGFIE
    void Test4() {
        Mat board{
            { 'A', 'B', 'C', 'E', 'H', 'J', 'I', 'G' },
            { 'S', 'F', 'C', 'S', 'L', 'O', 'P', 'Q' },
            { 'A', 'D', 'E', 'E', 'M', 'N', 'O', 'E' },
            { 'A', 'D', 'I', 'D', 'E', 'J', 'F', 'M' },
            { 'V', 'C', 'E', 'I', 'F', 'G', 'G', 'S' },
        };
        string word = "SLHECCEIDEJFGGFIE";
        checkResult( "Test4", board, word, true );
    }

    // ABCEHJIG
    // SFCSLOPQ
    // ADEEMNOE
    // ADIDEJFM
    // VCEIFGGS

    // SGGFIECVAASABCEHJIGQEM
    void Test5() {
        Mat board{
            { 'A', 'B', 'C', 'E', 'H', 'J', 'I', 'G' },
            { 'S', 'F', 'C', 'S', 'L', 'O', 'P', 'Q' },
            { 'A', 'D', 'E', 'E', 'M', 'N', 'O', 'E' },
            { 'A', 'D', 'I', 'D', 'E', 'J', 'F', 'M' },
            { 'V', 'C', 'E', 'I', 'F', 'G', 'G', 'S' },
        };
        string word = "SGGFIECVAASABCEHJIGQEM";
        checkResult( "Test5", board, word, true );
    }

    // ABCEHJIG
    // SFCSLOPQ
    // ADEEMNOE
    // ADIDEJFM
    // VCEIFGGS

    // SGGFIECVAASABCEEJIGOEM
    void Test6() {
        Mat board{
            { 'A', 'B', 'C', 'E', 'H', 'J', 'I', 'G' },
            { 'S', 'F', 'C', 'S', 'L', 'O', 'P', 'Q' },
            { 'A', 'D', 'E', 'E', 'M', 'N', 'O', 'E' },
            { 'A', 'D', 'I', 'D', 'E', 'J', 'F', 'M' },
            { 'V', 'C', 'E', 'I', 'F', 'G', 'G', 'S' },
        };
        string word = "SGGFIECVAASABCEEJIGOEM";
        checkResult( "Test6", board, word, false );
    }

    // ABCEHJIG
    // SFCSLOPQ
    // ADEEMNOE
    // ADIDEJFM
    // VCEIFGGS

    // SGGFIECVAASABCEHJIGQEMS
    void Test7() {
        Mat board{
            { 'A', 'B', 'C', 'E', 'H', 'J', 'I', 'G' },
            { 'S', 'F', 'C', 'S', 'L', 'O', 'P', 'Q' },
            { 'A', 'D', 'E', 'E', 'M', 'N', 'O', 'E' },
            { 'A', 'D', 'I', 'D', 'E', 'J', 'F', 'M' },
            { 'V', 'C', 'E', 'I', 'F', 'G', 'G', 'S' },
        };
        string word = "SGGFIECVAASABCEHJIGQEMS";
        checkResult( "Test7", board, word, false );
    }

    // AAAA
    // AAAA
    // AAAA

    // AAAAAAAAAAAA
    void Test8() {
        Mat board{
            { 'A', 'A', 'A', 'A' },
            { 'A', 'A', 'A', 'A' },
            { 'A', 'A', 'A', 'A' },
        };
        string word = "AAAAAAAAAAAA";
        checkResult( "Test8", board, word, true );
    }

    // AAAA
    // AAAA
    // AAAA

    // AAAAAAAAAAAAA
    void Test9() {
        Mat board{
            { 'A', 'A', 'A', 'A' },
            { 'A', 'A', 'A', 'A' },
            { 'A', 'A', 'A', 'A' },
        };
        string word = "AAAAAAAAAAAAA";
        checkResult( "Test9", board, word, false );
    }

    // A

    // A
    void Test10() {
        Mat board{ { 'A' } };
        string word = "A";
        checkResult( "Test10", board, word, true );
    }

    // A

    // B
    void Test11() {
        Mat board{ { 'A' } };
        string word = "B";
        checkResult( "Test11", board, word, false );
    }

    void Test12() {
        Mat board;
        string word = "";
        checkResult( "Test12", board, word, false );
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
        Test9();
        Test10();
        Test11();
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}
