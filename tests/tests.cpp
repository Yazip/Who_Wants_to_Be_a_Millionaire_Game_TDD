#include "pch.h"
#include "CppUnitTest.h"

#include "../src/question.h"

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
	};
}