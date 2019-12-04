#pragma warning(disable : 4996)
#include <algorithm>
#include<iostream>
#include <stdlib.h>
#include<stack>
#include<string.h>
#include <string>
#include <iostream>


using namespace std;

//Function declarations
void determineSymptoms();
void print();
void checkMember();
void instance(string, string, string, string, string, string, string, string, string, string, string, string , string, string, string);
void stackfunc();
void Initializing();


char varTemp[120];
char conclusionList[40][40];
char clauseVarList[120][40];
char varList[40][40];
int instlt[40];
int statsk[30];	
char buff[128];
int clausk[40], sn, t, p, z;


int sp = 40;

int main() {
	int choice=0;
	print();
	Initializing();

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
			Initializing();
			break;
		case 3:
			cout << "You have selected to EXIT the probram \n";
			cout << "Thank you, come again! \n";
			exit(0);
		}

	} while (choice != NULL);
	return 0;
}

void Initializing()
{
	////////////////Initializing Each List/////////////////////

	for (t = 1; t < 11; t++)
	{
		strcpy(conclusionList[t], "");
		strcpy(varList[t], "");
		instlt[t] = 0;
		statsk[t] = 0;
		clausk[t] = 0;
	}
	for (t = 1; t < 41; t++)  strcpy(clauseVarList[t], "");

	//////////////////VAriable List//////////////////////
	strcpy(varList[0], "Problem");
	strcpy(varList[1], "NoStart");
	strcpy(varList[2], "Start");
	strcpy(varList[3], "noFlicker");
	strcpy(varList[4], "Flickers");
	strcpy(varList[5], "NoLights");
	strcpy(varList[6], "Engine");
	strcpy(varList[7], "Heating");
	strcpy(varList[8], "FanSound");
	strcpy(varList[9], "Shift");
	strcpy(varList[10], "Squeal");
	strcpy(varList[11], "Brake");
	strcpy(varList[12], "NoBreak");
	strcpy(varList[13], "Steering");
	strcpy(varList[14], "Shake");
	strcpy(varList[15], "Streaks");
	strcpy(varList[16], "NoHeadlights");

	//////////////Conclusion List/////////////
			//initialize
		//conclusionList[1] = "Problem";
	strcpy(conclusionList[1], "Problem");
	strcpy(conclusionList[2], "Battery");
	strcpy(conclusionList[3], "Problem");
	strcpy(conclusionList[4], "Alternator");

	strcpy(conclusionList[6], "Problem");
	strcpy(conclusionList[7], "Gas");
	strcpy(conclusionList[8], "Problem");

	strcpy(conclusionList[9], "Problem");
	strcpy(conclusionList[10], "oil");
	strcpy(conclusionList[11], "Problem");
	strcpy(conclusionList[12], "Problem");

	strcpy(conclusionList[13], "water");
	strcpy(conclusionList[14], "water");
	strcpy(conclusionList[15], "Problem");

	strcpy(conclusionList[16], "Fan");
	strcpy(conclusionList[17], "Problem");
	strcpy(conclusionList[18], "Transmission");

	strcpy(conclusionList[19], "Transmission");
	strcpy(conclusionList[20], "Transmission");
	strcpy(conclusionList[21], "Problem");

	strcpy(conclusionList[22], "Brakes");
	strcpy(conclusionList[23], "Problem");
	strcpy(conclusionList[24], "BrakeFluid");
	strcpy(conclusionList[25], "BrakeFluid");

	strcpy(conclusionList[26], "Problem");
	strcpy(conclusionList[27], "BrakePads");

	strcpy(conclusionList[28], "Problem");
	strcpy(conclusionList[29], "TightBrake");
	strcpy(conclusionList[30], "Problem");
	strcpy(conclusionList[31], "Steering");

	strcpy(conclusionList[32], "TirePressure");
	strcpy(conclusionList[33], "Steering");
	strcpy(conclusionList[34], "Alignment");

	strcpy(conclusionList[35], "Alignment");
	strcpy(conclusionList[36], "Problem");
	strcpy(conclusionList[37], "wipers");
	strcpy(conclusionList[38], "Problem");
	strcpy(conclusionList[39], "Bulbs");

	/////////////Clause Variable List/////////////
	strcpy(clauseVarList[0], "Problem");

	//Battery
	strcpy(clauseVarList[1], "Problem");
	strcpy(clauseVarList[2], "NoStart");
	strcpy(clauseVarList[3], "NoFlicker");

	//Gas
	strcpy(clauseVarList[0], "Problem");
	strcpy(clauseVarList[0], "NoStart");
	strcpy(clauseVarList[0], "Lights");
	

	//alternator
	strcpy(clauseVarList[11], "Problem");
	strcpy(clauseVarList[12], "NoStart");
	strcpy(clauseVarList[13], "Lights");
	strcpy(clauseVarList[14], "Flicker");

	//oil
	strcpy(clauseVarList[17], "Problem");
	strcpy(clauseVarList[18], "Start");
	strcpy(clauseVarList[19], "Engine");

	//waterlevel
	strcpy(clauseVarList[22], "Problem");
	strcpy(clauseVarList[23], "Start");
	strcpy(clauseVarList[24], "heating");

	//fan
	strcpy(clauseVarList[27], "Problem");
	strcpy(clauseVarList[28], "Start");
	strcpy(clauseVarList[29], "FanSound");

	//car stalls
	strcpy(clauseVarList[32], "Problem");
	strcpy(clauseVarList[33], "Start");
	strcpy(clauseVarList[34], "Shift");
	strcpy(clauseVarList[35], "TransmissionFluid");

	//brakes
	strcpy(clauseVarList[38], "Problem");
	strcpy(clauseVarList[39], "Start");
	strcpy(clauseVarList[40], "NoBrake");

	strcpy(clauseVarList[41], "Start");
	strcpy(clauseVarList[42], "Brake");
	strcpy(clauseVarList[43], "Squeal");


	//Steering
	strcpy(clauseVarList[48], "Problem");
	strcpy(clauseVarList[49], "Start");
	strcpy(clauseVarList[50], "Shake");

	//wipers
	strcpy(clauseVarList[54], "Problem");
	strcpy(clauseVarList[55], "Start");
	strcpy(clauseVarList[56], "Streak");

	//brakeLights
	strcpy(clauseVarList[59], "Problem");
	strcpy(clauseVarList[60], "Start");
	strcpy(clauseVarList[61], "noHeadlights");


}

