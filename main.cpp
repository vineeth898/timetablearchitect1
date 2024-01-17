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
    bob.open("datastorage/teacher.csv",fstream::app);
    teacher t;
    t.name="vabu";
}