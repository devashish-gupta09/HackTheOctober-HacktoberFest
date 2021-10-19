#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct student_data
{
    long int rollno;
    char student_name[30];
    char father_name[30];
    char mother_name[30];
    int year;
    int semester;
    int branch;

    char h_no[30];
    char s_name[30];
    char city[30];
    char state[30];
    char country[30];

    void get_data();
    void delete_data();
    void search_data();
    void search_city();
    void search_state();
    void search_country();
    void display_data();
    void record();
    void reportdisplay();
};

void student_data::get_data()
{
    student_data s;
    cout << "ENTER ROLL NO.: ";
    cin >> s.rollno;
    cout << "ENTER STUDENT'S NAME: ";
    fflush(stdin);
    cin.getline(s.student_name, 30);
    cout << "ENTER FATHER'S NAME: ";
    fflush(stdin);
    cin.getline(s.father_name, 30);
    cout << "ENTER MOTHER'S NAME: ";
    fflush(stdin);
    cin.getline(s.mother_name, 30);
    cout << "ENTER COLLEGE YEAR: ";
    cin >> s.year;
    cout << "ENTER COLLEGE SEMESTER: ";
    cin >> s.semester;
    cout << "\nENTER 1: CIVIL\nENTER 2: COMPUTER SCIENCE\nENTER 3: ELECTRONICS AND COMMUNICATION\nENTER 4: MECHANICAL\n\nENTER BRANCH: ";
    cin >> s.branch;
    cout << endl
         << "ENTER HOUSE NO.: ";
    fflush(stdin);
    cin.getline(s.h_no, 30);
    cout << "ENTER STREET: ";
    fflush(stdin);
    cin.getline(s.s_name, 30);
    cout << "ENTER CITY: ";
    fflush(stdin);
    cin.getline(s.city, 30);
    cout << "ENTER STATE: ";
    fflush(stdin);
    cin.getline(s.state, 30);
    cout << "ENTER COUNTRY: ";
    fflush(stdin);
    cin.getline(s.country, 30);

    fstream data("data.txt", ios::app);
    data.write((char *)&s, sizeof(s));
    data.close();

    cout << "\n\n\n--------------------------------\tTHE DATA HAS BEEN RECORDED\t--------------------------------\n\n\n";
}

void student_data::delete_data()
{
    long int input;
    cout << "ENTER THE STUDENT ROLL NO.: ";
    cin >> input;

    student_data s;

    fstream data("data.txt");

    data.seekg(0, ios::end);
    int n = data.tellg() / sizeof(s);
    data.seekg(0, ios ::beg);

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        data.read((char *)&s, sizeof(s));
        if (input == s.rollno)
        {
            cout << "--------------------------------\t      RECORD FOUND      \t--------------------------------\n\n\n";
            count++;
            continue;
        }
        fstream temp("temp.txt", ios::app);
        temp.write((char *)&s, sizeof(s));
        temp.close();
    }

    if (count == 0)
    {
        cout << "--------------------------------\tNO RECORD FOUND\t--------------------------------\n\n\n";
    }
    else
    {
        cout << "--------------------------------\tTHE RECORD HAS BEEN DELETED\t--------------------------------\n\n\n";
    }
    data.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

