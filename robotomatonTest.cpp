//testrun of non memoized algorithm robotomaton calculation

#include<iostream>
using namespace std;

/*
int main(){

    cout<< "test\n";
    
    //  used for calculating total sprockets
    //pdf test
    //int calcSprockets[] = {3, 2, 10, 7};
    int calcSprockets[] = {3, 11, 31, 29, 5};
    //  number of stages required
    //pdf test
    //int stageReq[] = {0, 1, 1, 3};
    int stageReq[] = {0, 0, 1, 2, 4};

    //  number of stages
    int n = 5;
    int i = 0;
    while (i < n){
        
        cout<< "test outer while\n";
        cout<< i << "iteration\n"; 
        
        if (stageReq[i] != 0){
            int j = stageReq[i];
            
            //test line
            cout<< "" <<calcSprockets[i];
            cout<< "\n";
            
            while (j > 0){
                
                cout<< "test inner while\n";
                //test line
                cout<< "" <<calcSprockets[i];
                cout<< "\n";
                
                calcSprockets[i] = calcSprockets[i] + calcSprockets[i-j];
                
                //test line
                cout<< "" <<calcSprockets[i];
                cout<< "\n";
                
                j--;
            }//end innerwhile
        }//end else
        i++;
    }//end while
    //cout<< "test end\n";
    cout<< "" <<calcSprockets[n-1];
    
    cout<< "\n";
    cout<< "" <<calcSprockets[0];
    cout<< "\n";
    cout<< "" <<calcSprockets[1];
    cout<< "\n";
    cout<< "" <<calcSprockets[2];
    cout<< "\n";
    cout<< "" <<calcSprockets[3];
    cout<< "\n";
    
    return 0;
}//end main
*/

int main(){

    cout<< "test\n";
    
    int calcSprockets[] = {3, 11, 31, 29, 5};
    int stageReq[] = {0, 0, 1, 2, 4};

    //  number of stages
    int n = 5;
    int i = 0;
    while (i < n){
        if (stageReq[i] != 0){
            int j = stageReq[i];

            while (j > 0){

                calcSprockets[i] = calcSprockets[i] + calcSprockets[i-j];
                j--;
            }//end innerwhile
        }//end else
        i++;
    }//end while
    //cout<< "test end\n";
    cout<< "" <<calcSprockets[n-1];
    return 0;



}//end main
