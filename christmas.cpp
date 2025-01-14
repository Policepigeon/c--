#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <unordered_map>
#include <functional>

// Function prototypes
void showCompletionScreen();
void saveProgress(const std::unordered_map<int, bool>& progress);
std::unordered_map<int, bool> loadProgress();
void unlockPuzzles(const std::unordered_map<int, bool>& progress);
bool isValidDay(int day);
void displayMenu();
void playPuzzle(int day);
void setupPuzzles();

std::unordered_map<int, std::function<void()>> puzzles;

int main() {
    setupPuzzles();

    // Load user progress
    std::unordered_map<int, bool> progress = loadProgress();

    // Main menu loop
    while (true) {
        displayMenu();
        int choice;
        std::cout << "Enter a day to attempt its puzzle (or 0 to quit): ";
        std::cin >> choice;
        if (choice == 0) {
            std::cout << "Goodbye and Merry Christmas!" << std::endl;
            break;
        }

        if (!isValidDay(choice)) {
            std::cout << "Invalid day! Please enter a number between 1 and 25." << std::endl;
            continue;
        }

        if (progress[choice]) {
            std::cout << "You've already completed this day's puzzle!" << std::endl;
            continue;
        }

        playPuzzle(choice);
        progress[choice] = true;
        saveProgress(progress);

        // Check if all days have been completed
        bool allCompleted = true;
        for (const auto& pair : progress) {
            if (!pair.second) {
                allCompleted = false;
                break;
            }
        }

        if (allCompleted) {
            showCompletionScreen();
            break;
        }
    }

    return 0;
}
void showCompletionScreen() {
    std::cout << "\nCongratulations! You've completed all the puzzles!\n";
    std::cout << "        *\n";
    std::cout << "       /|\\\n";
    std::cout << "      / | \\\n";
    std::cout << "     /  |  \\\n";
    std::cout << "    /   |   \\\n";
    std::cout << "   /    |    \\\n";
    std::cout << "  /     |     \\\n";
    std::cout << " /______|______\\\n";
    std::cout << "     Merry Christmas!\n";
}

void saveProgress(const std::unordered_map<int, bool>& progress) {
    std::ofstream file("progress.txt");
    if (!file.is_open()) {
        std::cerr << "Error saving progress!" << std::endl;
        return;
    }
    for (const auto& pair : progress) {
        file << pair.first << " " << pair.second << "\n";
    }
    file.close();
}

std::unordered_map<int, bool> loadProgress() {
    std::unordered_map<int, bool> progress;
    for (int i = 1; i <= 25; ++i) {
        progress[i] = false;
    }

    std::ifstream file("progress.txt");
    if (!file.is_open()) {
        return progress;
    }

    int day;
    bool completed;
    while (file >> day >> completed) {
        progress[day] = completed;
    }
    file.close();

    return progress;
}

void unlockPuzzles(const std::unordered_map<int, bool>& progress) {
    time_t now = time(0);
    tm* localTime = localtime(&now);
    int currentDay = localTime->tm_mday;

    std::cout << "\nAvailable puzzles:\n";
    for (int i = 1; i <= 25; ++i) {
        if (i <= currentDay) {
            std::cout << "Day " << i << ": " << (progress.at(i) ? "Completed" : "Available") << "\n";
        } else {
            std::cout << "Day " << i << ": Locked" << std::endl;
        }
    }
}

bool isValidDay(int day) {
    return day >= 1 && day <= 25;
}

void displayMenu() {
    std::cout << "\nWelcome to the Advent Calendar Puzzle Game!\n";
    std::unordered_map<int, bool> progress = loadProgress();
    unlockPuzzles(progress);
}

void playPuzzle(int day) {
    if (puzzles.find(day) != puzzles.end()) {
        puzzles[day]();
    } else {
        std::cout << "This puzzle is not implemented yet!" << std::endl;
    }
}

