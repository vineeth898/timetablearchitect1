#include<fstream>
#include<iostream>
#include<string>
using namespace std;
std::string returnLine(std::string name, std::string path){
	fstream file(path);
	for(int i=0;i<1000;i++){
		std::string line;
		if(file.eof()){
			break;
		}
		file>>line;
		int j;
		for(j=0;j<name.size();j++){
			if(name[j]!=line[j]){
				goto a;
			}
		}
		return line;
		a:
		continue;
	}
	file.close();
	return "not found";
}
int main(){
	cout<<returnLine("chemlab","datastorage/subject.csv");
}