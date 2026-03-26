#pragma once

#include <iostream>

class Question {
private:
	std::string text;
	int correct_answer_index = 0;
public:
	Question() = default;

	void set_correct_answer_index(int correct_answer_index);
	void set_text(std::string text);
	void set_difficulty_level(int difficulty_level);

	int get_correct_answer_index() const;
	std::string get_text() const;
	int get_difficulty_level() const;

	bool check_answer(int answer_index) const; // Метод для проверки на правильность ответа выбранного игроком
};