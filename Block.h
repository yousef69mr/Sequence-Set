//
// Created by LENOVO on 1/5/2022.
//

#ifndef LINKEDLIST_BLOCK_H
#define LINKEDLIST_BLOCK_H

#include "node.h"

struct Record{
    int iKey;
    int iVal;
};

template<class K,class T>
class Block {
private:
    Record* records;
public:

    Block(){
        records=new Record[1];
        records[0].iKey=-1;
        records[0].iVal=-1;
    }
    Block(int numberOfRecords){
        records=new Record[numberOfRecords];
        records[0].iKey=-1;
    }

    void setNumberOfRecords(int numberOfRecords){
        records=new node<K,T>[numberOfRecords];
        records[0].iKey=-1;
    }

};


#endif //LINKEDLIST_BLOCK_H
