/**
* \file node.h
* \author Marcin
* \version 1.0
* \brief Plik zawiera deklaracje klas reprezentujacych wezel listy
*/
// -------------------------------------------------------------------------
#ifndef NODE
#define NODE
// -------------------------------------------------------------------------

/**
* \class singleNode
* \author Marcin Dyrcz
* \brief Klasa reprezentuje wezel listy pojedynczo wiazanej
*/
template <typename T>
class singleNode {
  public:
    T val;///< Wartosc przechowywana w wezle
    singleNode *next;  ///< Wskazanie na wezel nastepujacy

    /// \brief Konstruktor parametrowy klasy
    ///
    /// \param _val - wartosc, ktora ma zawierac wezel
    /// \param _next - wskaznik na wezel nastepujacy
    singleNode(T _val, singleNode *_next)
    {
        val = _val;
        next = _next;
    }

    /// \brief Konstruktor parametrowy klasy
    ///
    /// \param _next - wskaznik na wezel nastepujacy
    singleNode(singleNode *_next)
    {
        next = _next;
    }
};

/**
* \class doubleNode
* \author Marcin Dyrcz
* \brief Klasa reprezentuje wezel listy podwojnie wiazanej
*/
template <typename T>
class doubleNode {
  public:
    T val;///< Wartosc przechowywana w wezle
    doubleNode *next; ///< Wskazanie na wezel nastepujacy
    doubleNode *last; ///< Wskazanie na wezel poprzedzajacy

    /// \brief Konstruktor parametrowy klasy
    ///
    /// \param _val - wartosc, ktora ma zawierac wezel
    /// \param _next - wskaznik na wezel nastepujacy
    /// \param _last - wskaznik na wezel poprzedzajacy
    doubleNode(T _val, doubleNode *_next,  doubleNode *_last)
    {
        val = _val;
        next = _next;
        last = _last;
    }

    /// \brief Konstruktor parametrowy klasy
    ///
    /// \param _next - wskaznik na wezel nastepujacy
    /// \param _last - wskaznik na wezel poprzedzajacy
    doubleNode(doubleNode *_next,  doubleNode *_last)
    {
        next = _next;
        last = _last;
    }
};

#endif
