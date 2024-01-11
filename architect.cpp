#include<string>
#include<iostream>
#include"configs.cpp"
#include<vector>
#include"teacher.cpp"
#include"room.cpp"
#include"subject.cpp"
#include<bits/stdc++.h>
using namespace std;
/*
First step:
Configure teachers and subjects
1) use addElective(teacher for subject,subject) to assign teachers and subject . passed arguments are the teacher and subject objects that have been provided;
2)use addLabs(list of teachers who are can take the class,number of the teachers given in the prev parameter,lab subject). 
3)use block(day,period,message at blocked place,teacher at blocked place) to prevent the program from assigning class at that time also alters timetable name at t the places mentioned.
*/
class section{
    public:
        int name;
        vector<teacher> coreTeachers;
        vector<subject> coreSubjects;
        //vector<vector<teacher>> electiveTeachers;
        //vector<subject> electiveSubjects;
        vector<vector<teacher>> labTeachers;
        vector<subject> labSubjects;
        string timeTable[days][periods];
        string teacherTable[days][periods];
        void displayTimeTable();
        void displayTeacherTable(); 
        void addCore(teacher Teacher,subject Subject);
        //void addElective(teacher Teacher[],int numberOfTeachers,subject Subject);
        void addLab(teacher Teacher[],int noteachers,subject Subject);
        void block(int a,int b,string subject, string teacher);
        void makeTIMETABLE();
        section(){
            for(int i=0;i<days;i++){
                for(int j=0;j<periods;j++){
                    timeTable[i][j]="f";
                    teacherTable[i][j]="f";
                }
            }
        }
    private:
        int weight(int &dayfactor,int time,int bfactor){
            return (time*10+bfactor*5+dayfactor);
        }
};

void section::displayTimeTable(){
    cout<<"timeTable of class "<<name<<endl;
    for(int i=0;i<days;i++){
        for(int j=0;j<periods;j++){
            cout<<timeTable[i][j]<<"      ";
        }
        cout<<endl;
    }
}

void section::displayTeacherTable(){
    cout<<"timeTable of class "<<name<<endl;
    for(int i=0;i<days;i++){
        for(int j=0;j<periods;j++){
            cout<<teacherTable[i][j]<<"      ";
        }
        cout<<endl;
    }
}

void section::addCore(teacher Teacher,subject Subject){
    coreTeachers.push_back(Teacher);
    coreSubjects.push_back(Subject);
}

void section::addLab(teacher Teacher[],int noteachers,subject Subject){
    vector<teacher> a;
    for(int i=0;i<noteachers;i++){
        a.push_back(Teacher[i]);
    }
    labTeachers.push_back(a);
    labSubjects.push_back(Subject);
}

void section::block(int i,int j,string Teacher, string Subject){
    timeTable[i][j]=Teacher;
    teacherTable[i][j]=Subject;
}

