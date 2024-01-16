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

vector<vector<bool>> intersectElectives(vector<teacher> teacherList,int credits){
    int intersectionCount[days][periods]={0};
    vector<vector<bool>> returnVal(6,vector<bool>(6,false));
    for(int i=0;i<teacherList.size();i++){
        for(int j=0;j<days;j++){
            for(int k=0;k<periods;k++){
                if(!teacherList[i].timeTable[j][k]){
                    intersectionCount[j][k]++;
                }
            }
        }
    }  
    for(int j=0;j<days;j++){
        for(int k=0;k<periods;k++){
            if(intersectionCount[j][k]>credits){
                 returnVal[j][k]=1;
                 break;
            }
        }
    } 
    return returnVal;
}

int main(){
    fstream bob;
    string inp;
     bob.open("datastorage/teacher.csv");
    teacher t1,t2,t3,t4,t5,t6;
    if(bob.is_open()){
        bob>>inp;
        t1.readData(inp);
        bob>>inp;
        t2.readData(inp);
        bob>>inp;
        t3.readData(inp);
        bob>>inp;
        t4.readData(inp);
        bob>>inp;
        t5.readData(inp);
        bob>>inp;
        t6.readData(inp);
    }
    else{
        cout<<"Teacher opening failed";
    }
    vector<teacher> boby={t1,t2,t3,t4};
    intersectElectives(boby,3);
    bob.close();
}