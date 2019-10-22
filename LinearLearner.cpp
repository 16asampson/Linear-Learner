#include<iostream>
#include<fstream>
#include<cmath>
#include<list>
#include<stdlib.h> //srand rand
#include<time.h>    //time


#include "learner.h"
using namespace std;

int main()
{
    //TODO: read input document
    vector<Example> ExList;
    string fExamples = "./chocodata.txt";
    ExList = readInDataList(fExamples);


    //TODO: get LearningRate from user
    double LRate;
    cin >> LRate;

    

    //TODO Algorithm implementation
    vector<double> w;
    w = LinearLearner(ExList,LRate);

    SumOfSquaresError(w,LRate);
}

//Learning Algorithm, Returns Weight Vector after Linear Learning
vector<double> LinearLearner(vector<Example> dataList, double LRate)
{
    vector<double> w;
    /* Initialize Random seed*/
    srand (time(NULL));
    //get random wieghts between 0 and 100
    w.push_back(rand() % 100 +0);
    w.push_back(rand() % 100 +0);

    cout << "W0: " << w[0];
    cout << "W1: " << w[1];
    //cout << endl;
    //int yCap = computeYCap(w,dataList[0]);
    //iterate through examples and adjust weights 5000 times
    
    for (int it=0; it<5;it++)
    {

        //for every example update the weight
        for(int k=0; k<dataList.size(); k++)
        {
            int yCap = computeYCap(w,dataList[k]);
            int delta = dataList[k].y - yCap;

            //for each weight update
            for (int i=0; i<w.size();i++)
            {
                w[i] = w[i]  + LRate*delta*dataList[k].x[i];
            }
        }

    }
    
    cout << "After Running " << endl;
    cout << "W0: " << w[0] << endl;
    cout << "W1: " << w[1] << endl;
    return w;
}

void SumOfSquaresError(vector<double> w, double eta)
{
    string fvaild = "./chocovalid.txt";
    vector<Example> valList = readInDataList(fvaild);
    double SSE = 0;
    
    //loop through validation data and calculate sum-of-squares Error
    for (int i=0; i < valList.size(); i++)
    {
        int yCap = computeYCap(w,valList[i]);
        SSE = SSE + pow((valList[i].y - yCap),2);

    }

    //output results
    cout << "CS-5001: H1#1" << endl;
    cout << "Programmer: Austin Sampson" << endl << endl;

    cout << "TRANING" << endl;
    cout << "Using learning rate eta = " << eta << endl;
    cout << "Using 5000 iterations." << endl << endl;
    
    cout << "OUTPUT" << endl;
    cout << "w0 = " << w[0] << endl;
    cout << "w1 = " << w[1] << endl << endl;

    cout << endl << "VALIDATION" << endl;
    cout << "Sum-of-Squares Error = " << SSE << endl;
}