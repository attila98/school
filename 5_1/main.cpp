#include <iostream>
#include <math.h>

using namespace std;
//Cholesky
int main()
{
    int n;
    cin>>n;
    double a[n][n];
    double b[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin>>a[i][j];

    for(int i=0;i<n;i++){
        cin>>b[i];
    }

    for(int k=0; k<n;k++){
        if(a[k][k]<1e-15){
            cout<<"Hiba a(z)"<<k+1<<".dik lepesben\n";
            return 0;
        }
        a[k][k]=sqrt(a[k][k]);

        for(int i=k+1;i<n;i++){
            a[i][k]=a[i][k]/a[k][k];

            for(int j=k+1;j<=i;j++){
                a[i][j]=a[i][j]-a[i][k]*a[j][k];
            }
        }
    }

    /*for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout<<a[i][j]<<" ";}
        cout<<"\n";
    }*/

    for(int i=0; i<n;i++){
        for(int j=0; j<i;j++){
            b[i]=b[i]-a[i][j]*b[j];
        }
        b[i]=b[i]/a[i][i];
    }

    /*for(int i=0;i<n;i++){
        cout<<b[i]<<"\n";
    }*/

    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            b[i]=b[i]-a[j][i]*b[j];
        }
        b[i]=b[i]/a[i][i];
    }

     for(int i=0;i<n;i++){
        cout<<b[i]<<"\n";
    }
    return 0;
}
