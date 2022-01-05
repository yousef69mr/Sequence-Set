//
// Created by LENOVO on 1/5/2022.
//

#ifndef LINKEDLIST_BLOCK_H
#define LINKEDLIST_BLOCK_H

#include "node.h"

template<class K,class T>
class Block {
private:
    node<K,T>* records;
public:

    Block(){
        records=new node<K,T>[1];
        records[0].setKey(-1);
    }
    Block(int numberOfRecords){
        records=new node<K,T>[numberOfRecords];
        records[0].setKey(-1);
    }

    void setNumberOfRecords(int numberOfRecords){
        records=new node<K,T>[numberOfRecords];
        records[0].setKey(-1);
    }

};


#endif //LINKEDLIST_BLOCK_H
