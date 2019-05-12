#ifndef NODE_H
#define NODE_H

template <typename T>
class BSTree; 

template <typename T>
class Iterator; 

template <typename T>
class Node {

    private:
        T data;
        // Interesante tu solución, pero quizás estás desperdiciando un poco de memoria al hacer esto. Igual está bien
        BSTree<T> *left;
        BSTree<T> *right;


    public:
        Node(T data) {
            this->data = data;
            left = new BSTree<T>();
            right = new BSTree<T>();
        };

        void Killson(){

        }


    template<class>
    friend class BSTree; 

    template<class>
    friend class Iterator; 
};

#endif