void section::makeTIMETABLE(){
    int creditsl;
    bool collision=true;
    for(int i=0;i<coreTeachers.size();i++){
        creditsl=coreSubjects[i].credits;
        if(coreSubjects[i].hoursPerCredit==1){
            for(int j=0;j<days;j++){
                for(int k=0;k<periods;k++){
                    if(!coreTeachers[i].timeTable[j][k]){
                        if(timeTable[j][k]=="f"){
                            creditsl++;
                        }
                    }
                    if(creditsl>=coreSubjects[i].credits){
                        collision=false;
                    }
                }
            }
            if(!collision){
                vector<int> weights;
                int numberclasses=coreSubjects[i].credits;
                int dayfactor[days]={0};
                for(int j=0;j<days;j++){
                    for(int k=0;k<periods;k++){
                        if(!coreTeachers[i].timeTable[j][k]){
                            if(timeTable[j][k]=="f"){
                                weights.push_back(weight(dayfactor[j],k,coreSubjects[i].bFactor));
                            }
                        }
                    }
                }
                sort(weights.begin(),weights.end());
                for(int j=0;j<days;j++){
                    for(int k=0;k<periods;k++){
                        if(!coreTeachers[i].timeTable[j][k]){
                            if(timeTable[j][k]=="f"){
                                for(int a=0;a<coreSubjects[i].credits;a++){
                                    if(weight(dayfactor[j],k,coreSubjects[i].bFactor)==weights[a] && numberclasses){
                                        numberclasses--;
                                        dayfactor[j]+=coreSubjects[i].bFactor*5;
                                        timeTable[j][k]=coreSubjects[i].name;
                                        teacherTable[j][k]=coreTeachers[i].name;
                                        coreTeachers[i].timeTable[j][k]=1;
                                        coreTeachers[i].timeTableName[j][k]=name;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            } 
        }
        else if(coreSubjects[i].hoursPerCredit==2){
            for(int j=0;j<days;j++){
                for(int k=0;k<periods;k+=2){
                    if(!coreTeachers[i].timeTable[j][k] && !coreTeachers[i].timeTable[j][k+1]){
                        if(timeTable[j][k]=="f"){
                            creditsl++;
                        }
                    }
                    if(creditsl>=coreSubjects[i].credits){
                        collision=false;
                    }
                }
            }
            if(!collision){
                vector<int> weights;
                int numberclasses=coreSubjects[i].credits;
                cout<<"credits: "<<numberclasses;
                int dayfactor[days]={0};
                for(int j=0;j<days;j++){
                    for(int k=0;k<periods;k+=2){
                        if(!coreTeachers[i].timeTable[j][k] && !coreTeachers[i].timeTable[j][k+1]){
                            if(timeTable[j][k]=="f"){
                                weights.push_back(weight(dayfactor[j],k,coreSubjects[i].bFactor));
                            }
                        }
                    }
                }
                sort(weights.begin(),weights.end());
                for(int j=0;j<days;j++){
                    for(int k=0;k<periods;k+=2){
                        if(!coreTeachers[i].timeTable[j][k] && !coreTeachers[i].timeTable[j][k+1]){
                            if(timeTable[j][k]=="f"){
                                for(int a=0;a<coreSubjects[i].credits;a++){
                                    if(weight(dayfactor[j],k,coreSubjects[i].bFactor)==weights[a] && numberclasses){
                                        numberclasses--;
                                        dayfactor[j]+=coreSubjects[i].bFactor*5;
                                        timeTable[j][k]=coreSubjects[i].name;
                                        teacherTable[j][k]=coreTeachers[i].name;
                                        coreTeachers[i].timeTable[j][k]=1;
                                        coreTeachers[i].timeTableName[j][k]=name;
                                        timeTable[j][k+1]=coreSubjects[i].name;
                                        teacherTable[j][k+1]=coreTeachers[i].name;
                                        coreTeachers[i].timeTable[j][k+1]=1;
                                        coreTeachers[i].timeTableName[j][k+1]=name;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            } 
        }
    }
}

int main(){
    teacher T1;
    teacher T2;
    teacher sudeep;
    subject S1;
    subject S2,caeg;
    room R1;
    fstream src;
    string input;
    src.open("datastorage/teacher.csv");
    src>>input;
    T1.readData(input);
    src>>input;
    T2.readData(input);
    src>>input;
    sudeep.readData(input);
    src.close();
    src.open("datastorage/subject.csv");
    src>>input;
    S1.readData(input);
    src>>input;
    S2.readData(input);
    src>>input;
    caeg.readData(input);
    src.close();
    src.open("datastorage/room.csv");
    src>>input;
    R1.readData(input);
    src.close();
    section s;
    s.addCore(T2,S2);
    s.addCore(T1,S1);
    s.addCore(sudeep,caeg);
    s.makeTIMETABLE();
    s.displayTimeTable();
    s.displayTeacherTable();
    return 0;
}

