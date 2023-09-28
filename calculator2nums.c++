#include <iostream>

void prime() {
	double num1, num2;
	char sym;
	std::cout << "Введите пример состоящий из двух чисел:" << std::endl;
	std::cin >> num1 >> sym >> num2;
	std::cout << num1 << " " << sym << " " << num2 << " " << '=' << " ";

	switch (sym) {
	case '+':
		std::cout << num1 + num2;
		break;
	case '-':
		std::cout << num1 - num2;
		break;
	case '*':
		std::cout << num1 * num2;
		break;
	case '/':
		std::cout << num1 / num2;
		break;
	case '^':
		std::cout << pow(num1,num2);
		break;
	default:
		std::cout << "Ошибка" << std::endl;
		break;
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	prime();
}