void student_data::search_city()
{
    student_data s;
    cout << "ENTER CITY'S NAME: ";
    char input[30];
    fflush(stdin);
    cin.getline(input, 30);

    fstream data("data.txt");
    data.seekg(0, ios::end);
    int n = data.tellg() / sizeof(s);
    data.seekg(0, ios::beg);

    system("cls");
    cout << "--------------------------------\tSEARCH ON THE BASIS OF CITY\t--------------------------------\n\n\n";
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        data.read((char *)&s, sizeof(s));
        if (strcmp(s.city, input) == 0)
        {
            cout << "STUDENT'S ROLL NO.: " << s.rollno << endl
                 << "NAME              : " << s.student_name << endl
                 << "FATHER'S NAME     : " << s.father_name << endl
                 << "MOTHER'S NAME     : " << s.mother_name << endl
                 << "YEAR              : " << s.year << endl
                 << "SEMESTER          : " << s.semester << endl
                 << "BRANCH            : ";
            if (s.branch == 1)
            {
                cout << "Civil";
            }
            if (s.branch == 2)
            {
                cout << "Computer Science";
            }
            if (s.branch == 3)
            {
                cout << "Electronics and Communication";
            }
            if (s.branch == 4)
            {
                cout << "Mechanical";
            }

            cout << endl;
            cout << "ADDRESS           : " << s.h_no << ", " << s.s_name << endl
                 << "CITY              : " << s.city << endl
                 << "STATE             : " << s.state << endl
                 << "COUNTRY           : " << s.country << endl;
            cout << "\n\n";
            count++;
        }
    }
    if (count == 0)
    {
        cout << "\n------NO MATCHES FOUND------\n";
    }
}

void student_data::search_state()
{
    student_data s;
    cout << "ENTER STATE'S NAME: ";
    char input[30];
    fflush(stdin);
    cin.getline(input, 30);

    fstream data("data.txt");
    data.seekg(0, ios::end);
    int n = data.tellg() / sizeof(s);
    data.seekg(0, ios::beg);

    system("cls");
    cout << "--------------------------------\tSEARCH ON THE BASIS OF STATE\t--------------------------------\n\n\n";
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        data.read((char *)&s, sizeof(s));
        if (strcmp(s.state, input) == 0)
        {
            cout << "STUDENT'S ROLL NO.: " << s.rollno << endl
                 << "NAME              : " << s.student_name << endl
                 << "FATHER'S NAME     : " << s.father_name << endl
                 << "MOTHER'S NAME     : " << s.mother_name << endl
                 << "YEAR              : " << s.year << endl
                 << "SEMESTER          : " << s.semester << endl
                 << "BRANCH            : ";
            if (s.branch == 1)
            {
                cout << "Civil";
            }
            if (s.branch == 2)
            {
                cout << "Computer Science";
            }
            if (s.branch == 3)
            {
                cout << "Electronics and Communication";
            }
            if (s.branch == 4)
            {
                cout << "Mechanical";
            }

            cout << endl;
            cout << "ADDRESS           : " << s.h_no << ", " << s.s_name << endl
                 << "CITY              : " << s.city << endl
                 << "STATE             : " << s.state << endl
                 << "COUNTRY           : " << s.country << endl;
            cout << "\n\n";
            count++;
        }
    }
    if (count == 0)
    {
        cout << "\n------NO MATCHES FOUND------\n";
    }
}

void student_data::search_country()
{
    student_data s;
    cout << "ENTER COUNTRY'S NAME: ";
    char input[30];

    fflush(stdin);
    cin.getline(input, 30);

    fstream data("data.txt");
    data.seekg(0, ios::end);
    int n = data.tellg() / sizeof(s);
    data.seekg(0, ios::beg);

    system("cls");
    cout << "--------------------------------\tSEARCH ON THE BASIS OF COUNTRY\t--------------------------------\n\n\n";
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        data.read((char *)&s, sizeof(s));
        if (strcmp(s.country, input) == 0)
        {
            cout << "STUDENT'S ROLL NO.: " << s.rollno << endl
                 << "NAME              : " << s.student_name << endl
                 << "FATHER'S NAME     : " << s.father_name << endl
                 << "MOTHER'S NAME     : " << s.mother_name << endl
                 << "YEAR              : " << s.year << endl
                 << "SEMESTER          : " << s.semester << endl
                 << "BRANCH            : ";
            if (s.branch == 1)
            {
                cout << "Civil";
            }
            if (s.branch == 2)
            {
                cout << "Computer Science";
            }
            if (s.branch == 3)
            {
                cout << "Electronics and Communication";
            }
            if (s.branch == 4)
            {
                cout << "Mechanical";
            }

            cout << endl;
            cout << "ADDRESS           : " << s.h_no << ", " << s.s_name << endl
                 << "CITY              : " << s.city << endl
                 << "STATE             : " << s.state << endl
                 << "COUNTRY           : " << s.country << endl;
            cout << "\n\n";
            count++;
        }
    }
    if (count == 0)
    {
        cout << "\n------NO MATCHES FOUND------\n";
    }
}

