# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <locale.h>
# define N 20
# define M 20

int matr_inp(int mat[N][M], int stroka, int stolbec)
{   // Функция ввода значений матрицы
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < stroka; i++)
        for (int j = 0; j < stolbec; j++)
        {
            if (scanf("%d", &mat[i][j]) != 1)
            {
                printf("Введено неверное значение\n");
                return 0;
            }
        }
}


int matr_out(int mat[N][M], int stroka, int stolbec) 
{   // Функция вывода значений матрицы
    for (int i = 0; i < stroka; i++)
    {
        for (int j = 0; j < stolbec; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
    printf("\n");
}

//-----------------------------------------------------------------------------------------------------------------------------------------------

int main() {
	int str, col, min_str = N + 1, temp; // Кол-во строк и столбцов, первая строка, где все элементы + и в +порядок
	int matrix[N][M]; // Здесь будет матрица
	char term;
	setlocale(0, "");

    printf("Введите кол-во строк:\n");
    if (scanf("%d%c", &str, &term) != 2) // Ввод количества строк
    {
        printf("Указана неверная длина строк\n");
        return 0;
    }
    if (term != '\n' || str <= 0 || str > N || str >= N)
    {
        printf("Указана неверная длина строк\n");
        return 0;
    }

    printf("Введите кол-во столбцов:\n");
    if (scanf("%d%c", &col, &term) != 2) // Ввод количества столбцов
    {
        printf("Указана неверная длина столбцов\n");
        return 0;
    }
    if (term != '\n' || col <= 0 || col > M || col >= M)
    {
        printf("Указана неверная длина столбцов\n");
        return 0;
    }

    // Ввод матрицы
    if (!matr_inp(matrix, str, col))
        return 0;

    // Вывод исходной матрицы
    printf("Исходная матрица:\n");
    matr_out(matrix, str, col);

    // Поиск первой строки, где все элементы положительные и упорядочены по возрастанию
    if (col == 1) // Для матриц с 1 столбцом
    {
        for (int i = 0; i < str; i++)
        {
            temp = 0;
            if (matrix[i][0] > 0)
                temp += 1;
            if (temp == 1)
            {
                min_str = i;
                break;
            }
        }      
    }
    else // Для матриц с столбцом [2; 20]
    {
        for (int i = 0; i < str; i++)
        {
            temp = 0;
            for (int j = 0; j < col - 1; j++)
            {
                if (matrix[i][j] > 0 && matrix[i][j] < matrix[i][j + 1])
                    temp += 1;
            }
            if (temp == col - 1)
            {
                min_str = i;
                break;
            }
        }
    }
    // Проверка на отсутствие в матрице нужной строки
    if (min_str == N + 1)
    {
        printf("В матрице нет подходящей строки");
        return 0;
    }

    // Проверка на то, является ли нужная строка последней и не единственной строкой в матрице
    if (min_str == str - 1 && str != 1)
    {   
        str -= 1;
        printf("Итоговая матрица:\n");
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < col; j++)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }
        return 0;
    }

    // Проверка на то, является ли нужная строка первой и последней
    if (min_str == str - 1 && str == 1)
    {   
        str -= 1;
        printf("Матрицы больше нет, как и нужной строки, так как в матрице была одна строка\n");
        return 0;
    }

    // Удалить нужную строку
    for (int i = min_str; i < str - 1; i++)
    {
        for (int j = 0; j < col; j++)
            matrix[i][j] = matrix[i + 1][j];
    }
    str -= 1;

    // Вывод итоговой матрицы
    printf("Итоговая матрица:\n");
    matr_out(matrix, str, col);
}