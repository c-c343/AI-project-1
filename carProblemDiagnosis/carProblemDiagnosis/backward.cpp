#include <algorithm>
#include<iostream>
#include <stdlib.h>
#include<stack>
#include<string.h>
#include <string>
#include <iostream>


using namespace std;

//Function declarations
void conclusion();
void determineSymptoms();
void clauseV();
void print(string []);
void analizeSymptoms(int);
void checkMember(string[]);



int main() {
	int i;	//counter
	int choice=0;

	string varList[50][50];

	char condVar[10][10];
	char clauseVList[50][3];

	do {
		cout << " Hi, welcome to our automibile diagnosis program! \n";
		cout << " How may we help you today? \n";
	
		cout << "\n\t1) My car neets to be diagnosed.\n";
		cout << "\t2) Summary of previous diagnostics. \n";
		cout << "\t3) EXIT\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "You selected : My car needs to be diagnosed\n";
			determineSymptoms();
			break;
		case 2:
			cout << "Summary of previous diagnostics";
			analizeSymptoms(choice);
			break;
		case 3:
			cout << "You have selected to EXIT the probram \n";
			cout << "Thank you, come again! \n";
			 //EXIT_SUCCESS;
			 exit(0);
		}

	} while (choice != NULL);
	return 0;
}

//Backward chaining
void determineSymptoms() {

	int choice;
	do {
		cout << "\nFrom the menu, please enter the number that highlights your problem: \n\n ";
		cout << "\t1) Car wont start\n";
		cout << "\t2) Car Stalls\n";
		cout << "\t3) Car is heating up\n";
		cout << "\t4) Car wont move\n";
		cout << "\t5) Breaks Squeal \n";
		cout << "\t6) Steering wheel shakes\n";
		cout << "\t7) EXIT\n";

		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "'Car wont start'\n";
			choice = 1;
			analizeSymptoms(choice);
			break;
		case 2:
			cout << "'Car Stalls'\n";
			choice = 2;
			analizeSymptoms(choice);
			break;
		case 3:
			cout << "'Car is heating up'\n";
			choice = 3;
			analizeSymptoms(choice);
			break;
		case 4:
			cout << "'Car wont move'\n";
			choice = 4;
			analizeSymptoms(choice);
			break;
		case 5:
			cout << "'Breaks Squeal'\n";
			choice = 5;
			analizeSymptoms(choice);
			break;
		case 6:
			cout << "'Steering wheel shakes'\n";
			choice = 6;
			analizeSymptoms(choice);
			break;
		case 7:
			cout << "You''ve chosen to exit. \n";
			main();
		}
	} while (choice != NULL);
}

void analizeSymptoms(int choice) {

	string varList[20];

			varList[0] = "Battery is weak";

			varList[1] = "Not enough fuel";
			
			varList[2] = "Alternator fails ";
			
			varList[3] = "Water level is empty/ low";
			varList[4] = "transmission fluid low";

			varList[3] = "Water level is empty/ low";
			varList[5] = "Fan not cooling properly";


			varList[3] = "transmission fluid low";
			varList[6] = "oil is old";

			varList[7] = "Brakepads are worn";
			varList[8] = "brakes are tight";
			varList[9] = "brake fluid low";

			varList[10] = "Tire thread uneven/tire pressure low";
			varList[11] = "Alignment problem";

			varList[12] = "worn out wipers";
			varList[13] = "worn out brake lights";


	print(varList);
	conclusion();
}

void conclusion()
{
	string conclusionList[50];
	conclusionList == NULL;

	//initialize
	conclusionList[0] = "Problems: ";
	conclusionList[1] = "Car not starting";
	conclusionList[2] = "Lights are flickering";
	conclusionList[3] = "Battery is draining";
	conclusionList[4] = "Engine failure";
	conclusionList[5] = "engine is over heating";
	conclusionList[6] = " car is heating up";
	conclusionList[7] = "Car won''t shift";
	conclusionList[8] = "Breaks aren't working";
	conclusionList[9] = "Brakes are squealing";
	conclusionList[10] = "brakes hit the floor/ car not stopping";
	conclusionList[11] = "brakes are grinding";
	conclusionList[12] = "steering wheel shaking";
	conclusionList[13] = "car is veering left/right";
	conclusionList[14] = "wipers aren't working";
	conclusionList[15] = "headlights are dimming/wont turn on";
	checkMember(conclusionList);
	instance(conclusionList);
}

void clauseV()
{
	string clauseVarList[50];

	//Car won't start
	clauseVarList[0] = "problem";
	clauseVarList[1] = "car not starting";
	clauseVarList[2] = "key clicking sound";
	clauseVarList[3] = "No lights turning on";
	clauseVarList[4] = "engine cranking";

	//Car wont run
	clauseVarList[7] = "engine failure";
	clauseVarList[8] = "engine cranking";
	clauseVarList[9] = "engine fan blowing loudly";
	clauseVarList[10] = "Car temperature rising";
	clauseVarList[11] = "fan is not turning on";

	//car stalls
	clauseVarList[14] = "Car not shifting";

	//brakes
	clauseVarList[17] = "brakes are faulty";
	clauseVarList[18] = "Car wont stop";
	clauseVarList[19] = "brakes hit the floor";
	clauseVarList[20] = "brakes are grinding";
	clauseVarList[21] = "brakes will squeal";

	//tires
	clauseVarList[24] = "tire pressure light";

	//steering
	clauseVarList[27] = "steering wheel is shaking";
	clauseVarList[28] = "car veering left/right";
	
	//other
	clauseVarList[30] = "wipers not functioning properly";
	clauseVarList[31] = "lights are not turning on";
	clauseVarList[32] = "headlights/brakes flickering";

}


