#include "question.h"

void Question::set_correct_answer_index(int correct_answer_index) {
	this->correct_answer_index = correct_answer_index;
}

int Question::get_correct_answer_index() const {
	return this->correct_answer_index;
}