/**
* \file Exception.h
* \author Marcin Dyrcz
* \version 1.0
* \brief Definicja klasy Exception pozwalajacej obslugiwac wyjatki(bledy)
*/
// -------------------------------------------------------------------------

#ifndef EXCEPTION
#define EXCEPTION
// --------------------------------------------------------------

#include <iostream>
#include <string.h>

using namespace std;

// --------------------------------------------------------------

/**
* \class Exception
* \author Marcin Dyrcz
* \brief Definicja klasy Exception pozwalajacej wychwytywac wyjatki(bledy)
*/
class Exception
{
  private:

    int _errorCode;         ///Przechowuje kod bledu
    int _errorLine;         ///Przechowuje linie bledu(w pliku)
    string _errorMessage;    ///Przechowuje wiadomosc o bledzie(dla uzytkownika)
    string _errorFile;       ///Przechowuje nazwe pliku gdzie wystapil blad

    /// \brief Resetuje parametry bledu
    ///
    /// \return brak zwaracanej wartosci
    void reset(void);

  public:

    /// \brief Konstruktor domyslny
    Exception(void);

    /// \brief Konstruktor kopiujacy
    ///
    /// \param __other - obiekt
    Exception(Exception const &__other);

    /// \brief Konstruktor z parametrami
    ///
    /// \param __errorCode - kod bledu
    /// \param __errorLine - linia gdzie wystapil blad
    Exception(int __errorCode, int __errorLine);

    /// \brief Konstruktor z parametrami
    ///
    /// \param __errorCode - kod bledu
    /// \param __errorMessage - wiadomosc o bledzie dla uzytkownika
    Exception(int __errorCode, string __errorMessage);

    /// \brief Konstruktor z parametrami
    ///
    /// \param __errorFile - nazwa pliku gdzie wystapil blad
    /// \param __errorLine - linia w ktorej wystapil blad
    Exception(string __errorFile, int __errorLine);

    /// \brief Konstruktor z parametrami
    ///
    /// \param __errorCode - kod bledu
    /// \param __errorMessage - wiadomosc o bledzie dla uzytkownika
    /// \param __errorFile - nazwa pliku gdzie wystapil blad
    /// \param __errorLine - linia w ktorej wystapil blad
    Exception(int __errorCode, string __errorMessage, string __errorFile, int __errorLine);

    /// \brief Destructor
    ~Exception(void);

    /// \brief  zwaraca kod bledu
    ///
    /// \return Wartosc pola _errorCode
    int errorCode(void) const;

    /// \brief  zwaraca linie w ktorej wystapil blad
    ///
    /// \return Wartosc pola the _errorLine
    int errorLine(void) const;

    /// \brief zwraca wiadomosc o bledzie dla uzytkownika
    ///
    /// \return nowa wartosc pola _errorMessage
    string errorMessage(void) const;

    /// \brief zwaraca nazwe pliku w ktorym wystapil blad
    ///
    /// \return Wartosc pola _errorFile
    string errorFile(void) const;

    /// \brief ustawia numer lini w ktrej wystapil blad
    ///
    /// \param __errorLine - nowa wartosc pola _errorLine
    /// \return brak zwaracanej wartosci
    void setErrorLine(int __errorLine);

    /// \brief ustawia kod bledu
    ///
    /// \param __errorCode - nowa wartosc pola _errorCode
    /// \return brak zwracanej wartosci
    void setErrorCode(int __errorCode);

    /// \brief ustawia wiadomosc o bledzie
    ///
    /// \param __errorMessage - nowa wartosc pola _errorMessage
    /// \return brak zwracanej wartosci
    void setErrorMessage(string __errorMessage);

    /// \brief ustawia nazwe pliku w ktorym wystapil blad
    ///
    /// \param __errorFile - nowa wartosc pola _errorFile
    /// \return brak zwaracnej wartosci
    void setErrorFile(string __errorFile);

    /// \brief operator przypisania
    ///
    /// \param __other - obiekt
    /// \return referencja do obiektu
    Exception &operator=(Exception const &__other);
};
// --------------------------------------------------------------

/// \brief przeladowany operator << wpisuje parametry bledu na podane wyjscie
///
/// \param __out -podany strumien (display, file, etc.)
/// \param __exception - referencja do obektu
/// \return zwraca referencje do podanego strumienia
ostream &operator<<(ostream &__out, Exception &__exception);
// --------------------------------------------------------------

#endif
