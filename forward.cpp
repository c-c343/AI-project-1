#pragma warning(disable : 4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstring>

using namespace std;


int flag;
char cndvar[10][40];
char varlt[10][40]; /* variable list*/
char clvarlt[40][40]; /* clause var list */
char c[3], v[3]; /*variable */
char problem[50];
char repair[50];
char position[10]; /* position */
int instList[10]; /* instantiated list*/
int f, i, j, k, s, fp   /* front pointer */;
int  bp,  /* back pointer */  sn; /* statement number */
int cn;  /* clause number */
int choice;
void a_main();
void search();
void check_instantiation();
void instantiate();

void a_main() {

	cout << "\n Select the number corresponding to your problem: \n" << endl;
	cout << "1. Battery" << endl;
	cout << "2. Fuel" << endl;
	cout << "3. Alternator" << endl;
	cout << "4. Oil" << endl;
	cout << "5. Engine" << endl;
	cout << "6. Water Fluid" << endl;
	cout << "7. Transmission Fluid" << endl;
	cout << "8. Brakepads" << endl;
	cout << "9. Brake Fluid" << endl;
	cout << "10. Brakes" << endl;
	cout << "11. Alignment" << endl;
	cout << "12. Windshield Wipers" << endl;
	cout << "13. Lights" << endl;

	cin >> choice;



	/******** INITIALIZATION SECTION ***********/
	fp = 1;
	bp = 1;

	for (i = 1; i < 40; i++)
		strcpy(clvarlt[i], "");
	for (i = 1; i < 11; i++)
		strcpy(cndvar[i], "");
	for (i = 1; i < 11; i++)
		instList[i] = 0;
	for (i = 1; i < 11; i++)
		strcpy(varlt[i], "");
	for (i = 1; i < 11; i++)
	{
		strcpy(cndvar[i], "");
		strcpy(varlt[i], "");
		instList[i] = 0;
	}

	/* enter variables which are in the IF part, 1 at a time in
	the exact order that they occur. Up to 3 variables per
	IF statement. Do not duplicate any variable names. Any
	name is used only once. If no more variables left, just
	hit return key */
	/****** comment 367 *************/
	strcpy(varlt[1], "");
	strcpy(varlt[2], "");
	strcpy(varlt[3], "");
	strcpy(varlt[4], "");
	strcpy(varlt[5], "");

	printf("*** VARIABLE LIST ***\n");
	for (i = 1; i < 11; i++)
		printf("ENTER VARIABLE   %d   %s\n", i, varlt[i]);
	printf("HIT RETURN TO CONTINUE");
	getchar();

	/* enter variables as they appear in the IF clauses, Up to 3
	variables per IF statement. If no more variables left, just
	hit return key */
	/****** comment 407, 408 *************/
	strcpy(clvarlt[1], "problem");
	strcpy(clvarlt[5], "problem");
	strcpy(clvarlt[9], "problem");
	strcpy(clvarlt[13], "problem");
	strcpy(clvarlt[17], "problem");
	strcpy(clvarlt[18], "problem");
	printf("*** CLAUSE-VARIABLE LIST ***\n");
	for (i = 1; i < 9; i++)
	{
		printf("** CLAUSE %d\n", i);
		for (j = 1; j < 5; j++)
		{
			k = 4 * (i - 1) + j;
			printf("VARIABLE %d  %s\n", j, clvarlt[k]);
		}

		if (i == 4)
		{
			printf("HIT RETURN TO CONTINUE");
			getchar();
		}
	}

	/****** INFERENCE SECTION *****************/
	printf("ENTER CONDITION VARIABLE? ");
	cin >> c;

	/* place condition variable c on condition var queue cndvar */
	strcpy(cndvar[bp], c);
	/* move backpointer (bp) to back */
	bp = bp + 1;
	/* set the condition variable pointer consisting of the
	statement number (sn) and the clause number (cn) */
	sn = 1; cn = 1;
	/* find the next statement number containing the condition variable
	which is in front of the queue (cndvar), this statement number
	is located in the clause variable list (clvarlt) */
	/* start at the beginning */
	f = 1;


	search();
	/* point to first clause in statement */
	cn = 1;
	if (sn != 0)
		/* more statements */
	{
		/* locate the clause */
		i = 4 * (sn - 1) + cn;
		/* clause variable */
		strcpy(v, clvarlt[i]);
		/* are there any more clauses for this statement */
		while (strcmp(v, "") == 0)
			/* more clauses */
		{
			/* check instantiation of this clause */
			check_instantiation();
			cn = cn + 1;
			/* check next clause */
			i = 4 * (sn - 1) + cn;
			strcpy(v, clvarlt[i]);
		}

		/* no more clauses - check IF part of statement */
		s = 0;
		/* sample IF-THEN statements from the position knowledge base */
		switch (sn)
		{
			/* statement 1 */
			/***** comment 1500 *****/
		case 1:
			if (strcmp(problem, "Battery") == 0) s = 1;
			break;
			/* statement 2 */
			/***** comment 1510 *****/
		case 2:
			if (strcmp(problem, "Fuel") == 0) s = 1;
			break;
			/* statement 3 */
			/***** comment 1540 *****/
		case 3:
			if (strcmp(problem, "Alternator Issues") == 0) s = 1;
			break;
			/* statement 4 */
			/***** comment 1550 *****/
		case 4:
			if (strcmp(problem, "Oil") == 0) s = 1;
			break;
			/* statement 5 */
		case 5:
			if (strcmp(problem, "Engine") == 0)  s = 1;
			break;
			/* statement 6 */
		case 6:
			if (strcmp(problem, "Water Fluid") == 0) s = 1;
			break;
			/***** comment 1610 *****/
		case 7:
			if (strcmp(problem, "Transmission Fluid") == 0) s = 1;
			break;
		case 8:
			if (strcmp(problem, "Brakepads") == 0) s = 1;
			break;
		case 9:
			if (strcmp(problem, "Brake Fluid") == 0) s = 1;
			break;
		case 10:
			if (strcmp(problem, "Brakes") == 0) s = 1;
			break;
		case 11:
			if (strcmp(problem, "Alignment Issues") == 0) s = 1;
			break;
		case 12:
			if (strcmp(problem, "Windshield Wipers") == 0)  s = 1;
			break;
		case 13:
			if (strcmp(problem, "Lights") == 0) s = 1;
			break;
		default:
			cout << "Invalid" << endl;

		}

		/* see if the THEN part should be invoked, i.e., s=1 */
		if (s != 1)
		{
			f = sn + 1;
			search();
		}

		/* invoke THEN part */
		switch (sn)
		{
			/*********** comment 1500 ***********/
			/* put variable on the conclusion variable queue */
		case 1:
			strcpy(repair, "Replace your battery.");
			printf("Your battery must be replaced in order to repair your vehicle.");
			strcpy(v, "repair");
			instantiate();
			break;
			/*********** comment 1510 ***********/
			/* put variable on the conclusion variable queue */
		case 2:
			strcpy(repair, "Add fuel");
			printf("Your fuel must be replenished in order to operate your vehicle");
			strcpy(v, "repair");
			instantiate();
			break;
			/*********** comment 1540 ***********/
			/* put variable on the conclusion variable queue */
		case 3:
			strcpy(repair, "Replace alternator");
			printf("Your alternator must be replaced.");
			strcpy(v, "repair");
			instantiate();
			break;
			/*********** comment 1550 ***********/
			/* put variable on the conclusion variable queue */
		case 4:
			strcpy(repair, "Oil must be changed");
			printf("Change your oil in order to operate vehicle.");
			strcpy(v, "repair");
			instantiate();
			break;
			/* put variable on the conclusion variable queue */
		case 5:
			strcpy(repair, "Refill water level");
			printf("Water level must be refilled to repair the vehicle.");
			strcpy(v, "repair");
			instantiate();
			break;
		case 6:
			strcpy(position, "Transmission fluid filled");
			printf("Your transmission fluid must be refilled/replaced.");
			strcpy(v, "repair");
			instantiate();
			break;
			/*********** comment 1610 ***********/
		case 7:
			strcpy(position, "Replace brakepads");
			printf("Brakepads must be replaced in order to be able to stop vehicle.");
			strcpy(v, "repair");
			instantiate();
			break;
		case 8:
			strcpy(position, "Refill brake fluid");
			printf("Your brake fluid must be refilled.");
			strcpy(v, "repair");
			instantiate();
			break;
		case 9:
			strcpy(position, "Replace the rotors");
			printf("Replace your rotors in order to stop your brakes from grinding.");
			strcpy(v, "repair");
			instantiate();
			break;
		case 10:
			strcpy(position, "Replace your tires");
			printf("Put new tires on your car for a more smooth ride.");
			strcpy(v, "repair");
			instantiate();
			break;
		case 11:
			strcpy(position, "Fix the alignment");
			printf("Take your car in for an alignment adjustment.");
			strcpy(v, "repair");
			instantiate();
			break;
		case 12:
			strcpy(position, "Replace windshield wipers");
			printf("Install new windshield wipers for your vehicle.");
			strcpy(v, "repair");
			instantiate();
			break;
		case 13:
			strcpy(position, "Replace light bulb");
			printf("Remove the light and replace the bulb for your vehicle.");
			strcpy(v, "repair");
			instantiate();
			break;
		default:
			cout << "Invalid choice, please enter a number corresponding to the menu." << endl;
		}
		f = sn + 1;
		search();
	}

	/* no more clauses in the clause variable list (clvarlt)
	containing the variable in front of the queue (cndvar(fp))
	then remove front variable (cndvar(fp)) and replace it by
	the next variable (cndvar(fp+1)). If no more variables are
	at the front of the queue, stop. */
	/* next queue variable */
	fp = fp + 1;
	if (fp < bp)
	{
		/* check out the condition variable */
		f = 1;
		search();
	}
	/* no more conclusion variables on queue */



}



