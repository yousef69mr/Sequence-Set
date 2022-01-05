//
// Created by LENOVO on 1/4/2022.
//


#include "LinkedList.h"
#include "Block.h"


template<class K,class T>
class SequenceSet {

private:
    int lastBit;
    char* fileName;
    Block<K,T>** blocks;
    LinkedList<K,T> Records;
    LinkedList<K,T> HeaderList;

public:

    SequenceSet(char* fileName,int m,int n){

        if(createRecordFile(fileName,m,n)) {
            this->fileName=fileName;
            HeaderList.insertLast(-1, -1);
            Records.insertLast(-1, -1);
        }

    }

    bool createRecordFile(char* name, int m,int n){

        try {
            ofstream file(name);
            if(!file){
                cout << "File could not be created" << endl;
                return false;
            }
            file.close();

            blocks=new Block<K,T>*[m];
            blocks[0]=new Block<K,T>();
            for(int i=1;i<m;i++){
                blocks[i]=new Block<K,T>(n);
            }

            return true;

        }catch(...){

            cout << "File could not be created" << endl;
            return false;

        }

    }

    void insertToFile(K key , T element){
        fstream file;

        lastBit=Records.getByteOffSet();
        file.seekp(lastBit,ios::beg);
        Records.remove(-1);
        Records.insertLast(key,element);
        Records.insertLast(-1,-1);
        node<K,T>* temp =Records.getNode(key);

       //int position = file.tellp();
        string buffer=to_string(temp->getItem())+'|';
        file.open(fileName,ios::out|ios::app);
        file<<buffer;

       // file.write((char*)&buffer, temp->getBytOffSet());
        //position = file.tellp();
       // file.write("|",1);
        //position = file.tellp();
        //file.write((char*)temp->getItem(),temp->getBytOffSet());
        file.close();
    }

    void readFromFile(K key){
        node<K,T>* temp =Records.getNode(key);
        if(temp!=NULL) {
            fstream file;
            file.open(fileName);

            file.seekg(temp->getBytOffSet(), ios::beg);
           // int position = file.tellg();

            char buffer[20];
            // buffer.erase();
            file.getline(buffer, temp->getSize() + 1, '|');
            cout << buffer << endl;
            file.close();
        }else{
            cout<<"key : "+ to_string(key)+" doesn't exist\n";
        }

    }

    void DeleteRecord(K key){
        node<K,T>* temp =Records.getNode(key);
        if(temp!=NULL) {

            HeaderList.remove(-1);
            HeaderList.insertLast(temp->getKey(),temp->getItem());
            HeaderList.insertLast(-1,-1);
            //Records.getNode(key)->setKey(-1);
            Records.remove(key);

        }else{
            cout<<"key : "+ to_string(key)+" doesn't exist\n";
        }
    }
    void DisplayHeaderList(){
        HeaderList.printList();
    }
    void DisplayRecords(){
        Records.printList();
    }
    node<K,T> getHeaderList(){
        return HeaderList;
    }

    node<K,T> getRecordsList(){
        return Records;
    }
};


