/**
* \file Vec.h
* \author Marcin Dyrcz
* \version 1.0
* \brief Plik zawiera deklaracje klasy Vector
*/
// -------------------------------------------------------------------------

#ifndef VECTOR
#define VECTOR

#include "Container.h"
#include <iostream>
// -------------------------------------------------------------------------

/**
* \class Vector
* \author Marcin Dyrcz
* \brief Klasa przechowujaca elementy w tablicy w 'bezpieczny' sposob
*/
template <typename T> class Vector : public Container<T>
{
  public:
    T *tab; ///< tablica przechoujaca elementy zadanego typu
    int length; ///< ilosc elementow w tablicy tab

    /// \brief Konstruktor domyslny klasy
    Vector()
    {
        tab = NULL;
        length = 0;
    }

    /// \brief Destruktor klasy
    ~Vector()
    {
        delete[] tab;
    }

    /// \brief Konstruktor kopiujacy klasy
    ///
    /// \param ToCopy - obiekt klasy Container z ktorego bedziemy kopiowac
    Vector<T>(const Container<T> &ToCopy)
    {
        tab = NULL;
        length = 0;

        for (int i = 0; i < ToCopy.size(); ++i)
        {
            this->append(ToCopy.at(i));
        }
    }

    /// \brief Funkcja wstawiajaca nowy element do tablicy w podanym indeksie
    ///
    /// \param inputt - obiekt ktory chcemy dodac
    /// \param index - miejscce w tablicy w ktorym chcemy dodac element
    /// \return true jesli dodawanie sie powiodlo, false jesli nie
    bool insert(int index, T const &inputt)
    {
        if (index > length || index < 0)
        {
            return false;
        }
        else
        {
            T *newTab = new T[++length];  //preinkrementacja length!

            for (int i = 0; i < index; ++i) { newTab[i] = tab[i]; }
            newTab[index] = inputt;
            for (int i = index + 1; i < length; ++i) { newTab[i] = tab[i - 1]; }

            delete[] tab;
            tab = newTab;

            return true;
        }
    }

    /// \brief Funkcja zwracajaca element z podanego miejsca tablicy
    ///
    /// \param a - numer indeksu elementu ktory chcemy uzyskac
    /// \return element o zadanym indeksie
    T &at(int a) const
    {
        if (a < 0)
        {
            Exception exep(0, "Nie moge zwrocic elementu tablicy o ujemnym indeksie!", __FILE__, __LINE__);
            throw exep;
        }
        if (a >= size())
        {
            Exception exep(1, "Nie moge zwrocic elementu tablicy o za duzym indeksie!", __FILE__, __LINE__);
            throw exep;
        }
        return tab[a];
    }

    /// \brief Funkcja zwracajaca ilosc elementow tablicy
    int size(void) const
    {
        return this->length;
    }

    /// \brief Funkcja usuwajaca element tablicy o podanym indeksie
    ///
    /// \param index - indeks elementu ktory chcemy usunac z tablicy
    /// \return true jesli usuwanie sie powiodlo, false jesli nie
    bool remove(int index)
    {
        if (index >= length || index < 0)
        {
            return false;
        }
        else
        {
            T *newTab = new T[--length];  //Uwaga predekrementacja length!

            for (int i = 0; i < index; ++i) { newTab[i] = tab[i]; }
            for (int i = index; i < length; ++i) { newTab[i] = tab[i + 1]; }

            delete[] tab;
            tab = newTab;

            return true;
        }
    }

    /// \brief Operator przypisania
    ///
    /// \param ex - element klasy Vector ktory chcemy przypisac
    /// \return wskaznik na obiekt po wykonaniu przypisania
    Vector &operator= (Vector const &ex)
    {
        Vector<T> tmp;

        for (int i = 0; i < ex.size(); i++)
        {
            tmp.append(ex.at(i));
        }

        int sz = ex.size();

        this->clear();

        for (int i = 0; i < sz; i++)
        {
            this->append(tmp.at(i));
        }

        return *this;
    }
};
// -------------------------------------------------------------------------
#endif