//==========================================================================
/* Routine to instantiate a variable (v) if it isn't already.
The instantiate indication (instlt) is a 0 if not, a 1 if it is.
The vriable list (varlt) contains the variable (v) */
void check_instantiation()
{
	i = 1;

	/* find variable in the variable list */
	while ((strcmp(v, varlt[i]) != 0) && (i <= 10)) i = i + 1;

	/* check if already instantiated */
	if (instList[i] != 1)
	{
		/* mark instantiated */
		instList[i] = 1;
		/* the designer of this knowledge base places the input
		statements to instantiate the variables in this case
		statement */

		switch (i)
		{
			/* input statements for sample position knowledge base */
		case 1:
			cout << "Executing rule 1." << endl;
			strcpy(problem, "Battery");
			break;
		case 2:
			cout << "Executing rule 2." << endl;
			strcpy(problem, "Fuel");
			break;
		case 3:
			cout << "Executing rule 3." << endl;
			strcpy(problem, "Alternator");
			break;
		case 4:
			cout << "Executing rule 4." << endl;
			strcpy(problem, "Oil");
			break;
		case 5:
			cout << "Executing rule 5." << endl;
			strcpy(problem, "Engine");
			break;
		case 6:
			cout << "Executing rule 6." << endl;
			strcpy(problem, "Water Fluid");
			break;
		case 7:
			cout << "Executing rule 7." << endl;
			strcpy(problem, "Transmission Fluid");
			break;
		case 8:
			cout << "Executing rule 8." << endl;
			strcpy(problem, "Brakepads");
			break;
		case 9:
			cout << "Executing rule 9." << endl;
			strcpy(problem, "Brake Fluid");
			break;
		case 10:
			cout << "Executing rule 10." << endl;
			strcpy(problem, "Brakes");
			break;
		case 11:
			cout << "Executing rule 11." << endl;
			strcpy(problem, "Alignment");
			break;
		case 12:
			cout << "Executing rule 12." << endl;
			strcpy(problem, "Windshield Wipers");
			break;
		case 13:
			cout << "Executing rule 13." << endl;
			strcpy(problem, "Lights");
			break;
		default:
			cout << "Error" << endl;
		}
	}
	/* end of input statements for the position knowledge base */
}


