# define _CRT_SECURE_NO_WARNINGS
# include <stdio.h>
# include <locale.h>
# define N 20
# define M 20

int matr_inp(int mat[N][M], int stroka, int stolbec)
{   // ������� ����� �������� �������
    printf("������� �������� �������:\n");
    for (int i = 0; i < stroka; i++)
        for (int j = 0; j < stolbec; j++)
        {
            if (scanf("%d", &mat[i][j]) != 1)
            {
                printf("������� �������� ��������\n");
                return 0;
            }
        }
}


int matr_out(int mat[N][M], int stroka, int stolbec) 
{   // ������� ������ �������� �������
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
	int str, col, min_str = N + 1, temp; // ���-�� ����� � ��������, ������ ������, ��� ��� �������� + � � +�������
	int matrix[N][M]; // ����� ����� �������
	char term;
	setlocale(0, "");

    printf("������� ���-�� �����:\n");
    if (scanf("%d%c", &str, &term) != 2) // ���� ���������� �����
    {
        printf("������� �������� ����� �����\n");
        return 0;
    }
    if (term != '\n' || str <= 0 || str > N || str >= N)
    {
        printf("������� �������� ����� �����\n");
        return 0;
    }

    printf("������� ���-�� ��������:\n");
    if (scanf("%d%c", &col, &term) != 2) // ���� ���������� ��������
    {
        printf("������� �������� ����� ��������\n");
        return 0;
    }
    if (term != '\n' || col <= 0 || col > M || col >= M)
    {
        printf("������� �������� ����� ��������\n");
        return 0;
    }

    // ���� �������
    if (!matr_inp(matrix, str, col))
        return 0;

    // ����� �������� �������
    printf("�������� �������:\n");
    matr_out(matrix, str, col);

    // ����� ������ ������, ��� ��� �������� ������������� � ����������� �� �����������
    if (col == 1) // ��� ������ � 1 ��������
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
    else // ��� ������ � �������� [2; 20]
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
    // �������� �� ���������� � ������� ������ ������
    if (min_str == N + 1)
    {
        printf("� ������� ��� ���������� ������");
        return 0;
    }

    // �������� �� ��, �������� �� ������ ������ ��������� � �� ������������ ������� � �������
    if (min_str == str - 1 && str != 1)
    {   
        str -= 1;
        printf("�������� �������:\n");
        for (int i = 0; i < str; i++)
        {
            for (int j = 0; j < col; j++)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }
        return 0;
    }

    // �������� �� ��, �������� �� ������ ������ ������ � ���������
    if (min_str == str - 1 && str == 1)
    {   
        str -= 1;
        printf("������� ������ ���, ��� � ������ ������, ��� ��� � ������� ���� ���� ������\n");
        return 0;
    }

    // ������� ������ ������
    for (int i = min_str; i < str - 1; i++)
    {
        for (int j = 0; j < col; j++)
            matrix[i][j] = matrix[i + 1][j];
    }
    str -= 1;

    // ����� �������� �������
    printf("�������� �������:\n");
    matr_out(matrix, str, col);
}