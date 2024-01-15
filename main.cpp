#include<iostream>
#include<fstream>
#include<string>
#include"configs.cpp"
#include"teacher.cpp"
#include"subject.cpp"
#include"room.cpp"
//dependencies

using namespace std;
//namespace

int main(){
    fstream bob;
    bob.open("datastorage/room.csv");
    string inp;
     bob>>inp;
     inp="";
     room c1,c2,c3;
     cout<<inp<<endl;
     bob.close();
     bob.open("datastorage/teacher.csv");
    bob>>inp;
    cout<<inp<<endl;
    teacher t1,t2,t3;
    t1.readData(inp);
    bob>>inp;
    t2.readData(inp);
    bob>>inp;
    t3.readData(inp);
    teacher teachers[3]={t1,t2,t3};
    cout<<"teacher list made";
    bob.close();
}