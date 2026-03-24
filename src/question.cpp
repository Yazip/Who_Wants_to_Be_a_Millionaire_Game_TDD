#include "question.h"

void Question::set_text(std::string text) {
	// TODO: реализовать полноценное установление текста вопроса
}

void Question::set_correct_answer_index(int correct_answer_index) {
	this->correct_answer_index = correct_answer_index;
}

std::string Question::get_text() const {
	// TODO: реализовать полноценный возврат текста вопроса
	return "Какая страна является родиной чая?";
}

int Question::get_correct_answer_index() const {
	return this->correct_answer_index;
}

// Метод для проверки на правильность ответа выбранного игроком
bool Question::check_answer(int answer_index) const {
	return (answer_index == this->correct_answer_index);
}