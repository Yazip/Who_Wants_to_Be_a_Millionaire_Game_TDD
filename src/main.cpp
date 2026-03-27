#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "question.h"

// Денежные вознаграждения
std::vector<int> money = {
    100, 500, 1000, 3000, 5000,
    10000, 15000, 25000, 50000, 100000,
    200000, 400000, 800000, 1500000, 3000000
};

// Функция для получения значения денежной суммы в случае проигрыша
int get_checkpoint(int question_index) {
    if (question_index >= 9) {
        return 100000;
    }
    if (question_index >= 4) {
        return 5000;
    }
    return 0;
}

// Функция для загрузки вопросов из файла
std::vector<Question> load_questions() {
    std::ifstream file("questions.txt");
    std::vector<Question> questions;

    while (!file.eof()) {
        Question q;
        std::string text;
        int difficulty_level;
        std::vector<std::string> answers(4);
        int correct_answer_index;

        getline(file, text);
        if (text.empty()) {
            break;
        }

        file >> difficulty_level;
        file.ignore();

        for (int i = 0; i < 4; i++) {
            getline(file, answers[i]);
        }

        file >> correct_answer_index;
        file.ignore();

        q.set_text(text);
        q.set_difficulty_level(difficulty_level);
        q.set_answers(answers);
        q.set_correct_answer_index(correct_answer_index);

        questions.push_back(q);
    }

    return questions;
}

// Функция для выбора случайного вопроса заданного уровня сложности
Question get_random_question(std::vector<Question>& questions, int difficulty_level) {
    std::vector<Question> same_difficulty_questions;

    for (Question& q : questions) {
        if (q.get_difficulty_level() == difficulty_level) {
            same_difficulty_questions.push_back(q);
        }
    }

    int index = rand() % same_difficulty_questions.size();
    return same_difficulty_questions[index];
}

// Функция для подсказки "50 на 50"
void hint_50_50(int correct_answer_index, std::vector<bool>& visible_answers) {
    std::vector<int> wrong;
    for (int i = 0; i < 4; i++) {
        if (i != correct_answer_index) {
            wrong.push_back(i);
        }
    }

    random_shuffle(wrong.begin(), wrong.end());

    visible_answers[wrong[0]] = false;
    visible_answers[wrong[1]] = false;
}

// Функция для подсказки "Звонок другу"
void hint_phone_call(int correct_answer_index) {
    int probability = 65; // Вероятность, что "друг" подскажет правильный ответ

    int chance = rand() % 100;

    int guess;

    if (chance < probability) {
        guess = correct_answer_index;
    }
    else {
        std::vector<int> wrong;
        for (int i = 0; i < 4; i++) {
            if (i != correct_answer_index) {
                wrong.push_back(i);
            }
        }

        guess = wrong[rand() % wrong.size()];
    }

    std::cout << "\nДруг думает, что правильный ответ: " << guess + 1 << std::endl;
}

