#include<fstream>
#include<algorithm>
#include<list>
#include<string>
#include<iostream>
#include<vector>
#define days 6
#define periods 6

class subject{
    public:
        std::string name;
        std::string elective;
        bool lab;
        int credits,hoursPerCredit;
        unsigned short int bFactor;
        std::string *rooms;
        unsigned short int noRooms;
        bool readData(std::string inp);
        std::string convertToString();
        subject(){
            credits=0;
            hoursPerCredit=0;
            bFactor=0;
        };
};
bool subject::readData(std::string inp){
    enum format{
        namen,
        electiven,
        labn,
        creditsn,
        hoursPerCreditn,
        bFactorn,
        roomsn,
    };
    int commaCount=0;
    try{
        for(int i=0;i<inp.size();i++){
            if(inp[i]==','){
                commaCount++;
                continue;
            }
            switch(commaCount){
                case namen:
                    name.push_back(inp[i]);
                    break;
                case electiven:
                    elective.push_back(inp[i]);
                    break;
                case labn:
                    lab=inp[i]-'0';
                    break;
                case creditsn:
                    credits=credits*10+inp[i]-'0';
                    break;
                case hoursPerCreditn:
                    hoursPerCredit=hoursPerCredit*10+inp[i]-'0';
                    break;
                case bFactorn:
                    bFactor=bFactor*10+inp[i]-'0';
                    break;
                case roomsn:
                    int commaCount=0;
                    i++;
                    std::vector<std::string> temp;
                    while(true){
                        if(inp[i]==']'){
                            noRooms=commaCount+1;
                             rooms=new std::string[noRooms];
                             for(commaCount;commaCount>=0;commaCount--){
                                 rooms[commaCount]=temp[commaCount];
                             }
                            break;
                        }
                        else if(inp[i]==','){
                            commaCount++;
                        }
                        else{
                            if(temp.size()>commaCount){
                                temp[commaCount].push_back(inp[i]);
                            }
                           else{
                            temp.push_back("");
                            temp[commaCount].push_back(inp[i]);
                           }
                        }
                        i++;
                    }

            }
        }
     }
     catch(...){
         return 0;
     }
}

class room{
    public:
        std::string name;
        int capacity=0;
        bool labOrNot=0;
        std::string building; 
        bool timeTable[days][periods];//when room is free. 0 for free 1 for occupiued.
        int timeTableName[days][periods];//what class the rooms is holding. changes done by program, not taken from user.
        bool readData(std::string inp);
        void showTimeTable();
        std::string convertToString();
        room(){
            for(int i=0;i<days;i++){
                for(int j=0;j<periods;j++){
                    timeTableName[i][j]=0;
                }
            }
        }//initialise all classes to zero.
};
void room::showTimeTable(){
    // for(int i=0;i<days;i++){
    //     for(int j=0;j<periods;j++){
    //         std::cout<<timeTable[i][j]<<" , ";
    //     }
    //     std::cout<<std::endl;
    // }
}
bool room::readData(std::string inp){
    enum format{
        namen,
        capacityn,
        labOrNotn,
        buildingn,
        timeTablen
    };
    int commacount=0;
    try{
        for(int i=0;i<inp.size();i++){
            if(inp[i]==','){
                commacount++;
                continue;
            }
            switch(commacount){
                case namen:
                    name.push_back(inp[i]);
                    break;//read name
                case capacityn:
                    capacity=capacity*10+inp[i]-'0';
                    break;//read branch
                case labOrNotn:
                    labOrNot=inp[i]-'0';
                    break;//read workhours
                case buildingn:
                    building.push_back(inp[i]);
                    break;//read name
                case timeTablen:
                    commacount=0;
                    int strptr=i;
                    while(inp[strptr]){
                        if(inp[strptr]==','){
                            commacount++;
                        }
                        else if(!(commacount%2)){
                            timeTable[commacount/12][(commacount%12)/2]=inp[strptr]-'0';
                        }
                        else{
                            timeTableName[commacount/12][(commacount%12)/2]=timeTableName[commacount/12][(commacount%12)/2]*10+inp[strptr]-'0';
                        }
                        strptr++;
                    }   
                    goto a;
                    break;
            }
        }
    }
    catch(...){
        return 0;
    }
    a:
    return 1;
}
std::string room::convertToString(){
    std::string output;
    output+=name+","+std::to_string(capacity)+","+std::to_string(labOrNot)+","+building;
    for(int i=0;i<days;i++){
        for(int j=0;j<days;j++){
            output+=","+std::to_string(timeTable[i][j])+","+std::to_string(timeTableName[i][j]);
        }
    }
    return output;
}
std::string subject::convertToString(){
    std::string out;
    out=name+",";
    out+=elective+",";
    out+=std::to_string(lab)+",";
    out+=std::to_string(credits)+",";
    out+=std::to_string(hoursPerCredit)+",";
    out+=std::to_string(bFactor)+",[";
    for(int i=0;i<noRooms-1;i++){
        out+=rooms[i]+",";
    }
    out+=rooms[noRooms-1]+"]";
    return out;
}

