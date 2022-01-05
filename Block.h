//
// Created by LENOVO on 1/5/2022.
//

#ifndef LINKEDLIST_BLOCK_H
#define LINKEDLIST_BLOCK_H
#include <bits/stdc++.h>


struct Record{
    int iKey;
    int iVal;
    int byteOffset;
};

template<class K,class T>
class Block {
private:
    Record* records;
    int currentNumberOfRecords;
    int numberOfRecords;
public:

    Block(){
        records=new Record[1];
        records[0].iKey=-1;
        records[0].iVal=-1;
    }
    Block(int numberOfRecords){
        this->numberOfRecords=numberOfRecords;
        records=new Record[numberOfRecords];
        fillArray();
        records[0].iKey=-1;
        records[0].iVal= -1;
    }

    void fillArray(){
        for(int i=0;i<numberOfRecords;i++){
            records[i].iKey=NULL;
            records[i].iVal=NULL;
        }
    }

    void setCurrentNumberOfRecords(){
        int sum=0;

        for(int i=0;i<numberOfRecords;i++){
            if(records[i].iKey!=NULL){
                sum++;
            }
        }
        currentNumberOfRecords=sum;

    }

    int getCurrentNumberOfRecords(){
        return currentNumberOfRecords;
    }

    int getNumberOfRecords(){
        return numberOfRecords;
    }

    void sort(){
        Record temp;
        for(int i=0;i<numberOfRecords;i++){
            if(records[i].iKey>records[i+1].iKey){
                temp = records[i];
                records[i]=records[i+1];
                records[i+1]=temp;
            }
        }
    }

    bool isValid(){
        setCurrentNumberOfRecords();
        if(getNumberOfRecords()==getCurrentNumberOfRecords()){
            return false;
        }
        return true;
    }


    void add(int key,int value){
        if(records[1].iKey==NULL){
            records[1].iKey=key;
            records[1].iVal=value;
            records[0].iVal= records[1].iKey;
        }else{

            if(getNumberOfRecords()>getCurrentNumberOfRecords()){
                records[getCurrentNumberOfRecords()].iKey=key;
                records[getCurrentNumberOfRecords()].iVal=value;
                records[0].iVal= records[getCurrentNumberOfRecords()].iKey;
            }

            sort();
        }
    }


    int getKey(int value){

        int key =records[value].iKey;

        return key;
    }

    int getVal(int value){

        int recordValue =records[value].iVal;

        return recordValue;
    }

   void deleteRecord(int key){
        for(int i=1;i<numberOfRecords;i++){
            if(records[i].iKey==key){
                if(getCurrentNumberOfRecords()==i){
                    records[0].iVal=records[i-1].iVal;
                }
                records[i].iKey=NULL;
                records[i].iVal=NULL;
            }
        }

    }



/*
    int getKey(int value){
        for(int i =0;i<numberOfRecords;i++){
            if(records[i].iVal==value){
                return records[i].iKey;
            }
        }
        return NULL;
    }
*/
};


#endif //LINKEDLIST_BLOCK_H
