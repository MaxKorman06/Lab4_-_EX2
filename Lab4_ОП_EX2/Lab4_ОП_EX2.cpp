#include <iostream>
#include <Windows.h>
#include <math.h>

using namespace std;

void arr_cout(int**, int, int);

int main()
{
    SetConsoleOutputCP(1251);
    int n = 0, m = 0;
    cout << "Введіть розмірність масиву NxM" << '\n';
    cout << "N= "; cin >> n;
    cout << "M= "; cin >> m;
    cout << "Введіть масив " << n << "x" << m << '\n';
    int** arr = new int* [n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[m];
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    

    int* arr_h = new int[m];
    cout << "Наявний масив: " << '\n';
    arr_cout(arr, n, m);

    for (size_t i = 0; i < n; i++)
    {
        arr_h[i] = 0;
    }

    int num_zero = 0;
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                num_zero++;
                break;
            }
        }
    }
    cout <<"Кількість рядків які містять хоча б один нульвий елемент: " << num_zero << "\n\n\n";

    for (size_t i = 0; i < m; i++)
    {
        int* num_cop = new int[m];
        for (size_t i = 0; i < m; i++)
        {
            num_cop[i] = -1;
        }
        for (size_t j = 0; j < n; j++)
        {
            
            for (size_t k = 0; k < n; k++)
            {
                if (arr[j][i] == arr[k][i])
                {
                    num_cop[j]++;
                }
            }

            
        }
        int tmp = 0;
        for (int k = 0; k < m; k++)
        {
            for (int j = (m- 1); j >= (k + 1); j--) 
            {
                if (num_cop[j] > num_cop[j - 1]) 
                {
                    tmp = num_cop[j];
                    num_cop[j] = num_cop[j - 1];
                    num_cop[j - 1] = tmp;
                }
            }
        }
            
        arr_h[i] = num_cop[0];
        
        cout << '\n';

    }
    
    int** arr_h2 = new int* [2];
    for (int i = 0; i < 2; i++)
    {
        arr_h2[i] = new int[m];
    }
    for (size_t i = 0; i < m; i++)
    {
        arr_h2[1][i] = i+1;
    }
    for (size_t i = 0; i < m; i++)
    {
        arr_h2[0][i] = arr_h[i];
    }

    int tmp = 0;
    for (int i = 0; i < m; i++) 
    {
        for (int j = (m - 1); j >= (i + 1); j--) 
        {
            if (arr_h2[0][j] > arr_h2[0][j - 1]) 
            {
                for (size_t k = 0; k < 2; k++)
                {
                    tmp = arr_h2[k][j];
                    arr_h2[k][j] = arr_h2[k][j - 1];
                    arr_h2[k][j - 1] = tmp;
                }
                
            }
        }
    }
  
    cout << "Номер стовпця в якому міститься найдовша серія однакових елементів: " << arr_h2[1][0] << "\n\n\n";
}

void arr_cout(int** arr, int n, int m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << '\n';
    }
}
