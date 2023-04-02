#include<iostream>
#include<vector>
#include<algorithm>
#include "InteresantnaMatrica.h"
using namespace std;

vector<int>vratiVektorProvjere(int broj_redova){
    vector<int>provjera(broj_redova);

    int j=0;
    for(auto it=provjera.begin();it!=provjera.end();it++){
        *it=j++;
    }
    return provjera;
}
void ispisiInteresantnost(bool provjera){
    if(provjera)
        cout<<"Jeste interesantna matrica!"<<endl;
    else
        cout<<"Nije interesantna matrica!"<<endl;
}

int main(){
    //testni primjer za matricu koja jeste interesantna matrica
    vector<vector<int>> testna_matrica={
        {10,17,13,28,23},
        {17,22,16,29,23},
        {24,28,22,34,24},
        {11,13,6,17,7},
        {45,44,32,37,23},
        {36,33,19,21,6},
        {75,66,51,53,34}
    };
   InteresantnaMatrica matrica(testna_matrica);
    //matrica.ispisi();
    bool test_interesantna=matrica.jeLiInteresantnaMatrica();
    ispisiInteresantnost(test_interesantna);

     vector<int>provjera=vratiVektorProvjere(testna_matrica.size());
     /*for(int i=0;i<provjera.size();i++)
        cout<<provjera[i]<<" ";*/


     vector<int> rezultat=matrica.indeksiNajmanjih(testna_matrica,provjera);
     cout<<"Indeksi najmanjih elemenata po redu u matrici su: ";
    for(int i=0;i<rezultat.size();i++)
        cout<<rezultat[i]<<" ";
    cout<<endl;

    //testni primjer za matricu koja nije interesantna matrica
    vector<vector<int>> testna_matrica_2={
        {0,23,24,-1},
        {21,6,7,10},
        {53,34,30,31},
        {32,13,6,9},
        {43,21,8,15}
    };
    InteresantnaMatrica matrica2(testna_matrica_2);
    //matrica2.ispisi();
    bool test_interesantna_2=matrica2.jeLiInteresantnaMatrica();
    ispisiInteresantnost(test_interesantna_2);

    //testni primjer da korisnik sam unese
    int broj_redova,broj_kolona;
    cout<<"Unesite broj redova u vasoj matrici: "<<endl;
    cin>>broj_redova;
    cout<<"Unesite broj kolona u vasoj matrici: "<<endl;
    cin>>broj_kolona;

    vector<vector<int>>samostalna_matrica(broj_redova);
    for(int i=0;i<samostalna_matrica.size();i++)
        samostalna_matrica[i].resize(broj_kolona);
    cout<<"Unesite elemente matrice!"<<endl;

    for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_kolona;j++)
            cin>>samostalna_matrica[i][j];
    }
    /*for(int i=0;i<broj_redova;i++){
        for(int j=0;j<broj_kolona;j++)
            cout<<samostalna_matrica[i][j]<<" ";
        cout<<endl;
    }*/

    InteresantnaMatrica matrica3(samostalna_matrica);
    bool test_interesantna_3=matrica3.jeLiInteresantnaMatrica();
    ispisiInteresantnost(test_interesantna_3);

    if(test_interesantna_3){
        vector<int>provjera2=vratiVektorProvjere(samostalna_matrica.size());
        /*for(int i=0;i<provjera.size();i++)
            cout<<provjera[i]<<" ";*/

     vector<int> rezultat3=matrica3.indeksiNajmanjih(samostalna_matrica,provjera2);
     cout<<"Indeksi najmanjih elemenata po redu u matrici su: ";
     for(int i=0;i<rezultat3.size();i++)
        cout<<rezultat3[i]<<" ";
    cout<<endl;
    }
    else{
        cout<<"Kraj! Vasa matrica nije interesantna i ne moze se koristit funkcija vratiIndeksNajmanjih!";
    }





}
