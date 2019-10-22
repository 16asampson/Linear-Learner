#ifndef LEARNER_H
#define LEARNER_H

#include<vector>  //process vector
#include<fstream>  // file i/o
#include<iostream> // cerr
#include<list>

using namespace std;


struct Example
{
    vector<int> x = {1, 0};
    int y =0;
};

//purpose: to read in the input cordinates data from the training file
//and input it into a list for processing by the Linear Learner
//return: dataList
vector<Example> readInDataList(const string& fname)
{
    vector<Example> dataList;
    fstream myfile;
    int num;
    //open the training file
    myfile.open(fname);

    if(myfile.fail())
    {
        cerr << "Unable to open file \"" << fname << "\", terminating" << endl;
        exit(-1);
    }

    //get all input from file and put in cordniate list
    while(!myfile.eof())
    {
        Example temp;
        myfile >> temp.x[1] >> temp.y;
        dataList.push_back(temp);
    }
    
    myfile.close(); //close the training file
    return dataList;

}

//Purpose: compute the YCap value for a given example
//return: the calculated YCap value
int computeYCap(vector<double> w, Example Ex)
{
    int YCap = 0;
    for (int c=0; c < Ex.x.size(); c++)
    {
        YCap = YCap + (w[c] * Ex.x[c]);
        

    }
    cout << "W0= " << w[0] << "W1= " << w[1] << endl;
    cout << "YCap= " << YCap << endl;
    //return YCap
    return YCap;
}

vector<double> LinearLearner(vector<Example> dataList, double LRate);

void SumOfSquaresError(vector<double> w, double eta);
#endif