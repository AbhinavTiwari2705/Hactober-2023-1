#include <iostream>
#include <string>
#include <ctime>

bool crackPassword(const std::string& password, int maxLength = 6) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}|;':,.<>?";
    clock_t startTime = clock();
    
    for (int length = 1; length <= maxLength; length++) {
        std::string guess(length, ' ');

        while (true) {
            for (int i = 0; i < characters.length(); i++) {
                guess[length - 1] = characters[i];
                if (guess == password) {
                    clock_t endTime = clock();
                    double elapsedTime = double(endTime - startTime) / CLOCKS_PER_SEC;
                    std::cout << "Estimated time to crack the password: " << elapsedTime << " seconds" << std::endl;
                    return true;
                }
            }

            // Generate the next guess
            int index = length - 1;
            while (index >= 0 && guess[index] == characters[characters.length() - 1]) {
                guess[index] = characters[0];
                index--;
            }
            if (index < 0) {
                break;
            }
            guess[index] = characters[characters.find(guess[index]) + 1];
        }
    }

    return false;
}

int main() {
    std::string password = "your_password_here";
    if (!crackPassword(password)) {
        std::cout << "Password not cracked within the specified length." << std::endl;
    }

    return 0;
}
