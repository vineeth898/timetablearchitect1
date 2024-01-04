#include<iostream>
#include<fstream>
#include<string>
#include"configs.cpp"
#include"teacher.cpp"
#include"room.cpp"
//dependencies

using namespace std;
//namespace

int main(){
    fstream teacherfile;
    teacherfile.open("room.csv");
    if(teacherfile.is_open()){
        room first;
        string s;
        teacherfile>>s;
        first.readData(s);
        for(int i=0;i<days;i++){
            for(int j=0;j<periods;j++){
                cout<<first.timeTable[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<endl<<first.convertToString();
    }
    teacherfile.close(); 
    int a;
    cin>>a;
}