add_rules("mode.debug", "mode.release")

target("demo")
    set_kind("binary")
    add_files("src/*.cpp")
    set_default(false)
    set_filename("out")

-- 工具函数库

target("utils")
    set_kind("static")
    add_files("src/Utilities/**.cpp")
    add_headerfiles("src/Utilities/**.h")



-- 01. 数据结构
target("05_ReplaceSpaces")
    set_kind("binary")
    add_deps("utils")
    add_files("src/05_*/*.cpp")
    set_default(false)
    set_filename("out")

target("06_PrintListInReversedOrder")
    set_kind("binary")
    add_deps("utils")
    add_files("src/06_*/*.cpp")
    set_default(false)
    set_filename("out")


target("09_QueueWithTwoStacks")
    set_kind("binary")
    add_deps("utils")
    add_files("src/09_*/*.cpp")
    set_default(false)
    set_filename("out")


target("20_NumericStrings")
    set_kind("binary")
    add_deps("utils")
    add_files("src/20_*/*.cpp")
    set_default(false)
    set_filename("out")


target("24_ReverseList")
    set_kind("binary")
    add_deps("utils")
    add_files("src/24_*/*.cpp")
    set_default(false)
    set_filename("out")


target("30_MinInStack")
    set_kind("binary")
    add_deps("utils")
    add_files("src/30_*/*.cpp")
    set_default(false)
    set_filename("out")

target("35_CopyComplexList")
    set_kind("binary")
    add_deps("utils")
    add_files("src/35_*/*.cpp")
    set_default(false)
    set_filename("out")


