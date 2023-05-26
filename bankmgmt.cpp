// Author     :- Tirth jasoliya , Smit joshi
// Program    :-  Bank
// Problem    :-  Transfer Money from Account to Account , One Object to Another Object
// Start Date :-  14-May-2022
// End Date   :-

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <string>
#include <windows.h>
#include <fstream>

using namespace std;



class bank
{
private:
    string first, middle, last, usr_name;
    string acc_number;
    string OPASS;
    string OPIN;

    ofstream data;
    ifstream DATA;

    char acc_type;
    float s_balance = 0, c_balance = 0, loan_ammount = 0, FD = 0;
    short age, acc;

    void acc_num_generator()
    {
        srand(time(0));

        const string range = "0123456789";
        string number;
        char temp;

        for (int i = 0; i < 5; i++)
        {
            temp = range[rand() % range.length()];
            number.push_back(temp);
        }

        switch (acc_type)
        {
        case 'S':
            acc_number = "SICIC" + number;
            break;
        case 'C':
            acc_number = "CICIC" + number;
            break;
        }
        number = "";
    }
    void PASSWORd()
    {
        OPASS.clear();

        while (OPASS.length() <= 4)
        {
            cout << "\t\t\t\t| Enter NEW Password            :-  ";
            cin >> OPASS;
        }

        cout << "\t\t\t\t| Adding Password";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << "  Added...";
        cout << endl;
        Sleep(500);
    }
    void set_pin()
    {
        bool count;

        OPIN.clear();

        do
        {
            do
            {
                cout << "\t\t\t\t| Enter NEW Pin    (4 Digit)    :-  ";
                cin >> OPIN;

                if (OPIN.length() == 4)
                {
                    for (int i = 0; i < OPIN.length(); i++)
                    {
                        if (isdigit(OPIN[i]) == false)
                        {
                            count = false;
                            break;
                        }
                        else
                        {
                            count = true;
                        }
                    }
                }
                else
                {
                    break;
                }
            } while (count == false);

        } while (OPIN.length() != 4);

        cout << "\t\t\t\t| Adding PIN";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << "  Added...";
        cout << endl;
        Sleep(500);
    }
    void correction(string &cor)
    {
        int i, j;
        for (i = 0; i < cor.length(); i++)
        {
            if (i == 0)
            {
                cor[i] = toupper(cor[i]);
            }
            else
            {
                j = i;
                do
                {
                    if (cor[i - 1] == ' ')
                    {
                        cor[i] = toupper(cor[i]);
                    }
                    else
                    {
                        cor[i] = tolower(cor[i]);
                    }
                    j++;
                } while (cor[j - 1] == ' ');
            }
        }
    }

    static short account;

    char options(int &);

    void putdata();
    void withdraw();
    void deposit();
    void intrest(const int);
    void fix_deposit();
    void loan();
    void safe();
    void transfer();

public:
    void getdata();
    void enter();

    bank()
    {
        account++;
        acc = account;

        // data.open("Accounts.txt");
        // data << account;
        // data.close();
    }

