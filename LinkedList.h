//
// Created by LENOVO on 1/4/2022.
//

#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H


#include<iostream>
#include<fstream>
#include"node.h"

using namespace std;

template <typename K,typename T>
class LinkedList {
private:

    node<K,T> *head;
    node<K,T> *tail;
    int numberOfBlocks;
    int numberOfRecordsInEachBlock;
    node<K,T> *temp;
    int byteOffSet;
    int numoflists = 0;

public:

    LinkedList() {

        head = NULL;
        tail = NULL;
        byteOffSet=0;
    }

    LinkedList(T value, int intial_size) {
        byteOffSet=0;
        for (int i = 0; i < intial_size; i++) {
            insertLast(value);
        }
    }

    void setNumberOfRecordsInEachBlock(int numberOfRecordsInEachBlock){
        this->numberOfRecordsInEachBlock=numberOfRecordsInEachBlock;
    }

    void setNumberOfBlocks(int NumberOfBlocks){
        this->numberOfBlocks=NumberOfBlocks;
    }

    ~LinkedList() {
        node<K,T> *P = head;
        while (head) {

            P = head->getNext();
            delete head;
            head = P;
        }
    }

    bool isEmpty() {

        return head == NULL;
    }

    void insert(K key,T value, int position) {

        if (position < 0 || position > numoflists) {
            cout << "Out of Range\n";
        } else {

            node<K,T> *newNode = new node<K,T>;
            newNode->setItem(value);
            newNode->setKey(key);
            if (position == 0) {
                insertFirst(key,value);
            } else if (position == numoflists) {
                insertLast(key,value);
            } else {
                node<K,T> *curr = head;
                for (int i = 1; i < position; i++) {
                    curr = curr->getNext();
                }
                newNode->setNext(curr->getNext());
                newNode->setPrevious(curr);
                curr->setNext(newNode);
                curr->getNext()->setPrevious(newNode);

                numoflists++;
            }

        }
    }


    void insertFirst(K key,T Element) {
        node<K,T> *newNode = new node<K,T>;
        newNode->setItem(Element);
        newNode->setKey(key);
        if (numoflists == 0) {
            head = tail = newNode;
            newNode->setPrevious(NULL);
            newNode->setNext(NULL);

        } else {
            newNode->setNext(head);
            newNode->setPrevious(NULL);
            head->setPrevious(newNode);
            head = newNode;
        }

        numoflists++;

    }


    void insertLast(K key,T Element) {
        node<K,T> *newNode = new node<K,T>;
        newNode->setItem(Element);
        newNode->setKey(key);
        if (numoflists == 0) {
            head = tail = newNode;
            newNode->setPrevious(NULL);
            newNode->setNext(NULL);
            if(key!=-1) {
                newNode->setBytOffSet(byteOffSet);
                newNode->setIndex(numoflists);
                byteOffSet = newNode->getBytOffSet() + 1;
            }

        } else {

            newNode->setNext(NULL);
            newNode->setPrevious(tail);
            tail->setNext(newNode);
            tail = newNode;
            if (key != -1) {
                byteOffSet += newNode->getBytOffSet() + 1;
                newNode->setBytOffSet(byteOffSet);
                newNode->setIndex(numoflists);
            }
        }
        numoflists++;

    }

    void removeFirst() {
        if (numoflists == 0) {
            cout << "Empty List\n";
        } else if (numoflists == 1) {      //head==tail

            delete head;
            tail = head = NULL;
            numoflists--;
        } else {
            node<K,T> *current = head;
            head = head->getNext();
            head->setPrevious(NULL);
            delete current;
            numoflists--;
        }
    }

    void removeLast() {
        if (numoflists == 0) {
            cout << "Empty List\n";
        } else if (numoflists == 1) {      //head==tail

            delete head;
            tail = head = NULL;
            numoflists--;
        } else {
            node<K,T> *current = tail;
            tail = tail->getPrevious();
            tail->setNext(NULL);
            delete current;
            numoflists--;
        }
    }

    void remove(T key) {
        if (numoflists == 0) {
            cout << "Empty List\n";
        }
        if (head->getKey() == key) {
            removeFirst();
        } else {
            node<K,T> *current = head->getNext();
            while (current != NULL && current->getKey() != key) {
                current = current->getNext();
            }

            if (current == NULL) {
                cout << "Item not found\n";
            } else if (current->getNext() == NULL) {
                removeLast();
            } else {
                current->getPrevious()->setNext(current->getNext());
                //if (current->getNext() != NULL)
                current->getNext()->setPrevious(current->getPrevious());

                delete current;

                numoflists--;
            }
        }


    }

    int size() {
        return numoflists;
    }

    void printList() {
        node<K,T> *current = head;
        cout << "[ ";
        while (current != NULL) {

            cout << current->getItem();
            current = current->getNext();
            if(current!=NULL){
                cout<< " , ";
            }
        }
        cout << " ]\n";

    }

    void reversePrintList() {
        node<K,T> *current = tail;
        cout << "[ ";
        while (current != NULL) {

            cout << current->getItem();
            current = current->getPrevious();

            if(current!=NULL){
                cout<< " , ";
            }
        }
        cout << " ]\n";

    }

    bool search(K key) {
        node<K,T> *temp = new node<K,T>;
        temp = head;
        while (temp != NULL) {
            //cout<<temp->getitem()<<" ";
            if (temp->getKey() == key) {
                return true;
            }

            temp = temp->getNext();

        }
        return false;

    }

    node<K,T>* getNode(K key){
        node<K,T> *temp = new node<K,T>;
        temp = head;
        while (temp != NULL) {
            //cout<<temp->getitem()<<" ";
            if (temp->getKey() == key) {
                return temp;
            }

            temp = temp->getNext();

        }
        return NULL;

    }

    int getNumberOfRecords(int blockNumber){

        int counter=0;

        node<K,T> *temp = new node<K,T>;
        temp = head;
        while (temp != NULL) {
            //cout<<temp->getitem()<<" ";
            if (temp->getBlockNumber() == blockNumber) {
                counter++;
            }

            temp = temp->getNext();

        }
        return counter;
    }


    int getByteOffSet(){
        return byteOffSet;
    }
    void ReadListInt() {

        int val;
        cin >> val;
        while (val != -1) {

            this->insertLast(val);
            cin >> val;
        }
    }

};

#endif //LINKEDLIST_LINKEDLIST_H
