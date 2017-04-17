#include <iostream>
#include <string.h>
// --------------------------------------------------------------
using namespace std;
// --------------------------------------------------------------

#include "Exception.h"
// --------------------------------------------------------------

Exception::Exception(void)
{
    reset();
}
// --------------------------------------------------------------

Exception::Exception(Exception const &__other)
{
    reset();
    setErrorCode(__other.errorCode());
    setErrorLine(__other.errorLine());
    setErrorMessage(__other.errorMessage());
    setErrorFile(__other.errorFile());
}
// --------------------------------------------------------------

Exception::Exception(int __errorCode, int __errorLine)
{
    reset();
    setErrorCode(__errorCode);
    setErrorLine(__errorLine);
}
// --------------------------------------------------------------

Exception::Exception(int __errorCode, string __errorMessage)
{
    reset();
    setErrorCode(__errorCode);
    setErrorMessage(__errorMessage);
}
// --------------------------------------------------------------

Exception::Exception(string __errorFile, int __errorLine)
{
    reset();
    setErrorLine(__errorLine);
    setErrorFile(__errorFile);
}
// --------------------------------------------------------------

Exception::Exception(int __errorCode, string __errorMessage, string __errorFile, int __errorLine)
{
    reset();
    setErrorCode(__errorCode);
    setErrorLine(__errorLine);
    setErrorMessage(__errorMessage);
    setErrorFile(__errorFile);
}
// --------------------------------------------------------------

Exception::~Exception(void)
{
    reset();
}
// --------------------------------------------------------------

void Exception::reset(void)
{
    _errorMessage = "";
    _errorFile = "";
    _errorLine = -1;
    _errorCode = -1;
}
// --------------------------------------------------------------

int Exception::errorCode(void) const
{
    return _errorCode;
}
// --------------------------------------------------------------

int Exception::errorLine(void) const
{
    return _errorLine;
}
// --------------------------------------------------------------

string Exception::errorMessage(void) const
{
    return _errorMessage;
}
// --------------------------------------------------------------

string Exception::errorFile(void) const
{
    return _errorFile;
}
// --------------------------------------------------------------

void Exception::setErrorLine(int __errorLine)
{
    _errorLine = __errorLine;
}
// --------------------------------------------------------------

void Exception::setErrorCode(int __errorCode)
{
    _errorCode = __errorCode;
}
// --------------------------------------------------------------

void Exception::setErrorMessage(string __errorMessage)
{
    _errorMessage = __errorMessage;
}
// --------------------------------------------------------------

void Exception::setErrorFile(string __errorFile)
{
    _errorFile = __errorFile;
}
// --------------------------------------------------------------

Exception &Exception::operator=(Exception const &__other)
{
    reset();

    setErrorCode(__other.errorCode());
    setErrorLine(__other.errorLine());
    setErrorMessage(__other.errorMessage());
    setErrorFile(__other.errorFile());

    return *this;
}
// --------------------------------------------------------------

ostream &operator<<(ostream &__out, Exception &__exception)
{
    __out << "Error in " << __exception.errorFile() << " file at " << __exception.errorLine() << " line.\nError code: " << __exception.errorCode() << " (" << __exception.errorMessage() << ").";
    return __out;
}
// --------------------------------------------------------------
