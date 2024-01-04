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
    teacherfile.open("teacher.csv");
    if(teacherfile.is_open()){
        teacher list[250];
        string input;
        int i=0;
        while(!teacherfile.eof()){
            teacherfile>>input;
            list[i].readData(input);
            i++;
        }
        teacherfile<<list[i].convertString();
        teacherfile>>input;
    }
    teacherfile.close(); 
    int a;
    cin>>a;
}