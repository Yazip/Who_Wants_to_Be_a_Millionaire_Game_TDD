#pragma once

class Question {
private:
	int correct_answer_index;
public:
	Question() = default;

	void set_correct_answer_index(int correct_answer_index);

	int get_correct_answer_index() const;
};