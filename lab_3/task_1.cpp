#include <iostream>

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';

    std::cout << std::endl;
}

void copyArray(int source[], int dest[], int n)
{
    for (int i = 0; i < n; i++)
        dest[i] = source[i];
}

void reverseArray(int arr[], int n)
{
    for (int i = 0; i < n / 2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }
}


void minMaxSort(int arr[], int n)
{
    // На каждом шаге ищем минимальный элемент
    // в неотсортированной части массива и ставим его
    // на текущую позицию. После каждого прохода
    // слева формируется отсортированная часть массива.
    int imin, imax;
    imin = imax = 0;

    for (int i = 0; i < n; i++)
    {
        imin = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[imin])
                imin = j;
        int temp = arr[i];
        arr[i] = arr[imin];
        arr[imin] = temp;
    }
}

void bubbleSort(int arr[], int n)
{
    // Сортировка пузырьком сравнивает соседние элементы
    // и меняет их местами, если они стоят в неправильном порядке.
    // За один проход самый большой элемент "всплывает" в конец массива.
    // Проходы повторяются, пока массив не станет отсортированным.
    for (int pass = 0; pass < n - 1; pass++)
    {
        for (int i = 0; i < n - 1 - pass; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
    }
}

int split(int arr[], int left, int right)
{
    // Вспомогательная функция для быстрой сортировки.
    // Выбирается опорный элемент, после чего массив делится так,
    // чтобы элементы меньше опорного оказались слева,
    // а больше — справа.
    int pivot = arr[(left + right) / 2];

    while (left <= right)
    {
        while (arr[left] < pivot)
            left++;

        while (arr[right] > pivot)
            right--;

        if (left <= right)
        {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }

    return left;
}

void quickSort(int arr[], int left, int right)
{
    // Быстрая сортировка сначала разбивает массив на две части
    // относительно опорного элемента, а затем рекурсивно
    // сортирует левую и правую части.
    // За счет такого разбиения сортировка работает быстрее,
    // чем простые методы, на больших массивах.
    if (left >= right)
        return;

    int index = split(arr, left, right);

    quickSort(arr, left, index - 1);
    quickSort(arr, index, right);
}


void evenAscOddDesc(int arr[], int n)
{
    // Подсчитываем количество чётных и нечётных чисел
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    int *even = new int[evenCount];
    int *odd = new int[oddCount];
    int ei = 0, oi = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
            even[ei++] = arr[i];
        else
            odd[oi++] = arr[i];
    }

    // Сортируем оба массива по возрастанию
    bubbleSort(even, evenCount);
    bubbleSort(odd, oddCount);

    // Нечётные переворачиваем, чтобы получить убывание
    reverseArray(odd, oddCount);

    // Собираем обратно в один массив
    int k = 0;
    for (int i = 0; i < evenCount; i++)
        arr[k++] = even[i];

    for (int i = 0; i < oddCount; i++)
        arr[k++] = odd[i];
}

void sortRange(int mas[], int n, int n1, int n2, bool asc)
{
    // Проверяем границы диапазона
    if (n1 < 0) n1 = 0;
    if (n2 >= n) n2 = n - 1;
    if (n1 > n2) return;

    // Пузырьковая сортировка только на участке [n1, n2]
    for (int i = n1; i < n2; i++)
    {
        for (int j = n1; j < n2 - (i - n1); j++)
        {
            if ((asc && mas[j] > mas[j + 1]) ||
                (!asc && mas[j] < mas[j + 1]))
            {
                int t = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = t;
            }
        }
    }
}

int main()
{
    int mas[] = {2, 5, -8, 1, -4, 6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(mas) / sizeof(int);
    int copy[n];

    std::cout << "Сортировка мини-максом:" << std::endl;
    copyArray(mas, copy, n);
    printArray(copy, n);
    minMaxSort(copy, n);
    printArray(copy, n);

    std::cout << "Сортировка пузырьком:" << std::endl;
    copyArray(mas, copy, n);
    printArray(copy, n);
    bubbleSort(copy, n);
    printArray(copy, n);

    std::cout << "Быстрая сортировка:" << std::endl;
    copyArray(mas, copy, n);
    printArray(copy, n);
    quickSort(copy, 0, n - 1);
    printArray(copy, n);

    std::cout << "Сортировка четных/нечетных:" << std::endl;
    copyArray(mas, copy, n);
    printArray(copy, n);
    evenAscOddDesc(copy, n);
    printArray(copy, n);

    std::cout << "Сортировка диапазона по возрастанию:" << std::endl;
    copyArray(mas, copy, n);
    printArray(copy, n);
    sortRange(copy, n, 2, 8, true);
    printArray(copy, n);

    std::cout << "Сортировка диапазона по убыванию:" << std::endl;
    copyArray(mas, copy, n);
    printArray(copy, n);
    sortRange(copy, n, 2, 8, false);
    printArray(copy, n);
}