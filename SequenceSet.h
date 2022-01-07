//
// Created by LENOVO on 1/4/2022.
//


#include "Block.h"


template<class K,class T>
class SequenceSet {

private:
    //int lastBit;
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
            buffer=buffer.substr(0,buffer.size()-1);
            buffer+="$\n";
            cout<<"Set added to file successfully\n";
        }

        file.open(fileName,ios::out|ios::app);
        file<<buffer;


        file.close();
    }

    void writeSetToFile(){

        bool end;
        bool endOfSet=false;


        for(int j=0;j<numberOfBlocks;j++) {
            //cout<<"Block ("+ to_string(j)+") :"<<endl;
            if(j==0){
                end= true;
                //cout << "Record Key : " + to_string(blocks[j]->getKey(0)) + " / Record Value : " + to_string(blocks[j]->getVal(0)) << endl;
                insertToFile(blocks[j]->getKey(0),blocks[j]->getVal(0),end,endOfSet);


            }else {

                end= false;

                for (int i = 0; i < numberOfRecordsInEachBlock; i++) {
                   // cout << "Record Key : " + to_string(blocks[j]->getKey(i)) + " / Record Value : " + to_string(blocks[j]->getVal(i)) << endl;
                    if(j+1==numberOfBlocks &&i+1==numberOfRecordsInEachBlock) {
                        endOfSet = true;
                    }

                    if(i+1==numberOfRecordsInEachBlock){
                        end= true;
                    }

                    insertToFile(blocks[j]->getKey(i),blocks[j]->getVal(i),end,endOfSet);



                }

            }

        }

    }
    int InsertVal( int iToken, int iKey){
        for(int i=1;i<numberOfBlocks;i++){
            if(blocks[i]->isValid()){
                blocks[i]->add(iKey,iToken);
                blocks[i-1]->setKey(i);
                blocks[0]->setValue(FirstEmptyBlock());
                if(i>1 && !blocks[i]->islessThanHalf()){

                    if(blocks[i]->getCurrentNumberOfRecords()<blocks[i-1]->getCurrentNumberOfRecords()){
                        split(i+1, blocks[i]->getCurrentNumberOfRecords()/2);
                    }
                }
                return i;
            }
        }

        cout<<"There is no empty record\n";
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

    void combineWithPrevious(int deletedBlock,int numOfRecords){
        for(int i=1,j=0;i<numberOfRecordsInEachBlock&&j<numOfRecords;i++,j++) {
            if (blocks[deletedBlock-1]->isValid()&&(!blocks[deletedBlock]->islessThanHalf()||!blocks[deletedBlock]->isEmpty())) {
                blocks[deletedBlock-1]->add(blocks[deletedBlock]->getKey(i),blocks[deletedBlock]->getVal(i));
                blocks[deletedBlock]->deleteRecord(blocks[deletedBlock]->getKey(i));

                blocks[deletedBlock-1]->setCurrentNumberOfRecords();
                blocks[deletedBlock]->setCurrentNumberOfRecords();

            }else if(i<numOfRecords && i!=0){
                cout<<"Can't fully combined";
            }else{
                cout<<"Previous block is full";
            }
        }
    }


    void split(int deletedBlock,int numOfRecords){
        for(int i=1,j=1;i<numberOfRecordsInEachBlock&&j<numOfRecords;i++,j++) {
            if (blocks[deletedBlock]->isValid()&&!blocks[deletedBlock-1]->islessThanHalf()&&(blocks[deletedBlock]->islessThanHalf()||blocks[deletedBlock]->isEmpty())) {

                if(blocks[deletedBlock]->isEmpty()){
                    blocks[deletedBlock-1]->setKey(-1);
                } else{
                    blocks[deletedBlock-1]->setKey(deletedBlock);
                }


                blocks[deletedBlock]->add(blocks[deletedBlock-1]->getKey(i),blocks[deletedBlock-1]->getVal(i));
                blocks[deletedBlock-1]->deleteRecord(blocks[deletedBlock-1]->getKey(i));

                blocks[deletedBlock-1]->setCurrentNumberOfRecords();
                blocks[deletedBlock]->setCurrentNumberOfRecords();



            }else if(i<numOfRecords && i!=0){
                cout<<"Can't fully split";
            }
        }
    }

   void DeleteKey(int iToken){

       for(int i=1;i<numberOfBlocks;i++){
           for(int j=0;j<numberOfRecordsInEachBlock;j++){
               int key =blocks[i]->getKey(j);
               if(key==iToken){
                   blocks[i]->deleteRecord(iToken);

                   if(blocks[i]->isEmpty()){
                       blocks[i-1]->setKey(-1);
                   }

                   if(i>1 && blocks[i]->islessThanHalf()){

                       if(blocks[i-1]->isValid()&&!blocks[i]->isEmpty()) {
                           combineWithPrevious(i, blocks[i]->getCurrentNumberOfRecords() / 2);
                       }else if(!blocks[i-1]->islessThanHalf()&&!blocks[i]->isEmpty()){
                           split(i, blocks[i-1]->getCurrentNumberOfRecords()/2);
                       }
                   }

                   if(i<numberOfBlocks){
                       if(!blocks[i+1]->isEmpty() && blocks[i]->isEmpty()) {
                           blocks[i]->setKey(-1);
                           blocks[i - 1]->setKey(getIndexOfNonEmptyBlock(i));

                       }else if(!blocks[i+1]->isEmpty()) {
                           blocks[i]->setKey(getIndexOfNonEmptyBlock(i));
                       }

                   }

                   blocks[0]->setValue(FirstEmptyBlock());
               }
           }

       }
       writeSetToFile();
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


    int getIndexOfNonEmptyBlock(int start){
        for(int i=start+1;i<numberOfBlocks;i++){
            if(!blocks[i]->isEmpty()){
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


