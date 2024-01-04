
#include<iostream>
#include<fstream>
#include<string>
#include"configs.cpp"
//includes
using namespace std;
//namespace declaration
class teacher{
    public:
        string name;//name of teacher
        string branch;//branch of teacher
        int workHours=0; //how many hours the teacher would work
        bool timeTable[days][periods];//when teacher is free. 1 for free 0 for occupiued.
        int timeTableName[days][periods];//what teacher is teaching when occupied. changes done by program, not taken from user.
        bool readData(string inp);//function which converts string input from teacherdata to the objects data
        string convertString();//reverse of above
        teacher(){
            for(int i=0;i<days;i++){
                for(int j=0;j<periods;j++){
                    timeTableName[i][j]=0;
                }
            }
        }//initialise all classes to zero.
};
bool teacher::readData(string inp){
    enum format{
        namen,
        branchn,
        workHoursn,
        timeTablen
    };//Used for switch statements. each field corresponds to its location in the string
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
                case workHoursn:
                    workHours=workHours*10+inp[i]-'0';
                    break;//read workhours
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
string teacher::convertString(){
    string output;
    output=name;
    output.push_back(',');
    output+=branch;
    output.push_back(',');
    output+=to_string(workHours);
    for(int i=0;i<days;i++){
        for(int j=0;j<days;j++){
            output+=","+to_string(timeTable[i][j])+","+to_string(timeTableName[i][j]);
        }
    }
    return output+" ";
}