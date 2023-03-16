#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;
ifstream f("fisier.txt");
int finale[100], nrfinal, starefinala, nrstari, stare1, stare2, nrlaux, mataux[100][100], i, j, drum[100], nrdrum, k, ok,last2, l , last, lungime_cuvant;
char litera, matrice[100][100], cuvant[1000];
int main() {
  // nr stari final, stari finale , cuvant, nr stari intiale, set 3 variabile(stare 1 , litera, stare 2)
  f >> nrfinal;
  for(i = 0; i < nrfinal; i++){
    f >> starefinala;
    finale[i] = starefinala;
  }

  f >> cuvant;
  f>> nrstari;

  while(f >> stare1 >> litera >> stare2) {
     if(matrice[stare1][stare2] == 0)
         matrice[stare1][stare2] =  litera;
      else{
           mataux[nrlaux][0] = stare1;
           mataux[nrlaux][1] = litera;
           mataux[nrlaux++][2] = stare2;
       }
  }

lungime_cuvant = strlen(cuvant);
last = 0;
l = 1;

  for(i = 0 ; i < lungime_cuvant; i++){
    ok = 0;
    for(j =  0; j < nrstari; j++){
        if (matrice[last][j] == cuvant[i]){
          ok = 1;
          last = j;
          drum[nrdrum++] = last;
          break;
        }
    }
    if(ok==0){
         k = 0;
            while(k < nrlaux && ok==0){
              if(mataux[k][1] == cuvant[i] && last == mataux[k][0] && mataux[k][2] == j-1) {
                  ok = 1;
                  last = j-1;
                  drum[nrdrum++] = last;
                  break;
              }
              k++;
            }
   }
    if(ok == 0)
        { cout << "Cuvant neacceptat"<<endl;
          l = 0;
          break;
        }
   }

last2 = 0;

  if(l == 1) {
      for(i = 0; i < nrfinal; i++)
        if(finale[i] == last) last2 = 1;

      if(last2 == 1) {
        cout << "Cuvant acceptat";
        cout << endl << "Pe drumul: ";
        for(i= 0 ;i < nrdrum; i++){
          cout << drum[i] << " ";
        }
      }
     else cout << "Cuvant neaceptat";
  }

  return 0;
}