//Backward chaining
void determineSymptoms() {
	p = 0, t = 0;
	int choice;
	string battery, oil, gas, alternator, tranFl, align, tires, water, fan, wiper, bulbs, brakePads, brakeFluid;
	string problem, turnOn, flicker, engineFailure, carRun, heating, fanOn, stall, shift, brakes, lights, wipers, squeal, steering;
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
			strcpy(varTemp, "WeakBattery");
			strcpy(varTemp, "noFuel");
			strcpy(varTemp, "Alternator");
			checkMember();
			break;
		case 2:
			cout << "'Car Stalls'\n";
			strcpy(varTemp, "Alternator");
			strcpy(varTemp, "LowTransFluid");
			checkMember();
			break;
		case 3:
			cout << "'Car is heating up'\n";
			strcpy(varTemp, "noWater");
			strcpy(varTemp, "Fan");
			checkMember();
			break;
		case 4:
			cout << "'Car wont move'\n";
			strcpy(varTemp, "Alternator");
			strcpy(varTemp, "LowTransFluid");
			strcpy(varTemp, "OldOil");
			checkMember();
			break;
		case 5:
			cout << "'Breaks Squeal'\n";
			strcpy(varTemp, "Brakes");
			choice = 5;
			checkMember();
			break;
		case 6:
			cout << "'Steering wheel shakes'\n";
			choice = 6;
			strcpy(varTemp, "Alignment");
			strcpy(varTemp, "Tires");
			checkMember();
			break;
		case 7:
			cout << "You''ve chosen to exit. \n";
			main();
		}
