#include<iostream>

template<typename T>
int Partition(T arr[], int start, int end, bool (*CmpFun)(T, T)) {

    int pivot = end;
    int j = start;
    for (int i = start; i < end; ++i) {
        if (CmpFun(arr[i], arr[pivot])) {
            std::swap(arr[i], arr[j]);
            ++j;
        }
    }
    std::swap(arr[j], arr[pivot]);
    return j;

}

template<typename T>
void Quicksort(T arr[], int start, int end, bool (*CmpFun)(T, T)) {
    if (start < end) {
        int ptr = Partition(arr, start, end, CmpFun);
        Quicksort(arr, start, ptr - 1, CmpFun);
        Quicksort(arr, ptr + 1, end, CmpFun);
    }

}

template<typename T>
void Sort(T *Arr, int N, bool (*CmpFun)(T, T)) {
    Quicksort(Arr, 0, N - 1, CmpFun);
}

template<typename T>
bool greater(T Arg1, T Arg2) {
    return Arg1 < Arg2;
}

template<typename T>
bool less(T Arg1, T Arg2) {
    return !(Arg1 < Arg2);
}

template<typename T>
void PrintArray(T arr[], int n) {
    for (int i = 0; i < n; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
int main() {
    int a[] = { 1, 4, 2, 10, 47, 167, 61, 99, 100 };
    float b[] = { 1.73, 9.3, 12.4, 773.8923, 72.8, 2837.89, 221.92 };
    Sort<int>(a, 9, greater);
    PrintArray<int>(a, 9);
    Sort<int>(a, 9, less);
    PrintArray<int>(a, 9);
    Sort<float>(b, 7, greater);
    PrintArray<float>(b, 7);
    Sort<float>(b, 7, less);
    PrintArray<float>(b, 7);
}