class teacher{
    public:
        std::string name;//name of teacher
        std::string branch;//branch of teacher
        //unsigned int workHours=0; //how many hours the teacher would work
        bool timeTable[days][periods];//when teacher is free. 1 for free 0 for occupiued.
        unsigned int timeTableName[days][periods];//what teacher is teaching when occupied. changes done by program, not taken from user.
        bool readData(std::string inp);//function which converts std::string input from teacherdata to the objects data
        std::string convertToString();//reverse of above
        void showTimeTable();
        teacher(){
            for(int i=0;i<days;i++){
                for(int j=0;j<periods;j++){
                    timeTableName[i][j]=0;
                }
            }
        }
        //initialise all classes to zero.
        
        // teacher(const teacher &bob){
        //     name=bob.name;
        //     branch=bob.branch;
        //     for(int i=0;i<days;i++){
        //         for(int j=0;j<periods;j++){
        //             timeTable[i][j]=bob.timeTable[i][j];
        //             timeTableName[i][j]=bob.timeTableName[i][j];
        //         }
        //     }
        // }
};
bool teacher::readData(std::string inp){
    enum format{
        namen,
        branchn,
        //workHoursn,
        timeTablen
    };//Used for switch statements. each field corresponds to its location in the std::string
    int commacount=0;//numebr of commas encountered
    try{
        for(int i=0;i<inp.size();i++){
            if(inp[i]==','){
                commacount++;
                continue;
            }//equivalent to next column
            switch(commacount){
                case namen:
                    name.push_back(inp[i]);
                    break;//read name
                case branchn:
                    branch.push_back(inp[i]);
                    break;//read branch
                /*case workHoursn:
                    workHours=workHours*10+inp[i]-'0';
                    break;//read workhours
                    */
                case timeTablen:
                    commacount=0;
                    int strptr=i;
                    while(inp[strptr]){
                        if(inp[strptr]==','){
                            commacount++;
                        }
                        else if(!(commacount%2)){
                            timeTable[commacount/12][(commacount%12)/2]=inp[strptr]-'0';
                        }
                        else{
                            timeTableName[commacount/12][(commacount%12)/2]=timeTableName[commacount/12][(commacount%12)/2]*10+inp[strptr]-'0';
                        }
                        strptr++;
                    }   
                    goto a;
                    break;
            }
        }
    }
    catch(...){
        return 0;
    }
    a:
    return 1;
}
std::string teacher::convertToString(){
    std::string output;
    output=name;
    output.push_back(',');
    output+=branch;
    //output.push_back(',');
    //output+=std::to_string(workHours);
    for(int i=0;i<days;i++){
        for(int j=0;j<days;j++){
            output+=","+std::to_string(timeTable[i][j])+","+std::to_string(timeTableName[i][j]);
        }
    }
    return output;
}
void teacher::showTimeTable(){
    // for(int i=0;i<days;i++){
    //     for(int j=0;j<periods;j++){
    //         std::cout<<timeTable[i][j]<<"      ";
    //     }
    //     std::cout<<std::endl;
    // }
}
class section{
    public:
        int name;
        std::vector<teacher> allTeachers;
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
        void storeTimeTable();
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
        int dayfactor[days]={0};
    private:
        bool error_=false;
        int weight(int &dayfactor,int time,int bfactor){
            return (time*10+bfactor*5+dayfactor);
        }
        room &returnRoom(std::string name){//edit actual room
            error_=false;
            for(int i=0;i<allRooms.size();i++){
                if(allRooms[i].name==name){
                    return allRooms[i];
                }
            }
            error_=true;
            return allRooms[allRooms.size()-1];//fix and make program throw error saying room not there
        }
        teacher &returnTeacher(std::string inp){//return teacher function 
            error_=false;
            for(int i=0;i<allTeachers.size();i++){
                if(allTeachers[i].name==inp){
                    return allTeachers[i];
                }
            }
            error_=true;
            return allTeachers[allTeachers.size()-1];
        }
        subject &returnSubject(std::string inp){
            error_=false;
            for(int i=0;i<coreTeachers.size();i++){
                if(coreSubjects[i].name==inp){
                    return coreSubjects[i];
                }
            }
            error_=true;
            return coreSubjects[coreSubjects.size()-1];
        }
};