    void file_creation()
    {
        data.open("Account_" + to_string(acc) + ".txt");

        // data << "First Name      :- " << first << endl;
        // data << "Middle Name     :- " << middle << endl;
        // data << "Last Name       :- " << last << endl;
        // data << "Age             :- " << age << endl;
        // data << "Password        :- " << OPASS << endl;
        // data << "Pin             :- " << OPIN << endl;
        // switch (acc_type)
        // {
        // case 'S':
        //     data << "Account Type    :- " << acc_type << "aving" << endl;
        //     data << "Account Number  :- " << acc_number << endl;
        //     data << "Account Balance :- " << s_balance << endl;
        //     if (loan_ammount > 0)
        //     {
        //         data << "Loan Ammount    :-" << loan_ammount << endl;
        //     }
        //     break;
        // case 'C':
        //     data << "Account Type    :- " << acc_type << "urrent" << endl;
        //     data << "Account Number  :- " << acc_number << endl;
        //     data << "Account Balance :- " << c_balance << endl;
        //     if (loan_ammount > 0)
        //     {
        //         data << "Loan Ammount    :-" << loan_ammount << endl;
        //     }

        data << first << endl;
        data << middle << endl;
        data << last << endl;
        data << age << endl;
        data << OPASS << endl;
        data << OPIN << endl;

        switch (acc_type)
        {
        case 'S':
            data << acc_type << endl;
            data << acc_number << endl;
            data << fixed << s_balance << endl;

            if (FD > 0)
            {
                data << FD << endl;
            }
            else
            {
                FD = 0;
                data << fixed << FD << endl;
            }
            if (loan_ammount > 0)
            {
                data << fixed << loan_ammount << endl;
            }
            else
            {
                loan_ammount = 0;
                data << fixed << loan_ammount << endl;
            }
            break;

        case 'C':
            data << acc_type << endl;
            data << acc_number << endl;
            data << fixed << c_balance << endl;

            if (loan_ammount > 0)
            {
                data << fixed << loan_ammount << endl;
            }
            else
            {
                loan_ammount = 0;
                data << fixed << loan_ammount << endl;
            }

            break;
        }

        data.close();
    }
    void file_creation(int acount)
    {
        data.open("Account_" + to_string(acount) + ".txt");

        data << first << endl;
        data << middle << endl;
        data << last << endl;
        data << age << endl;
        data << OPASS << endl;
        data << OPIN << endl;

        switch (acc_type)
        {
        case 'S':
            data << acc_type << endl;
            data << acc_number << endl;
            data << fixed << s_balance << endl;

            if (FD > 0)
            {
                data << FD << endl;
            }
            else
            {
                FD = 0;
                data << fixed << FD << endl;
            }
            if (loan_ammount > 0)
            {
                data << fixed << loan_ammount << endl;
            }
            else
            {
                loan_ammount = 0;
                data << fixed << loan_ammount << endl;
            }
            break;

        case 'C':
            data << acc_type << endl;
            data << acc_number << endl;
            data << c_balance << endl;

            if (loan_ammount > 0)
            {
                data << fixed << loan_ammount << endl;
            }
            else
            {
                loan_ammount = 0;
                data << fixed << loan_ammount << endl;
            }

            break;
        }

        data.close();
    }

    void file_open()
    {
        DATA.open("Account_" + to_string(acc) + ".txt");

        DATA >> first;
        DATA >> middle;
        DATA >> last;
        DATA >> age;
        DATA >> OPASS;
        DATA >> OPIN;
        DATA >> acc_type;

        switch (acc_type)
        {
        case 'S':
            DATA >> acc_number;
            DATA >> s_balance;
            DATA >> FD;
            DATA >> loan_ammount;

            break;

        case 'C':

            DATA >> acc_number;
            DATA >> c_balance;
            DATA >> loan_ammount;

            break;
        }

        DATA.close();
    }
    void file_open(int acount)
    {
        DATA.open("Account_" + to_string(acount) + ".txt");

        DATA >> first;
        DATA >> middle;
        DATA >> last;
        DATA >> age;
        DATA >> OPASS;
        DATA >> OPIN;
        DATA >> acc_type;

        switch (acc_type)
        {
        case 'S':
            DATA >> acc_number;
            DATA >> s_balance;
            DATA >> FD;
            DATA >> loan_ammount;

            break;

        case 'C':

            DATA >> acc_number;
            DATA >> c_balance;
            DATA >> loan_ammount;

            break;
        }

        DATA.close();
    }

    void passbook_c(float amount)
    {
        data.open("Passbook_" + to_string(acc) + ".txt");
    }
    void passbook_o(float amount)
    {
        DATA.open("Passbook_" + to_string(acc) + ".txt");
    }
};

