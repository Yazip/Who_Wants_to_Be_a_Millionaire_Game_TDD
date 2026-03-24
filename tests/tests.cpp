#include "pch.h"
#include "CppUnitTest.h"

#include "../src/question.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace tests
{
	TEST_CLASS(WhoWantsToBeAMillionaireTests)
	{
	public:
		
		// Тестовый метод для проверки существования класса Question
		TEST_METHOD(TestQuestionClassExistence)
		{
			Question question;
			Assert::IsTrue(true); // При успешной компиляции считаем тест пройденным
		}

		// Тестовый метод для проверки задания значения полю correct_answer_index класса Question
		TEST_METHOD(TestSetCorrectAnswerIndex)
		{
			Question question;
			question.set_correct_answer_index(0);
			Assert::AreEqual(0, question.get_correct_answer_index());
		}
	};
}