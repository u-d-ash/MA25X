#include <iostream>
#include <string>

using namespace std;

class Master{

	private:
		string name;
		string dob;
		string doj;
	
	protected:
		void set_name(string n){
		
			name = n;
		
		}
		
		void set_dob(string d){
		
			dob = d;
		
		}
		
		void set_doj(string d){
		
			doj = d;
		
		}
		string get_name(){
		
		
			return name;
		
		}
		string get_dob(){
		
			return dob;
		
		}
		
		string get_doj(){
		
		
			return doj;
		
		}

};

class Admin : public Master{

	private:
		double exp;
	
	protected:
		void set_exp(double e){
		
			exp = e;
			
		
		}
		
		double get_exp(){
		
			return exp;
		
		}

};

class Account : public Master{

	private:
		double pay;
	
	protected:
		void set_pay(double p){
			
			pay = p;
		
		}
		
		double get_pay(){
		
			return pay;
		
		}

};

class Person : public Admin, public Account{

	public:
		Person(string n, string db, string dj, double p, double e){
		
			set_exp(e);
			set_pay(p);
			Admin::set_name(n);
			Admin::set_dob(db);
			Admin::set_doj(dj);
			
		
		}

		void set_person_values(string n, string db, string dj, double p, double e){
		
			set_exp(e);
			set_pay(p);
			Admin::set_name(n);
			Admin::set_dob(db);
			Admin::set_doj(dj);
		
		}
		
		void print_values(){
		
			cout << "pay " << get_pay() << endl;
			cout << "exp " << get_exp() << endl;
			cout << "dob " << Admin::get_dob() << endl;
			cout << "doj " << Admin::get_doj() << endl;
			cout << "name " << Admin::get_name() << endl;
		
		}


};

int main(){
	
	

}
