#pragma once

class Question {
private:
	int correct_answer_index;
public:
	Question() = default;

	void set_correct_answer_index(int correct_answer_index);

	int get_correct_answer_index() const;

	bool check_answer(int answer_index) const; // Метод для проверки на правильность ответа выбранного игроком
};