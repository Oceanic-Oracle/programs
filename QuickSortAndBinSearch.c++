#include <iostream>
#include <ctime>
#include <vector>

void intput_rand_nums_in_vector(std::vector <int> &vec, int x) {
	for (int i = 0; i != x; i++) {
		vec[i] = rand() % 100;
	}
}

void output_vec(std::vector <int>& vec, int x) {
	for (int i = 0; i != x; i++) {
		std::cout << i + 1 << "." << vec[i] << " ";		
	} 
	std::cout << std::endl << "------------------------------------------------" << std::endl;
}

void QuickSort(std::vector <int> &vec, int left, int right) {
	int l = left, r = right;
	int pivot = vec[(left + right) / 2];

	while (l <= r) {
		while (vec[l] < pivot) {
			l++;
		}
		while (vec[r] > pivot) {
			r--;
		}

		if (l <= r) {
			std::swap(vec[l], vec[r]);
			l++;
			r--;
		}
	}

	if (left < r) {
		QuickSort(vec, left, r);
	}
	if (l < right) {
		QuickSort(vec, l, right);
	}
}

int BinSerch(std::vector <int>& vec, int item) {
	int low = 0, high = size(vec) - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		int guess = vec[mid];
		if (guess == item) {
			return mid;
		}
		if (guess > item) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return {};
}




int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int x = rand() % 15;
	while (x == 0) {
		x = rand() % 15;
	}
	std::vector <int> arr(x);


	intput_rand_nums_in_vector(arr, size(arr));

	std::cout << "Вектор заполненный псевдослучайными числами:" << std::endl;

	output_vec(arr, size(arr));

	QuickSort(arr, 0, size(arr) - 1);

	std::cout << "Отсортированный вектор:" << std::endl;

	output_vec(arr, size(arr));

	std::cout << "Введите число, которое хотите найти:" << std::endl;
	int y;
	std::cin >> y;

	std::cout << "Оно находится в ячейке под номером: " << BinSerch(arr, y);
}
