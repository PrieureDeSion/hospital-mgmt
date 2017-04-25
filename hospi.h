/*
This file stores the accessor and mutator functions for the classes declared
in the header file "hospital.h"
 -------------------------------------------------------------------
| Shashwat Shukla, Dhruv Ilesh Shah, Parth Jatakia, Pranav Kulkarni.|
| CS213(M) - Data Structures and Algorithms, Spring 2017.           |
| IIT Bombay.                                                       |
 -------------------------------------------------------------------
*/

#include "hospital.h"

void assignDoc(patient * p);

//.......Patient Functions..........//
void patient::getName(string &fname, string &lname)
{
	fname = patient::fname;
	lname = patient::lname;
}

void patient::getID(string &id)
{
	id = patient::ID;
}

void patient::setName(string fname, string lname)
{
	patient::fname = fname;
	patient::lname = lname;
}

void patient::setSymptoms (string symp)
{
	patient::symptoms.push_back(toSympInt(symp));
}

//.......Doctor Functions..........//
void doctor::addToLine(patient * p)
{
	doctor::patientLine.push(p);
	cout << "Patient added to waiting line for Dr. " << doctor::name << endl;
}

void doctor::setWhatICanCure ()
{
	if (fieldID == 1 || fieldID == 2) { 
		whatICanCure.push_back(0); 
		whatICanCure.push_back(1);
		whatICanCure.push_back(2);
	}

	if (fieldID == 3) { 
		whatICanCure.push_back(3); 
		whatICanCure.push_back(4);
	}
	if (fieldID == 4) { 
		whatICanCure.push_back(5); 
	}
	if (fieldID == 5) { 
		whatICanCure.push_back(6); 
	}
}


void doctor::diagnose(patient * p)
{
	for (int i=0; i<doctor::whatICanCure.size();i++)
	{
		for (int j=0; j<p->symptoms.size(); j++)
		{
			if (i==j)
			{
				cout << "Patient has been cured for symptom :" << toSympString(p->symptoms[j]) << endl;
				p->symptoms.erase(p->symptoms.begin()+j);

			}
		}
	}

doctor::patientLine.pop();
if (p->symptoms.size()!=0) 
{
		cout << "Patient is not yet cured send to another Doctor" << endl;
		assignDoc(p);
	}
}

int doctor::areUmyDoc(patient * p)
{
	for (int i=0; i<doctor::whatICanCure.size(); i++)
	{
		for (int j=0; j<p->symptoms.size(); j++)
		{
			if (i==j)
			{
				return doctor::patientLine.size();
			}
		}
	}

	return numeric_limits<int>::max();
	
}

void assignDoc(patient * p)
{
	int least_waiting = numeric_limits<int>::max(); // set to max initially
	doctor myDoctor;

	for (int i = 0; i <= AllDoctors.size(); i++) // iterating over all doctors to find the doctor with matching fieldID and minimun waiting
	{
		int curr_waiting = AllDoctors[i].areUmyDoc(p);
		if (curr_waiting < least_waiting)
		{	least_waiting = curr_waiting;
			myDoctor = AllDoctors[i];
		}
	}

	myDoctor.addToLine (p);
}