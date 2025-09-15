
#include <iostream>
#include <cstring>   // for strlen, strcpy

using std::cin, std::cout, std::endl;

// TODO: function prototypes
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity);
void updateGPA(double *gpaptr, double newGPA);
void printStudent(char* name, const double& gpa);
double averageGPA(const double gpas[], int size);
// TODO: implement addStudent
void addStudent(char* name, double gpa, char* names[], double gpas[], int& size, int capacity){
    if (size >= capacity){
        throw std::string("List full");
    }
    names[size] = name;
    gpas[size] = gpa;
    size++;
}
// TODO: implement updateGPA
void updateGPA(double *gpaptr, double newGPA){
    if (gpaptr == nullptr){
        throw std::string("GPA pointer is null");
    }
    *gpaptr = newGPA;

}
// TODO: implement printStudent
void printStudent(char* name, const double& gpa){
    cout << name << ", " << gpa << endl;
}    
// TODO: implement averageGPA
double averageGPA(const double gpas[], int size){
    if (size == 0){
        throw std::string("No students");
    }
    double sum = 0;
    for (int i = 0; i < size; i++){
        sum += gpas[i];
    }
    return sum/size;
}
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: ./program <capacity>" << std::endl;
        return 1;
    }

    int capacity = std::stoi(argv[1]);
    char** names = new char*[capacity];
    double* gpas = new double[capacity];
    int size = 0;

    int choice;
    do {
        std::cout << "Menu:\n";
        std::cout << "1. Add student\n";
        std::cout << "2. Update GPA\n";
        std::cout << "3. Print all students\n";
        std::cout << "4. Compute average GPA\n";
        std::cout << "5. Quit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1: {
                // TODO: implement menu logic
                const int MAX_NAME = 100;
                char* name = new char[MAX_NAME];
                double gpa;
                std::cout << "Enter name: ";
                std::cin.ignore();  // Clear newline from previous input
                std::cin.getline(name, MAX_NAME);
                std::cout << "Enter GPA: ";
                std::cin >> gpa;
                try {
                    addStudent(name, gpa, names, gpas, size, capacity);
                }
                catch (const std::string s){
                    cout << s << endl;
                    delete[] name;  // Only delete if addStudent failed
                }
                break;
            }
            case 2: {
                // TODO: implement menu logic
                int index;
                std::cout << "Enter index: ";
                std::cin >> index;
                if (index >= 0 && index < size){
                    try {
                        double newGPA;
                        std::cout << "Enter new GPA: ";
                        std::cin >> newGPA;
                        updateGPA(&gpas[index], newGPA);
                    }
                    catch (const std::string s){
                        cout << s << endl;
                    }
                }
                else {
                    std::cout << "Invalid index" << std::endl;
                }
                break;
            }
            case 3: {
                // TODO: implement menu logic
                //TODO Make sure throw is caught
                for (int i = 0; i < size; i++){
                    printStudent(names[i], gpas[i]);
                }
                break;
            }
            case 4: {
                // TODO: implement menu logic
                try {
                    double avg = averageGPA(gpas, size);
                    int avgInt = static_cast<int>(avg);
                    cout << "Average GPA: " << avgInt << endl;
                }
                catch (const std::string s){
                    cout << s << endl;
                }
                break;
            }
            case 5: {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
            }
        }
    } while (choice != 5);

    // TODO: free memory
    for (int i = 0; i < size; i++) {
        delete[] names[i];
    }
    delete[] names;
    delete[] gpas;

    return 0;
}
