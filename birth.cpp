#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
#include <chrono>

using namespace std;

// Define a struct to represent a birthday
struct Birthday {
    int day;
    int month;
    int year;
};

// Helper function to generate a random date within the last 50 years
Birthday generateRandomBirthday() {
    auto now = chrono::system_clock::now();
    auto now_t = chrono::system_clock::to_time_t(now);
    auto min_time = now_t - 50*365*24*60*60; // 50 years in seconds
    auto max_time = now_t;
    auto random_time = min_time + rand() % (max_time - min_time);
    auto random_tm = *localtime(&random_time);
    Birthday b;
    b.day = random_tm.tm_mday;
    b.month = random_tm.tm_mon + 1; // tm_mon is 0-based
    b.year = random_tm.tm_year + 1990; // tm_year is years since 1900
    return b;
}

// Helper function to print a Birthday object
void printBirthday(const Birthday& b) {
    cout << b.day << "/" << b.month << "/" << b.year;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(nullptr));
    
    // Define a map to store birthdays by name
    map<string, Birthday> birthdays;
    
    // Generate some random birthdays and add them to the maps
    vector<string> names = {"harshal", "prasad", "pradnya", "Ajay", "vaishnavi"};
    for (const auto& name : names) {
        Birthday b = generateRandomBirthday();
        birthdays[name] = b;
    }
    
    // Print the list of birthdays
    cout << "Birthday list:" << endl;
    for (const auto& entry : birthdays) {
        cout << entry.first << ": ";
        printBirthday(entry.second);
        cout << endl;
    }
    
    // Search for a birthday by name
    string search_name = "Charlie";
    auto it = birthdays.find(search_name);
    if (it != birthdays.end()) {
        cout << search_name << "'s birthday is on ";
        printBirthday(it->second);
        cout << endl;
    } else {
        cout << "Couldn't find " << search_name << " in the birthday list." << endl;
    }
    
    // List birthdays by month
    cout << "Birthdays by month:" << endl;
    for (int m = 1; m <= 12; m++) {
        cout << "Month " << m << ":" << endl;
        for (const auto& entry : birthdays) {
            if (entry.second.month == m) {
                cout << "- " << entry.first << ": ";
                printBirthday(entry.second);
                cout << endl;
            }
        }
    }
    
    return 0;
}
