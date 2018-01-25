#include <iostream>
#include <vector>
#include "Source.h"
#include <string>
#include <cstdlib>
#include <memory>
using namespace std;
int main() {
	string name;
	string phone;
	string complaint;
	string doctor;
	string survey;
	string analyzes;
	string results;
	string diagnosis;
	string recipes;
	int day;
	int month;
	int year;

	bool menu = 1;
	system("color F0");
	cout << " V, lab6, Doctor->Patient" << endl;
	vector<unique_ptr<Info<Patient, Disease>>> arr;
	string s;
	string names[30] = { "Ivanov", "Ivanova", "Petrov", "Povanova", "Frankova", "Opalnik", "Leynik", "Uzh", "Ischenko", "Terova", "Koval", "Opanasyuk", "Rorova", "Dudko", "Dudkova", "Sosnova", "Vekova", "July", "Summer", "Ostin", "Zaterova", "Dzvinko", "Doloras", "Cattyy", "Kirka", "Kutsya", "Lis", "Noros", "Filimonov", "Keresa" };
	string phones[30] = { "+380630000101", "+380630000102", "+380630000103", "+380630000104", "+380630000105", "+380630000106", "+380630000107", "+380630000108", "+380630000109", "+380630000110", "+380630000111", "+380630000112", "+380630000113", "+380630000114", "+380630000115", "+380630000116", "+380630000117", "+380630000118", "+380630000119", "+380630000120", "+380630000121", "+380630000122", "+380630000123", "+380630000124", "+380630000125", "+380630000126", "+380630000127", "+380630000129", "+380630000130", "+380630000131" };
	string diagnoses[30] = { "bronchit", "angina", "angina", "illnesss", "grup", "chickenpox", "illnesss", "grup", "illnesss", "grup", "angina", "illnesss", "bronchit", "illnesss", "grup", "grup", "grup", "bronchit", "bronchit", "illnesss", "chickenpox", "angina", "chickenpox", "angina", "angina", "illnesss", "illnesss", "angina", "illnesss", "angina" };

	for (int i = 0; i < 30; i++) {
		unique_ptr<Info<Patient, Disease>> patient(new Info<Patient, Disease>({ names[i], phones[i] }, { "illness", "Zvintsova", "illness", i+1,8,2017 }));
		patient->write_diagnosis(diagnoses[i]);
		arr.push_back(move(patient));
	}

	while (menu) {	
		cout << "Name:" << endl;
		cin >> s;
		name = s;
		cout << "Phone:" << endl;
		cin >> s;
		phone = s;
		cout << "Complaint:" << endl;
		cin >> s;
		complaint = s;
		cout << "Doctor:" << endl;
		cin >> s;
		doctor = s;
		cout << "Survey:" << endl;
		cin >> s;
		survey = s;
		cout << "Day:" << endl;
		cin >> s;
		day = atoi(s.c_str());
		cout << "Month:" << endl;
		cin >> s;
		month = atoi(s.c_str());
		cout << "Year:" << endl;
		cin >> s;
		year = atoi(s.c_str());
		unique_ptr<Info<Patient, Disease>> patient1(new Info<Patient, Disease>({ name, phone }, { complaint, doctor, survey, day,month,year }));
		patient1->get_analyzes();
		cout << "Diagnosis:" << endl;
		cin >> s;
		diagnosis = s;
		patient1->write_diagnosis(diagnosis);
		cout << "Recipes:" << endl;
		cin >> s;
		recipes = s;
		patient1->write_recipes(recipes);
		arr.push_back(move(patient1));
		cout << "continue? 1/0" << endl;
		cin >> s;
		if (s != "1") menu = 0;
	}
	cout << "Month:" << endl;
	cin >> s;
	month = atoi(s.c_str());
	int count = 0;
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i]->get_month() == month) {
			arr[i]->print_name(); arr[i]->print_diagnosis(); count++;
		}
	}
	cout <<"Number of patients :"<<endl<< count << endl;
	system("pause");
}