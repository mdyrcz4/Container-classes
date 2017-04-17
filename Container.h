/**
* \file Container.h
* \author Marcin Dyrcz
* \version 1.0
* \brief Szablon klasy bazowej, od której beda sie wywodzic pozostale klasy pojemnikowe
*/
// -------------------------------------------------------------------------
#ifndef CONTAINER
#define CONTAINER
// --------------------------------------------------------------

#include <iostream>

using namespace std;

// --------------------------------------------------------------

/**
* \class Container
* \author Marcin Dyrcz
* \brief Szablon klasy bazowej, od której beda sie wywodzic pozostale klasy pojemnikowe
*/

template <typename T>
class Container
{
  public:
    Container()
    {
        ;
    }

    Container(const Container &ToCopy)
    {
        for (int i = 0; i < ToCopy.size(); ++i)
        {
            this->append(ToCopy.at(i));
        }
    }

    /// \brief Operator przypisania
    ///
    /// \param ex - obiekt zrodlowy
    /// \return referencja do tego obiektu
    Container &operator= (Container const &ex)
    {
        T *tmpTab = new T[ex.size()]; /*Tablica pomocnicza, aby przechowac wartosci kontenera ex (konieczna w przypadku przypisania kontenera do jego samego*/

        for (int i = 0; i < ex.size(); ++i) /*Zczytanie wartosci do tablicy*/
        {
            tmpTab[i] = ex.at(i);
        }

        int Size = ex.size(); /* Zapamietanie dlugosci, przed wyczyszczeniem kontenera */
        this->clear();

        for (int i = 0; i < Size; ++i) /* Przepisanie wartosci z tablicy do obiektu */
        {
            this->append(tmpTab[i]);
        }

        delete[] tmpTab;

        return *this;
    }

    /// \brief Funkcja dodajaca element na koniec kontenera
    ///
    /// \param element - element, ktory ma byc dodany
    /// \return nie zwraca nic
    void append(T const &element)
    {
        insert(size(), element);
    }

    /// \brief Wirtualna funkcja wstawiajaca element na zadany indeks
    ///
    /// \param index - index, na ktory ma byc dodanie
    /// \param inputt - element na wejsciu
    /// \return zwraca 0, jesli nie da sie wstawic, 1 jesli sie da
    virtual bool insert(int index, T const &inputt) = 0;

    /// \brief Funkcja podmieniajaca element na zadanym indeksie
    ///
    /// \param index - index, na ktorym ma byc podmiana
    /// \param element - element, na ktory ma byc zamieniony
    /// \return zwraca 0, jesli nie da sie zamienic, 1 jesli sie da
    bool replace(int index, T const &element)
    {
        if ((index < 0) || (index >= size()) )
        {
            return false;
        }
        else
        {
            remove(index);
            insert(index, element);
            return true;
        }
    }

    /// \brief Wirtualna funkcja zwracajaca element kontenera o podanym indeksie
    ///
    /// \param a - index elementu, ktory ma byc zwrocony
    /// \return zwraca element o podanym indeksie
    virtual T &at(int a) const = 0;

    /// \brief Wirtualna funkcja zwracajaca ilosc elementow w kontenerze
    ///
    /// \return zwraca liczbe calkowita okreslajaca ilosc elementow w kontenerze
    virtual int size(void) const = 0;

    /// \brief Wirtualna funkcja usuwajaca element o zadanym indeksie
    ///
    /// \param index - index, gdzie ma nastapic usuniecie
    /// \return zwraca 0, jesli nie da sie usunac, 1 jesli sie da
    virtual bool remove(int index) = 0;

    /// \brief Funkcja czyszczaca kontener z elementow
    ///
    /// \return nie zwraca nic
    void clear(void)
    {
        while (size()) { remove(size() - 1); } /* Usuwanie ostatniego elementu, dopoki kontener nie jest pusty */
    }

