#include <iostream>
#include <fstream>
#include<iomanip>
#include<strings.h>
using namespace std;
struct date {
	int day;
	int month;
	int year;
};
struct time {
	int min;
	int hour;
	
};
class Flight {
protected:
	char flight_number[7];
	struct date date;
	struct time arrival,departure;
	int economic_fare;
	int business_fare;
	char flight_to[4];
	char flight_from[4];
	bool isposted;
//	int total_seats;
//	int seats_occupied;
//	int seats_left;
//	int gatenumber;
//	struct time duration;
	
public:
	friend istream &operator>> (istream &input, Flight &f); 
	Flight(){}
	Flight(char fn[])
	{
		strcpy(flight_number,fn);
	}
//	void setSchedule(string to,string from,struct date d,struct time at,struct time dt,int bfare,int efare)
//	{
//		this->flight_to = to;
//		this->flight_from = from;
//		this->date = d;
//		this->arrival = at;
//		this->departure = dt;
//		this->economic_fare = efare;
//		this->business_fare = bfare;
//		
//	}
	static void postFlight(Flight F)
	{
		Flight F1;
		ifstream myfile;
		ofstream desfile;
		myfile.open("Flight.dat",ios::app|ios::binary);
		desfile.open("Flight1.dat",ios::app|ios::binary);
		if (myfile.is_open())
 		 {
    		while(myfile.read((char*)&F1,sizeof(F1))!=NULL)
    		{
    			if(strcmp(F.flight_number,F1.flight_number)==0)
    			{
    				F1.isposted=true;
    				desfile.write((char *)&F1,sizeof(F1));
				}
				else
				{
					desfile.write((char *)&F1,sizeof(F1));
				}
				
			}
    		myfile.close();
    		desfile.close();
			remove("Flight.dat");
			rename("Flight1.dat","Flight.dat");
	
	}
}
	static void flightsavetofile(Flight &F)
	{
		ofstream myfile;
		myfile.open("Flight.dat",ios::app|ios::binary);
		if (myfile.is_open())
 		 {
    		myfile.write((char *)&F,sizeof(F));
    		myfile.close();
  			cout<<"Schedule Saved."; 
		}	
  		else cout << "Unable to open file";
	}
	void display()
	{
		cout<<"Flight Number: "<<flight_number<<endl;
		cout<<"To: "<<flight_to<<endl;
		cout<<"From: "<<flight_from<<endl;
    	cout<<"Date: "<<date.day<<"."<<date.month<<"."<<date.year<<endl;
		cout<<"Arrival: "<<arrival.hour<<":"<<arrival.min<<endl;
    	cout<<"Departure: "<<departure.hour<<":"<<departure.min<<endl;		
    	cout<<"Flight E-Fare: "<<economic_fare<<endl;
    	cout<<"Fligth B-Fare: "<<business_fare<<endl;
    	cout<<"Posted: "<<isposted<<endl;
    	
	}
	static void getschedule(char to[],char from[])
	{
		Flight F;
		ifstream myfile;
		myfile.open("Flight.dat",ios::in|ios::binary);
		if (myfile.is_open())
 		 {
    		while(myfile.read((char*)&F,sizeof(F))!=NULL)
    		{
    			if(strcmp(F.flight_from,from)==0 && strcmp(F.flight_to,to)==0)
    			{
    				F.display();
				}
				else
				continue;
			}
    		myfile.close();
  			 
		}	
  		else cout << "Unable to open file";
	}
	static void getschedule()
	{
		Flight F;
		ifstream myfile;
		myfile.open("Flight.dat",ios::in|ios::binary);
		if (myfile.is_open())
 		 {
    		while(myfile.read((char*)&F,sizeof(F))!=NULL)
    		{
    			if(F.isposted==false)
    			{
    				F.display();
				}
			}
    		myfile.close();
  			 
		}	
  		else cout << "Unable to open file";
	}
};
istream &operator>> (istream &input, Flight &f) 
	{
		cout<<"Flight Number: "<<f.flight_number<<endl;
		cout<<"To(Format XXX): ";
		input>>setw(4)>>f.flight_to;
		fflush(stdin);
		cout<<"From(Format XXX): ";
		input>>setw(4)>>f.flight_from;
		fflush(stdin);
		cout<<"Date(dd/mm/yyyy): ";
		input>>setw(2)>>f.date.day;
		input.ignore(1); //for /
		input>>setw(2)>>f.date.month;
		input.ignore(1);
		input>>setw(4)>>f.date.year;
		cout<<"Departure Time(hh:mm): ";
		input>>setw(2)>>f.departure.hour;
		input.ignore(1);
		input>>setw(2)>>f.departure.min;
		cout<<"Arrival Time(hh:mm): ";
		input>>setw(2)>>f.arrival.hour;
		input.ignore(1);
		input>>setw(2)>>f.arrival.min;
		cout<<"Economy Class Fare: ";
		input>>f.economic_fare;
		cout<<"Business Class Fare: ";
		input>>f.business_fare;
		f.isposted=false;
		return input;
	}
int main()
{
//	char a[]="nyk";
//	char b[]="khi";
	Flight F("1005");
//	cin>>F;
//	Flight::flightsavetofile(F);
//	Flight::postFlight(F);
	Flight::getschedule();
//	Flight::getschedule(a,b);

}
