#include<string>
#include<iostream>
#include"configs.cpp"
#include<vector>
#include"teacher.cpp"
#include"room.cpp"
#include"subject.cpp"
#include<bits/stdc++.h>
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
        std::vector<teacher> coreTeachers;
        std::vector<subject> coreSubjects;
        void addCore(teacher Teacher,subject Subject);


        //std::vector<std::vector<teacher>> electiveTeachers;
        //std::vector<subject> electiveSubjects;


        std::vector<std::vector<teacher>> labTeachers;
        std::vector<subject> labSubjects;
        std::vector<int> noOfLabs;
        void addLab(teacher Teacher[],int noteachers,subject Subject,int noLabs);

        std::vector<room> allRooms;
        std::vector<std::string> defaultRooms;
        std::string timeTable[days][periods];
        std::string teacherTable[days][periods];
        std::string roomTable[days][periods];

        void displayTimeTable();
        void displayTeacherTable();
        void displayClassTable();
        //void addElective(teacher Teacher[],int numberOfTeachers,subject Subject);
        void block(int a,int b,std::string subject, std::string teacher);
        void makeTIMETABLE();
        section(){
            for(int i=0;i<days;i++){
                for(int j=0;j<periods;j++){
                    timeTable[i][j]="f";
                    teacherTable[i][j]="f";
                    roomTable[i][j]="NA";
                }
            }
        }
    private:
        int weight(int &dayfactor,int time,int bfactor){
            return (time*10+bfactor*5+dayfactor);
        }
        room &returnRoom(std::string name){//edit actual room
            for(int i=0;i<allRooms.size();i++){
                if(allRooms[i].name==name){
                    return allRooms[i];
                }
            }
            return allRooms[allRooms.size()];//fix and make program throw error saying room not there
        }
};

void section::displayTimeTable(){
    for(int i=0;i<days;i++){
        for(int j=0;j<periods;j++){
            std::cout<<timeTable[i][j]<<"      ";
        }
        std::cout<<std::endl;
    }
}

void section::displayTeacherTable(){
    for(int i=0;i<days;i++){
        for(int j=0;j<periods;j++){
            std::cout<<teacherTable[i][j]<<"      ";
        }
        std::cout<<std::endl;
    }
}

void section::displayClassTable(){
    for(int i=0;i<days;i++){
        for(int j=0;j<periods;j++){
            std::cout<<roomTable[i][j]<<"      ";
        }
        std::cout<<std::endl;
    }
}

void section::addCore(teacher Teacher,subject Subject){
    coreTeachers.push_back(Teacher);
    coreSubjects.push_back(Subject);
}

void section::addLab(teacher Teacher[],int noteachers,subject Subject,int noLabs){
    std::vector<teacher> a;
    for(int i=0;i<noteachers;i++){
        a.push_back(Teacher[i]);
    }
    labTeachers.push_back(a);
    labSubjects.push_back(Subject);
    noOfLabs.push_back(noLabs);
}

void section::block(int i,int j,std::string Teacher, std::string Subject){
    timeTable[i][j]=Teacher;
    teacherTable[i][j]=Subject;
}