//==========================================================================
/* Search clause variable list for a variable (clvarlt) equal to the
one in front of the conclusion queue (cndvar). Return the statement
number (sn). If there is no match, i.e., sn=0, the first statement
for the space is f. */
void search()
{
	flag = 0;
	sn = f;

	while ((flag == 0) && (sn <= 10))
	{
		cn = 1;
		k = (sn - 1) * 4 + cn;
		while ((strcmp(clvarlt[k], cndvar[fp]) != 0) && (cn < 4))
		{
			cn = cn + 1;
			k = (sn - 1) * 4 + cn;
		}

		if (strcmp(clvarlt[k], cndvar[fp]) == 0) flag = 1;
		if (flag == 0) sn = sn + 1;
	}
	if (flag == 0) sn = 0;
}


//==========================================================================
/* Routine to instantiate a variable (v) and then place it on the
back of the queue (cndvar[bp]), if it is not already there. */
void instantiate()
{
	i = 1;
	/* find variable in the variable list (varlt) */
	while ((strcmp(v, varlt[i]) != 0) && (i <= 10)) i = i + 1;

	/* instantiate it */
	instList[i] = 1;
	i = 1;

	/* determine if (v) is or already has been on the queue (cndvar) */
	while ((strcmp(v, cndvar[i]) != 0) && (i <= 10)) i = i + 1;
	/* variable has not been on the queue. Store it in the back of the queue */
	if (strcmp(v, cndvar[i]) != 0)
	{
		strcpy(cndvar[bp], v);
		bp = bp + 1;
	}
}

