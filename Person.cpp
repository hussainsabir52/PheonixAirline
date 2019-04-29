#include <iostream>
using namespace std;

class Person{
	protected:
		string name;
		string CNIC;
		string mobile_NO;
		string passport_NO;
		string visa_NO;
		string Email;
	public:
		Person(){
		}
		Person(string name,string cnic,string mobile,string passport,string visa,string mail)
		{
			this->name=name;
			this->CNIC=cnic;
			this->mobile_NO=mobile;
			this->passport_NO=passport;
			this->visa_NO=visa;
			this->Email=mail;
		}
		void change_info(string name="NULL",string cnic="NULL",string mobile="NULL",string passport="NULL",string visa="NULL",string mail="NULL")
		{
			this->name=name;
			this->CNIC=cnic;
			this->mobile_NO=mobile;
			this->passport_NO=passport;
			this->visa_NO=visa;
			this->Email=mail;
		}
		string getnum()
		{
			return mobile_NO;
		}
};
