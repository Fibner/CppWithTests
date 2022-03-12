#include "pch.h"
#include "CppUnitTest.h"
#include "../FirstcppWithTests/SearchText.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SearchTextTest
{
	TEST_CLASS(SearchTextTest)
	{
	public:

		TEST_METHOD(Count_char_test) {
			SearchText st("alamak ota");
			Assert::AreEqual(st.CountChar(), 10);
		}
		TEST_METHOD(Count_number_test) {
			SearchText st("al ama23kota");
			Assert::AreEqual(st.CountNumbers(), 2);
		}
		TEST_METHOD(Count_letter_test) {
			SearchText st("alam54ak ota");
			Assert::AreEqual(st.CountLetters(), 9);
		}
		TEST_METHOD(Count_vowel_test) {
			SearchText st("alam54akuota");
			Assert::AreEqual(st.CountVowels(), 6);
		}
		TEST_METHOD(Count_word_test) {
			SearchText st("adsa lam asdsdk uota");
			Assert::AreEqual(st.CountWords(4), 3);
		}
		TEST_METHOD(Count_tag_test) {
			SearchText st("<p>ads < a > la<div>m a<ds>sds<grr>dk <uota");
			Assert::AreEqual(st.CountTags(), 4);
		}
	};
}