//	} while (choice != NULL);
	
	
	while (choice != 7)
	{
	
		
		
		int ruleNum = 0;
		if (sn != 0)
		{
			while ((p != 1) && (sn != 0))
			{
				stackfunc();
				while (varTemp != NULL)
				{
					t = (statsk[sp] - 1) * 4 + clausk[sp];

					ruleNum = statsk[sp];
					cout << "Rule to check is " << statsk[sp] << "\n" << endl;
					strcpy(varTemp, clauseVarList[t]);
					//copy(begin(varTemp), end(clauseVarList), begin(varTemp));//////////////need change

					if (varTemp != NULL)
					{

						t = 1;
						cout << "checking the stack for current var  " << clausk[sp] << " of rule " << ruleNum << ": " << varTemp << "\n" << endl;
						checkMember();
						if (sn != 0)
						{

							cout << "Variable " << varTemp << " is a Member.  Time to check another rule \n" << endl;

						}
					}
					instance(problem, turnOn, flicker, engineFailure, carRun, heating, fanOn, stall, shift, brakes, tires, lights, wipers, squeal, steering);
					clausk[sp] ++;
				}
				sn = statsk[sp];
				z = 0;

				switch (sn)
				{
				case 1:
					if ((problem == "N") == 0)
						z = 1;
					break;
				case 2:
					if ((problem == "Y" && turnOn == "N" && flicker == "N"))
					{
						battery = "Y";
						z = 1;
					}
					break;
				case 3:
					if ((problem == "Y" && turnOn == "N" && flicker == "Y"))
					{
						alternator = "Y";
						z = 1;
					}
					break;
				case 4:
					if ((problem == "Y" && turnOn == "N" && carRun == "N"))
					{
						gas = "Y";
						z = 1;
					}
					break;
				case 5:
					if ((problem == "Y" && turnOn == "Y" && carRun == "N"))
					{
						oil = "Y";
						z = 1;
					}
					break;
				case 6:
					if ((problem == "Y" && turnOn == "Y" && heating == "Y" && fanOn == "N"))
					{
						fan = "Y";
						z = 1;
					}
					break;
				case 7:
					if ((problem == "Y" && turnOn == "Y" && heating == "Y" && fanOn == "Y"))
					{
						water = "Y";
						z = 1;
					}
					break;
				case 8:
					if ((problem == "Y" && turnOn == "Y" && stall == "Y" && shift == "N"))
					{
						tranFl = "Y";
						z = 1;
					}
					break;
				case 9:
					if ((problem == "Y" && turnOn == "Y" && brakes == "Y" && squeal == "Y"))
					{
						brakePads = "Y";
						z = 1;
					}
					break;
				case 10:
					if ((problem == "Y" && turnOn == "Y" && brakes == "N" && squeal == "N"))
					{
						brakeFluid = "Y";
						z = 1;
					}
				case 11:
					if ((problem == "Y" && turnOn == "Y" && steering == "Y"))
					{
						align = "Y";
						z = 1;
					}
					break;
				case 12:
					if ((problem == "Y" && turnOn == "Y" && lights == "N"))
					{
						bulbs = "Y";
						z = 1;
					}
					break;
				case 13:
					if ((problem == "Y" && turnOn == "Y" && wipers == "N"))
					{
						wiper = "Y";
						z = 1;
					}
					break;
				}
				if (z != 1)
				{
					t = statsk[sp];
					strcpy(varTemp, clauseVarList[t]);
					t = statsk[sp] + 1;

				}
			}
		}
	}
} while (choice != NULL);
	sp++;
	if (sp >= 40)
		cout << "all done here" << endl;

	else 
		clausk[sp] ++;
}


void checkMember()
{

	
		t = 0, sn = 0;
	t = z;
	while ((strcmp(varTemp, conclusionList[t]) != 0) && (t < 60))
		t++;

	if (strcmp(varTemp, conclusionList[t]) == 0) 
		sn = t;
	stackfunc();
	
}

void stackfunc()
{
	sn = t;
	//int clausenum[50];
	//int stack[50];


	sp--;
	statsk[sp] = sn;
	clausk[sp] = 1;
}
//creating an instance
void instance(string problem, string turnOn, string flicker, string engineFailure, string carRun, string heating, string fanOn, string stall, string shift, string brakes, string tires, string lights, string wipers, string squeal, string steering)
{	
	t = 1;

	while ((strcmp(varTemp, varList[t]) != 0) && (t < 60))
		t++;
	

	if ((strcmp(varTemp, varList[t]) == 0) && (instlt[t] != 1))
	{
		instlt[t] = 1;

		switch (t)
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

void print()
{
	cout << "\nHere is a summary of the variable list\n";
	t = 0;
	int p = 0;
	int temp = 0;
	while (t < 13)
	{
		cout <<"\t" << t <<") " << varList[t] << endl;
		t++;
		
	}
	t = 1;

	cout << "\n Here is the clause Variable List: \n ";
	for (t = 1; t < 17; t++) {
		cout << "Clause #" << t << ": \n";

		for ( p = 1; p < 5; p++)
		{
			temp = 4 * (t-1) + p;
			cout << "\t" << p << ") " << clauseVarList[temp] << endl;
		}
		cout << "\n";

	}

}
