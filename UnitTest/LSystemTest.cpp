#include <gtest/gtest.h>
#include "LSystem.h"

TEST(LSystem, GetString) {
	LSystem model("F-F-F-F", "F", "F-F+F+FF-F-F+F");
	ASSERT_STREQ(model.GetString(0).c_str(), "F-F-F-F");
}

TEST(LSystem, GetStringTick1) {
	LSystem model("F-F-F-F", "F", "F-F+F+FF-F-F+F");
	ASSERT_STREQ(model.GetString(1).c_str(), "F-F+F+FF-F-F+F-F-F+F+FF-F-F+F-F-F+F+FF-F-F+F-F-F+F+FF-F-F+F");
}

TEST(LSystem, ClearRule) {
	LSystem model("b", "b", "ab");
	model.ClearRule();
	ASSERT_STREQ(model.GetString(1).c_str(), "b");
}

TEST(LSystem, SetInitialString) {
	LSystem model("b", "b", "ab");
	model.SetInitialString("hoge");
	ASSERT_STREQ(model.GetString(1).c_str(), "hoge");
}

// 参考サイトのサンプル動作の動きをすることを確認
// 初期文字列    : b
// 書き換え規則1 : a -> ab
// 書き換え規則2 : b -> a
// b -> a -> ab -> aba -> abaab -> abaababa -> ...
TEST(LSystem, SampleTest) {
	LSystem model("b", "a", "ab");
	model.AddRule("b", "a");
	ASSERT_STREQ(model.GetString(0).c_str(), "b");
	ASSERT_STREQ(model.GetString(1).c_str(), "a");
	ASSERT_STREQ(model.GetString(2).c_str(), "ab");
	ASSERT_STREQ(model.GetString(3).c_str(), "aba");
	ASSERT_STREQ(model.GetString(4).c_str(), "abaab");
	ASSERT_STREQ(model.GetString(5).c_str(), "abaababa");
}
