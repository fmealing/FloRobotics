#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

// Task struct definition
struct Task {
    string description;
    string date;
    string time;

    // Serialize Task to a string
    string toString() const {
        return description + "," + date + "," + time;
    }

    // Deserialize Task from a string
    static Task fromString(const string &str) {
        Task task;
        stringstream ss(str);
        getline(ss, task.description, ',');
        getline(ss, task.date, ',');
        getline(ss, task.time, ',');
        return task;
    }
};

// Function prototypes
void hello_world();
void calculator_menu();
double calculation_choice();
double calculator_calculation(double a, double b, char choice);
void calculator();
void guessing_game();
void displayTasks(const vector<Task> &tasks);
void to_do_list();
void searchTasks(const vector<Task> &tasks);

// 1) Hello World
void hello_world() {
    cout << "Hello, World!" << endl;
}

// 2) Calculator
void calculator_menu() {
    cout << "Calculator Menu: " << endl;
    cout << "Press 'P' for add" << endl;
    cout << "Press 'S' for subtract" << endl;
    cout << "Press 'M' for multiply" << endl;
    cout << "Press 'D' for divide" << endl;
    cout << "Press 'Q' to quit: ";
}

double calculation_choice() {
    double a;
    cout << "Enter a number: ";
    cin >> a;
    return a;
}

double calculator_calculation(double a, double b, char choice) {
    double result = 0;
    switch (choice) {
        case 'P':
        case 'p':
            result = a + b;
            break;
        case 'S':
        case 's':
            result = a - b;
            break;
        case 'M':
        case 'm':
            result = a * b;
            break;
        case 'D':
        case 'd':
            if (b == 0) {
                cout << "Error: Division by zero is not allowed." << endl;
                return result;
            }
            result = a / b;
            break;
        default:
            cout << "Please enter a valid choice (P, S, M or D)." << endl;
            break;
    }
    return result;
}

void calculator() {
    char selection;
    do {
        calculator_menu();
        cin >> selection;

        if (selection == 'Q' || selection == 'q') {
            break;
        }

        double choice1 = calculation_choice();
        double choice2 = calculation_choice();
        double result = calculator_calculation(choice1, choice2, selection);

        cout << "The result is: " << result << endl;
        cout << "****************************************" << endl;
    } while (selection != 'Q' && selection != 'q');
}

// 3) Number Guessing Game
void guessing_game() {
    // Initialize random seed
    srand(static_cast<unsigned>(time(nullptr)));

    // Generate a random number between 1 and 100
    const int MAX_NUMBER = 100;
    int secret_number = rand() % MAX_NUMBER + 1;
    int guess = 0;
    int count = 0;

    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Can you guess what it is?" << endl;

    while (true) {
        cout << "Enter your guess: ";
        cin >> guess;

        if (cin.fail()) {
            cin.clear(); // clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        count++;

        if (guess > secret_number) {
            cout << "Too high! Try again." << endl;
        } else if (guess < secret_number) {
            cout << "Too low! Try again." << endl;
        } else {
            break;
        }
    }

    cout << "Congratulations! You guessed my number!" << endl;
    cout << "It only took you " << count << " guesses" << endl;
}

// 4) To-Do List
void displayTasks(const vector<Task> &tasks) {
    cout << "To-Do List: " << endl;
    for (int i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description << " - " << tasks[i].date << " " << tasks[i].time << endl;
    }
}

void searchTasks(const vector<Task> &tasks) {
    string keyword;
    cout << "Enter a keyword to search: ";
    cin.ignore();
    getline(cin, keyword);

    cout << "Search Results: " << endl;
    for (const auto &task : tasks) {
        if (task.description.find(keyword) != string::npos) {
            cout << task.description << " - " << task.date << " " << task.time << endl;
        }
    }
}

void to_do_list() {
    vector<Task> tasks;
    Task task;
    char choice;

    // Load existing tasks from file
    ifstream inputFile("tasks.txt");
    if (inputFile.is_open()) {
        string line;
        while (getline(inputFile, line)) {
            tasks.push_back(Task::fromString(line));
        }
        inputFile.close();
    } else {
        cout << "No existing tasks found. Starting with an empty list." << endl;
    }

    do {
        cout << "A - Add a task" << endl;
        cout << "V - View tasks" << endl;
        cout << "S - Search tasks" << endl;
        cout << "Q - Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 'A':
            case 'a':
                cout << "Enter a task: ";
                cin.ignore(); // Clears the input buffer
                getline(cin, task.description);
                cout << "Enter the date (YYYY-MM-DD): ";
                getline(cin, task.date);
                cout << "Enter the time (HH:MM): ";
                getline(cin, task.time);
                tasks.push_back(task);
                break;
            case 'V':
            case 'v':
                displayTasks(tasks);
                break;
            case 'S':
            case 's':
                searchTasks(tasks);
                break;
            case 'Q':
            case 'q':
                break;
            default:
                cout << "This was not one of the options" << endl;
                break;
        }
    } while (choice != 'Q' && choice != 'q');

    // Save tasks to file
    ofstream outputFile("tasks.txt");
    if (outputFile.is_open()) {
        for (const auto &t : tasks) {
            outputFile << t.toString() << endl;
        }
        outputFile.close();
    } else {
        cout << "Unable to open file for saving tasks." << endl;
    }
}


int main() {
    // hello_world();
    // calculator();
    // guessing_game();
    to_do_list();
    return 0;
}
