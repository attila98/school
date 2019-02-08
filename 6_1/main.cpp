#include <iostream>
#include <math.h>

using namespace std;



int main()
{
    int szama;
    cin>>szama;
    int m;
    cin>>m;
    double t[m];
    double f[m];
    int n;

    if(szama==1){
    cin>>n;
    }
    if(szama==2){
        n=2;
    }

    for(int i=0; i<m;i++){
        cin>>t[i];
    }

    for(int i=0; i<m;i++){
        cin>>f[i];
    }

    if(szama==1){
    double A[m][n];

    for(int i=0;i<m;i++){
            A[i][0]=1;
        }

    for(int i=0;i<m;i++){
        for(int j=1;j<n;j++){
            A[i][j]=pow(t[i],j);
        }
    }

            double aTa[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                aTa[i][j]=0;
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<m;k++){
                    aTa[i][j]+=A[k][i]*A[k][j];
                }
            }
        }

        double aTf[n];
        for(int i=0;i<n;i++){
            aTf[i]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                    aTf[i]+=A[j][i]*f[j];
            }
        }


    //Cholesky
    double a[n][n];
    double b[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j]=aTa[i][j];

    for(int i=0;i<n;i++){
        b[i]=aTf[i];
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


    for(int i=0; i<n;i++){
        for(int j=0; j<i;j++){
            b[i]=b[i]-a[i][j]*b[j];
        }
        b[i]=b[i]/a[i][i];
    }


    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            b[i]=b[i]-a[j][i]*b[j];
        }
        b[i]=b[i]/a[i][i];
    }

     for(int i=0;i<n;i++){
        cout<<b[i]<<"\n";
    }



    }

    if(szama==2){
        double A[m][n];
        for(int i=0;i<m;i++){
            A[i][0]=1;
        }
        for(int i=0;i<m;i++){
            A[i][1]=1/t[i];
        }

        double aTa[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                aTa[i][j]=0;
            }
        }


        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                for(int k=0;k<m;k++){
                    aTa[i][j]+=A[k][i]*A[k][j];
                }
            }
        }

        double aTf[n];
        for(int i=0;i<n;i++){
            aTf[i]=0;
        }

        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                    aTf[i]+=A[j][i]*f[j];
            }
        }


    //Cholesky
    double a[n][n];
    double b[n];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a[i][j]=aTa[i][j];

    for(int i=0;i<n;i++){
        b[i]=aTf[i];
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


    for(int i=0; i<n;i++){
        for(int j=0; j<i;j++){
            b[i]=b[i]-a[i][j]*b[j];
        }
        b[i]=b[i]/a[i][i];
    }


    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            b[i]=b[i]-a[j][i]*b[j];
        }
        b[i]=b[i]/a[i][i];
    }

     for(int i=0;i<n;i++){
        cout<<b[i]<<"\n";
    }



    }

    if(szama==3){

    }
    if(szama!=1 && szama!=2 && szama!=3 ){
    cout<<"Hiba";
    }

    return 0;
}
