#include<iostream>
using namespace std;
class Luggage{
protected:
	int luggagenum;
	int allowed_weight;
	int weight;
	int prev_luggage;
	int count;
	int getPrevLuggage()
	{
		//filing	
	}
	int checkWeight(int c)
	{
		count=c;
		int a;
		for(a=0;a<c;a++)
		{
			cout<<"Enter WEIGHT in KG of "<<a+1<<"Bag.";
            cin>>weight;
			//weight+=weight;
		}

        a=weight-allowed_weight;
		if(a>0)
		{
			return a;
		}
	}
	void printTag()
	{
		//prints here
	}
	void savetofileluggage()
	{
		//saves to file
	}
};
