// Демонстрация работы с универсальной функцией считывания int из stdin
#include <stdio.h>

#define M 2
#define N 2

int getInt(int* int_variable, char* char_variable);
int getMatrix(int matrix[M][N]);

int main() {
    // Получаем 2 числа (размер массива) через пробел
    int is_valid = 0;
    char character;
    int x = 2;
    int y = 2;

    /* Пример ввода размера матрицы*/
    // первое число (должно быть с пробелом)
    is_valid = getInt(&x, &character);
    if (is_valid != 1 || character != ' ') {
        // ОШИБКА ПРИ ВВОДЕ
        return -1;
    }

    // второе число (должно быть с Enter)
    is_valid = getInt(&y, &character);
    if (is_valid != 1 || character != '\n') {
        // ОШИБКА ПРИ ВВОДЕ
        return -2;
    }

    /* Пример ввода элементов матрицы*/
    /* (в этом Примере введённый ранее размер матрицы не имеет никакого значения */
    int matrix[M][N] = {{0}};
    is_valid = getMatrix(matrix);
    if (is_valid != 1 || character != ' ') {
        // ОШИБКА ПРИ ВВОДЕ элемента матрицы
        return -1;
    }
}

int getInt(int* int_variable, char* char_variable) {
    int num = 0; // целое число, Результат
    float fnum = 0.0f; // с плавающей точкой (для проверки на int)
    int scan_flag = 0; // реультат от scanf
    char ch; // последний введённый символ

    scan_flag = scanf("%f%c", &fnum, &ch);
    num = (int)fnum;
    if ((num != fnum || scan_flag != 2)) {
        // ОШИБКА ПРИ ВВОДЕ
        return -1;
    }

    // отдаём введённые данные
    *char_variable = ch;
    *int_variable = num;
    return 1;
}

int getMatrix(int matrix[M][N]) {
    if (M < 1 || N < 1) {
        // ОШИБКА размер матрицы не может быть меньше 1
        return -1;
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int inp_num = 0;
            char ch;

            int is_valid = getInt(&inp_num, &ch);
            /* В этом примере элементы матрицы могут вводится как через пробел, так и через Enter*/
            // это поведение можно изменить через создание доболнительного if 
            // (т.е нет проблем переделать на ввод в строку ЗАДАННОГО количества элеметов)
            if (is_valid != 1 || (ch != '\n' && ch != ' ')) {
                // ОШИБКА ПРИ ВВОДЕ
                return -2;
            }

            matrix[i][j] = inp_num;
        }
    }
    
    return 1;
}
