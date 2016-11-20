#include "person.h"
#include <fstream>

int main()
{
	
	string Junk;
	ifstream fin;
	fin.open("titanic.csv", ios::in);

	//toss out the first line that says class gender age etc
	fin >> Junk;

	//get length for array
	int j =0;
	while (!fin.eof())
	{
		fin >> Junk;
		j++;
	}
	int length = j;
	
	
	//we would prefer to use this, but resorted to the 2 lines following it:
	//fin.seekg(0, fin.beg);
	fin.close();
	fin.open("titanic.csv", ios::in);

	//create array
	Person *passengers = new Person[length];
	
	// DEBUG
	//cout << length;
	//cin.get();
	
	//fill array
	for (int i = 0; i < length; i++)
	{
		fin >> passengers[i];
	}
	fin.close();

	/*
	DEBUG TEST FOR PASSENGER ARRAY
	for (int y = 0; y < length; y++)
	{
		cout << passengers[y].socialClass << " " << passengers[y].gender << " " << passengers[y].age << " " << passengers[y].survived << endl;
	}
	cin.get();
	*/
	return 0;
}