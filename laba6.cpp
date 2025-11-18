#include <iostream>
#include <cstdlib>

using namespace std;


int A_is_pos(int num) 
{
    while (num < 0)
    {
        cout << "Число отрицательное. Повторите ввод" << endl;
        cin >> num;
    }
    return num;
}


int** matr_2_2(int a, int b, int c, int d)
{
    int strr = 2 + a;
    int stol = 2 + b;


    int** matr = (int**)calloc(strr, sizeof(int*));
    for (int i = 0; i < strr; i++) {
        matr[i] = (int*)calloc(stol, sizeof(int));
    }


    matr[0][0] = a;
    matr[0][1] = b;
    matr[1][0] = c;
    matr[1][1] = d;


    for (int i = 0; i < strr; i++) {
        for (int j = 2; j < stol; j++) {
            matr[i][j] = (i - 1) * c + (j - 1) * d;
        }
    }

    for (int i = 2; i < strr; i++)
    {
        for (int j = 0; j < stol; j++)
        {
            matr[i][j] = (i - 1) * c + (j - 1) * d;
        }
    }

    return matr;
}


int* nulevie_stolb(int** matr, int strr, int stoll, int& zeroCount) {
    //массив для отметки нулевых столбцов
    bool* zeroStoll = (bool*)calloc(stoll, sizeof(bool));
    zeroCount = 0;

    for (int j = 0; j < stoll; j++) {
        bool hasZero = false;
        for (int i = 0; i < strr; i++) {
            if (matr[i][j] == 0) {
                hasZero = true;
                break;
            }
        }
        if (hasZero) {
            zeroStoll[j] = true;
            zeroCount += 1;
        }
    }


    int* zeroStol = (int*)malloc(zeroCount * sizeof(int));
    int index = 0;
    for (int j = 0; j < stoll; j++) {
        if (zeroStoll[j]) {
            zeroStol[index++] = j;

        }
    }

    free(zeroStoll);
    return zeroStol;
}


int** del_Stoll(int** matr, int strr, int& stoll, int* udal_stoll, int count) {
    if (count == 0) return matr;

    int newStoll = stoll - count;
    int** newMatr = (int**)calloc(strr, sizeof(int*));

    for (int i = 0; i < strr; i++) {
        newMatr[i] = (int*)calloc(newStoll, sizeof(int));
        int newJ = 0;
        for (int j = 0; j < stoll; j++) {
            bool skip = false;
            for (int k = 0; k < count; k++) {
                if (j == udal_stoll[k]) {
                    skip = true;
                    break;
                }
            }
            if (!skip) {
                newMatr[i][newJ++] = matr[i][j];
            }
        }
    }

    for (int i = 0; i < strr; i++) {
        free(matr[i]);
    }
    free(matr);

    stoll = newStoll;
    return newMatr;
}


void printMatr(int** matr, int strr, int stoll) {
    for (int i = 0; i < strr; i++) {
        for (int j = 0; j < stoll; j++) {
            cout << matr[i][j] << "\t";
        }
        cout << endl;
    }
}

void freeMatrix(int** matr, int strr) {
    for (int i = 0; i < strr; i++) {
        free(matr[i]);
    }
    free(matr);
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a, b;
    cout << "Введите а" << endl;
    cin >> a;
    a = A_is_pos(a);
    cout << "Введите b" << endl;
    cin >> b;
    b = A_is_pos(b);
    cout << "Введите c: ";
    int c;
    cin >> c;

    cout << "Введите d: ";
    int d;
    cin >> d;


    int rows = 2 + a;
    int cols = 2 + b;
    int** matrix = matr_2_2(a, b, c, d);

    cout << "Исходная расширенная матрица:" << endl;
    printMatr(matrix, rows, cols);


    int zeroCount;
    int* zeroColumns = nulevie_stolb(matrix, rows, cols, zeroCount);

    if (zeroCount > 0) {
        cout << "Найдены нулевые значения в столбцах: ";
        for (int i = 0; i < zeroCount; i++) {
            cout << zeroColumns[i] + 1 << " ";
        }
        cout << endl;


        matrix = del_Stoll(matrix, rows, cols, zeroColumns, zeroCount);

        cout << "Матрица после удаления столбцов:" << endl;
        printMatr(matrix, rows, cols);
    }
    else {
        cout << "Нулевых значений нет" << endl;
    }


    free(zeroColumns);
    freeMatrix(matrix, rows);

    return 0;
}
