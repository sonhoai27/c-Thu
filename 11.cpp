#include "iostream"
#include <math.h>
using namespace std;

class TIME {
	private:
		int h,m,s;
	public:
		TIME(int g = 0, int p = 0, int gi = 0){
			this->h = g; this->m = p; this->s = gi;
		}
		void display(){
			cout<<this->h<<":"<<this->m<<":"<<this->s<<endl;
		}
		TIME distance(TIME time){
			int localHourSecond = this->h*60*60;
			int localMinuteSecond = this->m*60;
			int localSecond = localHourSecond+localMinuteSecond+this->s;
			
			int second = time.h*60*60+time.m*60+time.s;
			
			int distance = second - localSecond;
	
			TIME tempTime(
			(distance/3600), 
			((distance/60)%60), 
			distance - (((distance/3600)*60*60) + ((distance/60)%60)));
			return tempTime;
		}
	
};
class DATE {
	private:
		int day, month, year;
	public:
		DATE(int d, int m, int y){
			this->day = d;
			this->month = m;
			this->year = y;
		}
		long distance(DATE date){
			if(date.year == this->year){
				return abs((date.day + date.monthToDays(date.month,date.month)) - (this->day + monthToDays(this->month, this->year)));
			}else {
				return abs(yearToDays(this->year, date.year) + (date.day+monthToDays(date.month, date.year)) - (this->day + monthToDays(this->month, this->year)));
			}
			return 0;
		}
		bool leapYear(int y){
			if((y%4 == 0 && y%100 != 0)|| (y%400==0)) return true;
			return false;
		}
		int yearToDays(int localYear, int year){
			int tempYear = 0;
			for(int i = (localYear > year ? year: localYear); i < (localYear > year ? localYear: year); i++){
				if(leapYear(i)){
					tempYear += 366;
				}else {
					tempYear += 365;
				}
			}
			return tempYear;
		}
		int monthToDays(int month, int year){
			int tempDays = 0;
			if(month == 1){
				return tempDays;
			}
			else {
				for(int i = 1; i < month;i++){
					switch(i){
						case 1: case 3: case 5: case 7: case 8: case 10: case 12: {
							tempDays += 31;
						};break;
						case 2: {
							if(leapYear(year)){
								tempDays +=29;
							}else {
								tempDays +=28;
							}
						};break;
						case 4: case 6: case 9: case 11: {
							tempDays += 30;
						};break;
						default: 0;
					}
				}
				return tempDays;
			}
		}
};
int main(){
//	TIME timeA(0,30,20);
//	TIME timeB(2,30,22);
//	timeA.display();
//	timeB.display();
//	timeA.distance(timeB).display();
	DATE dateA(1,1,2014),dateB(10,6,2014);
	cout<<dateA.distance(dateB);
	system("pause");
	return 0;
}
