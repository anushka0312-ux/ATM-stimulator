#include <iostream>
#include <unordered_map>
#include <string>

class ATM {
private:
    struct Account {
        std::string pin;
        double balance;
    };

    std::unordered_map<std::string, Account> accounts;
    bool loggedIn;
    std::string currentAccount;

public:
    ATM() : loggedIn(false) {
        // Initialize with some example accounts
        accounts["123456"] = {"1234", 1000.0};
        accounts["654321"] = {"4321", 2000.0};
    }

    void authenticate() {
        std::string accountNumber;
        std::string pin;

        std::cout << "Enter account number: ";
        std::cin >> accountNumber;
        std::cout << "Enter PIN: ";
        std::cin >> pin;

        auto it = accounts.find(accountNumber);
        if (it != accounts.end() && it->second.pin == pin) {
            loggedIn = true;
            currentAccount = accountNumber;
            std::cout << "Login successful!" << std::endl;
        } else {
            std::cout << "Invalid account number or PIN." << std::endl;
        }
    }

    void checkBalance() {
        if (loggedIn) {
            std::cout << "Your current balance is: $" << accounts[currentAccount].balance << std::endl;
        } else {
            std::cout << "You need to log in first." << std::endl;
        }
    }

    void withdrawMoney() {
        if (loggedIn) {
            double amount;
            std::cout << "Enter amount to withdraw: ";
            std::cin >> amount;

            if (amount <= accounts[currentAccount].balance) {
                accounts[currentAccount].balance -= amount;
                std::cout << "Withdrawal successful! Your new balance is: $" << accounts[currentAccount].balance << std::endl;
            } else {
                std::cout << "Insufficient funds." << std::endl;
            }
        } else {
            std::cout << "You need to log in first." << std::endl;
        }
    }

    void run() {
        int choice;
        do {
            std::cout << "\nATM Simulator\n";
            std::cout << "1. Log in\n";
            std::cout << "2. Check balance\n";
            std::cout << "3. Withdraw money\n";
            std::cout << "4. Exit\n";
            std::cout << "Enter your choice: ";
            std::cin >> choice;

            switch (choice) {
                case 1:
                    authenticate();
                    break;
                case 2:
                    checkBalance();
                    break;
                case 3:
                    withdrawMoney();
                    break;
                case 4:
                    std::cout << "Exiting..." << std::endl;
                    break;
                default:
                    std::cout << "Invalid choice. Please try again." << std::endl;
                    break;
            }
        } while (choice != 4);
    }
};

int main() {
    ATM atm;
    atm.run();
    return 0;
}

