//
// Created by LENOVO on 1/4/2022.
//


#include "Block.h"


template<class K,class T>
class SequenceSet {

private:
    int lastBit;
    char* fileName;
    Block<K,T>** blocks;
    int numberOfBlocks;
    int numberOfRecordsInEachBlock;


public:

    SequenceSet(char* fileName,int m,int n){

        if(createRecordFile(fileName,m,n)) {
            this->fileName=fileName;

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

            //firstBlock.iKey=-1;
            //firstBlock.iVal=-1;

            numberOfBlocks=m;
            numberOfRecordsInEachBlock=n;

           // Records.setNumberOfBlocks(numberOfBlocks);
           // Records.setNumberOfRecordsInEachBlock(n);

            return true;

        }catch(...){

            cout << "File could not be created" << endl;
            return false;

        }

    }

/*

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

*/

    void insertToFile(K key , T element,int endOfBlock,int endOfSet){
        fstream file;

        string buffer=to_string(key)+','+to_string(element)+'|';
        if(endOfBlock&&!endOfSet){
            buffer+='\t';
        }
        if(endOfSet){
            buffer+='\n';
        }

        file.open(fileName,ios::out|ios::app);
        file<<buffer;


        file.close();
    }

    void writeSetToFile(){

        bool end= false;
        bool endOfSet=false;


        for(int j=0;j<numberOfBlocks;j++) {
            //cout<<"Block ("+ to_string(j)+") :"<<endl;
            if(j==0){
                end= true;
                //cout << "Record Key : " + to_string(blocks[j]->getKey(0)) + " / Record Value : " + to_string(blocks[j]->getVal(0)) << endl;
                insertToFile(blocks[j]->getKey(0),blocks[j]->getVal(0),end,endOfSet);
                end=false;


            }else {
                for (int i = 0; i < numberOfRecordsInEachBlock; i++) {
                   // cout << "Record Key : " + to_string(blocks[j]->getKey(i)) + " / Record Value : " + to_string(blocks[j]->getVal(i)) << endl;

                    insertToFile(blocks[j]->getKey(i),blocks[j]->getVal(i),end,endOfSet);
                    end = false;
                    if(i+1==numberOfBlocks){
                        end= true;
                        if(j==numberOfBlocks-1) {
                            endOfSet = true;
                        }
                    }

                }

            }

        }

    }
    int InsertVal( int iToken, int iKey){
        for(int i=1;i<numberOfBlocks;i++){
            if(blocks[i]->isValid()){
                blocks[i]->add(iKey,iToken);
                return i;
            }
        }

        return -1;
    }

    int getKey( int iBlock, int iRecord){
        int key =blocks[iBlock]->getKey(iRecord);
        if(key!=NULL){
            return key;
        }
        else{
            return -1;
        }
    }

    int getVal( int iBlock, int iRecord){
        int value =blocks[iBlock]->getVal(iRecord);
        if(value!=NULL){
            return value;
        }
        else{
            return -1;
        }
    }

    int GetBlockIndex(int iToken){
        for(int i=1;i<numberOfBlocks;i++){
            for(int j=0;j<numberOfRecordsInEachBlock;j++){
                int key =blocks[i]->getKey(j);
                if(key==iToken){
                    return i;
                }
            }

        }
        return -1;

    }

    int GetRecordIndex(int iToken){
        for(int i=1;i<numberOfBlocks;i++){
            for(int j=0;j<numberOfRecordsInEachBlock;j++){
                int key =blocks[i]->getKey(j);
                if(key==iToken){
                    return j;
                }
            }

        }
        return -1;

    }

   void DeleteKey(int iToken){

       for(int i=1;i<numberOfBlocks;i++){
           for(int j=0;j<numberOfRecordsInEachBlock;j++){
               int key =blocks[i]->getKey(j);
               if(key==iToken){
                   blocks[i]->deleteRecord(iToken);
               }
           }

       }
    }


    int FirstEmptyBlock(){
        for(int i=1;i<numberOfBlocks;i++){

            int key =blocks[i]->getKey(1);
            if(key==NULL){
                return i;
            }
        }

        return -1;
    }

    void DisplayBlockRecords(int iBlock){
        for(int i=0;i<numberOfRecordsInEachBlock;i++){
            cout<<"Record Key : "+ to_string(blocks[iBlock]->getKey(i))+" / Record Value : "+ to_string(blocks[iBlock]->getVal(i))<<endl;
        }
    }

    void DisplayAllBlockRecords(){
        for(int j=0;j<numberOfBlocks;j++) {
            cout<<"Block ("+ to_string(j)+") :"<<endl;
            if(j==0){
                cout << "Record Key : " + to_string(blocks[j]->getKey(0)) + " / Record Value : " + to_string(blocks[j]->getVal(0)) << endl;
            }else {
                for (int i = 0; i < numberOfRecordsInEachBlock; i++) {
                    cout << "Record Key : " + to_string(blocks[j]->getKey(i)) + " / Record Value : " + to_string(blocks[j]->getVal(i)) << endl;
                }
            }
        }
    }

};