void bank ::getdata()
{
    cout << endl;

    cout << "\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t| Enter Details of Account :- " << acc << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;

    cout << "\n\t\t\t\t| Enter First Name              :-  ";
    cin >> first;
    cout << "\n\t\t\t\t| Enter Middle Name             :-  ";
    cin >> middle;
    cout << "\n\t\t\t\t| Enter Last Name               :-  ";
    cin >> last;

    correction(first);
    correction(middle);
    correction(last);

    cout << endl;
    do
    {
        cout << "\t\t\t\t| Enter Your Age                :-  ";
        cin >> age;
    } while (age <= 0);

    cout << endl;
    PASSWORd();
    cout << endl;
    set_pin();
    cout << endl;

    do
    {
        cout << "\t\t\t\t| Enter Account Type [S/C]      :-  ";
        fflush(stdin);
        acc_type = _getch();
        acc_type = toupper(acc_type);
        _putch(acc_type);
        cout << endl;

        switch (acc_type)
        {
        case 'S':
            acc_num_generator();
            cout << "\n\t\t\t\t| Account Number                :-  ";
            Sleep(1000);
            cout << acc_number << endl;

            cout << "\n\t\t\t\t| Enter Saving Account Balance  :-  ";
            cin >> s_balance;

            break;

        case 'C':
            acc_num_generator();
            cout << "\n\t\t\t\t| Account Number                :-  ";
            Sleep(1000);
            cout << acc_number << endl;

            cout << "\n\t\t\t\t| Enter Current Account Balance :-  ";
            cin >> c_balance;

            break;
        }
    } while (acc_type != 'C' && acc_type != 'S');

    cout << "\t\t\t\t-----------------------------------------------" << endl;

    Sleep(1000);
    cout << "\n\t\t\t\t| Creating Account " << acc;
    Sleep(500);
    cout << " .";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << " Created Successfully |";
    Sleep(1000);

    data.open("Accounts.txt", ios::trunc);
    data << acc;
    data.close();
}
void bank ::putdata()
{
    system("cls");

    cout << endl;

    cout << "\t\t\t\t-----------------------------------------------" << endl;

    cout << "\t\t\t\tAccount :- " << acc << endl;

    cout << endl;

    char temp = middle[0];
    usr_name = first + " " + temp + "." + " " + last;

    cout << "\t\t\t\tUser Name                :-  " << setw(18) << usr_name << endl;
    cout << "\t\t\t\tAge                      :-  " << setw(18) << age << endl;
    cout << "\t\t\t\tAccount Number           :-  " << setw(18) << acc_number << endl;

    switch (acc_type)
    {
    case 'S':
        cout << "\t\t\t\tAccount Type             :-   " << setw(18) << " Saving " << endl;
        cout << "\t\t\t\tSaving Account Balance   :-  " << setw(18) << s_balance << endl;
        cout << "\t\t\t\tFixed Deposit Balance    :-  " << setw(18) << FD << endl;
        break;

    case 'C':
        cout << "\t\t\t\tAccount Type             :-   " << setw(18) << " Current " << endl;
        cout << "\t\t\t\tCurrent Account Balance  :-  " << setw(18) << c_balance << endl;
        break;
    }
    cout << "\t\t\t\tPayeble Loan Ammount     :-  " << setw(18) << loan_ammount << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;
}

