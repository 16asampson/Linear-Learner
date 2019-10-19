#ifndef LEARNER_H
#define LEARNER_H

#include<vector>  //process vector
#include<fstream>  // file i/o
#include<iostream> // cerr

using namespace std;


inline void readInProcList(const string& fname, vector<pair<int, int>>& dataList)
{
    ifstream in(fname.c_str());
    int cordCount;

    if(in.fail())
    {
        cerr << "Unable to open file \"" << fname << "\", terminating" << endl;
        exit(-1);
    }

    in >> cordCount;
    dataList.resize(cordCount);
    for(auto& p:dataList)
    {
        int x,y;
        in >> x >>y;
        p = make_pair(x,y);
    }
    in.close();
}

#endif