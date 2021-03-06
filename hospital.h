/*
Implementation of IITB Hospital Management System in C++.
This file contains declarations for all classes, structs
and stl containers used.
Function definitions will be enumerated in separate files.
 -------------------------------------------------------------------
| Shashwat Shukla, Dhruv Ilesh Shah, Parth Jatakia, Pranav Kulkarni.|
| CS213(M) - Data Structures and Algorithms, Spring 2017.           |
| IIT Bombay                                                        |
 -------------------------------------------------------------------
*/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <numeric>
#include <limits>
#include "time.h"
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <locale>
#include <sstream>

#define TABLE_SIZE 100
#define num_diseases 7

using namespace std;

class patient;
class doctor;
class diagnosis;
class patientrecord;


// Patient Database stored here

//Each patient has relevant attributes
class patient {
public:
    string fname, lname, ID; //Identity of the patient
    vector<diagnosis> prescription; //Diagnosed disease and corresponding treatement for the patient
    vector<int> symptoms; //Symptoms displayed by the patient. Change to stack if needed
    patient();
    void getName(string &fname, string &lname);
    void getID(string &id);
    void setName(string fname, string lname);
    void setSymptoms(string symptoms);
    void addPrescription(diagnosis prescript);
    void setID(string id);
    void getPrescriptionLenght();
    int symptomsSize();
    //Add accessor and mutator function
};


//At the reception, the patients are assigned to a doctor based on their symptoms.
//As of now, they are assigned to one doctor, despite having multiple symptoms. This doctor then
//assigns the patient to the next doctor based on his/her other symptoms.
//Each doctor is identified by his name, ID and specialisation ID.


// Cough(0), Fever(1), Diarrhea(2) -> Physician A, Physician B
// Fracture(3), MuscleInjury (4) -> Orthopedic
// HeartPain (5) -> Cardiologist
// Alzheimer (6) -> Neurologist

vector <doctor> AllDoctors; // a vector containing all the doctors in the hospital.
queue <string> output_logs;
vector <patient*> DB_compl;
vector<patient*> disease_list[num_diseases];

//Since the number of doctors is very less, hashmap for doctors is not required.
//Each doctor is identified by his name, id(remove if not needed) and specialisation
class doctor {
    string name;
    string ID;
    int fieldID; // fieldID is an int given to each field of specialization eg. 1 for general physician, 2 for Orthopaedic...
    //..$%$%$ I am doubtful if this is how a queue of pointers to patient is implemeneted please check.$%$%$
public:
    //Add accessor and mutator functions
    queue<patient*> patientLine;// queue of the patient waiting to be diagnosed under the doctor.
    void setName(string name);
    void getName(string &name);
    void setID(string id);
    void getID(string &id);
    void setFieldID(int id);
    void getFieldID(int &id);
    void addToLine(patient * p); //adds patient p to the queue of the doctor.
    void diagnose(); //Diagnose patient first in the queue and add diagnosis in patient's prescription vector.
    int areUmyDoc(patient *p);
    vector<int> whatICanCure;
    void setWhatICanCure ();
    int get_queue_length();
    //Add accessor and mutator functions
};



//Doctors diagnose the patient to identify the disease and the corresponding treatment
class diagnosis {
public:
    string disease, treatment;
};


//The heart of the database. Each patient has one entry in the database.
class patientrecord {
    string name, id;
    vector<diagnosis> record; //Contains the entire treatment history of the patient
public:
    //Add accessor and mutator functions
};

//Followed by declarations for all the search related databases

const string red("\033[0;31m");
const string green("\033[0;32m");
const string yellow("\033[0;33m");
const string blue("\033[0;34m");
const string cyan("\033[0;36m");
const string magenta("\033[0;35m");
const string reset("\033[0m");
const string bold("\033[1m");

long int clk = 0;
long int counter = 0;
