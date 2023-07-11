#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<iomanip>
using namespace std;
class time_Manage{
	
	public:
	
	
	
	int getHour(){
	time_t now = time(0); 
	tm* ltm = localtime(&now); 
	int Hour;
	stringstream ss;
	ss<<ltm->tm_hour  ;
	ss>>Hour;
	return Hour;
	}
	
string getTotal()
{
	time_t ttime = time(0);
    
	string  dt = ctime(&ttime);
	return dt;
}
	
int getMinutes()
{
	time_t now = time(0); 
	tm* ltm = localtime(&now); 
	int minutes;
	stringstream ss;
	ss<<ltm->tm_min;
	ss>>minutes;	

return minutes;
}

int getSeconds()
{
	time_t now = time(0); 
	tm* ltm = localtime(&now); 
	int seconds;
		
	stringstream ss;
	ss<<ltm->tm_sec ;   ;
	ss>>seconds;
	return seconds;
}
};