void bank ::withdraw()
{
    cout << endl;

    cout << "\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t|                  Withdraw                   |" << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;

    float withdraw;

    cout << "\t\t\t\t| Enter Ammount :- ";
    cin >> withdraw;

    if (withdraw > 0)
    {
        switch (acc_type)
        {
        case 'S':
            if (s_balance >= withdraw)
            {
                s_balance -= withdraw;
                cout << "\t\t\t\t| Withdrawing";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << "." << endl;
                Sleep(500);
                cout << "\t\t\t\t| Money Withdrawed Successfully...";
            }
            else
            {
                Sleep(1500);
                cout << "\t\t\t\t| Insufficient Balance";
            }
            break;

        case 'C':
            if (c_balance >= withdraw)
            {
                c_balance -= withdraw;
                cout << "\t\t\t\t| Withdrawing";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << "." << endl;
                Sleep(500);
                cout << "\t\t\t\t| Money Withdrawed Successfully...";
            }
            else
            {
                Sleep(1500);
                cout << "\t\t\t\t| Insufficient Balance";
            }
            break;
        }
    }
    else
    {
        cout << "\t\t\t\t| Enter Valid Amount...";
    }
    cout << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;
    Sleep(1500);
}
void bank ::deposit()
{
    cout << endl;

    cout << "\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t|                   Deposit                   |" << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;

    float deposit;
    cout << "\t\t\t\t| Enter Ammount :- ";
    cin >> deposit;

    if (deposit > 0)
    {
        switch (acc_type)
        {
        case 'S':
            s_balance += deposit;
            cout << "\t\t\t\t| Depositing";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << "." << endl;
            Sleep(500);
            cout << "\t\t\t\t| Money Deposited Successfully...";
            break;

        case 'C':
            c_balance += deposit;
            cout << "\t\t\t\t| Depositing";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << "." << endl;
            Sleep(500);
            cout << "\t\t\t\t| Money Deposited Successfully...";
            break;
        }
    }
    else
    {
        cout << "\t\t\t\t| Enter Valid Amount...";
    }
    cout << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;
    Sleep(1500);
}

void bank ::intrest(const int rate = 3)
{
    cout << endl;

    cout << "\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t|                   Intrest                   |" << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;

    int m;
    float intrest;

    cout << "\t\t\t\t| Enter Months :- ";
    cin >> m;

    intrest = s_balance * (m / 12.0) * (rate / 100.0);

    cout << "\n\t\t\t\t| Your Intrest after " << m << " Months :- " << intrest;
    cout << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;
    Sleep(2000);
}

