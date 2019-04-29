#include <iostream>
#include "Person.cpp"
#include "Flight.cpp"
using namespace std;
class Ticket:protected Person,protected Flight{
	protected:
		int ticketNumber;
		int prev_ticketno;
		int getPrevTicket()
		{
			//read last ticket number from file
		}
	public:
		static void getTicket()
		{
			Ticket temp;
			//gets from file
			ifstream myfile;
			myfile.open("Ticket.dat",ios::binary);
			if(myfile.is_open())
			{
				while(myfile.read((char*)&temp,sizeof(temp)))
				{
					temp.printTicket();
				}
				myfile.close();
			}
			else
			cout<<"error";
		}
		static void saveTicket(Ticket obj)
		{
			ofstream myfile;
			myfile.open("Ticket.dat",ios::binary);
			if(myfile.is_open())
			{
				myfile.write((char*)&obj,sizeof(obj));
				myfile.close();
				cout<<"written. ";
			}
			else
			cout<<"error";
		}
		void bookTicket(string flightnumber,string cnic,string email,string mobile,string name,string passport,string visano)
		{
			Ticket temp;
			temp.flight_number=flightnumber;
			temp.ticketNumber=(getPrevTicket()+1);
			temp.name=name;
			temp.passport_NO=passport;
			temp.visa_NO=visano;
			temp.CNIC=cnic;
			temp.mobile_NO=mobile;
		}
		static void cancelTicket(const Ticket obj)
		{
			//deletes from file
		}
		void printTicket()
		{
			cout<<"Ticket Number: "<<ticketNumber;
			cout<<"Customer Name: "<<name;
			cout<<"Customer Email: "<<Email;
			cout<<"Customer Mobile: "<<mobile_NO;
			cout<<"Customer Passport Number: "<<passport_NO;
			cout<<"Customer Visa Number: "<<visa_NO<<endl;
		}
	
};

