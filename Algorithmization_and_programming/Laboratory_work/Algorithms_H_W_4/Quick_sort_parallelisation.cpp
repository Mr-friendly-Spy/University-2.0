#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <algorithm>
#include <random>

using namespace std;

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high], i = low - 1;
        for (int j = low; j < high; j++)
            if (arr[j] < pivot) swap(arr[++i], arr[j]);
        swap(arr[++i], arr[high]);

        quickSort(arr, low, i - 1);
        quickSort(arr, i + 1, high);
    }
}

void quickSortPar(vector<int>& arr, int low, int high, int depth, int maxDepth) {
    if (low < high) {
        int pivot = arr[high], i = low - 1;
        for (int j = low; j < high; j++)
            if (arr[j] < pivot) swap(arr[++i], arr[j]);
        swap(arr[++i], arr[high]);

        if (depth < maxDepth) {
            thread t(quickSortPar, ref(arr), low, i - 1, depth + 1, maxDepth);
            quickSortPar(arr, i + 1, high, depth + 1, maxDepth);
            t.join();
        }
        else {
            quickSort(arr, low, i - 1);
            quickSort(arr, i + 1, high);
        }
    }
}

int main() {
    const int SIZE = 90000;
    vector<int> arr(SIZE);

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(1, 1000000);
    for (int i = 0; i < SIZE; i++) arr[i] = dist(gen);

    auto arrSeq = arr;
    auto start = chrono::high_resolution_clock::now();
    quickSort(arrSeq, 0, SIZE - 1);
    auto seqTime = chrono::duration<double>(chrono::high_resolution_clock::now() - start).count();

    cout << "Sequential: " << seqTime << "s\n\n";
    cout << "Threads\tTime\tSpeedup\n";

    for (int depth = 0; depth <= 6; depth++) {
        auto arrPar = arr;
        int threads = depth == 0 ? 1 : 1 << depth;

        start = chrono::high_resolution_clock::now();
        quickSortPar(arrPar, 0, SIZE - 1, 0, depth);
        auto parTime = chrono::duration<double>(chrono::high_resolution_clock::now() - start).count();

        cout << threads << "\t" << parTime << "s\t" << (seqTime / parTime) << "x";
     
        cout << endl;
    }

    return 0;
}