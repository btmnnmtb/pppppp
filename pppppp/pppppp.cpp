#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>

class MergeSort {
public:
    void Sort(std::vector<int>& arr) {
        if (arr.size() <= 1) return;

        int mid = arr.size() / 2;
        std::vector<int> left(arr.begin(), arr.begin() + mid);
        std::vector<int> right(arr.begin() + mid, arr.end());

        Sort(left);
        Sort(right);

        Merge(arr, left, right);
    }

private:
    void Merge(std::vector<int>& arr, std::vector<int>& left, std::vector<int>& right) {
        int i = 0, j = 0, k = 0;
        while (i < left.size() && j < right.size()) {
            if (left[i] < right[j]) {
                arr[k++] = left[i++];
            }
            else {
                arr[k++] = right[j++];
            }
        }
        while (i < left.size()) {
            arr[k++] = left[i++];
        }
        while (j < right.size()) {
            arr[k++] = right[j++];
        }
    }
};

int main() {

    setlocale(LC_ALL ,"ru");
    std::vector<int> arr(10);
    std::cout << "Введите 10 целый чисел: ";
    for (int& i : arr) {
        std::cin >> i;
    }

    MergeSort sorter;
    std::thread t([&sorter, &arr]() {
        sorter.Sort(arr);
        });

    t.join();

    std::cout << "Отсортированный список: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

  

   
    return 0;
}