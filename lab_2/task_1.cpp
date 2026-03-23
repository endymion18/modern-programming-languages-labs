#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define N 5

// Вывод матрицы
void printMatrix(float m[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            std::cout << std::setw(8) << std::setprecision(5) << m[i][j];
        }
        std::cout << std::endl;
    }
}

// Заполнение матрицы
void fillMatrix(float m[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            m[i][j] = rand() / 10.;
        }
    }
}

// Вывод массива
void printArray(float arr[N])
{
    for (int i = 0; i < N; i++)
        std::cout << std::setw(8) << arr[i];
    std::cout << std::endl;
}

// Минимум матрицы
float minMatrix(float m[N][N])
{
    float min_value = m[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (min_value > m[i][j])
                min_value = m[i][j];
    }

    return min_value;
}

// Максимум матрицы
float maxMatrix(float m[N][N])
{
    float max_value = m[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (max_value < m[i][j])
                max_value = m[i][j];
    }

    return max_value;
}

// Максимум нижнетреугольной части матрицы (i >= j)
float maxLowerTriangle(float m[N][N])
{
    float max_value = m[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
            if (max_value < m[i][j])
                max_value = m[i][j];
    }

    return max_value;
}

// Минимум нижнетреугольной части
float minLowerTriangle(float m[N][N])
{
    float min_value = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (min_value > m[i][j])
                min_value = m[i][j];
    return min_value;
}

// Максимум верхнетреугольной части матрицы (i <= j)
float maxUpperTriangle(float m[N][N])
{
    float max_value = m[0][0];
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
            if (max_value < m[i][j])
                max_value = m[i][j];
    }

    return max_value;
}

// Минимум верхнетреугольной части
float minUpperTriangle(float m[N][N])
{
    float min_value = m[0][0];
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (min_value > m[i][j])
                min_value = m[i][j];
    return min_value;
}

// Минимум главной диагонали
float minMainDiagonal(float m[N][N])
{
    float min_value = m[0][0];
    for (int i = 0; i < N; i++)
        if (min_value > m[i][i])
            min_value = m[i][i];
    return min_value;
}

// Максимум главной диагонали
float maxMainDiagonal(float m[N][N])
{
    float max_value = m[0][0];
    for (int i = 0; i < N; i++)
        if (max_value < m[i][i])
            max_value = m[i][i];
    return max_value;
}

// Минимум второстепенной диагонали
float minSecondaryDiagonal(float m[N][N])
{
    float min_value = m[0][N - 1];
    for (int i = 0; i < N; i++)
        if (m[i][N - 1 - i] < min_value)
            min_value = m[i][N - 1 - i];
    return min_value;
}

// Максимум второстепенной диагонали
float maxSecondaryDiagonal(float m[N][N])
{
    float max_value = m[0][N - 1];
    for (int i = 0; i < N; i++)
        if (m[i][N - 1 - i] > max_value)
            max_value = m[i][N - 1 - i];
    return max_value;
}

// Среднеарифметическое всей матрицы
float averageMatrix(float m[N][N])
{
    float sum = 0.0f;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += m[i][j];

    return sum / (N * N);
}

// Среднеарифметическое нижнетреугольной части
float averageLowerTriangle(float m[N][N])
{
    float sum = 0.0f;
    int count = 0;

    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
        {
            sum += m[i][j];
            count++;
        }

    return sum / count;
}

// Среднеарифметическое верхнетреугольной части
float averageUpperTriangle(float m[N][N])
{
    float sum = 0.0f;
    int count = 0;

    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
        {
            sum += m[i][j];
            count++;
        }

    return sum / count;
}

// Суммы строк
void sumRows(float m[N][N], float sums[N])
{
    for (int i = 0; i < N; i++)
    {
        sums[i] = 0.0f;
        for (int j = 0; j < N; j++)
            sums[i] += m[i][j];
    }
}

// Суммы столбцов
void sumCols(float m[N][N], float sums[N])
{
    for (int j = 0; j < N; j++)
    {
        sums[j] = 0.0f;
        for (int i = 0; i < N; i++)
            sums[j] += m[i][j];
    }
}

// Минимальные значения строк
void minRows(float m[N][N], float mins[N])
{
    for (int i = 0; i < N; i++)
    {
        mins[i] = m[i][0];
        for (int j = 1; j < N; j++)
            if (m[i][j] < mins[i])
                mins[i] = m[i][j];
    }
}

// Максимальные значения строк
void maxRows(float m[N][N], float maxs[N])
{
    for (int i = 0; i < N; i++)
    {
        maxs[i] = m[i][0];
        for (int j = 1; j < N; j++)
            if (m[i][j] > maxs[i])
                maxs[i] = m[i][j];
    }
}

