// RemoveDuplicateFromSortedArray.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


void sort_in_ascending_order(int* arr, int size);
int is_sorted_array(int* arr, int size);
void remove_from_array_duplicate(int* arr, int& size);

int main()
{
    int size;
    int* arr;
    int count;
   
    std::cout << "size = ";
    std::cin >> size;
    arr = (int*)new int[size];

    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    std::cout << "Insert count of array which you want to see after removing" << std::endl;
    std::cin >> count;

    if (is_sorted_array(arr, size) == 1)
    {
        remove_from_array_duplicate(arr,  size);
    }
    else
    {
        sort_in_ascending_order(arr, size);
        remove_from_array_duplicate(arr, size);
    }
    
    std::cout << "Result after removed\n";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ", ";
    }

    std::cout << "Array which size is count\n";
    if (count >= 0 && count <= size)
    {
        for (int i = 0; i < count; ++i)
        {
            std::cout << arr[i] << ", ";
        }
    }
    else {
        std::cout << "count must be positive and less than size of array";
    }
    delete[]arr;
    arr = nullptr;

    return 0;
}



void sort_in_ascending_order(int* arr, int size)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = i; j < size; ++j)
        {
            if (arr[j] >= arr[j + 1])
            {
                int num = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = num;
            }
        }
    }
}

int is_sorted_array(int* arr, int size)
{
    for (int i = 0; i < size - 1; ++i)
    {
        if (arr[i] > arr[i + 1]) return 0;
    }

    return 1;
}

void remove_from_array_duplicate(int* arr, int& size)
{
 
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == arr[i + 1])
        {
            for (int j = i; j < size - 1; ++j) 
            {
                arr[j + 1] = arr[j + 2];
            }
            --i;
            --size;
        }
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
