//Complejidad O(n)

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int gasTank;
    int kmRecorridos = 0;
    cout << "Introduce la cantidad de kilometros que el coche puede recorrer con el tanque lleno" << endl;
    cin >> gasTank;
    cout << endl;

    vector<int> gasDist;
    vector<int> stops;

    gasDist.push_back(13);
    gasDist.push_back(54);
    gasDist.push_back(86);
    gasDist.push_back(14);
    gasDist.push_back(13);
    gasDist.push_back(31);
    gasDist.push_back(37);
    gasDist.push_back(64);
    gasDist.push_back(44);
    gasDist.push_back(43);

    int gasF = gasTank;;
    for(int i = 0;i <= gasDist.size()-1 ;i++){
        gasF-=gasDist[i];
        kmRecorridos+=gasDist[i];

        if(gasF<gasDist[i+1]){
            stops.push_back(i);
            gasF = gasTank;
        }
    }

    if(kmRecorridos >= 378){//378 km entre CDMX y Acapulco
        if(stops.empty()){
        }else{
            cout << "El coche se paro en las siguientes gasolineras" << endl;
            for(int i = 0; i< stops.size();i++){
                cout << "Parada número " << i <<": "<< stops[i]<< endl;
            }
        }
    }else {
        cout << "El coche no puede recorrer el trayecto con ese tanque de gasolina" << endl;
        cout << "El coche recorrió: " << kmRecorridos << endl;
    }


    return 0;
}
