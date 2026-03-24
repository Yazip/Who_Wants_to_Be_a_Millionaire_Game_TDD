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

		// Тестовые методы для проверки задания значения полю correct_answer_index класса Question

		TEST_METHOD(TestSetCorrectAnswerIndex1)
		{
			Question question;
			question.set_correct_answer_index(0);
			Assert::AreEqual(0, question.get_correct_answer_index());
		}

		TEST_METHOD(TestSetCorrectAnswerIndex2)
		{
			Question question;
			question.set_correct_answer_index(1);
			Assert::AreEqual(1, question.get_correct_answer_index());
		}
	};
}