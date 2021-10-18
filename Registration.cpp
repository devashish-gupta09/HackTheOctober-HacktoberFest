#include <iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
#include <fstream>
class vaccine_dose_data
{
private:
    char candidate_name[30]; //30
    long int aadhar_num;     //4
    int birth_date;
    int birth_month;
    int birth_year;
    int today_date;
    int today_month;
    int today_year;
    int candidate_age;
    int anti_body_entry; //6
    int vaccine_which_entry;
    int vaccine_which_entry_2;

public:
    void get_details()
    {
        cout << "\nENTER NAME(as written on aadhar card) : ";
        fflush(stdin);
        cin.get(candidate_name, 30);
        aadhar_num = 0;
        cout << "ENTER AADHAR CARD NUMBER : ";
        cin >> aadhar_num;
        cout << "\nENTER TODAY'S DATE : \n";
        cout << "DAY : ";
        cin >> today_date;
        cout << "MONTH : ";
        cin >> today_month;
        cout << "YEAR : ";
        cin >> today_year;
        cout << "\nENTER BIRTH DETAILS : \n\n";
        cout << "DAY : ";
        cin >> birth_date;
        cout << "MONTH : ";
        cin >> birth_month;
        cout << "YEAR : ";
        cin >> birth_year;
    }
    int age_verify()
    {
        if ((today_year - birth_year) == 18)
        {
            if (today_month > birth_month)
            {
                if (today_date > birth_date)
                {
                    return 1;
                }
                else
                {
                    return 2;
                }
            }
            else
            {
                return 2;
            }
        }
        if (today_year - birth_year > 18)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    void show_details()
    {
        cout << "NAME : " << candidate_name << endl;
        cout << "AADHAR NUMBER : " << aadhar_num << endl;
        cout << "BIRTH DATE : " << birth_date << "/" << birth_month << "/" << birth_year << endl;
        cout << "ANTI BODY STATUS : ";
        if (anti_body_entry == 1)
        {
            cout << "YES\n";
        }
        if (anti_body_entry == 2)
        {
            cout << "NO\n";
        }
        if (vaccine_which_entry == 1)
        {
            cout << "VACCINE DOSE 1 TYPE : COVAXIN\n";
        }
        if (vaccine_which_entry == 2)
        {
            cout << "VACCINE DOSE 1 TYPE : COVISHIELD\n";
        }
        if (vaccine_which_entry == 3)
        {
            cout << "VACCINE DOSE 1 TYPE : SPUTNIK\n";
        }
    }
    void anti_body()
    {
        cout << "\nHISTORY OF COVID : \n\n";
        cout << "ENTER 1 : IF YOU WERE CORONA POSITIVE\nENTER 2 : IF YOU WERE NOT CORONA POSITIVE\n\n";
        cin >> anti_body_entry;
    }
    void which_vaccine()
    {
        cout << "\nENTER 1 : COVAXIN\nENTER 2 : COVISHIELD\nENTER 3 : SPUTNIK\n\n";
        cin >> vaccine_which_entry;
        cout << "\n\nCONGRATULATIONS YOU HAVE BEEN VACCINATED WITH 1st DOSE\n\n";
    }
    int check_sputnik()
    {
        if (vaccine_which_entry == 3)
        {
            cout << "\n\nSPUTNIK only requires one dose\n\n";
            return 3;
        }
        else
            return 1;
    }
    void which_vaccine_2()
    {
        cout << "\nCHOOSE VACCINE FOR 2nd DOSE : \n\n";
        cout << "\n\nENTER 1 : COVAXIN ";
        if (vaccine_which_entry == 1)
        {
            cout << "(1st dose)\n";
        }
        else
        {
            cout << "\n";
        }
        cout << "ENTER 2 : COVISHIELD";
        if (vaccine_which_entry == 2)
        {
            cout << "(1st dose)\n";
        }
        else
        {
            cout << "\n";
        }
        cin >> vaccine_which_entry_2;
    }
    void final_message()
    {
        cout << "NAME : " << candidate_name << endl;
        cout << "AADHAR NUMBER : " << aadhar_num << endl;
        cout << "BIRTH DATE : " << birth_date << "/" << birth_month << "/" << birth_year << endl;
        cout << "ANTI BODY STATUS : ";
        if (anti_body_entry == 1)
        {
            cout << "YES\n";
        }
        if (anti_body_entry == 2)
        {
            cout << "NO\n";
        }
        if (vaccine_which_entry == 1)
        {
            cout << "VACCINE DOSE 1 TYPE : COVAXIN\n";
        }
        if (vaccine_which_entry == 2)
        {
            cout << "VACCINE DOSE 1 TYPE : COVISHIELD\n";
        }
        if (vaccine_which_entry == 3)
        {
            cout << "VACCINE DOSE TYPE : SPUTNIK\n";
        }
        if (vaccine_which_entry_2 == 1)
        {
            cout << "VACCINE DOSE 2 TYPE : COVAXIN\n";
        }
        if (vaccine_which_entry_2 == 2)
        {
            cout << "VACCINE DOSE 2 TYPE : COVISHIELD\n";
        }
    }
    int search_candidate(long int class_aadhar_num)
    {
        if (class_aadhar_num == aadhar_num)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
    int search_candidate_if_first_dose(vaccine_dose_data obz)
    {
        if (obz.aadhar_num == aadhar_num)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }
    int if_both_vaccine_done()
    {
        if (vaccine_which_entry_2 == 1 || vaccine_which_entry_2 == 2)
        {
            return 4;
        }
        else
            return 1;
    }
    int aadhar_dose_1()
    {
        if (aadhar_num != 0)
        {
            return 1;
        }
        else
        {
            return 2;
        }
    }
};
int main()
{
    int what_about;
    vaccine_dose_data ob1;
    vaccine_dose_data ob2[100];
    int vaccine_num;
    int aadhar_dose_d;
    int check_d;
    static int number_of_first;
    long int main_aadhar_num;
    while (1)
    {
        fstream ob("myfile_2.txt", ios::in | ios::out | ios::ate);
        cout << "\n\nENTER 1 : FIRST DOSE VACCINE\nENTER 2 : SECOND DOSE VACCINE\nENTER 3 : DISPLAY CERTIFICATE\nENTER 4 : EXIT\n\n";
        fflush(stdin);
        what_about = 0;
        cin >> vaccine_num;
        switch (vaccine_num)
        {
        case 1:
        {
            int first_vaccine_d;
            int age_verify_d;
            int closure;
            int d_break;
            ob1.get_details();
            age_verify_d = ob1.age_verify();
            if (age_verify_d == 2)
            {
                cout << "\n\n--VACCINATION DENIED AS THE CANDIDATE IS UNDER 18--\n\n";
                ob.close();
                break;
            }

            int end = ob.tellg();
            int size = sizeof(ob1);
            int qty = end / size;
            ob.seekg(0);
            for (int i = 0; i < qty; i++)
            {
                ob.read((char *)&ob2[i], sizeof(ob2[i]));
                first_vaccine_d = ob2[i].search_candidate_if_first_dose(ob1);
                if (first_vaccine_d == 2)
                {
                    cout << "\n\n--CANDIDATE HAS ALREADY BEEN VACCINATED WITH DOSE - 1--\n\n";
                    d_break = 3;
                    ob.close();
                    break;
                }
            }
            if (d_break != 3)
            {
                ob1.anti_body();
                ob1.which_vaccine();
                ob.write((char *)&ob1, sizeof(ob1));
                ob.close();
                break;
            }
            ob.close();
            break;
        }
        case 2:
        {
            int entry_3;
            cout << "ENTER AADHAR CARD NUMBER : ";
            cin >> main_aadhar_num;
            int j_final;
            int end = ob.tellg();
            int size = sizeof(ob1);
            int qty = end / size;
            ob.seekg(0);
            for (int j = 0; j < qty; j++)
            {
                ob.read((char *)&ob2[j], sizeof(ob2[j]));
                int return_d = ob2[j].search_candidate(main_aadhar_num);
                if (return_d == 1)
                {
                    int if_both_d = ob2[j].if_both_vaccine_done();
                    if (if_both_d == 4)
                    {
                        what_about = 10;
                        cout << "BOTH VACCINATIONS HAVE BEEN DONE\n";
                        ob.close();
                        break;
                        break;
                    }
                    break;
                }
            }
            if (what_about == 10)
            {
                ob.close();
                break;
            }
            ob.seekg(0);
            for (int j = 0; j < qty; j++)
            {
                ob.read((char *)&ob2[j], sizeof(ob2[j]));
                int return_d = ob2[j].search_candidate(main_aadhar_num);
                if (return_d == 1)
                {
                    j_final = j;
                    cout << "\n\nSHOWING DETAILS : \n\n";
                    ob2[j].show_details();
                    check_d = ob2[j].check_sputnik();
                    break;
                }
            }
            if (check_d == 3)
            {
                ob.close();
                break;
            }
            ob2[j_final].which_vaccine_2();
            ob.seekp(size * (j_final));
            ob.write((char *)&ob2[j_final], sizeof(ob2[j_final]));
            cout << "YOUR VACCINATION IS COMPLETE \n\nCERTIFICATE : \n\n";
            ob2[j_final].final_message();
            ob.close();
            break;
        }

        case 3:
        {
            int count = 0;
            cout << "ENTER AADHAR CARD NUMBER : ";
            cin >> main_aadhar_num;
            int end = ob.tellg();
            int size = sizeof(ob1);
            int qty = end / size;
            ob.seekg(0);
            for (int j = 0; j < qty; j++)
            {
                ob.read((char *)&ob2[j], sizeof(ob2[j]));
                int return_d = ob2[j].search_candidate(main_aadhar_num);
                if (return_d == 1)
                {
                    cout << "\n\nSHOWING CERTIFICATE : \n\n";
                    ob2[j].final_message();
                    break;
                }
                count++;
            }
            if (count == qty)
            {
                cout << "\n\nCANDIDATE HAS NOT GOT BOTH DOSE-1 AND DOSE-2\n\n";
            }
            ob.close();
            break;
        }

        case 4:
            ob.close();
            exit(0);

        default:
            cout << "\n\n---WRONG CHOICE---\n\n";
        }
    }
    return 0;
}
