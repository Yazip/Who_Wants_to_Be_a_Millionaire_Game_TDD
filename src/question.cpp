#include "question.h"

void Question::set_text(std::string text) {
	this->text = text;
}

void Question::set_correct_answer_index(int correct_answer_index) {
	this->correct_answer_index = correct_answer_index;
}

void Question::set_difficulty_level(int difficulty_level) {
	// TODO: реализовать полноценное установление уровня сложности вопроса
}

std::string Question::get_text() const {
	return this->text;
}

int Question::get_correct_answer_index() const {
	return this->correct_answer_index;
}

int Question::get_difficulty_level() const {
	// TODO: реализовать полноценный возврат уровня сложности вопроса
	return 1;
}

// Метод для проверки на правильность ответа выбранного игроком
bool Question::check_answer(int answer_index) const {
	return (answer_index == this->correct_answer_index);
}