void bank ::fix_deposit()
{
    cout << endl;

    cout << "\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t|                 Fix Deposit                 |" << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;

    cout << "\t\t\t\t| Press 1 for New Fix Deposit" << endl;
    cout << "\t\t\t\t| Press 2 for Exit Fix Deposit" << endl;
    cout << endl
         << "\t\t\t\t| Enter Your Choice :- ";

    char ch;
    fflush(stdin);
    ch = _getch();
    ch = toupper(ch);
    _putch(ch);
    Sleep(600);
    cout << endl;

    switch (ch)
    {
    case '1':
        if (acc_type == 'S')
        {
            int month, ch;
            float ammount;

            cout << "\n\t\t\t\t1. Intrest on 12 Month to 24 Month :: 5% " << endl;
            cout << "\t\t\t\t2. Intrest on 24 Month to 36 Month :: 6% " << endl;
            cout << "\t\t\t\t3. Intrest on 36 Month to 48 Month :: 7% " << endl;
            cout << "\n\t\t\t\tNote Senior Cityzen get extra 0.5% Intrest  " << endl;

            cout << "\n\t\t\t\tEnter Ammount          :-    ";
            cin >> ammount;

            if (ammount > 0)
            {
                if (ammount <= s_balance)
                {

                    cout << "\t\t\t\tEnter Month            :-    ";
                    cin >> month;

                    if (month >= 12 && month < 24)
                        ch = 1;
                    else if (month >= 24 && month < 36)
                        ch = 2;
                    else
                        ch = 3;

                    FD += ammount;
                    s_balance -= ammount;

                    switch (ch)
                    {
                    case 1:

                        if (age > 60)
                        {
                            FD += ammount * (month / 12.0) * (5.5 / 100.0);
                            cout << "\n\t\t\t\tAmmount After " << month << " Month's :- " << FD;
                        }
                        else
                        {
                            FD += FD * (month / 12.0) * (5 / 100.0);
                            cout << "\n\t\t\t\tAmmount After " << month << " Month's :- " << FD;
                        }
                        break;

                    case 2:

                        if (age > 60)
                        {
                            FD += ammount * (month / 12.0) * (6.5 / 100.0);
                            cout << "\n\t\t\t\tAmmount After " << month << " Month's :- " << FD;
                        }
                        else
                        {
                            FD += ammount * (month / 12.0) * (6 / 100.0);
                            cout << "\n\t\t\t\tAmmount After " << month << " Month's :- " << FD;
                        }
                        break;

                    case 3:

                        if (age > 60)
                        {
                            FD += ammount * (month / 12.0) * (7.5 / 100.0);
                            cout << "\n\t\t\t\tAmmount After " << month << " Month's :- " << FD;
                        }
                        else
                        {
                            FD += ammount * (month / 12.0) * (7 / 100.0);
                            cout << "\n\t\t\t\tAmmount After " << month << " Month's :- " << FD;
                        }
                        break;

                    default:
                        cout << endl
                             << "\t\t\t\t|             -: Invalid Choice :-            |";
                    }
                }
                else
                {
                    cout << "\n\t\t\t\tInsufficient Balance";
                }
            }
            else
            {
                cout << "\t\t\t\t| Enter Valid Amount...";
            }
        }
        else
        {
            cout << "\n\t\t\t\t Current Account Can't Get Fixed Deposit";
        }
        break;

    case '2':
        s_balance += FD;
        FD -= FD;
        cout << "\n\t\t\t\t| FD Closed";
        Sleep(500);
        cout << " .";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";

        cout << endl;
        cout << "\t\t\t\t| Account Balance     :- " << s_balance << endl;
        cout << "\t\t\t\t| Fix Deposit Ammount :- " << FD;

        break;

    default:
        cout << endl
             << "\t\t\t\t|             -: Invalid Choice :-            |";
    }

    cout << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;
    Sleep(2000);
}
void bank ::loan()
{
    cout << endl;

    cout << "\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t|                     Loan                    |" << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;

    cout << "\t\t\t\t| Press 1 For Take Loan...                     " << endl;
    cout << "\t\t\t\t| Press 2 For Pay  Loan...                     " << endl;
    cout << endl
         << "\t\t\t\t| Enter Your Choice :- ";

    char op;
    fflush(stdin);
    op = _getch();
    op = toupper(op);
    _putch(op);
    Sleep(600);

    cout << endl
         << endl;

    switch (op)
    {
    case '1':
        char ch;
        int month;
        float loan;

        cout << "\t\t\t\t| Press 1 Personal Loan  (12%)" << endl;
        cout << "\t\t\t\t| Press 2 Home     Loan  (08%)" << endl;
        cout << "\t\t\t\t| Press 3 Car      Loan  (06%)" << endl;
        cout << endl
             << "\t\t\t\t| Enter Your Choice :- ";
        fflush(stdin);
        ch = _getch();
        ch = toupper(ch);
        _putch(ch);
        Sleep(600);
        cout << endl
             << endl;

        cout << "\t\t\t\t| Enter Ammount :- ";
        cin >> loan;
        loan_ammount += loan;
        cout << "\t\t\t\t| Enter Month's :- ";
        cin >> month;

        if (loan > 0)
        {
            switch (ch)
            {
            case '1':
                loan_ammount += loan * (month / 12.0) * (12.0 / 100.0);
                break;

            case '2':
                loan_ammount += loan * (month / 12.0) * (8.0 / 100.0);
                break;

            case '3':
                loan_ammount += loan * (month / 12.0) * (6.0 / 100.0);
                break;

            default:
                cout << endl
                     << "\t\t\t\t|             -: Invalid Choice :-            |";
            }
        }
        else
        {
            cout << "\t\t\t\t| Enter Valid Amount...";
        }

        cout << "\t\t\t\t| Loan Successfull";
        Sleep(500);
        cout << " .";
        Sleep(500);
        cout << ".";
        Sleep(500);
        cout << ".";

        break;

    case '2':
        switch (acc_type)
        {
        case 'S':
            if (loan_ammount <= s_balance)
            {
                s_balance -= loan_ammount;
                loan_ammount -= loan_ammount;

                cout << "\t\t\t\t| Loan Payed Successfull";
                Sleep(500);
                cout << " .";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
            }
            else
            {
                Sleep(1500);
                cout << "\t\t\t\t| Insufficient Balance";
            }
            break;

        case 'C':
            if (loan_ammount <= c_balance)
            {
                c_balance -= loan_ammount;
                loan_ammount -= loan_ammount;

                cout << "\t\t\t\t| Loan Payed Successfull";
                Sleep(500);
                cout << " .";
                Sleep(500);
                cout << ".";
                Sleep(500);
                cout << ".";
            }
            else
            {
                Sleep(1500);
                cout << "\t\t\t\t| Insufficient Balance";
            }
            break;
        }
        break;

    default:
        cout << endl
             << "\t\t\t\t|             -: Invalid Choice :-            |";
    }
    cout << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;
    Sleep(2000);
}

