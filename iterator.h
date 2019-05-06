#ifndef ITERATOR_H
#define ITERATOR_H

#include "node.h"
#include <vector>

template <typename T> 
class Iterator {
    private:
        Node<T> *current;
        int index;
        vector<Node<T>*> data;


    public:
        Iterator() {
            this->current = nullptr;
        }

        Iterator(Node<T> *node) {

                makelist(node);
                this->current = (this->data)[0];
                this->index = 0;

        }

        void makelist(Node<T> *node){

                if(node->left->root)
                        makelist(node->left->root);
                (this->data).push_back(node);
                if(node->right->root)
                        makelist(node->right->root);


        }


        Iterator<T> operator=(Iterator<T> other) {
                this->current=other->current;
        }

        bool operator!=(Iterator<T> other) {
                return this->current!=other.current;
        }

        Iterator<T> operator++() {


                if(this->index < data.size()-1){

                        this->index = this->index +1;
                        this->current = data[this->index];


                } else if(this->index = data.size()-1){
                        this->current = nullptr;
                        this->index = this->index +1;

                }

                return (*this);

        }

        Iterator<T> operator--() {
                if(this->index > 0){

                        this->index = this->index -1;
                        this->current = data[this->index];


                } else if(this->index = 0){
                        this -> index = this->index -1;
                        this->current = nullptr;
                }
                return (*this);

        }

        T operator*() {
                if(!this->current)
                        throw out_of_range("el iterador apunta a null\n");
                return this->current->data;
        }
};

#endif
