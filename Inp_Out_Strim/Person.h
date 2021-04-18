#pragma once
#include "Header.h"

class Person
{
	char _name[100];//���
	char _patronymic[100];//��������
	char _surname[100];//�������
	int _message = 0;
	Dates _data;//���� ��������

public:

	Person();

	Person(const char* name, const char* surname, 
		const int& y, const int& m, const int& d);

	Person(const char* name, const char* patronymic,
		const char* surname, const int& y, const int& m, const int& d);


	void SetName(const char* name);

	void SetPatronymic(const char* patronymic);

	void SetSurname(const char* surname);

	void SetData(const int& y, const int& m, const int& d);

	const char* GetName();

	const char* GetPatronymic() const;

	const char* GetSurname() const;

	int GetDataDay() const;

	int GetDataMonth() const;

	int GetDataYear() const;

	int GetMessage() const;

	int GetMessageDate() const;

	void PrintPerson() const;

};
void DateInput(Person& p);

void NameInput(Person& p);