void bank ::transfer()
{
    cout << endl;

    cout << "\t\t\t\t-----------------------------------------------" << endl;
    cout << "\t\t\t\t|                   Transfer                  |" << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;

    float ammount;
    short account;

    cout << "\t\t\t\t| Enter Account :- ";
    cin >> account;
    cout << "\t\t\t\t| Enter Ammount :- ";
    cin >> ammount;

    bank temp;

    switch (acc_type)
    {
    case 'S':

        if (ammount <= s_balance)
        {
            temp.file_open(account);

            s_balance -= ammount;

            switch (temp.acc_type)
            {
            case 'S':
                temp.s_balance += ammount;
                break;

            case 'C':
                temp.c_balance += ammount;
                break;
            }

            temp.file_creation(account);

            cout << "\t\t\t\t| Transfering";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << "." << endl;
            Sleep(500);
            cout << "\t\t\t\t| Money Transfered Successfully...";
        }
        else
        {
            cout << "\t\t\t\t| Not Enough Balance in Account";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
        }
        break;

    case 'C':

        if (ammount <= c_balance)
        {
            temp.file_open(account);

            c_balance -= ammount;

            switch (temp.acc_type)
            {
            case 'S':
                temp.s_balance += ammount;
                break;

            case 'C':
                temp.c_balance += ammount;
                break;
            }

            temp.file_creation(account);

            cout << "\t\t\t\t| Transfering";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << "." << endl;
            Sleep(500);
            cout << "\t\t\t\t| Money Transfered Successfully...";
        }
        else
        {
            cout << "\t\t\t\t| Not Enough Balance in Account";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
        }
        break;
    }
    cout << endl;
    cout << "\t\t\t\t-----------------------------------------------" << endl;
    Sleep(1500);
}

