//
// Created by LENOVO on 1/5/2022.
//

#ifndef LINKEDLIST_BLOCK_H
#define LINKEDLIST_BLOCK_H
#include <bits/stdc++.h>


struct Record{
    int iKey;
    int iVal;

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

    void setKey(int index){
        records[0].iKey=index;
    }

    void setValue(int index){
        records[0].iVal=index;
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
    void swap(Record* af, Record* bf){

        Record t = *af;
        *af = *bf;
        *bf = t;
    }

    void sort(Record* &array){

        int size =sizeof (array)/sizeof (array[0]);
        for(int i=0;i<size+1;i++){
            if(array[i].iKey>array[i+1].iKey){
                swap(&array[i],&array[i+1]);
            }
        }
    }

    void arrSort(int* pDonate[], int s)
    {
        bool swap;
        int* temp;
        do
        {
            swap = false;
            for (int count = 0; count < (s-1); count++)
            {
                if ((*pDonate[count]) > (*pDonate[count+1]))
                {
                    temp = pDonate[count];
                    pDonate[count] = pDonate[count+1];
                    pDonate[count+1] = temp;
                }
                swap = true;
            }
        }
        while(swap);
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
            cout<<"Added Successfully\n";
        }else{


            if(getNumberOfRecords()>getCurrentNumberOfRecords()){
                records[getCurrentNumberOfRecords()].iKey=key;
                records[getCurrentNumberOfRecords()].iVal=value;
                sort(records);
                //arrSort(records,numberOfRecords);
                records[0].iVal= records[getCurrentNumberOfRecords()].iKey;
                cout<<"Added Successfully\n";
            }

            sort(records);
            records[0].iVal= records[getCurrentNumberOfRecords()].iKey;
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
                setCurrentNumberOfRecords();
                cout<<"Deleted Successfully\n";
            }
        }

    }

};


#endif //LINKEDLIST_BLOCK_H
