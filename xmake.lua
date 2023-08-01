add_rules("mode.debug", "mode.release")

target("demo")
    set_kind("binary")
    add_files("src/*.cpp")
    set_default(false)
    set_filename("out")


-- 01. 数据结构
target("05_ReplaceSpaces")
    set_kind("binary")
    add_files("src/05_*/*.cpp")
    set_default(false)
    set_filename("out")

target("06_PrintListInReversedOrder")
    set_kind("binary")
    add_files("src/06_*/*.cpp")
    set_default(false)
    set_filename("out")


target("09_QueueWithTwoStacks")
    set_kind("binary")
    add_files("src/09_*/*.cpp")
    set_default(false)
    set_filename("out")


target("20_NumericStrings")
    set_kind("binary")
    add_files("src/20_*/*.cpp")
    set_default(false)
    set_filename("out")


target("24_ReverseList")
    set_kind("binary")
    add_files("src/24_*/*.cpp")
    set_default(false)
    set_filename("out")


target("30_MinInStack")
    set_kind("binary")
    add_files("src/30_*/*.cpp")
    set_default(false)
    set_filename("out")

target("35_CopyComplexList")
    set_kind("binary")
    add_files("src/35_*/*.cpp")
    set_default(false)
    set_filename("out")


target("58_02_LeftRotateString")
    set_kind("binary")
    add_files("src/58_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("59_01_MaxInSlidingWindow")
    set_kind("binary")
    add_files("src/59_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("59_02_QueueWithMax")
    set_kind("binary")
    add_files("src/59_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("67_StringToInt")
    set_kind("binary")
    add_files("src/67_*/*.cpp")
    set_default(false)
    set_filename("out")



-- 02. 动态规划

target("10_01_Fibonacci")
    set_kind("binary")
    add_files("src/10_01_*/*.cpp")
    set_default(false)
    set_filename("out")


target("10_02_FrogJumpStairs")
    set_kind("binary")
    add_files("src/10_02_*/*.cpp")
    set_default(false)
    set_filename("out")


target("19_RegularExpressionsMatching")
    set_kind("binary")
    add_files("src/19_*/*.cpp")
    set_default(false)
    set_filename("out")


target("42_GreatestSumOfSubarrays")
    set_kind("binary")
    add_files("src/42_*/*.cpp")
    set_default(false)
    set_filename("out")


target("46_GreatestSumOfSubarrays")
    set_kind("binary")
    add_files("src/46_*/*.cpp")
    set_default(false)
    set_filename("out")


target("47_MaxValueOfGifts")
    set_kind("binary")
    add_files("src/47_*/*.cpp")
    set_default(false)
    set_filename("out")


target("48_LongestSubstringWithoutDup")
    set_kind("binary")
    add_files("src/48_*/*.cpp")
    set_default(false)
    set_filename("out")


target("49_UglyNumber")
    set_kind("binary")
    add_files("src/49_*/*.cpp")
    set_default(false)
    set_filename("out")


target("60_DicesProbability")
    set_kind("binary")
    add_files("src/60_*/*.cpp")
    set_default(false)
    set_filename("out")


target("63_MaximalProfit")
    set_kind("binary")
    add_files("src/63_*/*.cpp")
    set_default(false)
    set_filename("out")



add_files("src/Utilities/**.cpp")
add_headerfiles("src/Utilities/**.h")




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