// Функция для подсказки "Помощь зала"
void hint_audience_help(int correct_answer_index) {
    std::vector<int> votes(4, 0);

    int probability = 70; // Вероятность, что зал проголосует большинством за правильный ответ

    int chance = rand() % 100;

    // Определяем, будет ли зал прав
    bool audience_correct = (chance < probability);

    int majority_index;

    if (audience_correct) {
        majority_index = correct_answer_index;
    }
    else {
        std::vector<int> wrong;
        for (int i = 0; i < 4; i++) {
            if (i != correct_answer_index) {
                wrong.push_back(i);
            }
        }

        majority_index = wrong[rand() % wrong.size()];
    }

    int majority_vote = 50 + rand() % 31;
    votes[majority_index] = majority_vote;

    int remaining = 100 - majority_vote;

    std::vector<int> others;
    for (int i = 0; i < 4; i++) {
        if (i != majority_index) {
            others.push_back(i);
        }
    }

    int a = rand() % (remaining + 1);
    int b = rand() % (remaining - a + 1);
    int c = remaining - a - b;

    std::vector<int> parts = { a, b, c };
    random_shuffle(parts.begin(), parts.end());

    for (int i = 0; i < 3; i++) {
        votes[others[i]] = parts[i];
    }

    std::cout << "\nГолоса зала:\n";
    for (int i = 0; i < 4; i++) {
        std::cout << i + 1 << ": " << votes[i] << "%\n";
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    srand(time(0));

    std::vector<Question> questions = load_questions();

    while (true) {
        std::cout << "\nГлавное меню:\n";
        std::cout << "1. Начать игру\n";
        std::cout << "2. Выход\n";

        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');

            std::cout << "\nОшибка: введите номер пункта меню!\n";
            continue;
        }

        if (choice == 1) {
            bool used_50_50 = false;
            bool used_phone_call = false;
            bool used_audience_help = false;

            int winnings = 0;

            for (int i = 0; i < 15; i++) {
                int difficulty_level = (i < 5) ? 1 : (i < 10) ? 2 : 3;

                Question q = get_random_question(questions, difficulty_level);

                std::vector<std::string> answers = q.get_answers();
                int correct_index = q.get_correct_answer_index();

                std::vector<int> indices = { 0, 1, 2, 3 };

                random_shuffle(indices.begin(), indices.end());

                std::vector<std::string> shuffled_answers(4);

                int new_correct_index;

                for (int i = 0; i < 4; i++) {
                    shuffled_answers[i] = answers[indices[i]];

                    if (indices[i] == correct_index) {
                        new_correct_index = i;
                    }
                }

                // Устанавливаем новые значения после перемешивания
                q.set_answers(shuffled_answers);
                q.set_correct_answer_index(new_correct_index);

                std::vector<bool> visible(4, true);

                std::cout << "\nВопрос " << i + 1 << " на " << money[i] << " руб.\n";
                std::cout << q.get_text() << std::endl;

                while (true) {
                    for (int j = 0; j < 4; j++) {
                        if (visible[j])
                            std::cout << j + 1 << ": " << q.get_answers()[j] << std::endl;
                    }

                    std::cout << "\nВозможности и подсказки:\n";
                    std::cout << "5. Забрать деньги\n";
                    std::cout << "6. 50/50\n";
                    std::cout << "7. Звонок другу\n";
                    std::cout << "8. Помощь зала\n";

                    int ans;
                    std::cin >> ans;

                    if (std::cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore(32767, '\n');
                        std::cout << "\nОшибка: введите цифру от 1 до 8!\n";
                        continue;
                    }

                    if (ans == 5) {
                        std::cout << "\nВы забрали: " << winnings << " руб.\n";
                        break;
                    }

                    if (ans == 6) {
                        if (!used_50_50) {
                            hint_50_50(q.get_correct_answer_index(), visible);
                            used_50_50 = true;
                        }
                        else {
                            std::cout << "\nОшибка: вы уже использовали подсказку \"50/50\"!\n";
                        }
                        continue;
                    }

                    if (ans == 7) {
                        if (!used_phone_call) {
                            hint_phone_call(q.get_correct_answer_index());
                            used_phone_call = true;
                        }
                        else {
                            std::cout << "\nОшибка: вы уже использовали подсказку \"Звонок другу\"!\n";
                        }
                        continue;
                    }

                    if (ans == 8) {
                        if (!used_audience_help) {
                            hint_audience_help(q.get_correct_answer_index());
                            used_audience_help = true;
                        }
                        else {
                            std::cout << "\nОшибка: вы уже использовали подсказку \"Помощь зала\"!\n";
                        }
                        continue;
                    }

                    if (ans >= 1 && ans <= 4) {
                        if (q.check_answer(ans - 1)) {
                            std::cout << "\nПравильно!\n";
                            winnings = money[i];

                            if (i == 14) {
                                std::cout << "\nПОБЕДА! Вы выиграли 3 000 000 руб!\n";
                            }
                        }
                        else {
                            int safe = get_checkpoint(i - 1);
                            std::cout << "\nНеверно!\n";
                            std::cout << "\nВы выиграли: " << safe << " руб.\n";
                        }
                        break;
                    }

                    std::cout << "\nОшибка: введите цифру от 1 до 8!\n";
                }

                if (winnings != money[i]) {
                    break;
                }
            }
        }
        else if (choice == 2) {
            break;
        }
        else {
            std::cout << "\nОшибка: введите номер пункта меню\n";
        }
    }

    return 0;
}