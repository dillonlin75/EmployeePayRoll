//Dillon Lin
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ofstream outFile;
    ifstream inFile;
    float gp,tw,np;
    int choice,num,choice2,idlength=0;
    int count=0,count2=0;
    const int maxemp = 100;
    string temp;
    bool thereis;

    struct employeerec
    {
        string id,lastname, firstname;
        float hours, payrate, taxrate;
    };
    employeerec emparray[maxemp] {};

    //Right Justification
    cout.setf(ios::right,ios::adjustfield);
    //Set Precision
    cout.precision(2);
    cout.setf(ios::fixed,ios::floatfield);
    cout.setf(ios::showpoint);

    inFile.open("personnel1.dat",ios::in);
    if (!inFile)
    {
        cout << "Error: File could not be opened.";
        system("pause");
    }

    while(!inFile.eof())
    {
        count++;
        inFile >> emparray[count].id >> emparray[count].lastname >> emparray[count].firstname
               >> emparray[count].hours >> emparray[count].payrate >> emparray[count].taxrate;
    }
    inFile.close();

    do
    {
        system("cls");
        cout << "\n1 - Display ALL Employees"
             << "\n2 - Find One Employee Based on ID (i.e. AF101,SG101,CV299)"
             << "\n3 - Find and Change Values"
             << "\n4 - Add a New Employee"
             << "\n5 - Quit"
             << "\nEnter Option 1 to 5: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                    system("cls");
                    count2 = 0;
                    for(int n=1; n<count; n++)
                    {
                        gp = emparray[n].hours * emparray[n].payrate;
                        tw = gp * emparray[n].taxrate;
                        np = gp - tw;

                        cout << "\n\nEmployee #" << n << " of " << count-1
                             <<"\nEmployee ID: " << emparray[n].id
                             << "\nEmployee Last Name: " << emparray[n].lastname
                             << "\nEmployee First Name: " << emparray[n].firstname
                             << "\n" << emparray[n].hours << " Hours Worked @ " << emparray[n].payrate << "\t$" << gp
                             << "\nTax Rate of " << emparray[n].taxrate *100 << "%\t\t$" << tw
                             << "\nEmployee Net Pay:\t\t$" << np;
                        count2++;
                        if (count2 % 3 == 0)
                        {
                            cout << "\n";
                            system("pause");
                            system("cls");
                        }
                    }
                    cout << "\n";
                    system("pause");
                    break;

            case 2:
                thereis = false;
                    cin.ignore();
                    cout << "\n\nThere are " << count-1 << " Records Available."
                          << "\nEnter Employee ID You Wish To Find (i.e.AF101,BB002...): ";
                    getline(cin,temp);

                    for(int n=1; n<count; n++)
                    {
                        if(emparray[n].id == temp)
                        {
                            gp = emparray[n].hours * emparray[n].payrate;
                            tw = gp * emparray[n].taxrate;
                            np = gp - tw;

                            cout << "\n\nEmployee #" << n << " of " << count-1
                                 <<"\nEmployee ID: " << emparray[n].id
                                 << "\nEmployee Last Name: " << emparray[n].lastname
                                 << "\nEmployee First Name: " << emparray[n].firstname
                                 << "\n" << emparray[n].hours << " Hours Worked @ $" << emparray[n].payrate << "\t$" << gp
                                 << "\nTax Rate of " << emparray[n].taxrate *100 << "%\t\t$" << tw
                                 << "\nEmployee Net Pay:\t\t$" << np;
                                 thereis = true;
                        }
                    }
                    if(thereis == false)
                    {
                        cout << "\n\nThe ID You Have Entered Does Not Exist In The Array.";
                    }
                    cout << "\n";
                    system("pause");
                    break;

            case 3:
                    thereis = false;
                    cin.ignore();
                    cout << "\n\nEnter Employee ID Whose Fields You Want To Change (i.e.BB002): ";
                    getline(cin,temp);
                    for(int n=0; n<count; n++)
                    {
                        if(emparray[n].id == temp)
                        {
                            do
                            {
                                system("cls");
                                cout << "\n1 - Change Employee ID (" << emparray[n].id << ")"
                                     << "\n2 - Change Employee Last Name (" << emparray[n].lastname << ")"
                                     << "\n3 - Change Employee First Name (" << emparray[n].firstname << ")"
                                     << "\n4 - Change Employee Hours Worked (" << emparray[n].hours << ")"
                                     << "\n5 - Change Employee Pay Per Hour ($" << emparray[n].payrate << ")"
                                     << "\n6 - Change Employee Tax Rate (" << emparray[n].taxrate << ")"
                                     << "\n7 - QUIT Changes"
                                     << "\nEnter Option 1 to 7: ";
                                cin >> choice2;

                                switch(choice2)
                                {
                                case 1:
                                    cout << "\nChange " << emparray[n].id << " to(i.e.BB002): ";
                                    cin >> emparray[n].id;
                                    idlength = emparray[n].id.length();
                                    while(idlength != 5)
                                    {
                                        cout << "\n\n!! ID MUST BE OF SIZE 5 !!"
                                             << "\nEnter NEW Employee ID(i.e.BB002): ";
                                        cin >> emparray[n].id;
                                        idlength = emparray[n].id.length();
                                    }
                                case 2:
                                    cout << "\nChange " << emparray[n].lastname << " to: ";
                                    cin >> emparray[n].lastname;
                                    break;
                                case 3:
                                    cout << "\nChange " << emparray[n].firstname << " to: ";
                                    cin >> emparray[n].firstname;
                                    break;
                                case 4:
                                    cout << "\nChange " << emparray[n].hours << " hours to: ";
                                    cin >> emparray[n].hours;
                                    break;
                                case 5:
                                    cout << "\nChange $" << emparray[n].payrate << " to: $";
                                    cin >> emparray[n].payrate;
                                    break;
                                case 6:
                                    cout << "\nChange " << emparray[n].taxrate << " to: ";
                                    cin >> emparray[n].taxrate;
                                    break;
                                }
                            }while(choice2 != 7);
                            thereis = true;
                        }
                    }
                    if(thereis == false)
                        {
                            cout << "\n\nThe ID You Have Entered Does Not Exist In The Array."
                                 << "\n";
                            system("pause");
                        }
                    break;

            case 4:
                    cout << "\n\nEnter NEW Employee ID(i.e.BB002): ";
                    cin >> emparray[count].id;
                    idlength = emparray[count].id.length();
                    while(idlength != 5)
                    {
                        system("cls");
                        cout << "\n\n!! ID MUST BE OF SIZE 5 !!"
                             << "\nEnter NEW Employee ID(i.e.BB002): ";
                        cin >> emparray[count].id;
                        idlength = emparray[count].id.length();
                    }
                    cout << "\nEnter NEW Employee Last Name: ";
                    cin >> emparray[count].lastname;
                    cout << "\nEnter NEW Employee First Name: ";
                    cin >> emparray[count].firstname;
                    cout << "\nEnter NEW Employee Hours: ";
                    cin >> emparray[count].hours;
                    cout << "\nEnter NEW Employee Payrate: $";
                    cin >> emparray[count].payrate;
                    cout << "\nEnter NEW Employee Taxrate: ";
                    cin >> emparray[count].taxrate;
                    count++;
                    break;

            case 5:
                    outFile.open("personnel1.dat");
                    for(int n=1; n<count; n++)
                    {
                        outFile << emparray[n].id << " " << emparray[n].lastname << " " << emparray[n].firstname << " "
                                << emparray[n].hours << " " << emparray[n].payrate << " " << emparray[n].taxrate << "\n";
                    }
                    outFile.close();
                    cout << "\n\nALL NEW INFO COPIED TO DATAFILE.\n";
                    system("pause");
                    break;

        }
    }while(choice != 5);
}
