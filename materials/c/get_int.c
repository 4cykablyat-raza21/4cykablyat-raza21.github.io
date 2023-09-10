// Программа для считывания только целых чисел из stdin,
// 8.0 считается за целое число
#include <stdio.h>

int get_int(int* result_number);

int main() {
    printf("Введите целое число: ");

    int number = 0;
    int err = get_int(&number);

    if (!err) {
        printf("%d", number);
    } else {
        printf("Не является целым или числом.");
    }
}

int get_int(int* result_number) {
    int num = 0;
    float fnum = 0.0f;
    int err = 0;
    char ch;

    err = scanf("%f%c", &fnum, &ch) == 2 ? 0: 1;
    num = (int)fnum; // берём целую часть от числа (если было 8.9 — то в «num» запишется 8)

    // если (8 не равен 8.9) то вывести ошибку
    if ((num != fnum || err != 0)) {
        return -1;
    }

    *result_number = num;
    return 0;
}
