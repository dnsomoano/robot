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

/*
//iterative algorithm
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
*/


//attempt of recrusive. no work
int calc(int n, int stageReq[], int sprockets[]){    
    //int stageReq[] = {0,1,1,3};
    //int sprockets[] ={3,2,10,7};
    int i = n-1;
    int total;

    if (stageReq[i] == 0){
        total = total + sprockets[i];
        return total;
    }
    else{
        int j = stageReq[i];
        for (;j>0 ; j--){
            total = total + calc(i, stageReq, sprockets);
        }
    }
    
    return total;
}

int main(){
    int n = 4;
    int stageReq[] = {0,1,1,3};
    int sprockets[] ={3,2,10,7};

    int temp = calc(n, stageReq, sprockets);
    std::cout<< "final value = "<<temp << "\n";
}

/*
//alternative interative algorithm...... didnt realize i was making this instead of recursive
int calc(int stageReq[], int sprockets[], int n) {
    int* totals = (int*)malloc(sizeof(int) * n);
    if (!totals) {
        cout << "error: could not allocate memory for totals" << endl;
        return -1;
    }
    
    int total = 0;
    
    totals[0] = sprockets[0];
    totals[n-1] = sprockets[n-1];
    
    for (int i = 0; i < n - 1; i++) {
        totals[i] = sprockets[i] + totals[i - 1];
    }
    
    for (int i = 0; i < n; i++) {
        total += totals[i];
    }
    
    if (totals) free(totals);
    return total;
}
*/
