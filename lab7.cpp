#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    system("chcp 1251");
    system("cls");

    cout << "Работу выполнил Жигалин Данил Вадимович, гр. 421-1\n" << endl;

    unsigned n, m;

    cout << "Введите колличество вершин: ";
    cin >> n;
    cout << "Введите колличество ребер: ";
    cin >> m;
    cout << endl;

    int** matrix = new int* [n];

    cout << " ";
    for (unsigned check = 0; check < n; check++)
    {
        cout << setw(3) << check + 1;
    }
    cout << endl;

    for (unsigned edge = 0; edge < m; edge++)
    {
        matrix[edge] = new int[m];

        cout << edge + 1;
        for (unsigned vertex = 0; vertex < n; vertex++)
        {
            matrix[edge][vertex] = 0;
            cout << setw(3) << 0;
        }
        cout << endl;
    }
    cout << endl;


    for (unsigned edge = 0; edge < m; edge++)
    {
        unsigned start, finish;

        cout << "Введите начало ребра (от 1 до " << n << "): ";
        cin >> start;
        cout << "Введите конец ребра (от 1 до " << n << "): ";
        cin >> finish;

        if (start == finish)
        {
            matrix[edge][start - 1] = 2;
        }
        else
        {
            matrix[edge][start - 1] = 1;
            matrix[edge][finish - 1] = -1;
        }

        system("cls");

        cout << " ";
        for (unsigned check = 0; check < n; check++)
        {
            cout << setw(3) << check + 1;
        }
        cout << endl;

        for (unsigned edge = 0; edge < m; edge++)
        {
            cout << edge + 1;
            for (unsigned vertex = 0; vertex < n; vertex++)
            {
                cout << setw(3) << matrix[edge][vertex];
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;


    cout << "Вершины графа, имеющие нулевую полустепень захода: ";
    for (unsigned vertex = 0; vertex < n; vertex++)
    {
        bool flag = true;
        for (unsigned edge = 0; edge < m; edge++)
        {
            int elem = matrix[edge][vertex];
            if (elem == 2 || elem == -1)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << setw(2) << vertex + 1;
        }
    }
    cout << endl;

    /*
    for (unsigned i = 0; i < m; i++)
        delete[] matrix[i];
    */

    delete[] matrix;
}