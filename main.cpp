#include <iostream>
#include <fstream>
#include <string>
//#include <cstring>

int main()
	{
	const int numElements(10);
	std::string symbols[numElements];
	std::string values[numElements];


	//initialize each array using txt file
	std::ifstream inputfile;

	inputfile.open("symbols.txt");
	for(int i = 0; i < numElements; i++)
		inputfile >> symbols[i];
	inputfile.close();

	inputfile.open("values.txt");
	for(int i = 0; i <numElements; i++)
		inputfile >> values[i];
	inputfile.close();

	// print out arrays
	//cout << "Symbols: ";
	//for(int i = 0; i <numElements; i++)
	//	cout << symbols[i] << " ";

	//	cout << "\nValues: ";
	//for(int i = 0; i <numElements; i++)
	//	cout << values[i] << " ";
	//cout << endl;

	char name[100];//= "He2CO4";
	std::string templetter;
	std::string lowercaseletter;
	char spaceInArray;
	double coeff(1);
	double mass;
	double massF;
	double totalMass(0);

	std::cout << "Enter a chemical formula: ";
	std::cin >> name;
	std::cout << std::endl;

	for( int i = 0; i < strlen(name); i++ )
		{
		if ( name[i] >=65 && name[i] <= 90 )  //checks for a capital letter
			{
			templetter = name[i];
			if ( name[i+1] >=48 && name[i+1] <=57 ) // checks if next part of string is a number
				{
				coeff = name[i+1] - 48;
				i++;				// increases i over the number used here
				}
			if ( name[i+1] >= 97 && name[i+1] <= 122 )	// checks if next part of string is a lowercase letter
				{
				lowercaseletter = name[i+1];
				// concat templetter + lowercaseletter
				templetter += lowercaseletter;
				std::cout << "With lowerase: " << templetter << std::endl;
				i++;				// add 1 to count to skip over this overcase on next iteration
				if ( name[i+1] >=48 && name[i+1] <=57 )
					{
					coeff = name[i+1] - 48;
					i++;				// increases i over the number used here
					}
				}
			}
		for( int j = 0; j < numElements; j++ ) // finds the letter in the symbols array
			{
			if( symbols[j] == templetter )		// returns spot where found, correspondes to spot on value of that symbol
				spaceInArray = j;
			}
		mass = std::stod(values[spaceInArray].c_str());		// converts string to double
		std::cout << "Mass: " << mass << std::endl;
		std::cout << "Coeff: " << coeff << std::endl;			
		massF = (mass)*(coeff);
		std::cout << "Mass of " << templetter << " : " << massF << std::endl;
		totalMass += massF;
		coeff = 1;
		std::cout << std::endl;
		}
	std::cout << "Molar Mass: " << totalMass << std::endl;
	return 0;
	}