// Example puzzles (add more as needed)
void setupPuzzles() {
    puzzles[1] = []() {
        std::cout << "Day 1: Solve this riddle - What has to be broken before you can use it?\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "egg" || answer == "Egg") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[2] = []() {
        std::cout << "Day 2: What is 5 + 7?\n";
        int answer;
        std::cin >> answer;
        if (answer == 12) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[3] = []() {
        std::cout << "Day 3: Unscramble this word: RELIK\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "kiler" || answer == "Kiler") {
            std::cout << "Correct! (Hint: It sounds festive!)" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[4] = []() {
        std::cout << "Day 4: What color is Rudolph's nose?\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "red" || answer == "Red") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[5] = []() {
        std::cout << "Day 5: Multiply 3 by 4.\n";
        int answer;
        std::cin >> answer;
        if (answer == 12) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[6] = []() {
        std::cout << "Day 6: What is the third letter of the alphabet?\n";
        char answer;
        std::cin >> answer;
        if (answer == 'c' || answer == 'C') {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[7] = []() {
        std::cout << "Day 7: Which Christmas song contains the lyrics 'Let it snow'?\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "Let it snow" || answer == "let it snow" || answer == "Let It Snow") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[8] = []() {
        std::cout << "Day 8: Unscramble: ANTTAS\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "Santa" || answer == "santa") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[9] = []() {
        std::cout << "Day 9: What is 9 x 8?\n";
        int answer;
        std::cin >> answer;
        if (answer == 72) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[10] = []() {
        std::cout << "Day 10: Solve this riddle: The more you take, the more you leave behind. What am I?\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "footsteps" || answer == "Footsteps") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[11] = []() {
        std::cout << "Day 11: How many reindeer pull Santa's sleigh (including Rudolph)?\n";
        int answer;
        std::cin >> answer;
        if (answer == 9) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[12] = []() {
        std::cout << "Day 12: What is the square root of 144?\n";
        int answer;
        std::cin >> answer;
        if (answer == 12) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[13] = []() {
        std::cout << "Day 13: What is Santa's favorite snack?\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "cookies" || answer == "Cookies") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[14] = []() {
        std::cout << "Day 14: Which fruit is commonly associated with Christmas?\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "orange" || answer == "Orange") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[15] = []() {
        std::cout << "Day 15: What is 15 + 15?\n";
        int answer;
        std::cin >> answer;
        if (answer == 30) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[16] = []() {
        std::cout << "Day 16: What are two things you hang on a Christmas tree?\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "ornaments and lights" || answer == "lights and ornaments") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[17] = []() {
        std::cout << "Day 17: What is the largest land animal?\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "elephant" || answer == "Elephant") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[18] = []() {
        std::cout << "Day 18: What is 18 - 9?\n";
        int answer;
        std::cin >> answer;
        if (answer == 9) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[19] = []() {
        std::cout << "Day 19: Name a famous Christmas movie.\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "Home Alone" || answer == "Elf" || answer == "The Grinch") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[20] = []() {
        std::cout << "Day 20: How many sides does a snowflake have?\n";
        int answer;
        std::cin >> answer;
        if (answer == 6) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[21] = []() {
        std::cout << "Day 21: What color are Christmas holly berries?\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "red" || answer == "Red") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[22] = []() {
        std::cout << "Day 22: What is 22 divided by 2?\n";
        int answer;
        std::cin >> answer;
        if (answer == 11) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[23] = []() {
        std::cout << "Day 23: Unscramble: LBEEL\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "bell" || answer == "Bell") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
    puzzles[24] = []() {
        std::cout << "Day 24: What gift did the 3 Wise Men bring to baby Jesus? (Name any one)\n";
        std::string answer;
        std::cin.ignore();
        std::getline(std::cin, answer);
        if (answer == "gold" || answer == "Gold" || answer == "frankincense" || answer == "Frankincense" || answer == "myrrh" || answer == "Myrrh") {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Wrong answer. Try again another time!" << std::endl;
        }
    };
}