void section::makeTIMETABLE(){
    int creditsl;
    bool collision=true;
    collision=true;
    //now for 2 hours per credit.
    for(int i=0;i<labSubjects.size();i++){
        std::vector<std::vector<room>> candidates;
        std::vector<int> intersectionCount;
        int intersections;
        for(int j=0;j<labSubjects[i].noRooms;j++){
            for(int k=j+1;k<labSubjects[i].noRooms;k++){
                intersections=0;
                room curRoomA=returnRoom(labSubjects[i].rooms[j]);
                room curRoomB=returnRoom(labSubjects[i].rooms[k]);
                for(int a=0;a<days;a++){
                    for(int b=0;b<periods;b+=2){
                        if(!curRoomA.timeTable[a][b] && !curRoomA.timeTable[a][b+1] && !curRoomB.timeTable[a][b] && !curRoomB.timeTable[a][b+1] && timeTable[a][b]=="f" && timeTable[a][b+1]=="f"){
                            intersections++;
                        }
                    }
                }
                if(intersections>=labSubjects[i].credits){
                    std::vector<room> selection={curRoomA,curRoomB};
                    candidates.push_back(selection);
                    intersectionCount.push_back(intersections);
                }
            }
        }
        int highest=0,highestindex=0;
        for(int j=0;j<candidates.size();j++){
            if(intersectionCount[j]>highest){
                highestindex=j;
                highest=intersectionCount[j];
            }
        }
        room curRoomA=candidates[highestindex][0];
        room curRoomB=candidates[highestindex][1];
        bool intersectionTimes[days][periods]={};
        for(int a=0;a<days;a++){
            for(int b=0;b<periods;b+=2){
                intersectionTimes[a][b]=!curRoomA.timeTable[a][b] && !curRoomA.timeTable[a][b+1] && !curRoomB.timeTable[a][b] && !curRoomB.timeTable[a][b+1];
                intersectionTimes[a][b+1]=!curRoomA.timeTable[a][b] && !curRoomA.timeTable[a][b+1] && !curRoomB.timeTable[a][b] && !curRoomB.timeTable[a][b+1];
            }
        }
        int creditsForLab;
        std::vector<teacher> teacherListForLab=labTeachers[i];
        std::vector<std::vector<teacher>> comb;
        std::vector<teacher> selectedTeachers;
        int lowest=36;
        int intersectionTable[days][periods]={0};
        for (int a = 0; a < teacherListForLab.size() - 3; ++a) {
            for (int j = a + 1; j < teacherListForLab.size() - 2; ++j) {
                for (int m = j + 1; m < teacherListForLab.size() - 1; ++m) {
                    for (int n = m + 1; n < teacherListForLab.size(); ++n) {
                        creditsForLab=labSubjects[i].credits;
                        int tempTable[days][periods]={0};
                        for(int k=0;k<days;k++){
                            for(int l=0;l<periods;l++){
                                if(intersectionTimes[k][l]){
                                    if(!teacherListForLab[a].timeTable[k][l] && !teacherListForLab[a].timeTable[k][l+1] && !teacherListForLab[j].timeTable[k][l] && !teacherListForLab[j].timeTable[k][l+1] && !teacherListForLab[m].timeTable[k][l] && !teacherListForLab[m].timeTable[k][l+1]&& !teacherListForLab[n].timeTable[k][l] && !teacherListForLab[n].timeTable[k][l+1]){
                                        tempTable[k][l]=1;
                                        tempTable[k][l+1]=1;
                                        creditsForLab--;
                                    }
                                }
                            }
                        }
                        if(creditsForLab<=0){
                            std::vector<teacher> temp={teacherListForLab[a],teacherListForLab[j],teacherListForLab[m],teacherListForLab[n]};
                            comb.push_back(temp);
                            if(lowest>labSubjects[i].credits-creditsForLab){
                                lowest=labSubjects[i].credits-creditsForLab;
                                selectedTeachers=temp;
                                for(int k=0;k<days;k++){
                                    for(int l=0;l<periods;l++){
                                        intersectionTable[k][l]=tempTable[k][l];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        creditsForLab=labSubjects[i].credits;
        for(int k=0;k<days;k++){
            for(int l=0;l<periods;l++){
                if(intersectionTable[k][l]){
                    creditsForLab--;
                    break;
                }
            }
        }
        if(creditsForLab<=0)
            collision=false;
        creditsForLab=labSubjects[i].credits;
        if(!collision){
            for(int k=0;k<days;k++){
                for(int l=0;l<periods;l++){
                    if(intersectionTable[k][l] && creditsForLab){
                        timeTable[k][l]=labSubjects[i].name;
                        timeTable[k][l+1]=labSubjects[i].name;
                        teacherTable[k][l]=selectedTeachers[0].name+" , "+selectedTeachers[1].name+" , "+selectedTeachers[2].name+" , "+selectedTeachers[3].name;
                        teacherTable[k][l+1]=selectedTeachers[0].name+" , "+selectedTeachers[1].name+" , "+selectedTeachers[2].name+" , "+selectedTeachers[3].name;
                        roomTable[k][l]=candidates[highestindex][0].name+" , "+candidates[highestindex][1].name;
                        roomTable[k][l+1]=candidates[highestindex][0].name+" , "+candidates[highestindex][1].name;
                        creditsForLab--;
                        break;
                    }
                }
            }
        }
        else{
            std::cout<<"bob";
        }
    }
    //core subjects allocation
    for(int i=0;i<coreTeachers.size();i++){
        creditsl=coreSubjects[i].credits;
        std::vector<room> defRooms;
        room roomDefault;int highest=0;
        for(int j=0;j<defaultRooms.size();j++){
            defRooms.push_back(returnRoom(defaultRooms[j]));
            int free=0;
            for(int k=0;k<days;k++){
                for(int l=0;l<periods;l++){
                    if(!defRooms[j].timeTable[k][l]){
                        free++;
                    }
                }
            }
            if(free>highest){
                roomDefault=defRooms[j];
            }
        }
        for(int j=0;j<days;j++){
            for(int k=0;k<periods;k++){
                std::cout<<roomDefault.timeTable[j][k]<<" , ";
            }
            std::cout<<std::endl;
        }
        
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
                        break;
                    }
                }
            }
            if(!collision){
                std::vector<int> weights;
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
                                        if(coreSubjects[i].rooms[0]=="0"){
                                            if(!roomDefault.timeTable[j][k]){
                                                roomDefault.timeTable[j][k]=1;
                                                roomDefault.timeTableName[j][k]=name;
                                                roomTable[j][k]=roomDefault.name;
                                                std::cout<<std::endl<< roomDefault.name<<" "<<roomDefault.timeTable[j][k]<<" at "<<j<<"  "<<k<<" moving on";
                                            }
                                            else{
                                                for(int s=0;s<defRooms.size();s++){
                                                    if(!defRooms[s].timeTable[j][k]){
                                                        defRooms[s].timeTable[j][k]=1;
                                                        defRooms[s].timeTableName[j][k]=name;
                                                        roomTable[j][k]=defRooms[s].name;
                                                        goto a;
                                                    }
                                                }
                                                roomTable[j][k]="?????";
                                            }
                                        }
                                        a:
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
                        break;
                    }
                }
            }
            if(!collision){
                std::vector<int> weights;
                int numberclasses=coreSubjects[i].credits;
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


std::vector<std::vector<bool>> intersectElectives(std::vector<teacher> teacherList,int credits){
    int intersectionCount[days][periods]={0};
    std::vector<std::vector<bool>> returnVal(6,std::vector<bool>(6,false));
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
    std::fstream bob;
    bob.open("datastorage/room.csv");
    std::string inp;
    section cse;
    if(bob.is_open()){
        bob>>inp;
        room c1,c2,c3,c4;
        c1.readData(inp);
        bob>>inp;
        c2.readData(inp);
        bob>>inp;
        c3.readData(inp);
        bob>>inp;
        c4.readData(inp);
        cse.allRooms.push_back(c1);
        cse.allRooms.push_back(c2);
        cse.allRooms.push_back(c3);
        cse.allRooms.push_back(c4);
        cse.defaultRooms.push_back(c1.name);
        cse.defaultRooms.push_back(c2.name);
        cse.defaultRooms.push_back(c3.name);
        cse.defaultRooms.push_back(c4.name);
    }
    else{
        std::cout<<"room opening failsed";
    }
    bob.close();
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
        std::cout<<"Teaccher opening failsed";
    }
    teacher teachers[]={t1,t2,t3,t4,t5,t6};
    bob.close();
    bob.open("datastorage/subject.csv");
    if(bob.is_open()){
        bob>>inp;
        subject labone;
        labone.readData(inp);
        cse.addLab(teachers,6,labone,2);
        subject sub1,sub2;
        bob>>inp;
        sub1.readData(inp);
        bob>>inp;
        sub2.readData(inp);
        cse.addCore(t1,sub1);
        cse.addCore(t2,sub2);
        cse.makeTIMETABLE();
        cse.displayTimeTable();
        cse.displayTeacherTable();
        cse.displayClassTable();
    }
}