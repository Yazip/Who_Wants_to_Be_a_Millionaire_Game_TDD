#pragma once

#include <string>
#include <vector>

class Question {
private:
	std::string text;
	int difficulty_level; // (1 - лёгкий, 2 - средний, 3 - сложный)
	std::vector<std::string> answers;
	int correct_answer_index = 0;
public:
	Question() = default;

	void set_text(std::string text);
	void set_difficulty_level(int difficulty_level);
	void set_answers(std::vector<std::string> answers);
	void set_correct_answer_index(int correct_answer_index);

	std::string get_text() const;
	int get_difficulty_level() const;
	std::vector<std::string> get_answers() const;
	int get_correct_answer_index() const;

	bool check_answer(int answer_index) const; // Метод для проверки на правильность ответа выбранного игроком
};