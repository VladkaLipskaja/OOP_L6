#ifndef Source_h
#define Source_h
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
class Patient {
protected:
	string Name;
	string Phone;
public:
	Patient(string name, string phone) :Name(name), Phone(phone) {};
	void print_name() {	cout << "Name: " << Name << endl;}
	void print_phone() { cout << "Phone: " << Phone << endl;}
};

class Disease {
protected:
	string Complaint;
	string Doctor;
	string Survey;
	string Analyzes;
	string Results;
	string Diagnosis;
	string Recipes;
	int Day;
	int Month;
	int Year;
public: 
	Disease(string complaint, string doctor, string survey, int day, int month, int year) :Complaint(complaint), Doctor(doctor), Survey(survey), Day(day), Month(month), Year(year) {};
	void print_disease() { cout << "Disease: " << Complaint << endl;}
	void print_doctor() { cout << "Doctor: " << Doctor << endl;}
	void print_survey() { cout << "Survey: " << Survey << endl;}
	void  get_analyzes() {
		srand(time(NULL));                 
		int index = rand() % 5;
		string results[5] = { "everything is ok", "just some problems","excellent","bad","almost badly" };
		cout << results[index] << endl;
		Results = results[index];
	}
	void print_analyzes() {	cout << "Results: " << Results << endl;	}
	void write_diagnosis(string diagnosis) { Diagnosis = diagnosis; };
	void write_recipes(string recipes) { Recipes = recipes; };
	void print_diagnosis() { cout << "Diagnosis: " << Diagnosis << endl;}
	void print_recipes() { cout << "Recipes: " << Recipes << endl; }
	int get_month() { return Month; }
	void print_date() {	cout << "Date: " << Day << " " << Month << " " << Year << endl;	}
};

template<class... Infos>  
class Info : public Infos...  {  
public:   
	Info(const Infos&&... infos) : Infos(infos)... {};
};
#endif
