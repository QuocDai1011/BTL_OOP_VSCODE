#include <iostream>
#include "./HospitalData.hpp"
#include "./HospitalFunction.hpp"
using namespace std;

Human *staff[100]; // mang con tro cua staff
Human *patient[1000]; //mang con tro cua patient
Human *doctor[100]; // mang con tro cua doctor


int main() { 
    system("CLS");
    // Staff đăng nhập
    staff[0] = new Staff;
    int login = 0; //
    Staff* staffPtr = dynamic_cast<Staff*>(staff[0]);
    
    if (staffPtr) { 
        staffPtr->logIn(login);
    } else {
        cout << "Error: Unable to cast to Staff." << endl;
        return 1;
    }
    if (!login) {
        cout << "Login failed." << endl;
        return 1;
    }
    // Kết thúc đăng nhập
    int indexSp;
    do {
        printFunctions();
        cout << "Enter the index corresponding to the supported function: ";
        cin >> indexSp;
        if(indexSp < 0 || indexSp > 5) {
            while(indexSp < 0 || indexSp > 5) {
                cout << "Input is incorrect. Try again: ";
                cin >> indexSp;
            }
        } 
        switch (indexSp)
        {
            case 1: {
                system("CLS");
                cout << "-------------------- LIST OF DOCTORS --------------------\n";
                for(int i = 0; i < 7; i++) {
                    doctor[i] = new Doctor;
                    Doctor* doctorPtr = dynamic_cast<Doctor*>(doctor[i]);
                    doctorPtr->readFromFile(i);
                    cout << doctorPtr;
                }
                break;
            }
            case 2: {
                system("CLS");
                Patient *pte = new Patient();
                string phone;
                cin.ignore();
                cout << "Enter the patient's phone number: ";
                getline(cin, phone);
                int check;
                pte->readInFormationByPhoneNumber(phone, check);
                system("CLS");
                if(check == 0) {
                    cout << "NOT FOUND THE PATIENT!\n";
                }else {
                    cout << pte;
                }
                break;
            }
            case 3: {
                Patient *p = new Patient();
                system("CLS");
                cin >> p;
                p->writeToFile();
                break;
            }
            case 4: {
                system("CLS");
                Patient *pte = new Patient();
                string phone;
                cin.ignore();
                cout << "Enter the patient's phone number: ";
                getline(cin, phone);
                int check;
                pte->readInFormationByPhoneNumber(phone, check);
                system("CLS");
                if(check == 0) {
                    cout << "NOT FOUND THE PATIENT TO UPDATE INFORMATION!\n";
                }else {
                    cout << pte;
                }
                cout << "------------------------------ UPDATE INFORMATION ------------------------------\n";
                pte->updateInformation();
                system("CLS");
                cout << "----------------------------- UPDATE SUCCESSFULLY ------------------------------\n";
                cout << pte;
                pte->writeToFile();
                break;
            }
            case 5: {

                break;
            }
            case 0: {
                break;
            }
            default:
                break;
        }
    }while(indexSp != 0);
}