// Минимальные значения столбцов
void minCols(float m[N][N], float mins[N])
{
    for (int j = 0; j < N; j++)
    {
        mins[j] = m[0][j];
        for (int i = 1; i < N; i++)
            if (m[i][j] < mins[j])
                mins[j] = m[i][j];
    }
}

// Максимальные значения столбцов
void maxCols(float m[N][N], float maxs[N])
{
    for (int j = 0; j < N; j++)
    {
        maxs[j] = m[0][j];
        for (int i = 1; i < N; i++)
            if (m[i][j] > maxs[j])
                maxs[j] = m[i][j];
    }
}

// Среднеарифметические значения строк
void averageRows(float m[N][N], float avgs[N])
{
    for (int i = 0; i < N; i++)
    {
        avgs[i] = 0.0f;
        for (int j = 0; j < N; j++)
            avgs[i] += m[i][j];
        avgs[i] /= N;
    }
}

// Среднеарифметические значения столбцов
void averageCols(float m[N][N], float avgs[N])
{
    for (int j = 0; j < N; j++)
    {
        avgs[j] = 0.0f;
        for (int i = 0; i < N; i++)
            avgs[j] += m[i][j];
        avgs[j] /= N;
    }
}

// Сумма нижнетреугольной части
float sumLowerTriangle(float m[N][N])
{
    float sum = 0.0f;
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            sum += m[i][j];
    return sum;
}

// Сумма верхнетреугольной части
float sumUpperTriangle(float m[N][N])
{
    float sum = 0.0f;
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            sum += m[i][j];
    return sum;
}

float closestToAverage(float m[N][N])
{
    float avg = averageMatrix(m);
    float closest = m[0][0];
    float min_diff = fabs(m[0][0] - avg);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            float diff = fabs(m[i][j] - avg);
            if (diff < min_diff)
            {
                min_diff = diff;
                closest = m[i][j];
            }
        }

    return closest;
}

int main()
{
    float m[N][N];
    float arr[N];

    fillMatrix(m);
    std::cout << "Матрица:" << std::endl;
    printMatrix(m);

    std::cout << "Минимум матрицы: " << minMatrix(m) << std::endl;
    std::cout << "Максимум матрицы: " << maxMatrix(m) << std::endl;
    std::cout << "Максимум нижнетреугольной части: " << maxLowerTriangle(m) << std::endl;
    std::cout << "Максимум верхнетреугольной части: " << maxUpperTriangle(m) << std::endl;
    std::cout << "Минимум нижнетреугольной части: " << minLowerTriangle(m) << std::endl;
    std::cout << "Минимум верхнетреугольной части: " << minUpperTriangle(m) << std::endl;

    std::cout << "Минимум главной диагонали: " << minMainDiagonal(m) << std::endl;
    std::cout << "Максимум главной диагонали: " << maxMainDiagonal(m) << std::endl;
    std::cout << "Минимум побочной диагонали: " << minSecondaryDiagonal(m) << std::endl;
    std::cout << "Максимум побочной диагонали: " << maxSecondaryDiagonal(m) << std::endl;

    std::cout << "Среднее матрицы: " << averageMatrix(m) << std::endl;
    std::cout << "Среднее нижнетреугольной части: " << averageLowerTriangle(m) << std::endl;
    std::cout << "Среднее верхнетреугольной части: " << averageUpperTriangle(m) << std::endl;

    sumRows(m, arr);
    std::cout << "Суммы строк: " << std::endl;
    printArray(arr);

    sumCols(m, arr);
    std::cout << "Суммы столбцов: " << std::endl;
    printArray(arr);

    minRows(m, arr);
    std::cout << "Минимумы строк: " << std::endl;
    printArray(arr);

    minCols(m, arr);
    std::cout << "Минимумы столбцов: " << std::endl;
    printArray(arr);

    maxRows(m, arr);
    std::cout << "Максимумы строк: " << std::endl;
    printArray(arr);

    maxCols(m, arr);
    std::cout << "Максимумы столбцов: " << std::endl;
    printArray(arr);

    averageRows(m, arr);
    std::cout << "Среднеарифметические строк: " << std::endl;
    printArray(arr);

    averageCols(m, arr);
    std::cout << "Среднеарифметические столбцов: " << std::endl;
    printArray(arr);

    std::cout << "Сумма нижнетреугольной части: " << sumLowerTriangle(m) << std::endl;
    std::cout << "Сумма верхнетреугольной части: " << sumUpperTriangle(m) << std::endl;
    std::cout << "Элемент, ближайший к среднему: " << closestToAverage(m) << std::endl;
}
