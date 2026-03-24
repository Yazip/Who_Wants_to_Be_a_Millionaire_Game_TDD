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

		// Тестовые методы для проверки работы метода для проверки правильности ответа данного игроком

		// Игрок дал правильный ответ
		TEST_METHOD(TestCheckAnswerCorrect)
		{
			Question question;
			question.set_correct_answer_index(0);
			Assert::IsTrue(question.check_answer(0));
		}

		// Игрок дал неправильный ответ
		TEST_METHOD(TestCheckAnswerWrong)
		{
			Question question;
			question.set_correct_answer_index(1);
			Assert::IsFalse(question.check_answer(0));
		}

		// Тестовый метод для проверки задания значения полю text класса Question
		TEST_METHOD(TestSetText)
		{
			Question question;
			question.set_text("Какая страна является родиной чая?");
			Assert::AreEqual((std::string)"Какая страна является родиной чая?", question.get_text());
		}
	};
}