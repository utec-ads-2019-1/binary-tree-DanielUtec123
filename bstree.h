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

            if(!find(data)){
                return false;
            } else{



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

                this->root->left->traversePreOrder();
                cout << this->root->data<< " ";
                this->root->right->traversePreOrder();
            }
        }

        void traversePostOrder() {
            if(this->root){

                this->root->left->traversePreOrder();
                this->root->right->traversePreOrder();
                cout << this->root->data << " ";
            }
        }

        Iterator<T> begin() {
            // TODO
        }

        Iterator<T> end() { 
            // TODO
        }

        ~BSTree() {
            // TODO
        }
};

#endif
