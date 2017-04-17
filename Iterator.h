/**
* \file Iterator.h
* \author Marcin Dyrcz
* \version 1.0
* \brief Plik zawiera deklaracje klasy Iterator, ktora umozliwia iterowanie po kontenerach dziedziczacych po klasie Container
*/
// -------------------------------------------------------------------------

#ifndef ITERATOR
#define ITERATOR

#include "Container.h"

// -------------------------------------------------------------------------

/**
* \class Iterator
* \author Marcin Dyrcz
* \brief Klasa Iterator, ktora umozliwia iterowanie po kontenerach dziedziczacych po klasie Container
*/

template <typename T>
class Iterator
{
  public:
    Container<T> *container; ///< Kontener, z ktorym zwiazany jest iterator
    int index; ///< Index elementu w kontenerze, na ktory wskazuje iterator

    /// \brief Konstruktor domyslny klasy
    Iterator()
    {
        container = NULL;
        index = 0;
    }

    /// \brief Konstruktor parametrowy klasy
    ///
    /// \param _container - kontener, z ktorym zwiazujemy iterator
    Iterator(Container<T> *_container)
    {
        container = _container;
        index = 0;
    }

    /// \brief Funkcja, ktora zwraca iterator pokazujacy na pierwszy element w pojemniku.
    ///
    /// \return Iterator pokazujacy na pierwszy element w pojemniku.
    Iterator first()
    {
        Iterator to_return(this->container);

        return to_return;
    }

    /// \brief Funkcja, ktora zwraca iterator pokazujacy na ostatni element w pojemniku.
    ///
    /// \return Iterator pokazujacy na ostatni element w pojemniku.
    Iterator last()
    {
        Iterator to_return(this->container);
        to_return.index = container->size() - 1;
        return to_return;
    }

    /// \brief Funkcja, ktora przesuwa iterator na nastepny element.
    ///
    /// \return Referencja do iteratora pokazujacego na nastepny element.
    Iterator &next()
    {
        index++;
        return *this;
    }

    /// \brief Funkcja, ktora przesuwa iterator na poprzedni element.
    ///
    /// \return Referencja do iteratora pokazujacego na poprzedni element.
    Iterator &prev()
    {
        index--;
        return *this;
    }

    /// \brief Funkcja, ktora zwraca aktualnie pokazywany element w pojemniku, oraz umozliwia zmiane wartosci tego elementu
    ///
    /// \return Referencja do obiektu aktualnie pokazywanego przez iterator.
    T &current()
    {
        if ((index < container->size()) && (index >= 0))
        {
            return container->at(index);
        }
        else
        {
            Exception exep(0, "Out of bounds!", __FILE__, __LINE__);
            throw exep;
        }
    }

    /// \brief Funkcja, ktora przenosi iterator na pierwszy element w pojemniku.
    ///
    /// \return Referencja do iteratora pokazujacego na pierwszy element.
    Iterator &atFirst()
    {
        index = 0;
        return *this;
    }

    /// \brief Funkcja, ktora przenosi iterator na ostatni element w pojemniku.
    ///
    /// \return Referencja do iteratora pokazujacego na ostatni element.
    Iterator &atLast()
    {
        index = container->size() - 1;
        return *this;
    }

    /// \brief Funkcja, ktora zwraca ilosc elementow od aktualnie pokazywanego do ostatniego elementu w pojemniku.
    ///
    /// \return Ilosc elementow od aktualnie pokazywanego do ostatniego elementu w pojemniku.
    int size()
    {
        return container->size() - index;
    }

    /// \brief Operator, ktory ustawia pojemnik na ktory iterator pokazuje
    ///
    /// \param ex - pojemnik, ktory ma byc pokazywany przez iterator
    void operator=(Container<T> *ex)
    {
        container = ex;
        index = 0;
    }

    /// \brief Operator, ktory umozliwia sprawdzenie czy iterator pokazuje na pojemnik, lub na ktory z kolei element w pojemniku iterator wskazuje
    ///
    /// \return NULL-> jesli iterator nie pokazuje na pojemnik, w przeciwnym wypadku indeks wskazywanego obiektu.
    operator int()
    {
        if ((container == NULL) || (index < 0) || (index >= container->size()))
        {
            return NULL;
        }
        else
        {
            return index;
        }
    }

    /// \brief Operator dereferencji, ktory zwraca aktualnie pokazywany element
    ///
    /// \return Referencja do aktualnie pokazywanego elementu.
    T &operator*()
    {
        return this->current();
    }

