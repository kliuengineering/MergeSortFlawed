//
//  main.cpp
//  MergeSort
//
//  Created by Kevin Liu on 2024-02-17.
//

/* Merge Sort review
 - merging 2 sorted lists
    1. indicating the 1st element of each partition
    2. compare the indicators and pick the smaller one
    3. copy the smaller -> merged list -> advance 1 position forward
    4. continue till either list is fully copied
 
*/

#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>

template <typename T>
void Merge(std::vector<T> &array, std::vector<T> &temp, int startA, int startB, int end);


template <typename T>
void MergeSort(std::vector<T> &array, std::vector<T> &temp, int start, int end)
{
    if(start < end)
    {
        int mid = (start + end)/2;
        MergeSort(array, temp, start, mid);
        MergeSort(array, temp, mid+1, end);
        Merge(array, temp, start, mid+1, end);
    }
}

template <typename T>
void Merge(std::vector<T> &array, std::vector<T> &temp, int startA, int startB, int end)
{
    int ptrA = startA, itr = startA, i = startA;
    int ptrB = startB;
    
    while( ptrA < startB && ptrB <= end)
    {
        if(array[ptrA] < array[ptrB])       // descending or ascending
        {
            temp[itr++] = array[ptrA++];
        }
        else
            temp[itr++] = array[ptrB++];
    }
    
    while( ptrA < ptrB )
    {
        temp[itr++] = array[ptrA++];
    }
    
    while (ptrB <= end)
    {
        temp[itr++] = array[ptrB++];
    }
    
    for(i = startA; i <= end; i++)
    {
        array[i] = temp[i];
    }
}

template <typename T>
void PopulateArray(std::vector<T> &array, const int &SIZE)
{
    array.clear();
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for(int i = 0; i < SIZE; i++)
    {
        T value = static_cast<T>(std::rand() % 200-100);
        array.push_back(value);
    }
}

template <typename T>
void Print(std::vector<T> &array)
{
    for(typename std::vector<T>::iterator itr = array.begin(); itr != array.end(); itr++)
    {
        std::cout << *itr << "  ";
    }
    puts("");
}


int main(int argc, const char * argv[]) 
{
    const int SIZE = 20;
    std::vector<int> array;
    std::vector<int> temp(20);

    std::cout << "Unsorted array: \n";
    PopulateArray(array, SIZE);
    Print(array);
    puts("");
    
    std::cout << "Merge Sort Result: \n";
    MergeSort(array, temp, 0, 19);
    Print(array);
    array.clear();
    puts("");
    
    return 0;
}
