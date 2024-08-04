#include <iostream>
#include <string>

using namespace std;

// Enum for Gender
enum class Gender {
    MALE,
    FEMALE
};

// Passport class definition
class Passport {

private:
    string Name;
    string birthDay;
    Gender gender;
    string lastExit;
    string lastReturn;

public:
    // Constructor
    Passport() {
        Name = "";
        birthDay = "";
        gender = Gender::MALE;  // default to Male
        lastExit = "";
        lastReturn = "";
    }

    // Setter for Gender based on input
    void setGender(char genderInput) {
        if (genderInput == 'F' || genderInput == 'f') {
            gender = Gender::FEMALE;
        } else {
            gender = Gender::MALE;
        }
    }

    // Getter for Gender
    char getGender() const {
        return (gender == Gender::MALE) ? 'M' : 'F';
    }

    // Input function to populate passport details
    void Input() {
        cout << "Enter name: ";
        getline(cin, Name);
        cout << "Enter birth date: ";
        getline(cin, birthDay);
        char genderInput;
        cout << "Enter gender (M/F): ";
        cin >> genderInput;
        cin.ignore();  // Ignore newline left in buffer
        setGender(genderInput);
        cout << "Enter last exit date: ";
        getline(cin, lastExit);
        cout << "Enter last return date: ";
        getline(cin, lastReturn);
    }

    // Display function to print passport details
    void Display() const {
        cout << "Name: " << Name << endl;
        cout << "Birth Date: " << birthDay << endl;
        cout << "Gender: " << getGender() << endl;
        cout << "Last Exit Date: " << lastExit << endl;
        cout << "Last Return Date: " << lastReturn << endl;
    }
};

// Main function
int main() {
    Passport passports[5];

    // Populate passport details
    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for Passport " << i + 1 << ":" << endl;
        passports[i].Input();
    }

    // Display passports based on user input
    int citizenNumber;
    cout << "Enter citizen number (1-5): ";
    cin >> citizenNumber;

    if (citizenNumber >= 1 && citizenNumber <= 5) {
        cout << "Passport details for citizen " << citizenNumber << ":" << endl;
        passports[citizenNumber - 1].Display();
    } else {
        cout << "Citizen does not have a passport." << endl;
    }

    return 0;
}