void bank ::enter()
{
    string TPIN;
    string TPASS;
    int attempt = 0;
    char ch1;

    do
    {
        cout << endl;
        TPIN.clear();
        cout << "\t\t\t\t| Enter     Pin    (4 Digit)      :-    ";
        char p;
        p = _getch();
        while (p != 13)
        {
            TPIN.push_back(p);
            cout << '*';
            p = _getch();
        }

        if (TPIN == OPIN)
        {
            switch (acc_type)
            {
            case 'S':
                do
                {
                    putdata();

                    ch1 = options(attempt);

                    putdata();
                } while (ch1 == 'Y');
                break;

            case 'C':
                do
                {
                    putdata();

                    ch1 = options(attempt);

                    putdata();
                } while (ch1 == 'Y');
                break;
            }
        }
        else
        {
            cout << "\n\n\t\t\t\t         X-X-X-XWrong PIN X-X-X-X" << endl;
            attempt++;
            cout << "\t\t\t\t        " << attempt << " Wrong Attempt [Max :- 3] " << endl;
            Sleep(1000);

            if (attempt == 3)
            {
                cout << endl;
                TPASS.clear();
                cout << "\t\t\t\t| Enter your Password           :-    ";
                char p;
                p = _getch();
                while (p != 13)
                {
                    TPASS.push_back(p);
                    cout << '*';
                    p = _getch();
                }
                if (TPASS == OPASS)
                {
                    switch (acc_type)
                    {
                    case 'S':
                        do
                        {
                            putdata();

                            ch1 = options(attempt);

                            putdata();
                        } while (ch1 == 'Y');
                        break;

                    case 'C':
                        do
                        {
                            putdata();

                            ch1 = options(attempt);

                            putdata();
                        } while (ch1 == 'Y');
                        break;
                    }
                }
                else
                {
                    cout << "\n\n\t\t\t\t     X-X-X-XWrong PASSWORD X-X-X-X" << endl;
                    Sleep(1000);
                }
            }
        }
    } while (attempt < 3);
}
char bank ::options(int &a)
{
    char ch;

    switch (acc_type)
    {
    case 'S':

        cout << endl
             << "\t\t\t\t       -: Press 1 for Withdraw Money  :- " << endl;
        cout << "\t\t\t\t       -: Press 2 for Deposit  Money  :- " << endl;
        cout << "\t\t\t\t       -: Press 3 for Change Password :- " << endl;
        cout << "\t\t\t\t       -: Press 4 for Change PIN      :- " << endl;
        cout << "\t\t\t\t       -: Press 5 for Transfer Money  :- " << endl;
        cout << "\t\t\t\t       -: Press 6 for Fix_Deposit...  :- " << endl;
        cout << "\t\t\t\t       -: Press 7 for About Loan...   :- " << endl;
        cout << "\t\t\t\t       -: Press 8 to View an Intrest  :- " << endl;
        cout << "\t\t\t\t       -: Press 9 to Log Out          :- " << endl;
        cout << endl
             << "\t\t\t\t\t      Enter Your Choice :- ";

        fflush(stdin);
        ch = _getch();
        ch = toupper(ch);
        _putch(ch);
        Sleep(1000);
        cout << endl;

        switch (ch)
        {
        case '1':
            withdraw();
            file_creation();
            return ('Y');
            break;

        case '2':
            deposit();
            file_creation();
            return ('Y');
            break;

        case '3':
            cout << endl;
            cout << "\t\t\t\t-----------------------------------------------" << endl;
            PASSWORd();
            cout << "\t\t\t\t-----------------------------------------------" << endl;
            file_creation();
            Sleep(1000);
            return ('Y');
            break;

        case '4':
            cout << endl;
            cout << "\t\t\t\t-----------------------------------------------" << endl;
            set_pin();
            cout << "\t\t\t\t-----------------------------------------------" << endl;
            file_creation();
            Sleep(1000);
            return ('Y');
            break;

        case '5':
            transfer();
            file_creation();
            return ('Y');
            break;

        case '6':
            fix_deposit();
            file_creation();
            return ('Y');
            break;

        case '7':
            loan();
            file_creation();
            return ('Y');
            break;

        case '8':
            intrest(5);
            file_creation();
            return ('Y');
            break;

        case '9':
            a = 3;
            return ('N');
            break;

        default:
            cout << endl
                 << "\t\t\t\t|             -: Invalid Choice :-            |";
            Sleep(2000);
            return ('Y');
        }
        break;

    case 'C':

        cout << endl
             << "\t\t\t\t       -: Press 1 for Withdraw Money  :- " << endl;
        cout << "\t\t\t\t       -: Press 2 for Deposit  Money  :- " << endl;
        cout << "\t\t\t\t       -: Press 3 for Change Password :- " << endl;
        cout << "\t\t\t\t       -: Press 4 for Change PIN      :- " << endl;
        cout << "\t\t\t\t       -: Press 5 for Transfer Money  :- " << endl;
        cout << "\t\t\t\t       -: Press 6 for About Loan...   :- " << endl;
        cout << "\t\t\t\t       -: Press 7 to Log Out          :- " << endl;
        cout << endl
             << "\t\t\t\t\t      Enter Your Choice :- ";

        fflush(stdin);
        ch = _getch();
        ch = toupper(ch);
        _putch(ch);
        Sleep(1000);
        cout << endl;

        switch (ch)
        {
        case '1':
            withdraw();
            file_creation();
            return ('Y');
            break;

        case '2':
            deposit();
            file_creation();
            return ('Y');
            break;

        case '3':
            cout << endl;
            cout << "\t\t\t\t-----------------------------------------------" << endl;
            PASSWORd();
            cout << "\t\t\t\t-----------------------------------------------" << endl;
            file_creation();
            Sleep(1000);
            return ('Y');
            break;

        case '4':
            cout << endl;
            cout << "\t\t\t\t-----------------------------------------------" << endl;
            set_pin();
            cout << "\t\t\t\t-----------------------------------------------" << endl;
            file_creation();
            Sleep(1000);
            return ('Y');
            break;

        case '5':
            transfer();
            file_creation();
            return ('Y');
            break;

        case '6':
            loan();
            file_creation();
            return ('Y');
            break;

        case '7':
            a = 3;
            return ('N');
            break;

        default:
            cout << endl
                 << "\t\t\t\t|             -: Invalid Choice :-            |";
            Sleep(2000);
            return ('Y');
        }
        break;
    }

    return ('\0');
}

