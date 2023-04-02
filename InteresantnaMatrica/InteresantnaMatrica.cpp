#ifndef INTERESANTNAMATRICA_CPP
#define INTERESANTNAMATRICA
#include "InteresantnaMatrica.h"

InteresantnaMatrica::InteresantnaMatrica(vector<vector<int>>&nova_matrica){
    matrica=nova_matrica;
}

void InteresantnaMatrica::ispisi(){
    for(int i=0;i<matrica.size();i++){
        for(int j=0;j<matrica[i].size();j++)
            cout<<matrica[i][j]<<" ";
        cout<<endl;
    }
}
bool InteresantnaMatrica::jeLiInteresantnaMatrica(){
    int broj_redova=matrica.size();
    int broj_kolona=matrica[0].size();

    if(broj_redova>=2 && broj_kolona>=2){
        for(int i=0; i<broj_redova-1; i++){
            for(int j=0; j<broj_kolona-1; j++){
                if(matrica[i][j] + matrica[i+1][j+1] > matrica[i][j+1] + matrica[i+1][j]){
                    return false;
                }
            }
        }
        return true;
    }
    else
        return false;
}
vector<int>InteresantnaMatrica::indeksiNajmanjih(vector<vector<int>>& matrica,vector<int>&provjera){
    int broj_redova=matrica.size();
    int broj_kolona=matrica[0].size();

    vector<int>indeksiNajmanjih;

     if(provjera.size() == 1){
		int i = provjera[0], indeks= 0;
		for(int j=0; j<broj_kolona; j++){
			if(matrica[i][j] < matrica[i][indeks])
				indeks= j;
		}
		indeksiNajmanjih={indeks};
		return indeksiNajmanjih;
	}


	vector<int> parniRedovi;
	vector<int>neparniRedovi;
	for(int i=0;i<provjera.size();i++){
        if(i%2==0)
            parniRedovi.push_back(provjera[i]);
        else
            neparniRedovi.push_back(provjera[i]);
	}

   vector<int>pomocni=InteresantnaMatrica::indeksiNajmanjih(matrica,parniRedovi);
	for(int i=0;i<neparniRedovi.size();i++){
        indeksiNajmanjih.push_back(pomocni[i]);
        int k=pomocni[i];
        int r=min(pomocni[i+1],broj_kolona-1);
        int indeks2=k;
        for(int j=k;j<=r;j++){
            if(matrica[neparniRedovi[i]][j]<matrica[neparniRedovi[i]][indeks2])
                indeks2=j;
        }
        indeksiNajmanjih.push_back(indeks2);

	}

	if(parniRedovi.size()>neparniRedovi.size())
        indeksiNajmanjih.push_back((pomocni.back()));
    return indeksiNajmanjih;

}
#endif // INTERESANTNAMATRICA_CPP

