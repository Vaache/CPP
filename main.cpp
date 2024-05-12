#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

class MergeInsertionSort {
private:
    void blockSwap(std::vector<int>& array, int a, int b, int s) {
        while (s-- > 0) std::swap(array[a--], array[b--]);
    }

    void blockInsert(std::vector<int>& array, int a, int b, int s) {
        while (a - s >= b) {
            this->blockSwap(array, a - s, a, s);
            a -= s;
        }
    }

    void blockReversal(std::vector<int>& array, int a, int b, int s) {
        b -= s;
        while (b > a) {
            this->blockSwap(array, a, b, s);
            a += s;
            b -= s;
        }
    }

    int blockSearch(std::vector<int>& array, int a, int b, int s, int val) {
        while (a < b) {
            int m = a + (((b - a) / s) / 2) * s;
            if (val < array[m])
                b = m;
            else
                a = m + s;
        }
        return a;
    }

    void order(std::vector<int>& array, int a, int b, int s) {
        for (int i = a, j = i + s; j < b; i += s, j += 2 * s)
            this->blockInsert(array, j, i, s);

        int m = a + (((b - a) / s) / 2) * s;
        this->blockReversal(array, m, b, s);
    }

public:
    void runSort(std::vector<int>& array, int length) {
        int k = 1;
        while (2 * k <= length) {
            for (int i = 2 * k - 1; i < length; i += 2 * k)
                if (array[i - k] > array[i])
                    this->blockSwap(array, i - k, i, k);
            k *= 2;
        }

        while (k > 0) {
            int a = k - 1;
			int i = a + 2 * k;
			int g = 2;
			int p = 4;
			int c = i + 2 * k * g - k;
            while (c <= length) {
                this->order(array, i, i + 2 * k * g - k, k);
                int b = a + k * (p - 1);

                i += k * g - k;
                for (int j = i; j < i + k * g; j += k)
                    this->blockInsert(array, j, this->blockSearch(array, a, b, k, array[j]), k);

                i += k * g + k;
                g = p - g;
                p *= 2;
            }
            while (i < length) {
                this->blockInsert(array, i, this->blockSearch(array, a, i, k, array[i]), k);
                i += 2 * k;
            }

            k /= 2;
        }
    }
};


int main() {
    std::vector<int> arr = {14,135,614353,65,24525,246153,242462462,14,134134,134,1221};

    // Добавляем 100 случайных элементов в массив
    srand(time(NULL)); // Инициализируем генератор случайных чисел
    for (int i = 0; i < 100; ++i) {
        arr.push_back(rand() % 1000); // Генерируем случайное число от 0 до 999 и добавляем его в массив
    }

    // Создаем объект сортировки и запускаем сортировку
    MergeInsertionSort obj;
    obj.runSort(arr, arr.size());

    // Выводим отсортированный массив
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
