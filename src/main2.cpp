#include <print>
#include <vector>

bool isPrime(int num) {
    for (int i = 2; num > i; ++i) {
        if (num % i == 0) return false;
    }
    return num > 1;
}
void findPrimes() {
    for (int i{}; i <= 100; ++i) {
        if (isPrime(i)) std::println("{} is a prime!", i);
    }
}

std::vector<int> square() {
    std::vector<int> squares;
    for (int i = 1;; i *=2) {
        squares.push_back(i);
    }
    return squares;
}

void printSquares() {
    auto squares = square();
    auto size = static_cast<int>(squares.size());
    for (int i = 0; i < size; ++i) {
        int element = squares.at(i);
        std::println("The square of {} is: {}", i, element);
    }
}

int main() {
    printSquares();
    return 0;
}