short bank ::account;

int main()
{
    system("cls");

    cout << fixed << setprecision(2);

    int ch, op, n, m, choice;
    char ch1, ch2;

    bank *b;

    ifstream open_file("Accounts.txt");

    if (open_file.fail())
    {
        ofstream create_file("Accounts.txt");
        m = 0;
        create_file << m;
        // open_file >> m;
    }
    else
    {
        open_file >> m;
    }

    cout << "\n\t\t\t\tChecking Data";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << ".";
    Sleep(500);
    cout << "." << endl;
    Sleep(500);
    system("cls");

    cout << "\n\t\t\t\t" << m << " Old Account Data Found ";

    cout << endl;
    cout << "\n\t\t\t\tPress 1 For Create new Account Data ";
    cout << "\n\t\t\t\tPress 2 For  Use  Old  Account Data ";
    cout << endl;
    cout << "\n\t\t\t\tIn which Data you want to open  :- ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");

        cout << "\n\t\t\t\tHow many new Account's want to Create :- ";
        cin >> n;

        if (m > 0)
        {
            b = new bank[n + m];

            // for (int i = 0; i < m; i++)
            // {
            //     b[i].file_open();
            // }

            for (int i = m; i < m + n; i++)
            {
                system("cls");
                b[i].getdata();
                b[i].file_creation();
            }
        }
        else
        {
            b = new bank[n];
            for (int i = 0; i < n; i++)
            {
                system("cls");
                b[i].getdata();
                b[i].file_creation();
            }
        }

        break;

    case 2:
        if (m > 0)
        {
            system("cls");

            b = new bank[m];

            // for (int i = 0; i < m; i++)
            // {
            //     b[i].file_open();
            // }

            do
            {
                for (int i = 0; i < m; i++)
                {
                    b[i].file_open();
                }

                system("cls");

                cout << "\n\t\t\t\tTotal Bank Account's              :-    " << m << endl;

                cout << "\n\t\t\t\tEnter Account you want to Operate :-    ";
                cin >> op;
                cout << endl;

                if (op < m + 1 && op > 0)
                {
                    b[op - 1].enter();
                }
                else
                {
                    cout << "\n\t\t\t\tNo Bank Account Detected " << endl;
                    Sleep(1500);
                }

                system("cls");

                do
                {
                    cout << "\n\t\t\t\tChange Operating Account ? [Y/N]  :-    ";
                    fflush(stdin);
                    ch2 = _getch();
                    ch2 = toupper(ch2);
                    _putch(ch2);
                    Sleep(1000);
                } while (ch2 != 'Y' && ch2 != 'N');

            } while (ch2 == 'Y');
        }
        else
        {
            system("cls");
            cout << "\n\t\t\t\tNo Old Account Data Found";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << ".";
            Sleep(500);
            cout << "." << endl;
            Sleep(2000);
        }
        break;
    }
    return 0;
}
