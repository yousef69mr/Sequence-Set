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

    int getKey(){
        return records[0].iKey;
    }

    int getValue(){
        return records[0].iVal;
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


    void sortArray(Record array[],int size){
        bool swapped;
        do{
            swapped= false;
            for(int count=0;count<size;count++){
                if(array[count].iKey>array[count+1].iKey){
                    swap(array[count],array[count+1]);
                    swapped= true;
                }

            }
        } while (swapped);
    }

    bool isValid(){
        setCurrentNumberOfRecords();
        if(getNumberOfRecords()==getCurrentNumberOfRecords()){
            return false;
        }
        return true;
    }

    bool isEmpty(){
        setCurrentNumberOfRecords();
        if(getCurrentNumberOfRecords()==1){
            return true;
        }
        return false;
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

                records[0].iVal= records[getCurrentNumberOfRecords()].iKey;
                cout<<"Added Successfully\n";
            }


            sortArray(records,getCurrentNumberOfRecords());

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
                /*
                if(getCurrentNumberOfRecords()==i){
                    records[0].iVal=records[i-1].iKey;
                }
*/
                arrayShifter(records,i,numberOfRecords);

                records[getNumberOfRecords()-1].iKey=NULL;
                records[getNumberOfRecords()-1].iVal=NULL;


                records[0].iVal=getLastKey();

                if(isEmpty()){
                    records[0].iVal=-1;
                }

                setCurrentNumberOfRecords();
                cout<<"Deleted Successfully\n";
            }
        }

    }

    int getLastKey(){
        for(int i=1;i<numberOfRecords;i++){
            if(records[i+1].iKey==NULL){
                return records[i].iKey;
            }
        }

        return -1;
    }

    void arrayShifter(Record array[],int index,int size){
        for(int i=index;i<size;i++){
            array[i]=array[i+1];
        }

    }

    bool islessThanHalf(){
        setCurrentNumberOfRecords();

        if(getCurrentNumberOfRecords()<=((numberOfRecords)/2)){
            return true;
        }

        return false;
    }
};


#endif //LINKEDLIST_BLOCK_H