void section::displayTimeTable(){
    for(int i=0;i<days;i++){
        for(int j=0;j<periods;j++){
            std::cout<<timeTable[i][j]<<"      ";
        }
        std::cout<<"   bfactor: "<<dayfactor[i]<<std::endl;
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
        bool flag=1;
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

void section::storeTimeTable(){
    std::fstream storage;
    std::string bob="storage/"+std::to_string(name)+".csv";
    storage.open(bob,std::ios::app);
    storage<<"NEW TIME TABLE:   \n";
    if(storage.is_open()){
        for(int i=0;i<days;i++){
            bob="";
            for(int j=0;j<periods-1;j++){
                bob+=timeTable[i][j]+",";
            }
            bob+=timeTable[i][periods-1]+"\n";
            storage<<bob;
        }
        storage.close();
    }
    
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
                                    if(!returnTeacher(teacherListForLab[a].name).timeTable[k][l] && !returnTeacher(teacherListForLab[a].name).timeTable[k][l+1] && !returnTeacher(teacherListForLab[j].name).timeTable[k][l] && !returnTeacher(teacherListForLab[j].name).timeTable[k][l+1] && !returnTeacher(teacherListForLab[m].name).timeTable[k][l] && !returnTeacher(teacherListForLab[m].name).timeTable[k][l+1]&& !returnTeacher(teacherListForLab[n].name).timeTable[k][l] && !returnTeacher(teacherListForLab[n].name).timeTable[k][l+1]){
                                        tempTable[k][l]=1;
                                        tempTable[k][l+1]=1;
                                        creditsForLab--;
                                    }
                                }
                            }
                        }
                        if(creditsForLab<=0){
                            std::vector<teacher> temp={returnTeacher(teacherListForLab[a].name),returnTeacher(teacherListForLab[j].name),returnTeacher(teacherListForLab[m].name),returnTeacher(teacherListForLab[n].name)};
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
        //make collisiosn handelling
        //update teacher timetable
        if(!collision){
            for(int k=0;k<days;k++){
                for(int l=0;l<periods;l++){
                    if(intersectionTable[k][l] && creditsForLab){
                        dayfactor[k]+=labSubjects[i].bFactor*5;
                        timeTable[k][l]=labSubjects[i].name;
                        timeTable[k][l+1]=labSubjects[i].name;
                        teacherTable[k][l]=selectedTeachers[0].name+" , "+selectedTeachers[1].name+" , "+selectedTeachers[2].name+" , "+selectedTeachers[3].name;
                        teacherTable[k][l+1]=selectedTeachers[0].name+" , "+selectedTeachers[1].name+" , "+selectedTeachers[2].name+" , "+selectedTeachers[3].name;
                        roomTable[k][l]=candidates[highestindex][0].name+" , "+candidates[highestindex][1].name;
                        roomTable[k][l+1]=candidates[highestindex][0].name+" , "+candidates[highestindex][1].name;
                        room &tempUpdate=returnRoom(candidates[highestindex][0].name);
                        tempUpdate.timeTable[k][l]=1;
                        tempUpdate.timeTable[k][l+1]=1;
                        tempUpdate.timeTableName[k][l]=name;
                        tempUpdate.timeTableName[k][l+1]=name;
                        room &tempUpdateA=returnRoom(candidates[highestindex][1].name);
                        tempUpdateA.timeTable[k][l]=1;
                        tempUpdateA.timeTable[k][l+1]=1;
                        tempUpdateA.timeTableName[k][l]=name;
                        tempUpdateA.timeTableName[k][l+1]=name;
                        for(int p=0;p<4;p++){
                            returnTeacher(selectedTeachers[p].name).timeTable[k][l]=1;
                            returnTeacher(selectedTeachers[p].name).timeTable[k][l+1]=1;
                            returnTeacher(selectedTeachers[p].name).timeTableName[k][l]=1;
                            returnTeacher(selectedTeachers[p].name).timeTableName[k][l+1]=1;
                            
                        }
                        creditsForLab--;
                        break;
                    }
                }
            }
        }
        else{
            //std::cout<<"bob";
        }
    }
    //core subjects allocation
    for(int i=0;i<coreTeachers.size();i++){
       // std::cout<<"\niterating through: "<<coreSubjects[i].name;
        creditsl=0;
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
        if(coreSubjects[i].hoursPerCredit==1){
            for(int j=0;j<days;j++){
                for(int k=0;k<periods;k++){
                    if(!returnTeacher(coreTeachers[i].name).timeTable[j][k]){
                        if(timeTable[j][k]=="f"){
                            creditsl++;
                        }
                    }
                }
            }
            if(creditsl>=coreSubjects[i].credits){
                collision=false;
            }
            else{
                collision=true;
            }
            if(!collision){
                //std::cout<<"\nno collision for: "<<coreSubjects[i].name;
                int currentAssigned=0;
                repeat:
                std::vector<int> weights;
                int numberclasses=coreSubjects[i].credits-currentAssigned;
                for(int j=0;j<days;j++){
                    int discouragementFactor=1;
                    for(int k=0;k<periods;k++){
                        if(timeTable[j][k]==coreSubjects[i].name){
                            discouragementFactor=200;
                        }
                        if(!returnTeacher(coreTeachers[i].name).timeTable[j][k]){
                            if(timeTable[j][k]=="f"){
                                weights.push_back(weight(dayfactor[j],k,coreSubjects[i].bFactor*discouragementFactor));
                            }
                        }
                    }
                }
                std::list<int> weightsl;
                for(int o=0;o<weights.size();o++){
                    weightsl.push_back(weights[o]);
                }
                weightsl.sort();
                std::list<int>::iterator ptr=weightsl.begin();
                int j=0;
                while(ptr != weightsl.end()){
                    weights[j]=*ptr;
                    ptr++;
                    j++;
                }
                for(int j=0;j<days;j++){
                    int discouragementFactor=1;
                    for(int k=0;k<periods;k++){
                        if(timeTable[j][k]==coreSubjects[i].name){
                            discouragementFactor=200;
                        }
                        if(!returnTeacher(coreTeachers[i].name).timeTable[j][k]){
                            if(timeTable[j][k]=="f"){
                                for(int a=0;a<coreSubjects[i].credits-currentAssigned;a++){
                                    if(weight(dayfactor[j],k,coreSubjects[i].bFactor*discouragementFactor)==weights[a] && numberclasses){
                                        numberclasses--;
                                        dayfactor[j]+=coreSubjects[i].bFactor*5;
                                        timeTable[j][k]=coreSubjects[i].name;
                                        teacherTable[j][k]=coreTeachers[i].name;
                                        returnTeacher(coreTeachers[i].name).timeTable[j][k]=1;
                                        returnTeacher(coreTeachers[i].name).timeTableName[j][k]=name;
                                        if(coreSubjects[i].rooms[0]=="0"){
                                            if(!roomDefault.timeTable[j][k]){
                                                roomDefault.timeTable[j][k]=1;
                                                roomDefault.timeTableName[j][k]=name;
                                                roomTable[j][k]=roomDefault.name;
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
                                        else{
                                            for(int q=0;q<coreSubjects[i].noRooms;q++){
                                                room temp=returnRoom(coreSubjects[i].rooms[q]);
                                                if(!temp.timeTable[j][k]){
                                                    temp.timeTableName[j][k]=name;
                                                    temp.timeTable[j][k]=1;
                                                    roomTable[j][k]=temp.name;
                                                    goto a;
                                                }
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
                if(numberclasses>0){
                    currentAssigned=coreSubjects[i].credits-numberclasses;
                    goto repeat;
                }
            } 
            else{
                //std::cout<<"collision of subject "<<coreSubjects[i].name<<std::endl;
                int assigned=coreSubjects[i].credits;
                for(int j=0;j<days;j++){
                    for(int k=0;k<periods;k++){
                        if(!returnTeacher(coreTeachers[i].name).timeTable[j][k]){
                            if(timeTable[j][k]=="f" && assigned){
                                dayfactor[j]+=coreSubjects[i].bFactor*5;
                                timeTable[j][k]=coreSubjects[i].name;
                                teacherTable[j][k]=coreTeachers[i].name;
                                returnTeacher(coreTeachers[i].name).timeTable[j][k]=1;
                                returnTeacher(coreTeachers[i].name).timeTableName[j][k]=name;
                                assigned--;
                                 if(coreSubjects[i].rooms[0]=="0"){
                                    if(!roomDefault.timeTable[j][k]){
                                        roomDefault.timeTable[j][k]=1;
                                        roomDefault.timeTableName[j][k]=name;
                                        roomTable[j][k]=roomDefault.name;
                                    }
                                    else{
                                        for(int s=0;s<defRooms.size();s++){
                                            if(!defRooms[s].timeTable[j][k]){
                                                defRooms[s].timeTable[j][k]=1;
                                                defRooms[s].timeTableName[j][k]=name;
                                                roomTable[j][k]=defRooms[s].name;
                                                goto b;
                                            }
                                        }
                                        roomTable[j][k]="?????";
                                    }
                                }
                                b:
                                break;
                            }
                            if(assigned){
                                teacher &present=returnTeacher(teacherTable[j][k]);
                                subject& presentSub=returnSubject(timeTable[j][k]);
                                if(error_){
                                    break;
                                }
                                for(int l=0;l<days;l++){
                                    bool flag=1;
                                    for(int m=0;m<periods;m++){
                                        if(timeTable[l][m]==presentSub.name){
                                            if(l!=j || k!=m){
                                                l++;
                                                flag=0;
                                            }
                                        }
                                    }
                                    if(flag){
                                        for(int m=0;m<periods;m++){
                                            if(timeTable[l][m]=="f" && !present.timeTable[l][m] && assigned){
                                                subject& presentSub=returnSubject(timeTable[j][k]);
                                                timeTable[j][k]=coreSubjects[i].name;
                                                teacherTable[j][k]=coreTeachers[i].name;
                                                dayfactor[j]+=coreSubjects[i].bFactor*5-presentSub.bFactor*5;
                                                returnTeacher(coreTeachers[i].name).timeTable[j][k]=1;
                                                returnTeacher(coreTeachers[i].name).timeTableName[j][k]=name;
                                                present.timeTable[j][k]=0;
                                                //check if default rooms for new subject
                                                timeTable[l][m]=presentSub.name;
                                                teacherTable[l][m]=present.name;
                                                dayfactor[l]+=presentSub.bFactor*5;
                                                present.timeTable[l][m]=1;
                                                present.timeTableName[l][m]=name;
                                                assigned--;
                                                if(coreSubjects[i].rooms[0]=="0"){
                                                    if(!roomDefault.timeTable[l][m]){
                                                        roomDefault.timeTable[l][m]=1;
                                                        roomDefault.timeTableName[l][m]=name;
                                                        roomTable[l][m]=roomDefault.name;
                                                    }
                                                    else{
                                                        for(int s=0;s<defRooms.size();s++){
                                                            if(!defRooms[s].timeTable[l][m]){
                                                                defRooms[s].timeTable[l][m]=1;
                                                                defRooms[s].timeTableName[l][m]=name;
                                                                roomTable[l][m]=defRooms[s].name;
                                                                break;
                                                            }
                                                            roomTable[j][k]="?????";
                                                        }
                                                    }
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
        }
        else if(coreSubjects[i].hoursPerCredit==2){
            for(int j=0;j<days;j++){
                for(int k=0;k<periods;k+=2){
                    if(!returnTeacher(coreTeachers[i].name).timeTable[j][k] && !returnTeacher(coreTeachers[i].name).timeTable[j][k+1]){
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
                int classesAssigned=0;
                repeat2:
                std::vector<int> weights;
                int numberclasses=coreSubjects[i].credits-classesAssigned;
                for(int j=0;j<days;j++){
                    int discouragementFactor=1;
                    for(int k=0;k<periods;k+=2){
                        if(timeTable[j][k]==coreSubjects[i].name){
                            discouragementFactor=200;
                        }
                        if(!returnTeacher(coreTeachers[i].name).timeTable[j][k] && !returnTeacher(coreTeachers[i].name).timeTable[j][k+1]){
                            if(timeTable[j][k]=="f"){
                                weights.push_back(weight(dayfactor[j],k,coreSubjects[i].bFactor*discouragementFactor));
                            }
                        }
                    }
                }
                
                std::list<int> weightsl;
                for(int o=0;o<weights.size();o++){
                    weightsl.push_back(weights[o]);
                }
                weightsl.sort();
                std::list<int>::iterator ptr=weightsl.begin();
                int j=0;
                while(ptr != weightsl.end()){
                    weights[j]=*ptr;
                    ptr++;
                    j++;
                }
                for(int j=0;j<days;j++){
                    int discouragementFactor=1;
                    for(int k=0;k<periods;k+=2){
                        if(timeTable[j][k]==coreSubjects[i].name){
                            discouragementFactor=200;
                        }
                        if(!returnTeacher(coreTeachers[i].name).timeTable[j][k] && !returnTeacher(coreTeachers[i].name).timeTable[j][k+1]){
                            if(timeTable[j][k]=="f"){
                                for(int a=0;a<coreSubjects[i].credits-classesAssigned;a++){
                                    if(weight(dayfactor[j],k,coreSubjects[i].bFactor*discouragementFactor)==weights[a] && numberclasses){
                                        numberclasses--;
                                        dayfactor[j]+=coreSubjects[i].bFactor*5;
                                        timeTable[j][k]=coreSubjects[i].name;
                                        teacherTable[j][k]=returnTeacher(coreTeachers[i].name).name;
                                        returnTeacher(coreTeachers[i].name).timeTable[j][k]=1;
                                        returnTeacher(coreTeachers[i].name).timeTableName[j][k]=name;
                                        timeTable[j][k+1]=coreSubjects[i].name;
                                        teacherTable[j][k+1]=coreTeachers[i].name;
                                        returnTeacher(coreTeachers[i].name).timeTable[j][k+1]=1;
                                        returnTeacher(coreTeachers[i].name).timeTableName[j][k+1]=name;
                                        break;
                                        if(coreSubjects[i].rooms[0]=="0"){
                                            if(!roomDefault.timeTable[j][k] && !roomDefault.timeTable[j][k+1]){
                                                roomDefault.timeTable[j][k]=1;
                                                roomDefault.timeTableName[j][k]=name;
                                                roomTable[j][k]=roomDefault.name;
                                                roomDefault.timeTable[j][k+1]=1;
                                                roomDefault.timeTableName[j][k+1]=name;
                                                roomTable[j][k+1]=roomDefault.name;
                                            }
                                            else{
                                                for(int s=0;s<defRooms.size();s++){
                                                    if(!defRooms[s].timeTable[j][k] && !defRooms[s].timeTable[j][k+1]){
                                                        defRooms[s].timeTable[j][k]=1;
                                                        defRooms[s].timeTableName[j][k]=name;
                                                        roomTable[j][k]=defRooms[s].name;
                                                        defRooms[s].timeTable[j][k+1]=1;
                                                        defRooms[s].timeTableName[j][k+1]=name;
                                                        roomTable[j][k+1]=defRooms[s].name;
                                                        goto c;
                                                    }
                                                }
                                                roomTable[j][k]="?????";
                                            }
                                        }
                                        else{
                                            for(int q=0;q<coreSubjects[i].noRooms;q++){
                                                room temp=returnRoom(coreSubjects[i].rooms[q]);
                                                if(!temp.timeTable[j][k]){
                                                    temp.timeTableName[j][k]=name;
                                                    temp.timeTable[j][k]=1;
                                                    roomTable[j][k]=temp.name;
                                                    goto c;
                                                }
                                            }
                                        }
                                        c:
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
                if(numberclasses>0){
                    classesAssigned=coreSubjects[i].credits-numberclasses;
                    goto repeat2;
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
