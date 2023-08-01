# 《剑指offer》练习集


这是个人的《剑指offer》（第一册）练习题库，目前使用的语言是C++和python。已完成的练习在 `src/` 目录下，C++程序使用 `xmake` 工具构建。已提供测试用例，无需安装任何第三方库。

- [已完成练习列表](./Finished.md)

## 运行环境工具链
- [xmake](https://xmake.io/#/)
- python
- gcc or clang
- [optional] vscode & xmake插件


## 使用方式

### C++ 代码
1. 在运行习题对应的cpp程序时，请将 `xmake.lua` 中对应题目target的 `set_default(false)` 字段使用 `--` 进行注释。
2. 使用xmake对程序进行编译后运行，推荐使用vscode及xmake插件，更加方便。
```bash
# 首次使用xmake需要进行config，使用
xmake f -m debug [--toolchain=gcc]

# 编译
xmake -w

# 运行
xmake run {题目对应的target名称}
```

### Python 代码

进入 `src/` 目录下题目对应的目录，运行其中对应的`.py`程序即可。


## 参考资料

- [《剑指offer》官方参考代码的github仓库](https://github.com/zhulintao/CodingInterviewChinese2)
- [《图解数据结构》leetbook & OA系统](https://leetcode.cn/leetbook/detail/illustration-of-algorithm/)
- [xmake中文文档](https://xmake.io/#/zh-cn/about/introduction)




