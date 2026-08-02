#include <iostream>
#include <string>
using namespace std;

class Patient
{
private:
    int roomNo;
    string name;
    int age;
    string disease;

public:
    void getData();
    void displayData();
    int getRoomNo();
};

void Patient::getData()
{
    cout << "\nEnter Room Number: ";
    cin >> roomNo;

    cin.ignore();

    cout << "Enter Patient Name: ";
    getline(cin, name);

    cout << "Enter Age: ";
    cin >> age;

    cin.ignore();

    cout << "Enter Disease: ";
    getline(cin, disease);
}

void Patient::displayData()
{
    cout << "\n-----------------------------";
    cout << "\nRoom Number : " << roomNo;
    cout << "\nPatient Name: " << name;
    cout << "\nAge         : " << age;
    cout << "\nDisease     : " << disease;
    cout << "\n-----------------------------";
}

int Patient::getRoomNo()
{
    return roomNo;
}

int main()
{
    Patient p[50];
    int n = 0;
    int choice, room, i;
    bool found;

    do
    {
        cout << "\n\n===== Hospital Patient Management System =====";
        cout << "\n1. Add Patient";
        cout << "\n2. Display All Patients";
        cout << "\n3. Search Patient by Room Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                if(n < 50)
                {
                    p[n].getData();
                    n++;
                    cout << "\nPatient Added Successfully!";
                }
                else
                {
                    cout << "\nHospital Records Full!";
                }
                break;

            case 2:
                if(n == 0)
                {
                    cout << "\nNo Patient Records Found!";
                }
                else
                {
                    cout << "\nPatient Records:";
                    for(i = 0; i < n; i++)
                    {
                        p[i].displayData();
                    }
                }
                break;

            case 3:
                if(n == 0)
                {
                    cout << "\nNo Patient Records Found!";
                    break;
                }

                cout << "\nEnter Room Number to Search: ";
                cin >> room;

                found = false;

                for(i = 0; i < n; i++)
                {
                    if(p[i].getRoomNo() == room)
                    {
                        p[i].displayData();
                        found = true;
                        break;
                    }
                }

                if(!found)
                {
                    cout << "\nPatient Not Found!";
                }
                break;

            case 4:
                cout << "\nThank You!";
                break;

            default:
                cout << "\nInvalid Choice!";
        }

    } while(choice != 4);

    return 0;
}