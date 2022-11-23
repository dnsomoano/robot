#include "Robotomaton.h"

Robotomaton::Robotomaton(vector<pair<string, string>> strToks, int sprockets[], int stages[])
{
    BuildRobotomata(strToks, sprockets, stages);
}

void Robotomaton::BuildRobotomata(vector<pair<string, string>> strToks, int sprockets[], int stages[])
{
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
}
