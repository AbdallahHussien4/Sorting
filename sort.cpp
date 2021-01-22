#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <time.h>
#include <chrono>
#include <fstream>
#include <climits>
#include <string>
#include <sstream>
using namespace std;
using namespace std::chrono;

void SelectionSort(vector<int> &A, int n)
{
    int min = 0;
    int temp = 0;
    int index = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        min = A[i];
        index = i;
        for (int j = i; j < n; j++)
        {
            if (A[j] < min)
            {
                min = A[j];
                index = j;
            }
        }
        temp = A[i];
        A[i] = A[index];
        A[index] = temp;
    }
}

void InsertionSort(vector<int> &A, int f, int n)
{
    int j, key;
    for (int i = f; i < n; i++)
    {
        j = i - 1;
        key = A[i];
        while (j >= 0 && A[j] > key)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = key;
    }
}

void Merge(vector<int> &A, int f, int mid, int n)
{
    int n1 = mid - f + 1, n2 = n - mid;
    int *R = new int[n2 + 1];
    int *L = new int[n1 + 1];
    for (int j = 0; j < n1; j++)
    {
        L[j] = A[j + f];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = A[j + mid + 1];
    }
    L[n1] = INT_MAX;
    R[n2] = INT_MAX;
    int j = 0, m = 0;
    for (int k = f; k <= n; k++)
    {
        if (L[j] <= R[m])
        {
            A[k] = L[j];
            j++;
        }
        else
        {
            A[k] = R[m];
            m++;
        }
    }
}

void MergeSort(vector<int> &A, int i, int n)
{
    int mid;
    if (i < n)
    {
        // mid = (n-1+i) / 2;
        mid = (n + i) / 2;
        MergeSort(A, i, mid);
        MergeSort(A, mid + 1, n);
        Merge(A, i, mid, n);
    }
}

int Partition(vector<int> &A, int f, int n)
{
    int pivot = A[n];
    int i = f - 1;
    int temp;
    for (int j = f; j < n; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    temp = A[i + 1];
    A[i + 1] = pivot;
    A[n] = temp;
    return i + 1;
}

void QuickSort(vector<int> &A, int i, int n)
{
    int pivot, temp;
    if (i < n)
    {
        int ran = i + (rand() % (n - i));
        temp = A[ran];
        A[ran] = A[n];
        A[n] = temp;
        pivot = Partition(A, i, n);
        QuickSort(A, i, pivot - 1);
        QuickSort(A, pivot + 1, n);
    }
}

void HypirdSort(vector<int> &A, int i, int n)
{
    if (i < n)
    {
        if (n - i < 50)
            InsertionSort(A, i + 1, n);
        else
        {
            // int mid = (n - 1 + i) / 2;
            int mid = (n + i) / 2;
            HypirdSort(A, i, mid);
            HypirdSort(A, mid + 1, n);
            Merge(A, i, mid, n);
        }
    }
}

vector<int> ReadFile(char *F)
{
    ifstream f;
    f.open(F);
    vector<int> Numbers;
    string num;
    int x = 0;
    while (getline(f, num))
    {
        stringstream S(num);
        S >> x;
        Numbers.push_back(x);
    }
    return Numbers;
}

void WriteFile(char *F, vector<int> Data)
{
    ofstream f;
    f.open(F);
    for (int i = 0; i < Data.size(); i++)
        f << Data[i] << endl;
    f.close();
}

int main(int argc, char **argv)
{
    vector<int> Data = ReadFile(argv[2]);
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    srand(time(NULL));

    if (argv[1][0] == '0')
    {
        start = high_resolution_clock::now();
        SelectionSort(Data, Data.size());
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
    }
    else if (argv[1][0] == '1')
    {
        start = high_resolution_clock::now();
        InsertionSort(Data, 1, Data.size());
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
    }
    else if (argv[1][0] == '2')
    {
        start = high_resolution_clock::now();
        MergeSort(Data, 0, Data.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
    }
    else if (argv[1][0] == '3')
    {
        start = high_resolution_clock::now();
        QuickSort(Data, 0, Data.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
    }
    else if (argv[1][0] == '4')
    {
        start = high_resolution_clock::now();
        HypirdSort(Data, 0, Data.size() - 1);
        stop = high_resolution_clock::now();
        duration = duration_cast<milliseconds>(stop - start);
    }

    WriteFile(argv[3], Data);
    ofstream f;
    f.open(argv[4]);
    f << duration.count() << endl;
    f.close();

    return 0;
}
