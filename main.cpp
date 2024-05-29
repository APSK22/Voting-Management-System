#include <bits/stdc++.h>
#include <conio.h>
#include <iostream>
using namespace std;

class Voter {
public:
    string name;
    int age;
    string state;
    int voterId;
    int party;
    Voter *next;

    Voter(string name, int age, string state, int voterId, int party) {
        this->name = name;
        this->age = age;
        this->state = state;
        this->voterId = voterId;
        this->party = party;
        next = NULL;
    }
};

class VoterFunctions {
public:
    Voter *head = NULL;
    Voter *tail = NULL;

    void InitializeFromDataFile(const string &filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            string name, state;
            int age, voterId, party;
            while (inFile >> name >> age >> state >> voterId >> party) {
                Insert(name, age, state, voterId, party);
            }
            inFile.close();
        } else {
            cout << "Error: Unable to open the file." << endl;
        }
    }

    void Insert(string name, int age, string state, int voterId, int party) {
        Voter *temp = new Voter(name, age, state, voterId, party);
        if (head == NULL) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = tail->next;
        }
    }

    void Display() {
        Voter *temp = head;
        while (temp != NULL) {
            cout << "\033[1;36mName:\033[0m " << temp->name << endl;
            cout << "\033[1;36mAge:\033[0m " << temp->age << endl;
            cout << "\033[1;36mState:\033[0m " << temp->state << endl;
            cout << "\033[1;36mVoter ID:\033[0m " << temp->voterId << endl;

            switch (temp->party) {
            case 1:
                cout << "\033[1;32mVoted for: BJP\033[0m";
                break;
            case 2:
                cout << "\033[1;34mVoted for: AAP\033[0m";
                break;
            case 3:
                cout << "\033[1;35mVoted for: Congress\033[0m";
                break;
            case 4:
                cout << "\033[1;33mVoted for: SVP\033[0m";
                break;
            case 5:
                cout << "\033[1;37mNOTA\033[0m";
                break;
            default:
                cout << "\033[1;31mNo valid option selected\033[0m";
                break;
            }
            cout << endl << endl;
            temp = temp->next;
        }
    }

    bool CheckId(int Id) {
        Voter *temp = head;
        while (temp != NULL) {
            if (temp->voterId == Id) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    void SaveToFile() {
        ofstream outFile("initial_data.txt", ios::trunc);
        if (outFile.is_open()) {
            Voter *temp = head;
            while (temp != NULL) {
                outFile << temp->name << " " << temp->age << " " << temp->state << " " << temp->voterId << " " << temp->party << endl;
                temp = temp->next;
            }
            outFile.close();
            cout << "Voter information saved successfully." << endl;
        } else {
            cout << "Error: Unable to save voter information to the file." << endl;
        }
    }

    int count() {
        int cnt = 0;
        Voter *temp = head;
        while (temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

    void WinningParty() {
        cout << endl << endl;
        const int PARTIES = 5;
        int partyVotes[PARTIES] = {0};
        Voter *temp = head;
        while (temp != NULL) {
            if (temp->party >= 1 && temp->party <= PARTIES) {
                partyVotes[temp->party - 1]++;
            }
            temp = temp->next;
        }

        cout << "Vote Results:" << endl;
        for (int i = 0; i < PARTIES; ++i) {
            switch (i + 1) {
            case 1:
                cout << "BJP: ";
                break;
            case 2:
                cout << "AAP: ";
                break;
            case 3:
                cout << "Congress: ";
                break;
            case 4:
                cout << "SVP: ";
                break;
            case 5:
                cout << "NOTA: ";
                break;
            default:
                break;
            }
            cout << partyVotes[i] << " votes" << endl;
        }

        int maxVotesIndex = 0;
        for (int i = 1; i < PARTIES; ++i) {
            if (partyVotes[i] > partyVotes[maxVotesIndex]) {
                maxVotesIndex = i;
            }
        }

        switch (maxVotesIndex + 1) {
        case 1:
            cout << "BJP is currently winning!" << endl;
            break;
        case 2:
            cout << "AAP is currently winning!" << endl;
            break;
        case 3:
            cout << "Congress is currently winning!" << endl;
            break;
        case 4:
            cout << "SVP is currently winning!" << endl;
            break;
        case 5:
            cout << "NOTA is currently winning!" << endl;
            break;
        default:
            break;
        }
    }

    void DeleteVoter(int voterId) {
        Voter *current = head;
        Voter *previous = nullptr;
        while (current != nullptr && current->voterId != voterId) {
            previous = current;
            current = current->next;
        }
        if (current != nullptr) {
            if (previous != nullptr) {
                previous->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            SaveToFile();
            cout << "Voter with ID " << voterId << " has been successfully deleted." << endl;
        } else {
            cout << "Voter with ID " << voterId << " not found." << endl;
        }
    }

    void UpdateVoter(int voterId, string newName, int newAge, string newState, int newParty) {
        Voter *temp = head;
        while (temp != NULL) {
            if (temp->voterId == voterId) {
                temp->name = newName;
                temp->age = newAge;
                temp->state = newState;
                temp->party = newParty;
                SaveToFile();
                cout << "Voter with ID " << voterId << " has been successfully updated." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Voter with ID " << voterId << " not found." << endl;
    }

    void printHeading() {
        system("CLS");
        cout << "\033[1;32m========================================================================================================================================================================================================\033[0m" << endl;
        cout << "\033[1;32m\t\t\t\t\t\t\t\t\t\t\t\t\033[1;32mV  O  T  I  N  G    S  Y  S  T  E  M\033[0m" << endl;
        cout << "\033[1;32m========================================================================================================================================================================================================\033[0m" << endl;
    }
};

void printMenu() {
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t===== Voting System Menu =====\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\033[1;36m1. Cast a Vote\033[0m\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\033[1;36m2. See Winning Party\033[0m\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\033[1;36m3. See Total Number of Votes Casted\033[0m\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\033[1;36m4. Update a Voter by ID\033[0m\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\033[1;36m5. Delete a Voter by ID\033[0m\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\t\033[1;36m6. Exit\033[0m\n";
    cout << "\n\t\t\t\t\t\t\t\t\t\t\tEnter your choice (1-6): ";
}

bool authenticateUser() {
    string username, password;
    cout << "\n\t\t\t\t\t\t\t\t================================ Login ================================" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\t\tEnter your username: ";
    cin >> username;
    cout << "\t\t\t\t\t\t\t\t\t\t\tEnter your password: ";
    char ch;
    while ((ch = _getch()) != 13) {
        password.push_back(ch);
        cout << '*';
    }
    cin.ignore();
    return (username == "DSP" && password == "MyDSP1");
}

int main() {
    bool runProgram = true;

    VoterFunctions vf;
    vf.InitializeFromDataFile("initial_data.txt");

    while (runProgram) {
        vf.printHeading();
        if (!authenticateUser()) {
            cout << "\n\nIncorrect username or password. Please try again.\n";
            continue;
        }

        bool inSession = true;
        while (inSession) {
            vf.printHeading();
            printMenu();

            int choice;
            cin >> choice;

            switch (choice) {
            case 1: {
                cout << "Enter name: ";
                string name;
                cin >> name;
                cout << "Enter age: ";
                int age;
                cin >> age;
                cout << "Enter state: ";
                string state;
                cin >> state;
                cout << "Enter voter ID: ";
                int voterId;
                cin >> voterId;
                if (!vf.CheckId(voterId)) {
                    cout << "Voter ID already exists. Please try again.\n";
                    break;
                }
                cout << "Enter party (1: BJP, 2: AAP, 3: Congress, 4: SVP, 5: NOTA): ";
                int party;
                cin >> party;
                vf.Insert(name, age, state, voterId, party);
                vf.SaveToFile();
                cout << "Vote casted successfully.\n";
                break;
            }
            case 2:
                vf.WinningParty();
                break;
            case 3:
                cout << "Total number of votes casted: " << vf.count() << endl;
                break;
            case 4: {
                cout << "Enter voter ID to update: ";
                int voterId;
                cin >> voterId;
                cout << "Enter new name: ";
                string newName;
                cin >> newName;
                cout << "Enter new age: ";
                int newAge;
                cin >> newAge;
                cout << "Enter new state: ";
                string newState;
                cin >> newState;
                cout << "Enter new party (1: BJP, 2: AAP, 3: Congress, 4: SVP, 5: NOTA): ";
                int newParty;
                cin >> newParty;
                vf.UpdateVoter(voterId, newName, newAge, newState, newParty);
                break;
            }
            case 5: {
                cout << "Enter voter ID to delete: ";
                int voterId;
                cin >> voterId;
                vf.DeleteVoter(voterId);
                break;
            }
            case 6:
                inSession = false;
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
            }

            cout << "\nPress any key to continue...";
            _getch();
        }
    }

    return 0;
}
