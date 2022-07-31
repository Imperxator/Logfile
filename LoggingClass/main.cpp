// Simple Tests for logfile

#include <iostream>
#include "Logfile.hpp"

using namespace std;

// main
/*
* use <br> html tag for newline
*/
int main()
{
	// variables
	//
	float controll = 123.456f;	// variable for testing

	// create new Logfile
	g_plogfile->CreateLogfile("Logfile.html");

	// create header
	g_plogfile->WriteTopic("Not formated text", 2);

	// print text
	g_plogfile->Textout("normal, black text<br>");
	g_plogfile->Textout(RED, "colorful text");
	g_plogfile->Textout(BLUE, "colorful text in list(1)");
	g_plogfile->Textout(BLUE, "colorful text in list(2)");
	g_plogfile->Textout(BLUE, "colorful text in list(3)");

	// create another header
	g_plogfile->WriteTopic("formated text", 2);

	// print text
	g_plogfile->fTextout("controll variable: %f<br>", controll);
	g_plogfile->fTextout(RED, "controll variable: %f<br>", controll);
	g_plogfile->fTextout(GREEN, true, "list controll: %f", controll);
	g_plogfile->fTextout(GREEN, true, "list controll: %f", controll*2.0f);
	g_plogfile->fTextout(GREEN, true, "list controll: %f", controll*4.0f);

	// Function test
	g_plogfile->FunctionResult("Function one", L_OK);
	g_plogfile->FunctionResult("Function two", L_FAIL);

	// close logfile
	g_plogfile->Del();         

	return 0;
}