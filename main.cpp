#include<fstream>
#include<iostream>
using namespace std;
void duplicateCSV(const string filepath,const string originalfile) {
		std::fstream outputFile;
		outputFile.open(filepath);
		if (!outputFile.is_open()) {
			ofstream outFile;
			outFile.open(filepath);
			std::fstream inputFile;
			inputFile.open(originalfile);
			string inp;
			if (inputFile.is_open())
			{
				while (!inputFile.eof()) {
					inputFile >> inp;
					outFile << inp <<endl;
				}
			}
			inputFile.close();
		}
		outputFile.close();
}
int main(){
    fstream file;
    duplicateCSV("bob.csv","datastorage/room.csv");
	cout<<"bob";
}