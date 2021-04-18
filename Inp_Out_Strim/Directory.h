#pragma once
#include "Header.h"

class Directory
{
private:
	Person* _arrPerson;
	size_t _size;

public:
	Directory();
	Directory(size_t size, Person& person);

	~Directory();
	void Clear();

	void SetElement(size_t index, Person& person);

	Person GetElement(size_t index) const;

	size_t GetSize() const;

	void AddElement(const Person& person);

	void DeleteElement(int index, Person& person);

	void PrintArrPerson();

	void OpenReadFile();

	void SaveFile();




};

