#include "fuzzifier.h"
#include <iostream>
#include <time.h>
#include <string.h>
#include <stdlib.h>
using namespace std;


category::category()
{

}

void category::setname(char *n)
{
	strcpy(name, n);
}

char * category::getname()
{
	return name;
}

void category::setval(float& h, float& m, float& l)
{
	this->lowval = l;
	this->midval = m;
	this->highval = h;
}

float category::getlowval()
{
	return lowval;
}

float category::getmidval()
{
	return midval;
}

float category::gethighval()
{
	return highval;
}

float category::getshare(const float& input)
{
	float output;

	float midlow, highmid;

	midlow = midval = lowval;
	highmid = highval - midval;

	if ((input <= lowval) || (input >= highval))
	{
		output = 0;
	}
	else
	{
		if (input > midval)
		{
			output = (highval - input) / highmid;
		} else {

			if (input == midval)
			{
				output = 1.0;
			}
			else {
				output = (input - lowval) / midlow;
			}
		}
	}

	return output;

}


int randomnum(int maxval)
{
	srand((unsigned)time(NULL));
	return rand() % maxval;
}

int main()
{

	int i = 0, j = 0, numcat = 0, randnum;
	float l, m, h, inval = 1.0;

	char input[30] = "                  ";
	category* ptr[10];
	float relprob[10];
	float total = 0, runtotal = 0;

	for (;;)
	{
		std::cout << "\nPlease type in a category name, e.g. Cool\n";
		std::cout << "Enter one word without spaces\n";
		std::cout << "When you are done, type 'done' ";

		ptr[i] = new category;
		std::cin >> input;

		if (( input[0] == 'd' && input[1] == 'o' && input[2] == 'n' && input[3] == 'e')) break;

		ptr[i]->setname(input);

		std::cout << "\nType in the lowval, midval and highval\n";
		std::cout << "for each category, seperated by spaces\n";
		std::cout << "eg. 1.0 3.0 5.0 :\n\n";

		std::cin >> l >> m >> h;

		ptr[i]->setval(h, m, l);

		i++;
	}

	numcat = i;

	cout << "\n\n";
	cout << "===================================\n";
	cout << "===Fuzzifier is ready for data ====\n";
	cout << "====================================\n";

	while (1)
	{
		cout << "\ninput a data value, type 0 to terminate\n";

		cin >> inval;

		if (inval == 0) break;

		total = 0;
		for (j = 0;j < numcat;j++)
		{
			relprob[j] = 100 * ptr[j]->getshare(inval);
			total += relprob[j];
		}

		if (total == 0)
		{
			cout << "data out of range\n";
			//exit(1);
		}

		randnum = randomnum((int)total);

		j = 0;
		runtotal = relprob[0];

		while ((runtotal < randnum) && (j < numcat))
		{
			j++;
			runtotal += relprob[j];
		}

		cout << "\nOutput fuzzy category is ==> " <<
			ptr[j]->getname() << "<== \n";
			
		cout << "category\t" << "membership\n";
		cout << "----------------\n";

		for (j = 0;j < numcat;j++)
		{
			cout << ptr[j]->getname() << "\t\t" << (relprob[j] / total) << "\n";
		}


	}

	cout << "\n\n All done. Have a fuzzy day!\n";
	
}
