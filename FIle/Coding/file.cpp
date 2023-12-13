#include <fstream>
#include <iostream>
#include <limits>
#include <string>

using namespace std;


int main()
{
	ifstream inFile;
	string name, temp, temp2,temp3,temp4,temp5;
	int age,i = 0;

	inFile.open("file.txt");
		age++;
		while(getline(inFile,temp)){
			i++;
			inFile >> name;
			inFile >> age;
			inFile >> temp3;
			// getline(inFile,temp4);
			inFile >> temp5;
			cout << i << ".\n";
			cout << "temp : " << temp << endl;
			cout << "name : " << name << endl;
			cout << "age : " << age << endl;
			cout << "temp3 : " <<  temp3 << endl;
			cout << "temp4 : " <<  temp4 << endl;
			cout << "temp5 : " <<  temp5 << endl;
			inFile.ignore(numeric_limits<streamsize>::max(),'\n');
		}
		// temp4.append(temp);
			// getline(inFile,temp);

		// cout << temp << endl;
		cout << endl;
	// inFile >> name >> temp2;
	
	// cout << temp4 << endl;
	/*if(inFile.is_open()){
		while(getline(inFile,temp)){
			cout << temp << endl;
		}
	}*/
	/*getline(inFile, name); // use ' ' as separator, default is '\n' (newline). Now name is "John".
	name.append(1,' ');
	inFile >> temp >> temp2;
	// getline(inFile, temp, ' '); // Now temp is "Smith"
	// getline(inFile, temp2, ' ');
	// temp.append(1,' ');
	name += temp + temp2;
	inFile >> age; 

	cout << temp << endl;
	cout << temp2 << endl;
	cout << name << endl;
	cout << age << endl;  */

	inFile.close();    
	return 0;
}
