//testrun of non memoized algorithm robotomaton calculation

#include<iostream>
using namespace std;




int main(){

    cout<< "test";
    
    //  used for calculating total sprockets
    int calcSprockets[] = {-1, -1, -1, -1};
    //  stores given values of sprockets per stage
    int sprockets[] = {3, 2, 10, 7};
    //  number of stages required
    int stageReq[] = {0, 1, 1, 3};

    //  number of stages
    int n = 4;
    int i = 0;
    while (i <= n){
        if (stageReq[i] == 0)
            calcSprockets[i] = sprockets[i];
        else{
            int j = stageReq[i];
            calcSprockets[i] = sprockets[i];
            while (j > 0){
                calcSprockets[i] = calcSprockets[i] + calcSprockets[i-j];
                j--;
            }//end innerwhile
        }//end else
        i++;
    }//end while
    cout<< "test";
    cout<< "" <<calcSprockets[n-1];
    return 0;



}//end main