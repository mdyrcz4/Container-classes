/**
* \file Slist.h
* \author Marcin Dyrcz
* \version 1.0
* \brief Plik zawiera deklaracje klasy Slist
*/
// -------------------------------------------------------------------------

#ifndef SLIST
#define SLIST

#include "Container.h"
#include "node.h"
#include <iostream>

// -------------------------------------------------------------------------

/**
* \class Slist
* \author Marcin Dyrcz
* \brief Klasa reprezentujaca liste pojedynczo wiazana
*/
template <typename T> class Slist : public Container<T>
{
  public:
    singleNode<T> *head;  ///< wezel reprezentujacy glowe listy
    int length; ///< ilosc elementow na liscie zwiekszona o jeden

    /// \brief Konstruktor domyslny klasy, tworzy pusta liste zawieracjaca tylko glowe
    Slist()
    {
        head = new singleNode<T>(NULL);
        length = 1;
    }

    /// \brief Destruktor klasy
    ~Slist()
    {
        singleNode<T> *tmp = head;

        while (tmp->next != NULL)
        {
            singleNode<T> *to_delete = tmp;

            tmp = tmp->next;

            delete to_delete;
        }
    }

    /// \brief Konstruktor kopiujacy klasy
    ///
    /// \param ToCopy - obiekt klasy Slist z ktorego bedziemy kopiowac
    Slist(const Slist<T> &ToCopy)
    {
        head = new singleNode<T>(0, NULL);
        length = 1;

        for (int i = 0; i < ToCopy.size(); ++i)
        {
            this->insert(i, ToCopy.at(i));
        }
    }

    /// \brief Konstruktor kopiujacy klasy
    ///
    /// \param ToCopy - obiekt klasy Container z ktorego bedziemy kopiowac
    Slist(const Container<T> &ToCopy)
    {
        head = new singleNode<T>(0, NULL);
        length = 1;

        for (int i = 0; i < ToCopy.size(); ++i)
        {
            this->insert(i, ToCopy.at(i));
        }
    }

    /// \brief Operator przypisania
    ///
    /// \param ex - element klasy Slist ktory chcemy przypisac
    /// \return referencja do obiektu po wykonaniu przypisania
    Slist &operator= (Slist const &ex)
    {
        if (this != &ex)
        {
            /*Najpierw czyscimy liste, po czym psotepujemy tak samo jak w przypadku konstruktora kopiujacego*/
            this->~Slist();

            head = new singleNode<T>(0, NULL);

            length = 1;

            for (int i = 0; i < ex.size(); i++)
            {
                insert(i, ex.at(i));
            }
        }

        return *this;

    }

    /// \brief Funkcja wstawiajaca nowy element do listy w podanym miejscu
    ///
    /// \param index - miejsce w liscie, gdzie chcemy dodac element
    /// \param inputt - obiekt ktory chcemy dodac do listy
    /// \return true jesli dodawanie sie powiodlo, false jesli nie
    bool insert(int index, const T &inputt)
    {
        if ((index > length) || (index < 0))
        {
            return false;
        }
        else
        {
            singleNode<T> *tmp = head;
            for (int i = 0; i < index; i++)
            {
                tmp = tmp->next;
            }

            singleNode<T> *to_insert = new singleNode<T>(inputt, NULL);

            singleNode<T> *last = tmp->next; //Zapamietanie wezla, aby nie utracic wskazania

            tmp->next = to_insert;

            to_insert->next = last;

            length++;
        }


        return true;
    }

    /// \brief Funkcja pomocnicza do wypisania listy na strumien
    void printL()
    {
        if (size() != 0)
        {
            singleNode<T> *tmp = head->next;
            for (int i = 0; i < length - 1; i++)
            {
                cout << tmp->val << endl;
                tmp = tmp->next;
            }
        } else {
            cout << "Lista jest pusta!";
        }
    }

    /// \brief Funkcja zwracajaca element z podanego miejsca listy
    ///
    /// \param a - numer indeksu elementu, ktory chcemy uzyskac
    /// \return element o zadanym indeksie
    T &at(int a) const
    {
        a = a + 1;

        if ((a > length) || (a < 0))
        {
            Exception exep(0, "Wyjscie poza zakres!", __FILE__, __LINE__);
            throw exep;
        }

        singleNode<T> *tmp = head;

        for (int i = 0; i < a; i++)
        {
            tmp = tmp->next;
        }

        return tmp->val;
    }

    /// \brief Funkcja usuwajaca element o podanym indeksie z listy
    ///
    /// \param index - indeks elementu, ktory chcemy usunac z listy
    /// \return true jesli usuwanie sie powiodlo, false jesli nie
    bool remove(int index)
    {
        index++;
        if ((index > length) || (index < 1))
        {
            return false;
        }
        else
        {
            singleNode<T> *tmp = head;
            for (int i = 0; i < index - 1; i++)
            {
                tmp = tmp->next;
            }

            singleNode<T> *to_delete = tmp->next;

            tmp->next = tmp->next->next;

            delete to_delete;

            --length;
        }

        return true;
    }

    /// \brief Funkcja zwracajaca ilosc elementow listy
    int size() const
    {
        return length - 1;
    }
};


#endif