    /// \brief Operator wyluskania, ktory zwraca element znajdujacy sie o i pozycji dalej wzgledem aktualnego elementu.
    ///
    /// \param i - o ile pozycji przesuwamy sie od aktualnego indeksu
    /// \return Referencja na element znajdujacy sie o i pozycji dalej wzgledem aktualnego elementu
    T &operator[](int i)
    {
        if ((index + i < container->size()) && (index + i >= 0))
        {
            return container->at(index + i);
        }
        else
        {
            Exception exep(1, "Out of bounds!", __FILE__, __LINE__);
            throw exep;
        }
    }

    /// \brief Operator, ktory zwraca iterator przesuniety o i elementow dalej.
    ///
    /// \param i - o ile pozycji przesuwamy sie od aktualnego indeksu
    /// \return Iterator przesuniety o i elementow dalej.
    Iterator operator+(int i)
    {
        Iterator to_return(this->container);
        to_return.index = this->index;
        to_return.index += i;

        return to_return;
    }

    /// \brief Operator, ktory przesuwa iterator o i elementow dalej.
    ///
    /// \param i - o ile pozycji przesuwamy sie od aktualnego indeksu
    /// \return Iterator przesuniety o i elementow dalej.
    Iterator operator+=(int i)
    {
        if (index + i < container->size())
        {
            index += i;
            return *this;
        }
    }

    /// \brief Operator, ktory przesuwa iterator o i elementow blizej.
    ///
    /// \param i - o ile pozycji cofamy sie wzgledem aktualnego indeksu
    /// \return Iterator przesuniety o i elementow blizej.
    Iterator operator-=(int i)
    {
        if ((index - i < container->size()) && (index - i >= 0))
        {
            index -= i;
            return *this;
        }
    }

    /// \brief Operator, ktory zwraca iterator przesuniety o i elementow blizej.
    ///
    /// \param i - o ile pozycji cofamy sie wzgledem aktualnego indeksu
    /// \return Iterator przesuniety o i elementow blizej.
    Iterator operator-(int i)
    {
        Iterator to_return(this->container);
        to_return.index = this->index;
        to_return.index -= i;

        return to_return;
    }

    /// \brief Operator postfiksowy, ktory zwraca iterator pokazujacy na i-ty element a nastepnie przesuwa iterator na i+1 element.
    ///
    /// \return Iterator pokazujacy na i-ty element
    Iterator operator++(int)
    {
        Iterator to_return(this->container);
        to_return.index = this->index;

        this->next();

        return to_return;
    }

    /// \brief Operator prefiksowy, ktory przesuwa iterator na i+1 element i zwraca iterator pokazujacy na i+1 element.
    ///
    /// \return Iterator pokazujacy na i+1 element.
    Iterator operator++()
    {
        Iterator to_return(this->container);
        to_return.index = this->index + 1;

        this->next();

        return to_return;
    }

    /// \brief Operator postfiksowy, ktory zwraca iterator pokazujacy na i-ty element a nastepnie przesuwa iterator na i-1 element.
    ///
    /// \return Iterator pokazujacy na i-ty element.
    Iterator operator--(int)
    {
        Iterator to_return(this->container);
        to_return.index = this->index;

        this->prev();

        return to_return;
    }

    /// \brief Operator prefiksowy, ktory przesuwa iterator na i-1 element i zwraca iterator pokazujacy na i-1 element.
    ///
    /// \return Iterator pokazujacy na i-1 element.
    Iterator operator--()
    {
        Iterator to_return(this->container);
        to_return.index = this->index - 1;

        this->prev();

        return to_return;
    }

    /// \brief Operator, ktory umozliwia porownanie dwoch iteratorow - sa sobie rowne tylko wtedy gdy pokazuja na ten sam element.
    /// \param ex - iterator stojacy po prawej stronie porownania
    ///
    /// \return true, jesli pokazuja na ten sam element, false w przeciwnym wypadku.
    bool operator==(const Iterator ex)
    {
        if (this->container == ex.container)
        {
            if (this->index == ex.index)
            {
                return true;
            } else {
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    /// \brief Operator, ktory umozliwia sprawdzenie roznosci dwoch iteratorow - sa od siebie rozne tylko wtedy gdy nie pokazuja na ten sam element.
    /// \param ex - iterator stojacy po prawej stronie porownania
    ///
    /// \return false, jesli pokazuja na ten sam element, true w przeciwnym wypadku.
    bool operator!=(const Iterator ex)
    {
        return !(*this == ex);
    }

};

#endif
