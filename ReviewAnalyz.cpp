//В файле Tag.txt написаны теги через пробел по которым определяется положительный ли отзыв, а в Reviews.txt написаны отзывы, которые перечесляются через '>'
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Reviews
{
private:
	std::vector <std::string> tags;

public:
	explicit Reviews(const std::string& pathTag, const std::string& pathRev) {
		std::ifstream tag(pathTag);
		std::ifstream revs(pathRev);

		if (!tag.is_open()) {
			throw std::runtime_error("Не удалось открыть файл " + pathTag);
		}
		if (!tag.is_open()) {
			throw std::runtime_error("Не удалось открыть файл " + pathRev);
		}

		parseTags(tag);
		analyz(revs);

		tag.close();
		revs.close();
	}

	void parseTags(std::ifstream& tag) {
		std::string word;
		while (tag >> word) {
			tags.push_back(word);
		}
	}

	void analyz(std::ifstream& revs) {
		bool isPositive = true;
		char sym;
		std::string review;
		std::string word;

		while (revs.get(sym)) {
			if (sym != '>') {
				review += sym;
			}
			else {
				std::cout << review << std::endl;

				if (isPositive) {
					std::cout << "Положительный отзыв" << std::endl << std::endl;
				}
				else{
					std::cout << "Отрицательный отзыв" << std::endl << std::endl;
				}

				review = "";
				isPositive = true;

			}

			if (sym != '>' && sym != ' ' && sym != '.') {
				word += sym;
			}
			else {
				for (int i = 0; i != tags.size(); i++) {
					if (word == tags[i]) {
						isPositive = false;
						break;
					}
				}

				word = "";
			}
		}

		revs.close();
	}
};

int main() {
	setlocale(LC_ALL, "Russian");

	std::string pathTag = "Tag.txt";
	std::string pathRev = "Reviews.txt";

	try {
		Reviews analyz(pathTag, pathRev);
	}
	catch (const std::runtime_error& ex) {
		std::cerr << "Ошибка: " << ex.what() << std::endl;

		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}