void checkMember(string conclusionList[50])
{
	string varTemp[30];
	int temp, i, k;
		i = 0, k = 0, temp = 0;
	i = k;
	while ((varTemp->compare(conclusionList[i]) != 0) && (i < 60))
		i++;

	if (varTemp->compare( conclusionList[i]) == 0) 
		temp = i;

}

void stack()
{
	int clausenum[50];
	int stack[50];

	int sp = 0;
	int stacknum;

	sp--;
	stack[sp] = stacknum;
	clausenum[sp] = 1;
}
//creating an instance
void instance(string conclusionList[50])
{
	string problem, turnOn, flicker, engineFailure, carRun, heating, fanOn, stall, shift, brakes, tires, lights, wipers, squeal, steering;
	string varTemp[30];
	int instant[30];
	int i = 0;

	while ((varTemp->compare(conclusionList[i]) != 0) && (i < 60))
		i++;

	if ((varTemp->compare(conclusionList[i]) == 0) && (instant[i] != 1))
	{
		instant[i] = 1;

		switch (i)
		{
		case 1: cout << "Determining a problem... \n" << endl;
			cout << "Do you need to determine a problem? (Y/N)\n" << endl;
			cout << "Answer: ";  cin >> problem;
			if (problem == "N")
			{
				cout << "No problem with car. Exiting now..." << endl;
				exit(0);
			}
		case 2:
			cout << "\nCreating instance for turnOn var... \n" << endl;
			cout << "Does your car turn on? (Y/N)" << endl;
			cout << "Answer: ";  cin >> turnOn;
			break;

		case 3:
			cout << "\nCreating instance for flicker var... \n" << endl;
			cout << "Are your lights flickering ? (Y/N)\n" << endl;
			cout << "Answer: "; cin >> flicker;
			break;

		case 4:
			cout << "\nCreating instance for engineFailure var... \n" << endl;
			cout << "Is your engine failing ? (Y/N)\n" << endl;
			cout << "Answer: "; cin >> engineFailure;
			break;
		case 5:
			cout << "\nCreating instance for carRun var... \n" << endl;
			cout << "Does your car run ? (Y/N)" << endl;
			cout << "Answer: ";  cin >> carRun;
			break;
		case 6:
			cout << "\nCreating instance for heating var... \n" << endl;
			cout << "is your car's temperature high? (Y/N)" << endl;
			cout << "Answer: ";  cin >> heating;
			break;
		case 7:
			cout << "\nCreating instance for fanOn var... \n" << endl;
			cout << "Is your car's fan turning on? (Y/N)" << endl;
			cout << "Answer: ";  cin >> fanOn;
			break;
		case 8:
			cout << "\nCreating instance for carRun var... \n" << endl;
			cout << "Does your car run ? (Y/N)" << endl;
			cout << "Answer: ";  cin >> carRun;
			break;
		case 9:
			cout << "\nCreating instance for stall var... \n" << endl;
			cout << "Is your car stalling ? (Y/N)" << endl;
			cout << "Answer: ";  cin >> stall;
			break;
		case 10:
			cout << "\nCreating instance for shift var... \n" << endl;
			cout << "Will your car shift? (Y/N)" << endl;
			cout << "Answer: ";  cin >> shift;
			break;
		case 11:
			cout << "\nCreating instance for brakes var... \n" << endl;
			cout << "Will your car brake ? (Y/N)" << endl;
			cout << "Answer: ";  cin >> brakes;
			break;
		case 12:
			cout << "\nCreating instance for squeal var... \n" << endl;
			cout << "Are your brakes squealing ? (Y/N)" << endl;
			cout << "Answer: ";  cin >> squeal;
			break;
		case 13:
			cout << "\nCreating instance for tires var... \n" << endl;
			cout << "Do you have an indicator light on for tire pressure ? (Y/N)" << endl;
			cout << "Answer: ";  cin >> tires;
			break;
		case 14:
			cout << "\nCreating instance for steering var... \n" << endl;
			cout << "Do you have a steering problem ? (Y/N)" << endl;
			cout << "Answer: ";  cin >> steering;
			break;
		case 15:
			cout << "\nCreating instance for lights var... \n" << endl;
			cout << "Are your headlights turning on ? (Y/N)" << endl;
			cout << "Answer: ";  cin >> lights;
			break;
		case 16:
			cout << "\nCreating instance for wipers var... \n" << endl;
			cout << "Are your wipers working ? (Y/N)" << endl;
			cout << "Answer: ";  cin >> wipers;
			break;

		}
	}

}

void print(string varList[50])
{
	cout << "\nHere is a summary of your variable list\n";
	int i = 0;
	while (i < 13)
	{
		cout <<"\t" << i <<") " << varList[i] << endl;
		i++;
		
	}

	cout << "\n Here is the clause Variable List: \n ";
	while (i < 32) {
		cout << "\t" << i << ") " << varList[i] << endl;
		i++;
	}

}