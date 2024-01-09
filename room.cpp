#include<string>
#include"configs.cpp"
//includes
using namespace std;
//namespace declaration
class room{
    public:
        string name;
        int capacity=0;
        bool labOrNot=0;
        string building; 
        bool timeTable[days][periods];//when teacher is free. 1 for free 0 for occupiued.
        int timeTableName[days][periods];//what teacher is teaching when occupied. changes done by program, not taken from user.
        bool readData(string inp);
        string convertToString();
        room
        (){
            for(int i=0;i<days;i++){
                for(int j=0;j<periods;j++){
                    timeTableName[i][j]=0;
                }
            }
        }//initialise all classes to zero.
};
bool room::readData(string inp){
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
string room::convertToString(){
    string output;
    output+=name+","+to_string(capacity)+","+to_string(labOrNot)+","+building;
    for(int i=0;i<days;i++){
        for(int j=0;j<days;j++){
            output+=","+to_string(timeTable[i][j])+","+to_string(timeTableName[i][j]);
        }
    }
    return output;
}