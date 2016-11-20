#ifndef person_h
#define person_h
#include <iostream>
#include <string>
#include "enum.h"
using namespace std;

struct Person {
	int socialClass;
	bool gender;
	bool age;
	bool survived;
	friend istream &operator>>(istream &input, Person &p)
	{
		string temp, tempClass, tempGender,tempAge,tempSurvived;
		input >> temp;
		int i = 0,attrib = 0;
		if (temp[0] != 0)
		{
			while (temp[i] != 0)
			{
				if (temp[i] == ',')
				{
					attrib++;
				}
				else if (attrib == 0)
				{
					tempClass += temp[i];
				}
				else if (attrib == 1)
				{
					tempGender += temp[i];
				}
				else if (attrib == 2)
				{
					tempAge += temp[i];
				}
				else if (attrib == 3)
				{
					tempSurvived += temp[i];
				}
				i++;
			}

			//delegate class enum
			if (tempClass == "Crew")
				p.socialClass = Crew;
			else if (tempClass == "3rd")
				p.socialClass = Third;
			else if (tempClass == "2nd")
				p.socialClass = Second;
			else if (tempClass == "1st")
				p.socialClass = First;
			else
				cout << "invalid social class data" << endl;

			//delegate age enum
			if (tempAge == "Adult")
				p.age = Adult;
			else if (tempAge == "Child")
				p.age = Child;
			else
				cout << "invalid age data" << endl;

			//delegate gender
			if (tempGender == "Male")
				p.gender = Male;
			else if (tempGender == "Female")
				p.gender = Female;
			else
				cout << "invalid gender data" << endl;

			//delegate surival
			if (tempSurvived == "No")
				p.survived = No;
			else if (tempSurvived == "Yes")
				p.survived = Yes;
			else
				cout << "invalid survival data" << endl;
		}

		return input;
	}
};
#endif /* person_h */