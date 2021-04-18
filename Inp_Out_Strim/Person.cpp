#include "Header.h"

Person::Person()
{
    _name[99]='X';//пишу [100] по€вл€етс€ сообщение о переполнении буфера?
    _patronymic[99]='X';
    _surname[99]='X';
    _message = 0;
    _data.SetDay(1);
    _data.SetMonth(1);
    _data.SetYear(2000);
}

Person::Person(const char* name, const char* surname,
    const int& y, const int& m, const int& d)
{
    _message = 0;
    SetName(name);
    SetSurname(surname);
    SetData(y,m,d);
}

Person::Person(const char* name, const char* patronymic,
    const char* surname, const int& y, const int& m, const int& d)
    :Person(name, surname, y, m, d)
{
    SetPatronymic(patronymic);
}

void Person::SetName(const char* name)
{
    if (name == nullptr || strlen(name) == 0)
    {
        _message = -1;
        return;
    }
    strcpy_s(_name, 100, name);
}

void Person::SetPatronymic(const char* patronymic)
{
    if (patronymic == nullptr || strlen(patronymic) == 0)
    {
        _message = -1;
        return;
    }
    strcpy_s(_patronymic, 100, patronymic);
}

void Person::SetSurname(const char* surname)
{
    if (surname == nullptr || strlen(surname) == 0)
    {
        _message = -1;
        return;
    }
    strcpy_s(_surname, 100, surname);
}

void Person::SetData(const int& y, const int& m, const int& d)
{
    _data.SetYear(y);
    _data.SetMonth(m);
    _data.SetDay(d);
}

const char* Person::GetName()
{
    return _name;
}

const char* Person::GetPatronymic() const
{
    return _patronymic;
}

const char* Person::GetSurname() const
{
    return _surname;
}

int Person::GetDataDay() const
{
    return _data.GetDay();
}

int Person::GetDataMonth() const
{
    return _data.GetMonth();
}

int Person::GetDataYear() const
{
    return _data.GetYear();
}

int Person::GetMessage() const
{
    return _message;
}

int Person::GetMessageDate() const
{
    return _data.GetMessage();
}

void Person::PrintPerson() const
{
    cout << "+-----------------------+--------------------+--------------------+---------+\n";
    cout << "| N | Surname           |Name                |Patronymic          | Birsday |\n";
    cout << "+-----------------------+--------------------+--------------------+---------+\n";
}

void DateInput(Person& p)
{
    int d = 1;
    int m = 1;
    int y = 2000;

    do
    {   
        system("cls");//очистка экрана

        if (p.GetMessageDate()==0)
        {
            cout << "\n\t”кажите дату рождени€:" << endl;
        }
        else
        {

            cout << "\n\t¬нимание!!! ќшибка!!!" << endl;
            cout << "\n\t”кажите дату рождени€:" << endl;
        }

        cout << "”кажите год\t\n";
        cout << "от 1900 до 2022\t:\t";
        cin >> y;
        while (cin.fail() || (y < 1000 || y > 2022))
        {
            cout << "¬нимание!! ";
            cout << "”кажите год\t\n";
            cout << "от 1900 до 2022\t:\t";

            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(); // и удал€ем значени€ предыдущего ввода из входного буфера
            cin >> y;
        }
        cout << "”кажите номер мес€ца\n";
        cout << "от 1 до 12\t:\t";
        cin.ignore();
        cin >> m;
        while (cin.fail() || (m < 1 || m > 12))
        {
            cout << "¬нимание!! ";
            cout << "”кажите номер мес€ца\n";
            cout << "от 1 до 12\t:\t";

            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(); // и удал€ем значени€ предыдущего ввода из входного буфера
            cin >> m;
        };

        int count = Dates::CountDayMonth(y, m);
        cout << "”кажите число в мес€це\n";
        cout << "от 1 до " << count << "\t:\t";
        cin.ignore();
        cin >> d;
        while (cin.fail() || (d < 1 || d > count))
        {
            cout << "¬нимание!! ";
            cout << "”кажите число в мес€це\n";
            cout << "от 1 до " << count << "\t:\t";

            cin.clear(); // то возвращаем cin в 'обычный' режим работы
            cin.ignore(); // и удал€ем значени€ предыдущего ввода из входного буфера
            cin >> d;
        }
        cin.ignore();
        p.SetData(y, m, d);
    } while (p.GetMessageDate()<0);
}

void NameInput(Person& p)
{
    char name[100];
    char patronymic[100];
    char surname[100];
    do
    {
        system("cls");//очистка экрана

        if (p.GetMessage() == 0)
        {
            cout << "\n\t¬ведите фамилию, им€, отчество:" << endl;
        }
        else
        {

            cout << "\n\t¬нимание!!! ќшибка!!!" << endl;
            cout << "\n\t¬ведите фамилию, им€, отчество:" << endl;
        }

    cout << "¬ведите им€\t:\t";
       cin >> name;
       while (cin.fail())
       {
           cout << "¬нимание!! ";
           cout << "¬ведите им€\t\n";

           cin.clear(); // то возвращаем cin в 'обычный' режим работы
           cin.ignore(); // и удал€ем значени€ предыдущего ввода из входного буфера
           cin >> name;
       }
       cin.ignore();
       cout << "¬ведите отчество:\t";
       cin >> patronymic;
       while (cin.fail())
       {
    	   cout << "¬нимание!! ";
    	   cout << "¬ведите отчество\t\n";

    	   cin.clear(); // то возвращаем cin в 'обычный' режим работы
    	   cin.ignore(); // и удал€ем значени€ предыдущего ввода из входного буфера
    	   cin >> patronymic;
       }
       cin.ignore();
       cout << "¬ведите фамилию\t:\t";
       cin >> surname;
       while (cin.fail())
       {
    	   cout << "¬нимание!! ";
    	   cout << "¬ведите фамилию\t\n";

    	   cin.clear(); // то возвращаем cin в 'обычный' режим работы
    	   cin.ignore(); // и удал€ем значени€ предыдущего ввода из входного буфера
    	   cin >> surname;
       }
       cin.ignore();
       p.SetName(name);
       p.SetPatronymic(patronymic);
       p.SetSurname(surname);

    } while (p.GetMessage() < 0);

}
