#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

pair <int, int> trova_intervallo ( vector < pair<int,int> > intervalli, int dim );

int main(){
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    vector < pair<int, int> > intervalli;
    int dim;

    in >> dim;
    for (int i=0; i<dim; i++){
        pair<int, int> tmp;
        in >> tmp.first >> tmp.second ;
        intervalli.push_back(tmp);
    }
    sort (intervalli.begin(), intervalli.end());
    pair<int, int> max_interv = trova_intervallo(intervalli, dim);
    out << max_interv.first <<" " <<max_interv.second <<endl;

    /*for (int i=0; i<dim; i++){
        out << intervalli[i].first <<" " <<intervalli[i].second <<endl;
    }*/

    in.close();
    out.close();
    return 0;
}

pair <int, int> trova_intervallo ( vector < pair<int,int> > intervalli, int dim ){
    int lunghezza = 0;
    pair<int, int> max_interv;
    for (int i=0; i<dim; i++){
        int distanza = intervalli[i+1].first - intervalli[i].second;
        if (distanza > 1){
            if (distanza > lunghezza ){
                lunghezza = distanza;
                max_interv.first = intervalli[i].second;
                max_interv.second = intervalli[i+1].first;
            }
        }
    }
    return max_interv;
}