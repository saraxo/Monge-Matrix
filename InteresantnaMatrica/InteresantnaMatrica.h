#ifndef INTERESANTNAMATRICA_H
#define INTERESANTNAMATRICA_H

#include<iostream>
#include<vector>
using namespace std;

class InteresantnaMatrica{
    vector<vector<int>> matrica;
    public:
    InteresantnaMatrica() : matrica(1,vector<int>(1,0)) {};
    InteresantnaMatrica(int red,int kolona) : matrica(red,vector<int>(kolona,0)) {};
    InteresantnaMatrica(vector<vector<int>>&nova_matrica);
    void ispisi();
    bool jeLiInteresantnaMatrica();
    vector<int> indeksiNajmanjih(vector<vector<int>>& matrica, vector<int>&provjera);
};
#endif // INTERESANTNAMATRICA_H
