#include "Header.h"

Directory::Directory()
{
	_arrPerson = nullptr;
	_size = 0;
}

Directory::Directory(size_t size, Person& person)
{
	_size = size;
	_arrPerson = new Person[size];

	for (size_t i = 0; i < size; i++)
	{
		_arrPerson[i] = person;
	}
}

Directory::~Directory()
{
	Clear();
}

void Directory::Clear()
{
	if (_arrPerson != nullptr)
	{
		delete[] _arrPerson;
		_arrPerson = nullptr;
		_size = 0;
	}
}

void Directory::SetElement(size_t index, Person& person)
{
	if (index >= _size)
	{
		cout << "Error: index out of range" << endl;
		return;
	}

	_arrPerson[index] = person;
}

Person Directory::GetElement(size_t index) const
{
	if (index < _size)
	{
		return _arrPerson[index];
	}
	else
	{
		cout << "Error: index out of range" << endl;
		return _arrPerson[0];
	}
}

size_t Directory::GetSize() const
{
	return _size;
}

void Directory::AddElement(const Person& person)
{
	Person* tmp = new Person[_size + 1];

	if (tmp == nullptr)
	{
		cout << "Error: can`t allocate memory" << endl;
		return;
	}

	for (size_t i = 0; i < _size; i++)
	{
		tmp[i] = _arrPerson[i];
	}

	tmp[_size] = person;

	delete[] _arrPerson;
	_arrPerson = tmp;
	_size++;
}

void Directory::DeleteElement(int index, Person& person)
{
	if (_arrPerson == nullptr || _size == 0) return;
	//создаем новый массив указателей на один элемент меньше
	size_t size = _size - 1;
	Person* tmp = new Person[size];
	//копируем адреса из старого массива в новый, исключая адрес строки под номером index

	for (size_t i = 0; i < size; i++)
	{
		if (i < index)
		{
			tmp[i] = _arrPerson[i];
		}
		else if (i >= index)
		{
			tmp[i] = _arrPerson[i + 1];
		}
	}
	//удаляем старый массив указателей
	delete[] _arrPerson;

	//перенаправляем на новый
	_arrPerson = tmp;
	_size = size;
}

void Directory::PrintArrPerson()
{
	for (size_t i = 0; i < _size; i++)
	{
		cout << "\t" << _arrPerson[i].GetName() << " " << _arrPerson[i].GetPatronymic()
			<< " " << _arrPerson[i].GetSurname() << "\t" << _arrPerson[i].GetDataDay()
			<< ":" << _arrPerson[i].GetDataMonth() << ":" << _arrPerson[i].GetDataYear() << endl;
	}
	cout << endl;
}

void Directory::OpenReadFile()
{
	ifstream fin("Directory.bin", ios::in | ios::binary);

	if (!fin.is_open())
	{
		cerr << "file not opened" << endl;
		return;
	}
	else
	{
		fin.read((char*)_arrPerson, sizeof(int) * _size);
		//не понимаю как оно работает, ведь _size=0
	}

	fin.close();
}

void Directory::SaveFile()
{
	ofstream fout("Contacts.bin", ios::app | ios::binary);

	if (!fout.is_open())
	{
		cerr << "file not opened" << endl;
		return;
	}
	else
	{
		fout.write((char*)_arrPerson, sizeof(int) * _size);
	}

}
