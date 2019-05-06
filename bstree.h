#ifndef BSTREE_H
#define BSTREE_H

#include "node.h"
#include "iterator.h"

template <typename T> 
class BSTree {
    private:
        Node<T> *root;
    public:
        BSTree() : root(nullptr) {};

        bool find(T data) {
            if(this->root){
                if(data == this->root->data){
                    return true;
                }
                else if(data < this->root->data ){
                    this->root->left->find(data);
                }
                else if(data > this->root->data ){
                    this->root->right->find(data);

                }
            } else{
                return false;
            }

        }

    /*while(temp){
            if(data==temp->data){
                return true;
            }
            else if(data<temp->data) {
                temp = temp->left;
            }
            else if(data>temp->data){
                temp = temp->right;
            }
        }*/

        bool insert(T data) {

            if(this->root){
                if(data == this->root->data){
                    return false;
                }
                if(data < this->root->data){
                    this->root->left->insert(data);
                }
                if(data > this->root->data ){
                    this->root->right->insert(data);
                }

            } else{

                this->root = new Node<T>(data) ;
                return true;
            }






            /*if(this->root){
                if(!find(data)){
                    Node<T>* temp = this->root;
                    Node<T>* next = nullptr;
                    while (true){
                        if(data<temp->data){
                            next = temp ->left;
                            if(!next){
                                temp ->left = new Node<T>(data);
                                return true;
                            } else{
                                temp = next;
                            }
                        }
                        if(data> temp->data){
                            next = temp ->right;
                            if(!next){
                                temp ->right = new Node<T>(data);
                                return true;

                            } else{
                                temp = next;
                            }
                        }
                    }
                } else{
                    return false;
                }
            } else{
                this->root = new Node<T>(data);
                return true;
            }*/
        }

        bool remove(T data) {
            if(find(data)){

                BSTree<T>* temp = this ;

                while(temp->root){
                    if(data==temp->root->data){
                        break;
                    }
                    else if(data<temp->root->data) {
                        temp = temp->root->left;
                    }
                    else if(data>temp->root->data){
                        temp = temp->root->right;
                    }
                }
                //temp apunta al arbol del nodo que queremos remover

                //si es un nodo hoja

                if(!temp->root->left->root and !temp->root->right->root){
                    delete temp->root;
                    temp->root = nullptr;
                }else if((temp->root->right->root and !temp->root->left->root) or (!temp->root->right->root and temp->root->left->root)){
                    //si es un nodo con un hijo

                    //si su hijo es el nodo de la izquierda
                    if(temp->root->left->root){


                        BSTree<T> * nuevoleft = temp->root->left->root->left;
                        BSTree<T> * nuevoright = temp->root->left->root->right;
                        T nuevodato = temp->root->left->root->data;

                        delete temp->root->left;



                        temp->root->left = nuevoleft;
                        temp->root->right = nuevoright;
                        temp->root->data = nuevodato;



                    } else if(temp->root->right->root){
                        //si su hijo es el nodo de la derecha

                        BSTree<T> * nuevoleft = temp->root->right->root->left;
                        BSTree<T> * nuevoright = temp->root->right->root->right;
                        T nuevodato = temp->root->right->root->data;

                        delete temp->root->right;

                        temp->root->left = nuevoleft;
                        temp->root->right = nuevoright;
                        temp->root->data = nuevodato;


                    }


                }else if(temp->root->left->root and temp->root->right->root){

                    // encontramos al elemento anterior

                    BSTree<T> *ant = temp->root->left;

                    while (ant->root->right->root){
                        ant = ant->root->right;
                    }
                    //ant apunta al ARBOL que tiene el nodo anterior a temp


                    T tdata = ant->root->data;
                    ant->root->data = data;
                    temp->root->data = tdata;

                    ant->remove(data);

                }

                return true;
            } else{
                return false;

            }
        }

        unsigned int size() {


            if(this->root){

                return  this->root->right->size() + this->root->left->size() + 1;
            } else{
                return 0;
            }



        }

        void traversePreOrder() {
            if (this->root) {

                cout << this->root->data << " ";
                this->root->left->traversePreOrder();
                this->root->right->traversePreOrder();
            }
        }

        void traverseInOrder() {


            if(this->root){

                this->root->left->traverseInOrder();
                cout << this->root->data<< " ";
                this->root->right->traverseInOrder();
            }
        }

        void traversePostOrder() {
            if(this->root){

                this->root->left->traversePostOrder();
                this->root->right->traversePostOrder();
                cout << this->root->data << " ";
            }
        }

        Iterator<T> begin() {
            if(this->root){
                return Iterator<T>(this->root);
            }
            return Iterator<T>();
        }

        Iterator<T> end() {
            return Iterator<T>();
        }

        ~BSTree() {
            // TODO
        }
    template<class>
    friend class Iterator;
};

#endif
