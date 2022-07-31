#ifndef __CLOGFILE
#define __CLOGFILE

// includes
//
#include <Windows.h>
#include <stdio.h>
#include "Singletone.hpp"

// defines
#define MAX_BUFFER 1024				// max datalength for buffer
#define L_FAIL false				// function failed
#define L_OK true					// function had no errors
#define g_plogfile CLogfile::Get () // makro for easy singelton access

// colours for text
enum FONTCOLORS
{
	BLACK,
	RED,
	GREEN,
	BLUE,
	PURPLE

};

// class declarations
class CLogfile : public TSingleton<CLogfile>
{
	
	// Member functions
public:

	CLogfile();
	~CLogfile();

	void CreateLogfile(const char* LogName);
	void WriteTopic(const char* Topic, int Size);
	void Textout(const char* Text);
	void Textout(int Color, const char* Text);
	void Textout(int Color, bool List, const char* Text);
	void fTextout(const char* Text, ...);
	void fTextout(int Color, const char* Text, ...);
	void fTextout(int Color, bool List, const char* Text, ...);
	void FunctionResult(const char* Name, bool Result);

	// Member variable
private:

	FILE* m_Logfile;

};

#endif