void student_data::search_data()
{
    cout << "SEARCH ON THE BASIS OF:\n"
         << "ENTER 1: CITY\n"
         << "ENTER 2: STATE\n"
         << "ENTER 3: COUNTRY\n\n";

    int search;
    cin >> search;
    switch (search)
    {
    case 1:
        search_city();
        break;

    case 2:
        search_state();
        break;

    case 3:
        search_country();
        break;

    default:
        cout << "\n------ENTER A VALID OPTION------\n";
        break;
    }
}

void student_data::display_data()
{
    int roll_no;
    cout << "ENTER ROLL NO.: ";
    cin >> roll_no;
    student_data s;

    fstream data("data.txt");
    data.seekg(0, ios::end);
    int n = data.tellg() / sizeof(s);
    data.seekg(0, ios::beg);

    int count = 0;
    for (int i = 0; i < n; i++)
    {
        data.read((char *)&s, sizeof(s));
        if (s.rollno == roll_no)
        {
            system("cls");
            cout << "--------------------------------\tSTUDENT DATA\t--------------------------------\n\n\n";
            cout << "STUDENT'S ROLL NO.: " << s.rollno << endl
                 << "NAME              : " << s.student_name << endl
                 << "FATHER'S NAME     : " << s.father_name << endl
                 << "MOTHER'S NAME     : " << s.mother_name << endl
                 << "YEAR              : " << s.year << endl
                 << "SEMESTER          : " << s.semester << endl
                 << "BRANCH            : ";
            if (s.branch == 1)
            {
                cout << "Civil";
            }
            if (s.branch == 2)
            {
                cout << "Computer Science";
            }
            if (s.branch == 3)
            {
                cout << "Electronics and Communication";
            }
            if (s.branch == 4)
            {
                cout << "Mechanical";
            }

            cout << endl;
            cout << "ADDRESS           : " << s.h_no << ", " << s.s_name << endl
                 << "CITY              : " << s.city << endl
                 << "STATE             : " << s.state << endl
                 << "COUNTRY           : " << s.country << endl;

            count++;
        }
    }
    if (count == 0)
    {
        cout << "--------------------------------\tNO RECORD FOUND\t--------------------------------\n\n\n";
    }

    data.close();
}

void student_data::record()
{
    system("CLS");
    cout << "--------------------------------\tRECORDS AVAILABLE\t--------------------------------\n\n\n";

    student_data s;

    fstream data("data.txt");
    data.seekg(0, ios::end);
    int n = data.tellg() / sizeof(s);
    data.seekg(0, ios::beg);

    for (int i = 0; i < n; i++)
    {
        data.read((char *)&s, sizeof(s));
        cout << s.rollno << endl
             << endl;
    }
}

int main()
{
    student_data sd;
    while (1)
    {
        system("CLS");
        cout << "--------------------------------\tSTUDENT DATA MANAGER\t--------------------------------"
             << "\n\n\n"
             << "ENTER 1:  ADD A NEW RECORD\n\n"
             << "ENTER 2:  DELETE A RECORD\n\n"
             << "ENTER 3:  SEARCH THE RECORDS\n\n"
             << "ENTER 4:  DISPLAY A RECORD\n\n"
             << "ENTER 5:  RECORDS AVAILABLE\n\n"
             << "ENTER 6:  EXIT"
             << "\n\n\n";

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            sd.get_data();
            break;

        case 2:
            sd.delete_data();
            break;

        case 3:
            sd.search_data();
            break;

        case 4:
            sd.display_data();
            break;

        case 5:
            sd.record();
            break;

        case 6:
            exit(0);
            break;

        default:
            cout << "\n------ENTER A VALID OPTION------\n";
            break;
        }

        getch();
    }
    return 0;
}
