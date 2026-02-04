#include <print>
#include <string>

void qs(char *items, int left, int right) {
    int i, j;
    char x, y;

    i = left;
    j = right;
    x = items[(left + right) / 2];

    do {
        while ((items [i] < x) && (i < right)) i++;
        while ((x < items[j]) && (j > left)) j--;

        if (i <= j) {
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            i++; j--;

        }
    } while (i <= j);
    if (left < j) qs (items, left, j);
    if (i < right) qs(items, i, right);
}

void quickSort(char *items, int len) {
    qs(items, 0, len-1);
}

void my_print(const char* foo) {
    std::println("Int was called");
    std::println("{}", foo);
}
void my_print(const int foo[]) {
    std::println("Double was called");
    std::println("{}", foo);
}

int main() {
    my_print("Hello");
    return 0;
}
