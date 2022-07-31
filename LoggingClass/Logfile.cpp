#include "Logfile.hpp"
#include <iostream>
#include <stdarg.h>

/* Constructor
* 
* 
* 
*/
CLogfile::CLogfile()
{
    g_plogfile->CreateLogfile("Logfile.html");
}

/*
*  Destructor
* 
*  Usage: Mentions that class was deleted and closes logfile    
*/
CLogfile::~CLogfile()
{

    Textout("<br><br>End of logfile</font></body></html>");
    fclose(m_Logfile);

}

/*
*  CreateLogfile
* 
*  Usage: Create Logfile and write head
*/
void CLogfile::CreateLogfile(const char* LogName)
{

    //Empty Logfile and write head
    fopen_s(&m_Logfile, LogName, "w");
    if (m_Logfile != NULL) {
        Textout("<hml><head><title>Logfile</title></head>");
        Textout("<body><font face='courier new'>");
        WriteTopic("Logfile", 3);

        // Write current build configuration
#ifdef _DEBUG
        Textout("BUILD: DEBUG<br>");
#else
        Textout("BUILD: RELEASE<br>");
#endif

        // Link for email-adress 
        Textout("<a href='mailto:StefanOdermattET@hotmail.com?subject=Logfile'>");
        Textout("Send E-Mail for support</a><br><br>");

        // Close Logfile and reopen with append
        fclose(m_Logfile);
        fopen_s(&m_Logfile, LogName, "a");
    }
    else
    {
        // I/O Error has occured
        /* Not Handled yet */
    }
}

/* Write Topic
* 
* Usage: create headline
*/
void CLogfile::WriteTopic(const char* Topic, int Size)
{
    // Überschrift schreiben und flushen
    Textout("<table cellspacing='0' cellpadding='0' width='100%%' ");
    Textout("bgcolor='#DFDFE5'>\n<td>\n<font face='arial' ");
    fTextout("size='+%i'>", Size);
    Textout(Topic);
    Textout("</font>\n</td>\n</tr>\n</table>\n<br>");
    fflush(m_Logfile);


}

/* Textout
* 
*  Usage: write text to logfile (black)
* 
*/
void CLogfile::Textout(const char* Text)
{
    // write text and flush
    fprintf(m_Logfile, Text);
    fflush(m_Logfile);

}

/* Textout
* 
*  Usage: write text to logfile (colorful)
*/
void CLogfile::Textout(int Color, const char* Text)
{
    Textout(Color, false, Text);
}

/* Textout
* 
*  Usage: write text to logfile (colorful, table)
*/
void CLogfile::Textout(int Color, bool List, const char* Text)
{
    // write list tag
    if (List == true)
    {
        Textout("<li>");
    }

    // write color tag
    switch (Color)
    {
    case BLACK:
        Textout("<font color=black>"); break;
    case RED:
        Textout("<font color=red>"); break;
    case GREEN:
        Textout("<font color=green>"); break;
    case BLUE:
        Textout("<font color=blue>"); break;
    case PURPLE:
        Textout("<font color=purple>"); break;
    default:
        Textout("<font color=black>"); break;
    }

    // write text
    Textout(Text);
    Textout("</font>");

    if (List == false)
    {
        Textout("<br>");
    }
    else
    {
        Textout("</li>");
    }

}

/* fTextout
* 
*  Usage: write text in to logfile like printf (black)
* 
*/
void CLogfile::fTextout(const char* Text, ...)
{
    char buffer[MAX_BUFFER];   // char-Buffer
    va_list pArgList;           // List der übergebenen Argumente

    // String aus den Argumenten erstellen
    va_start(pArgList, Text);
    vsprintf_s(buffer, Text, pArgList);
    va_end(pArgList);

    //write string
    Textout(buffer);


}
/* fTextout
* 
*  Usage: write text in to logfile like printf(colorful)
* 
*/
void CLogfile::fTextout(int Color, const char* Text, ...)
{
    char buffer[MAX_BUFFER];   // char-Buffer
    va_list pArgList;           // List der übergebenen Argumente

    // String aus den Argumenten erstellen
    va_start(pArgList, Text);
    vsprintf_s(buffer, Text, pArgList);
    va_end(pArgList);

    // write string with color
    Textout(Color, buffer);

}

/* fTextout
*
*  Usage: write text in to logfile like printf(colorful table)
*
*/
void CLogfile::fTextout(int Color, bool List, const char* Text, ...)
{
    char buffer[MAX_BUFFER];   // char-Buffer
    va_list pArgList;           // List der übergebenen Argumente

    // String aus den Argumenten erstellen
    va_start(pArgList, Text);
    vsprintf_s(buffer, Text, pArgList);
    va_end(pArgList);

    // write string with color
    Textout(Color, List, buffer);

}

/* FunctionResult
* 
*  Usage: write ok or error for functioncall
* 
*/
void CLogfile::FunctionResult(const char* Name, bool Result)
{
    if (L_OK == Result)
    {
    Textout("<table width='100%%' cellSpacing='1' cellPadding='5'");
    Textout(" border='0' bgcolor='#C0C0C0'><tr><td bgcolor=");
    fTextout("'#FFFFFF' width='35%%'>%s</TD>", Name);
    Textout("<td bgcolor='#FFFFFF' width='30%%'><font color =");
    Textout("'green'>OK</FONT></TD><td bgcolor='#FFFFFF' ");
    Textout("width='35%%'>-/-</TD></tr></table>");
    }
    else
    {
    Textout("<table width='100%%' cellSpacing='1' cellPadding='5'");
    Textout(" border='0' bgcolor='#C0C0C0'><tr><td bgcolor=");
    fTextout("'#FFFFFF' width='35%%'>%s</TD>", Name);
    Textout("<td bgcolor='#FFFFFF' width='30%%'><font color =");
    Textout("'red'>ERROR</FONT></TD><td bgcolor='#FFFFFF' ");
    Textout("width='35%%'>-/-</TD></tr></table>");
    }

}


