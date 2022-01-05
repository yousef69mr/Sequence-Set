//
// Created by LENOVO on 1/4/2022.
//
#include <iostream>
#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

template<class K,class T>
class node {
private:
    T item;
    K key;
    int blockNumber;
    int index;
    int size;
    int byteOffset;
    node<K,T>* next;
    node<K,T>* previous;
public:

    node() {

        next = nullptr;
    }

    node(K newKey ,T newItem) {

        key =  newKey;
        item = newItem;
        next = nullptr;

    }

    void setBlockNumber(int num){
        blockNumber=num;
    }

    int getBlockNumber(){
        return blockNumber;
    }

    void setItem(T newItem) {

        item = newItem;
        setSize(std::to_string(item));
        setBytOffSet(std::to_string(item));
    }

    void setKey(K newKey) {

        key = newKey;
    }

    K getKey(){
        return key;
    }

    void setSize(std::string size) {

        this->size = size.size();
    }

    int getSize(){
        return size;
    }
    void setBytOffSet(std::string byteOffset) {

        this->byteOffset = byteOffset.size();
    }

    void setBytOffSet(int byteOffset) {

        this->byteOffset = byteOffset;
    }

    int getBytOffSet(){
        return byteOffset;
    }

    void setNext(node<K,T>* nextNodePtr) {

        next = nextNodePtr;
    }

    T getItem() {

        return item;
    }

    node<K,T>* getNext() {

        return next;
    }

    void setIndex(int index){
        this->index=index;
    }

    int getIndex(){
        return index;
    }

    void setPrevious(node<K,T>* previousNodePtr) {

        previous = previousNodePtr;
    }

    node<K,T>* getPrevious() {

        return previous;
    }

};


#endif //LINKEDLIST_NODE_H
