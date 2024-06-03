#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	
	ofstream outfile("name.txt", ios::binary);
	if (!outfile.is_open())
	{
		cout << "fail to open the file." << endl;
		return -1;
	}
	outfile << "what do now?" << endl;
	outfile << "plan A" << endl;
	outfile.close();

	string line;
	ifstream infile("name.txt", ios::binary);

	if (!infile.is_open())
	{
		cerr << "File open failed" << endl;
		return 1; // Return an error code instead of aborting
	}

	while (getline(infile, line)) {
		cout << line << endl;
	}

	infile.close();

	return 0;
}
