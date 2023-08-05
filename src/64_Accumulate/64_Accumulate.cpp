// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
// 等关键字及条件判断语句（A?B:C）。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Solve {

class Solver {
   public:
    virtual int sum( int n ) = 0;
};

// ===============================
// 解法1：利用逻辑运算的短路效应+递归

class Solver1 : public Solver {
   public:
    int sum( int n ) override {
        // 利用短路运算充当真假判断：!n==false, !!n==true
        !!n && ( n += sum( n - 1 ) );
        return n;
    }
};

// =============================
// 解法2：利用构造函数+静态变量
class Solver2Temp {
   public:
    Solver2Temp() { N++, Sum += N; }

    static void reset() { N = 0, Sum = 0; }
    static int getSum() { return Sum; }

   private:
    static int N, Sum;  // 定义静态变量
};

int Solver2Temp::N = 0, Solver2Temp::Sum = 0;  // 静态变量需要初始化

class Solver2 : public Solver {
   public:
    int sum( int n ) override {
        Solver2Temp::reset();
        // 利用构造数组来替代循环
        Solver2Temp *tmp = new Solver2Temp[ n ];
        delete[] tmp;
        tmp = nullptr;
        return Solver2Temp::getSum();
    }
};

// ===========================
// 解法3：利用虚函数替代递归
class Solver3_A {
   public:
    virtual int getSum( int n ) { return 0; }
};

Solver3_A *solver3Arr[ 2 ];  // 替代递归的关键，在于定义存储两种情况的数组

class Solver3_B : public Solver3_A {
   public:
    virtual int getSum( int n ) {
        // 利用短路运算充当真假判断：!n==false, !!n==true
        // 根据真假在父类或子类的getSum函数中选择，从而实现递归
        return solver3Arr[ !!n ]->getSum( n - 1 ) + n;
    }
};

class Solver3 : public Solver {
   public:
    int sum( int n ) override {
        Solver3_A a;  // 父类
        Solver3_B b;  // 子类
        solver3Arr[ 0 ] = &a, solver3Arr[ 1 ] = &b;
        return solver3Arr[ 1 ]->getSum( n );  // 递归的起点
    }
};

// ====================================
// 解法4：利用函数指针，替代虚函数

typedef int ( *Solver4Func )( int );

int solver4Terminate( int n ) { return 0; }

int solver4GetSum( int n ) {
    // 与虚函数法的思路类似，用一个数组存储两类情况下的递归函数
    // 类内的函数指针（如以下列表内的）必须调用，因此此函数必须在类外定义
    static Solver4Func f[ 2 ] = { solver4Terminate, solver4GetSum };
    // 利用短路运算充当真假判断：!n==false, !!n==true
    return n + f[ !!n ]( n - 1 );
}

class Solver4 : public Solver {
   public:
    int sum( int n ) override { return solver4GetSum( n ); }
};

}  // namespace Solve


// ===============================
class Solution {
   public:
    // solver_i取值范围为1到4，对应4种解法
    int sumNums( int n, int solver_i = 1 ) {
        if ( solver_i )
            return solvers[ solver_i ]->sum( n );
        else
            return 0;
    }

    Solution() {
        solvers = SolVec{
            nullptr,
            new Solve::Solver1(),
            new Solve::Solver2(),
            new Solve::Solver3(),
            new Solve::Solver4(),
        };
    }

   private:
    using Solver = Solve::Solver;
    using SolVec = vector<Solver *>;

    SolVec solvers;
};

class Test {
   public:
    void checkResult( const string testName, int n, int expected ) {
        cout << testName;
        int result = solution.sumNums( n );

        if ( result == expected )
            cout << " passed.\n";
        else
            cout << " failed.\n";
    }

    void runTest() {
        checkResult( "Test1", 1, 1 );
        checkResult( "Test2", 5, 15 );
        checkResult( "Test3", 10, 55 );
        checkResult( "Test4", 0, 0 );
    }

   private:
    Solution solution;
};

int main() {
    Test test;
    test.runTest();
    return 0;
}