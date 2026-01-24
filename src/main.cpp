#include <print>
#include <string>
#include <iostream>
#include <stdexcept>

struct Account {
    std::string name;
    int age;
    double balance;
    int pin;
};

void deposit(Account& acc, double money) {
    if (money <= 0) {
        throw std::logic_error("Cannot deposit this amount of money");
    }
    acc.balance += money;
    std::println("Your money has been added.");
};

void withdraw(Account& acc, double money) {
    if (money <= 0 || money > acc.balance) {
        throw std::logic_error("Cannot withdraw this amount of money");
    }
    acc.balance -= money;
    std::println("Your money has been withdrawn.");
};

std::string checkBalance(const Account& acc) {
    return std::format("Your balance is: ", acc.balance);
}

bool is_child(int age) {
    return age < 18;
}

void startBankingSession() {
    std::string name;
    std::string ageStr;
    std::string pinStr;

    std::println("Welcome to starling bank. Please enter your name:");
    std::getline(std::cin, name);

    std::println("Please enter your age:");
    std::getline(std::cin, ageStr);

    int age = std::stoi(ageStr);
    if (is_child(age)) {
        throw std::logic_error("Unfortunately, you cannot create an account yet. Please wait until you are 18");
    }

    std::println("Finally, please enter your pin:");
    std::getline(std::cin, pinStr);
    int pin = std::stoi(pinStr);

    Account account = Account{ .name = name, .age = age, .balance = 0, .pin = pin};
    std::println("Your account has been created");

    while (true) {
        std::string oppStr;
        std::println("Please choose an Operation:\n1. Check balance\n2. Deposit money\n3. Withdraw money\n4. Exit\n");
        std::getline(std::cin, oppStr);
        int opp = std::stoi(oppStr);
        switch (opp) {
            case 1:
                double money;
                std::println("How much would you like to deposit?\n");
                std::cin >> money;
                deposit(account, money);
                std::println();
        }
    }
}

int main() {}
