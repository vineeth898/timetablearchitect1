#include<iostream>
#include<fstream>
#include<string>
#include"configs.cpp"
#include"teacher.cpp"
#include"room.cpp"
#include"subject.cpp"
//dependencies

using namespace std;
//namespace

int main(){
    fstream teacherfile;
    teacherfile.open("datastorage/subject.csv");
    if(teacherfile.is_open()){
        subject first;
        string s;
        teacherfile>>s;
        first.readData(s);
        // cout<<"SUBNAME "<<first.name;
        // cout<<"ELECTIVE "<<first.elective;
        // cout<<"LAB "<<first.lab;
        // cout<<"CREDITS "<<first.credits;
        // cout<<"CREDITSPERHOUR "<<first.hourspercredit;
        // cout<<"BOB "<<first.bfactor;
         cout<<first.convertToString();
        // for(int i=0;i<first.noRooms;i++){
        //     cout<<first.rooms[i]<<endl;
        // }
    }
    teacherfile.close(); 
    int a;
    cin>>a;
}