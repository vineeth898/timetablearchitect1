#include<iostream>
#include<fstream>
#include<string>
#include"configs.cpp"
#include"teacher.cpp"
//dependencies

using namespace std;
//namespace

int main(){
    fstream teacherfile;
    teacherfile.open("datastorage/subject.csv");
    string s;
    teacherfile>>s;
    teacher t;
    t.readData(s);
    cout<<"teacher name: "<<t.name<<endl;
    cout<<"teacher name: "<<t.branch<<endl;
    t.showTimeTable();
    teacherfile.close(); 
    int a;
    cin>>a;
}