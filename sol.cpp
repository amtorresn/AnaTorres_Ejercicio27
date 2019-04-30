#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;
using std::cout;
using std::endl;

void solve(string filename);

int main(){
    solve("datos.dat");
    return 0;
}

void solve(string filename){
    
    ofstream outfile;
    outfile.open(filename);
    
    double M[101][101];
    
    //Inicializa
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            M[i][j] = 0;
        }
    }
    for (int i = 0; i < 101; i++){
        
        M[0][i] = 0;
        M[i][0] = 0;
        M[100][i] = 0;
        M[i][100] = 0;
        
    }
    for(int i = 20; i < 100 -19; i++){
              
        M[40][i] = 100;
        M[60][i] = -100;
    }
    
    //Old
    double M_old[101][101];
    
    for (int i = 0; i < 101; i++){
        for (int j = 0; j < 101; j++){
            M_old[i][j] = M[i][j];
        }
    }
    
     //Promedio
    double dif[101][101];
    double diferencia = 100;
    
    while(diferencia > 0.1){
        double num;
        for(int i = 1; i < 100; i++){
            for(int j = 1; j < 100; j++){
                if(i!=20 || i!=40 || j < 20 || j >80){
                    M[i][j] = 0.25*(M_old[i+1][j] + M_old[i-1][j] + M_old[i][j+1] + M_old[i][j-1]);
                    dif[i][j] = abs(M[i][j] - M_old[i][j]);
                }
            }
        }
        for(int i = 1; i < 100; i++){
            for(int j = 1; j < 100; j++){
                num += dif[i][j];
            }
        }
        diferencia = num/(100*100);
    }
    for(int i = 1; i < 100; i++){
        for(int j = 1; j < 100; j++){
            outfile << M[i][j] << endl;
        }
    }
    outfile.close();
    
}