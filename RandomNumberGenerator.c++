#include <iostream>
using namespace std;
int getRandomArrayUnique(int size, int* arr, int min, int max) {
    int i, j;
    int duplicate;
    int value, diapazone = max - min + 1;
    if (diapazone < 1 || size<0 || size>diapazone) {
        return 1;
    }
    for (i = 0; i < size; i++) {
        for (; ; ) {
            value = min + rand() % diapazone;
            duplicate = 0;
            for (j = 0; j < i; j++) {
                if (value == arr[j]) { duplicate = 1; break; }
            }
            if (!duplicate) { break; }
        }
        arr[i] = value;
    }
    return 0;
}
int main(void) {
    int size = 100, min = 0, max = 99;
    int* arr = new int[size];
    if (!arr) {
        cout << "No memory!"; return 1;
    }
    int res = getRandomArrayUnique(size, arr, min, max);
    if (res) cout << "Bad data!";
    else for (int i = 0; i < size; i++) cout << arr[i] << " ";
    cin.sync(); cin.get(); return 0;
}