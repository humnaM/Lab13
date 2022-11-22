#include<iostream>
#include<string.h>
using namespace std;


class Workshop{
	public:
		virtual void getWorkshop(){
			cout<<"hello i am workshop"<<endl;
		}
	
};

class produce: public Workshop{
	public:
		void getWorkshop(){
			cout<<"hello i am workshop"<<endl;
		}
		
};

class assemble: public Workshop{
	public:
		void getWorkshop(){
			cout<<"hello i am workshop"<<endl;
		}
		
	
};

class Vehicle{
	public:
		produce pro;
		assemble assem;
		virtual void getVehicle(){
			cout<<"hello i am vehicle"<<endl;
		}
		
	

};

class bike: public Vehicle{
	public:
		void getVehicle(){
			cout<<"hello i am vehicle"<<endl;
		}
};

class bus: public Vehicle{
	public:
		void getVehicle(){
			cout<<"hello i am vehicle"<<endl;
		}
};


int main(){
	
	bike bik;
	bik.pro.getWorkshop();
	bik.assem.getWorkshop();
	
	cout<<endl;
	cout<<endl;
	
	bus bu;
	bu.assem.getWorkshop();
	bu.pro.getWorkshop();
	
	
	
	
}