target("58_02_LeftRotateString")
    set_kind("binary")
    add_deps("utils")
    add_files("src/58_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("59_01_MaxInSlidingWindow")
    set_kind("binary")
    add_deps("utils")
    add_files("src/59_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("59_02_QueueWithMax")
    set_kind("binary")
    add_deps("utils")
    add_files("src/59_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("67_StringToInt")
    set_kind("binary")
    add_deps("utils")
    add_files("src/67_*/*.cpp")
    set_default(false)
    set_filename("out")



-- 02. 动态规划

target("10_01_Fibonacci")
    set_kind("binary")
    add_deps("utils")
    add_files("src/10_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("10_02_FrogJumpStairs")
    set_kind("binary")
    add_deps("utils")
    add_files("src/10_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("19_RegularExpressionsMatching")
    set_kind("binary")
    add_deps("utils")
    add_files("src/19_*/*.cpp")
    set_default(false)
    set_filename("out")


target("42_GreatestSumOfSubarrays")
    set_kind("binary")
    add_deps("utils")
    add_files("src/42_*/*.cpp")
    set_default(false)
    set_filename("out")


target("46_GreatestSumOfSubarrays")
    set_kind("binary")
    add_deps("utils")
    add_files("src/46_*/*.cpp")
    set_default(false)
    set_filename("out")


target("47_MaxValueOfGifts")
    set_kind("binary")
    add_deps("utils")
    add_files("src/47_*/*.cpp")
    set_default(false)
    set_filename("out")


target("48_LongestSubstringWithoutDup")
    set_kind("binary")
    add_deps("utils")
    add_files("src/48_*/*.cpp")
    set_default(false)
    set_filename("out")


target("49_UglyNumber")
    set_kind("binary")
    add_deps("utils")
    add_files("src/49_*/*.cpp")
    set_default(false)
    set_filename("out")


target("60_DicesProbability")
    set_kind("binary")
    add_deps("utils")
    add_files("src/60_*/*.cpp")
    set_default(false)
    set_filename("out")


target("63_MaximalProfit")
    set_kind("binary")
    add_deps("utils")
    add_files("src/63_*/*.cpp")
    set_default(false)
    set_filename("out")


-- 03. 搜索与回溯

target("12_StringPathInMatrix")
    set_kind("binary")
    add_deps("utils")
    add_files("src/12_*/*.cpp")
    set_default(false)
    set_filename("out")


target("13_RobotMove")
    set_kind("binary")
    add_deps("utils")
    add_files("src/13_*/*.cpp")
    set_default(false)
    set_filename("out")


target("26_SubstructureInTree")
    set_kind("binary")
    add_deps("utils")
    add_files("src/26_*/*.cpp")
    set_default(false)
    set_filename("out")


target("27_MirrorOfBinaryTree")
    set_kind("binary")
    add_deps("utils")
    add_files("src/27_*/*.cpp")
    set_default(false)
    set_filename("out")


target("28_SymmetricalBinaryTree")
    set_kind("binary")
    add_deps("utils")
    add_files("src/28_*/*.cpp")
    set_default(false)
    set_filename("out")


target("32_01_PrintTreeFromTopToBottom")
    set_kind("binary")
    add_deps("utils")
    add_files("src/32_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("32_02_PrintTreesInLines")
    set_kind("binary")
    add_deps("utils")
    add_files("src/32_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("32_03_PrintTreesInZigzag")
    set_kind("binary")
    add_deps("utils")
    add_files("src/32_03_*/*.cpp")
    set_default(false)
    set_filename("out")


target("34_PathInTree")
    set_kind("binary")
    add_deps("utils")
    add_files("src/34_*/*.cpp")
    set_default(false)
    set_filename("out")


target("36_ConvertBinarySearchTree")
    set_kind("binary")
    add_deps("utils")
    add_files("src/36_*/*.cpp")
    set_default(false)
    set_filename("out")


target("37_SerializeBinaryTrees")
    set_kind("binary")
    add_deps("utils")
    add_files("src/37_*/*.cpp")
    set_default(false)
    set_filename("out")


target("38_StringPermutation")
    set_kind("binary")
    add_deps("utils")
    add_files("src/38_*/*.cpp")
    set_default(false)
    set_filename("out")


target("54_KthNodeInBST")
    set_kind("binary")
    add_deps("utils")
    add_files("src/54_*/*.cpp")
    set_default(false)
    set_filename("out")


target("55_01_TreeDepth")
    set_kind("binary")
    add_deps("utils")
    add_files("src/55_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("55_02_BalancedBinaryTree")
    set_kind("binary")
    add_deps("utils")
    add_files("src/55_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("64_Accumulate")
    set_kind("binary")
    add_deps("utils")
    add_files("src/64_*/*.cpp")
    set_default(false)
    set_filename("out")


target("68_01_CommonParentInSearchTree")
    set_kind("binary")
    add_deps("utils")
    add_files("src/68_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("68_02_CommonParentInBinaryTree")
    set_kind("binary")
    add_deps("utils")
    add_files("src/68_02_*/*.cpp")
    set_default(false)
    set_filename("out")


-- 04. 分治

target("07_ConstructBinaryTree")
    set_kind("binary")
    add_deps("utils")
    add_files("src/07_*/*.cpp")
    set_default(false)
    set_filename("out")


target("16_Power")
    set_kind("binary")
    add_deps("utils")
    add_files("src/16_*/*.cpp")
    set_default(false)
    set_filename("out")


target("17_Print1ToMaxOfNDigits")
    set_kind("binary")
    add_deps("utils")
    add_files("src/17_*/*.cpp")
    set_default(false)
    set_filename("out")


target("33_SquenceOfBST")
    set_kind("binary")
    add_deps("utils")
    add_files("src/33_*/*.cpp")
    set_default(false)
    set_filename("out")


target("51_InversePairs")
    set_kind("binary")
    add_deps("utils")
    add_files("src/51_*/*.cpp")
    set_default(false)
    set_filename("out")


-- 05. 排序

target("40_KLeastNumbers")
    set_kind("binary")
    add_deps("utils")
    add_files("src/40_*/*.cpp")
    set_default(false)
    set_filename("out")


target("41_StreamMedian")
    set_kind("binary")
    add_deps("utils")
    add_files("src/41_*/*.cpp")
    set_default(false)
    set_filename("out")


target("45_StreamMedian")
    set_kind("binary")
    add_deps("utils")
    add_files("src/45_*/*.cpp")
    set_default(false)
    set_filename("out")


target("61_ContinousCards")
    set_kind("binary")
    add_deps("utils")
    add_files("src/61_*/*.cpp")
    set_default(false)
    set_filename("out")


-- 06. 查找

target("03_DuplicationInArray")
    set_kind("binary")
    add_deps("utils")
    add_files("src/03_*/*.cpp")
    set_default(false)
    set_filename("out")


target("04_FindInPartiallySortedMatrix")
    set_kind("binary")
    add_deps("utils")
    add_files("src/04_*/*.cpp")
    set_default(false)
    set_filename("out")


target("11_MinNumberInRotatedArray")
    set_kind("binary")
    add_deps("utils")
    add_files("src/11_*/*.cpp")
    set_default(false)
    set_filename("out")


target("50_FirstNotRepeatingChar")
    set_kind("binary")
    add_deps("utils")
    add_files("src/50_*/*.cpp")
    set_default(false)
    set_filename("out")


target("53_01_NumberOfK")
    set_kind("binary")
    add_deps("utils")
    add_files("src/53_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("53_02_MissingNumber")
    set_kind("binary")
    add_deps("utils")
    add_files("src/53_02_*/*.cpp")
    set_default(false)
    set_filename("out")


-- 07. 双指针

target("18_DeleteNodeInList")
    set_kind("binary")
    add_deps("utils")
    add_files("src/18_*/*.cpp")
    set_default(false)
    set_filename("out")


target("21_ReorderArray")
    set_kind("binary")
    add_deps("utils")
    add_files("src/21_*/*.cpp")
    set_default(false)
    set_filename("out")


target("22_KthNodeFromEnd")
    set_kind("binary")
    add_deps("utils")
    add_files("src/22_*/*.cpp")
    set_default(false)
    set_filename("out")


target("25_MergeSortedLists")
    set_kind("binary")
    add_deps("utils")
    add_files("src/25_*/*.cpp")
    set_default(false)
    set_filename("out")


target("52_FirstCommonNodesInLists")
    set_kind("binary")
    add_deps("utils")
    add_files("src/52_*/*.cpp")
    set_default(false)
    set_filename("out")


target("57_01_TwoNumbersWithSum")
    set_kind("binary")
    add_deps("utils")
    add_files("src/57_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("58_01_ReverseWordsInSentence")
    set_kind("binary")
    add_deps("utils")
    add_files("src/58_01_*/*.cpp")
    set_default(false)
    set_filename("out")


-- 08. 位运算

target("15_NumberOf1InBinary")
    set_kind("binary")
    add_deps("utils")
    add_files("src/15_*/*.cpp")
    set_default(false)
    set_filename("out")


target("56_01_NumbersAppearOnce")
    set_kind("binary")
    add_deps("utils")
    add_files("src/56_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("56_02_NumberAppearingOnce")
    set_kind("binary")
    add_deps("utils")
    add_files("src/56_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("65_AddTwoNumbers")
    set_kind("binary")
    add_deps("utils")
    add_files("src/65_*/*.cpp")
    set_default(false)
    set_filename("out")


-- 09. 数学

target("14_01_CuttingRope")
    set_kind("binary")
    add_deps("utils")
    add_files("src/14_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("14_02_CuttingRope")
    set_kind("binary")
    add_deps("utils")
    add_files("src/14_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("39_MoreThanHalfNumber")
    set_kind("binary")
    add_deps("utils")
    add_files("src/39_*/*.cpp")
    set_default(false)
    set_filename("out")


target("43_NumberOf1")
    set_kind("binary")
    add_deps("utils")
    add_files("src/43_*/*.cpp")
    set_default(false)
    set_filename("out")


target("44_DigitsInSequence")
    set_kind("binary")
    add_deps("utils")
    add_files("src/44_*/*.cpp")
    set_default(false)
    set_filename("out")


target("57_02_ContinuousSquenceWithSum")
    set_kind("binary")
    add_deps("utils")
    add_files("src/57_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("62_LastNumberInCircle")
    set_kind("binary")
    add_deps("utils")
    add_files("src/62_*/*.cpp")
    set_default(false)
    set_filename("out")


target("66_ConstuctArray")
    set_kind("binary")
    add_deps("utils")
    add_files("src/66_*/*.cpp")
    set_default(false)
    set_filename("out")



--
-- If you want to known more usage about xmake, please see https://xmake.io
--
-- ## FAQ
--
-- You can enter the project directory firstly before building project.
--
--   $ cd projectdir
--
-- 1. How to build project?
--
--   $ xmake
--
-- 2. How to configure project?
--
--   $ xmake f -p [macosx|linux|iphoneos ..] -a [x86_64|i386|arm64 ..] -m [debug|release]
--
-- 3. Where is the build output directory?
--
--   The default output directory is `./build` and you can configure the output directory.
--
--   $ xmake f -o outputdir
--   $ xmake
--
-- 4. How to run and debug target after building project?
--
--   $ xmake run [targetname]
--   $ xmake run -d [targetname]
--
-- 5. How to install target to the system directory or other output directory?
--
--   $ xmake install
--   $ xmake install -o installdir
--
-- 6. Add some frequently-used compilation flags in xmake.lua
--
-- @code
--    -- add debug and release modes
--    add_rules("mode.debug", "mode.release")
--
--    -- add macro definition
--    add_defines("NDEBUG", "_GNU_SOURCE=1")
--
--    -- set warning all as error
--    set_warnings("all", "error")
--
--    -- set language: c99, c++11
--    set_languages("c99", "c++11")
--
--    -- set optimization: none, faster, fastest, smallest
--    set_optimize("fastest")
--
--    -- add include search directories
--    add_includedirs("/usr/include", "/usr/local/include")
--
--    -- add link libraries and search directories
--    add_links("tbox")
--    add_linkdirs("/usr/local/lib", "/usr/lib")
--
--    -- add system link libraries
--    add_syslinks("z", "pthread")
--
--    -- add compilation and link flags
--    add_cxflags("-stdnolib", "-fno-strict-aliasing")
--    add_ldflags("-L/usr/local/lib", "-lpthread", {force = true})
--
-- @endcode
--

