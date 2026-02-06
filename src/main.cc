#include <print>
#include <string>

// void qs(char *items, int left, int right) {
//     int i, j;
//     char x, y;
//
//     i = left;
//     j = right;
//     x = items[(left + right) / 2];
//
//     do {
//         while ((items [i] < x) && (i < right)) i++;
//         while ((x < items[j]) && (j > left)) j--;
//
//         if (i <= j) {
//             y = items[i];
//             items[i] = items[j];
//             items[j] = y;
//             i++; j--;
//
//         }
//     } while (i <= j);
//     if (left < j) qs (items, left, j);
//     if (i < right) qs(items, i, right);
// }
//
// void quickSort(char *items, int len) {
//     qs(items, 0, len-1);
// }

namespace std {
    void foo() {
        int args[] = {1,2,3,4,5};
        for (auto i : args) {
            std::print("{}", i);
        }
        std::print("\n");
    }
}

int main() {
    int foo[] = {1,2,3,4,5};
    std::foo();
}
