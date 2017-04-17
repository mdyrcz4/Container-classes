/**
* \file Dlist.h
* \author Marcin Dyrcz
* \version 1.0
* \brief Plik zawiera deklaracje klasy Dlist
*/
// -------------------------------------------------------------------------

#ifndef DLIST
#define DLIST

#include "Container.h"
#include "node.h"
#include <iostream>

// -------------------------------------------------------------------------

/**
* \class Dlist
* \author Marcin Dyrcz
* \brief Klasa reprezentujaca liste podwojnie wiazana
*/
template <typename T> class Dlist : public Container<T>
{
  public:
    doubleNode<T> *head;  ///wezel reprezentujacy glowe listy
    doubleNode<T> *tail;  /// wezel reprezentujacy ogon listy
    int length;///ilosc elementow na liscie zwiekszana o jeden

    /// \brief Konstruktor domyslny klasy
    Dlist()
    {
        head = new doubleNode<T>(NULL, NULL);
        tail = new doubleNode<T>(NULL, head);
        this->head->next = tail;

        length = 1;
    }

    /// \brief Destruktor klasy
    ~Dlist()
    {
        doubleNode<T> *tmp = head;

        while (tmp->next != NULL)
        {
            doubleNode<T> *to_delete = tmp;

            tmp = tmp->next;

            delete to_delete;
        }
    }

    /// \brief Operator przypisania
    ///
    /// \param ex - element klasy Dlist ktory chcemy przypisac
    /// \return referencja do obiektu, po wykonaniu przypisania
    Dlist &operator= (Dlist const &ex)
    {
        if (this != &ex)
        {
            this->~Dlist();

            head = new doubleNode<T>(NULL, NULL);
            tail = new doubleNode<T>(NULL, head);
            this->head->next = tail;

            length = 1;

            for (int i = 0; i < ex.size(); i++)
            {
                insert(i, ex.at(i));
            }
        }

        return *this;

    }

    /// \brief Konstruktor kopiujacy klasy
    ///
    /// \param ToCopy - obiekt klasy Dlist z ktorego bedziemy kopiowac
    Dlist(const Dlist<T> &ToCopy)
    {
        head = new doubleNode<T>(NULL, NULL);
        tail = new doubleNode<T>(NULL, head);
        this->head->next = tail;

        length = 1;

        for (int i = 0; i < ToCopy.size(); ++i)
        {
            this->insert(i, ToCopy.at(i));
        }
    }

    /// \brief Konstruktor kopiujacy klasy
    ///
    /// \param ToCopy - obiekt klasy Container z ktorego bedziemy kopiowac
    Dlist(const Container<T> &ToCopy)
    {
        head = new doubleNode<T>(NULL, NULL);
        tail = new doubleNode<T>(NULL, head);
        this->head->next = tail;

        length = 1;

        for (int i = 0; i < ToCopy.size(); ++i)
        {
            this->insert(i, ToCopy.at(i));
        }
    }

    /// \brief Funkcja wstawiajaca nowy element do listy w podanym miejscu
    ///
    /// \param index - miejscce w liscie, gdzie chcemy dodac element
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
            doubleNode<T> *tmp;

            if (index < length / 2)
            {
                tmp = head;
                for (int i = 0; i < index; i++)
                {
                    tmp = tmp->next;
                }
            }
            else
            {
                tmp = tail;
                for (int i = length; i > index; i--)
                {
                    tmp = tmp->last;
                }
            }

            doubleNode<T> *to_insert = new doubleNode<T>(inputt, tmp->next, tmp);
            tmp->next->last = to_insert;
            tmp->next = to_insert;

            length++;
        }


        return true;
    }

    /// \brief Funkcja pomocnicza do wypisania listy
    void printL()
    {
        doubleNode<T> *tmp = head->next;
        for (int i = 0; i < length - 1; i++)
        {
            cout << tmp->val << endl;
            tmp = tmp->next;
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

        doubleNode<T> *tmp;

        if (a < length / 2)
        {
            tmp = head;
            for (int i = 0; i < a; i++)
            {
                tmp = tmp->next;
            }
        }
        else
        {
            tmp = tail;
            for (int i = length; i > a; i--)
            {
                tmp = tmp->last;
            }
        }

        return tmp->val;
    }

    /// \brief Funkcja usuwajaca element o podanym indeksie, z listy
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
            doubleNode<T> *tmp;

            if (index < length / 2)
            {
                tmp = head;
                for (int i = 0; i < index - 1; i++)
                {
                    tmp = tmp->next;
                }
            }
            else
            {
                tmp = tail;
                for (int i = length; i >= index; i--)
                {
                    tmp = tmp->last;
                }
            }

            doubleNode<T> *to_delete = tmp->next;

            tmp->next = tmp->next->next;
            tmp->next->last = tmp;

            delete to_delete;

            --length;
        }
    }

    /// \brief Funkcja zwracajaca ilosc elementow listy
    int size() const
    {
        return length - 1;
    }
};


#endif
