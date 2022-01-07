#include <iostream>
using namespace std;

#include "SequenceSet.h"
int main() {

    try{
        SequenceSet<int ,int> set("data.txt",4,5);
        int key,value,blockNumber,recordNumber,result;
        bool isRunning=true;


        set.InsertVal(5,1);
        set.InsertVal(18,4);
        set.InsertVal(27,5);
        set.InsertVal(88,2);


        set.InsertVal(20,3);
        set.InsertVal(4,8);
        set.InsertVal(11,9);
        set.InsertVal(15,7);

       // set.DeleteKey(7);
        //set.InsertVal(9,10);
        //set.InsertVal(5,11);
        //set.InsertVal(6,12);
        //set.InsertVal(8,14);


        while(isRunning) {
            cout << "//**********************//\n";
            cout<< "Main Menu:\n";
            cout << "//**********************//\n";
            cout<<"1)insert record\n2)delete record\n3)get specific record key value\n4)get specific record value\n5)First Empty Block\n6)Display Specific Block Records\n7)Display All Records\n8)get Block index containing key\n9)get Record index containing key \n10)Exit\n";
            cout << "//**********************//\n";
            int input;
            cout << "Enter choice : ";
            cin >> input;
            switch (input) {
                case (1):

                    cout << "Enter Key : ";
                    cin >> key;
                    cout << "Enter Value : ";
                    cin >> value;
                    set.InsertVal(value, key);
                    set.writeSetToFile();
                    break;
                case (2):
                    cout << "Enter Key : ";
                    cin >> key;
                    set.DeleteKey(key);
                    break;
                case (3):
                    cout << "Enter Block Number : ";
                    cin >> blockNumber;
                    cout << "Enter Value : ";
                    cin >> recordNumber;
                    result = set.getKey(blockNumber, recordNumber);
                    if (result != -1) {
                        cout << "Key Found :" + to_string(result) << endl;
                    } else {
                        cout << "Key not Found :(\n";
                    }


                case (4):
                    cout << "Enter Block Number : ";
                    cin >> blockNumber;
                    cout << "Enter Value : ";
                    cin >> recordNumber;
                    result = set.getVal(blockNumber, recordNumber);
                    if (result != -1) {
                        cout << "Key Found :" + to_string(result) << endl;
                    } else {
                        cout << "Key not Found :(\n";
                    }

                    break;
                case (5):
                    result = set.FirstEmptyBlock();
                    if (result != -1) {
                        cout << "Block Found :" + to_string(result) << endl;
                    } else {
                        cout << "There is no empty Block\n";
                    }
                    break;
                case (6):
                    cout << "Enter Block Number : ";
                    cin >> blockNumber;
                    set.DisplayBlockRecords(blockNumber);
                    break;
                case (7):
                    set.DisplayAllBlockRecords();
                    break;
                case (8):
                    cout << "Enter Key : ";
                    cin >> key;
                    result = set.GetBlockIndex(key);
                    if (result != -1) {
                        cout << "Block Index :" + to_string(result) << endl;
                    } else {
                        cout << "Key not found\n";
                    }
                    break;
                case (9):
                    cout << "Enter Key : ";
                    cin >> key;
                    result = set.GetRecordIndex(key);
                    if (result != -1) {
                        cout << "Record Index :" + to_string(result) << endl;
                    } else {
                        cout << "Key not found\n";
                    }
                    break;
                case (10):
                    isRunning = false;
                    break;
                default:
                    cout<<"Wrong Input\n";
                    break;
            }


        }


    }catch(...){
        exit(1);
    }

}