    /// \brief Funkcja sprawdzajaca czy kontener jest pusty
    ///
    /// \return zwraca 0, jesli kontener nie jest pusty, 1 jesli kontener jest pusty
    bool isEmpty(void)
    {
        if (size() == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    /// \brief Szukanie elementu od zadanej pozycji
    ///
    /// \param _value - Szukana wartosc
    /// \param _from - Odkad ma szukac
    /// \return Zwraca -1 jesli nie znajdzie elementu lub index znalezionego elementu
    int indexOf(T const &_value, int _from = 0) const
    {
        for (int i = _from; i < size(); i++)
        {
            if (_value == at(i))
            {
                return i;
                break; /* Szuka do napotkania pierwszego wyst¹pienia */
            }
        }

        return -1;
    }

    /// \brief Sprawdzanie czy kontener zawiera podany element
    ///
    /// \param _value - Szukana wartosc
    /// \param _from - Odkad ma szukac
    /// \return Zwraca 0 jesli nie znajdzie elementu lub 1 jesli znajdzie
    bool contains(T const &_value, int _from = 0) const
    {
        int is_found = indexOf(_value, _from); /* Wykorzystanie funkcji indexOf */

        if (is_found == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    /// \brief Operator porownania
    ///
    /// \param right - Kontener po prawej stronie operatora
    /// \return Zwraca 1 jesli kontenery sa rowne lub 0 jesli nie sa rowne
    bool operator==(Container<T> const &right)
    {
        if (this->size() != right.size())
        {
            return false;
        }
        else
        {
            for (int i = 0; i < size(); ++i)
            {
                if (this->at(i) != right.at(i)) { return false; }
            }
        }

        return true;
    }

    /// \brief Operator "rozny od"
    ///
    /// \param right - Kontener po prawej stronie operatora
    /// \return Zwraca 0 jesli kontenery sa rowne lub 1 jesli nie sa rowne
    bool operator!=(Container<T> const &right)
    {
        return !((*this) == right); /* ...Wykorzystujac porownanie */
    }

    /// \brief Operator []
    ///
    /// \param n - Indeks interesujacego nas elementu
    /// \return Zwraca element o indeksie n.
    T &operator[](int n) const
    {
        return this->at(n);
    }

    /// \brief Operator += z kontenerem po prawej
    ///
    /// \param right - Kontener po prawej stronie operatora
    /// \return Zwraca referencje do tego obiektu
    Container<T> &operator+=(Container<T> const &right)
    {
        if (this == &right)
        {
            int currentSize = this->size();

            for (int i = 0; i < currentSize; i++)
            {
                this->append(right.at(i));
            }
        }

        for (int i = 0; i < right.size(); i++)
        {
            this->append(right.at(i));
        }

        return *this;
    }

    /// \brief Operator += z pojedynczym elementem po prawej
    ///
    /// \param element - element po prawej
    /// \return Zwraca referencje do tego obiektu
    Container<T> &operator+=(T const &element)
    {
        this->append(element);

        return *this;
    }

    /// \brief Operator << z kontenerem po lewej
    ///
    /// \param element - element po prawej
    /// \return Zwraca referencje do tego obiektu
    Container<T> &operator<<(T const &element)
    {
        *this += element;

        return *this;
    }

    /// \brief Operator << z pojedynczym elementem po prawej
    ///
    /// \param right - Kontener po prawej stronie operatora
    /// \return Zwraca referencje do tego obiektu
    Container<T> &operator<<(Container<T> const &right)
    {
        *this += right;

        return *this;
    }

    /// \brief Operator wypisania na strumien
    ///
    /// \param output - Strumien, na ktory ma zostac wypisany kontener
    /// \param right - Kontener, ktory ma byc wypisany
    /// \return Zwraca strumien, na ktory wypisalismy
    friend ostream &operator<<(ostream &output, Container<T> const &right) /* Wypisanie na strumien */
    {
        for (int i = 0; i < right.size(); ++i)
        {
            output << "Element " << i << ": " << right.at(i) << '\n';
        }
        return output;
    }
};

#endif
