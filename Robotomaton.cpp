#include "Robotomaton.h"

Robotomaton::Robotomaton(RobotFileObj rbf, vector<long int> sprockets, vector<long int> stages)
{
    BuildRobotomata(rbf, sprockets, stages);
}

void Robotomaton::BuildRobotomata(RobotFileObj rbf, vector<long int> sprockets, vector<long int> stages)
{
	//int calcSprockets[] = {3, 11, 31, 29, 5};
 //   int stageReq[] = {0, 0, 1, 2, 4};

    //  number of stages
    int n = stages.size();
    int i = 0;
    while (i < n){
        if (stages[i] != 0){
            int j = stages[i];

            while (j > 0){

                sprockets[i] = sprockets[i] + sprockets[i-j];
                j--;
            }//end innerwhile
        }//end else
        i++;
    }//end while
    //cout<< "test end\n";
    this->setTotalSprockets(sprockets[n - 1]);
    //cout<< "" << sprockets[n-1];
}
