#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    int nnz;

    cin>>n;
    cin>>nnz;

    double x[n];
    double ertek[nnz];
    int sor[nnz];
    int oszlop[nnz];
    double y[n];


    for(int i=0;i<nnz;i++){
        cin>>ertek[i];
    }

    for(int i=0;i<nnz;i++){
        cin>>sor[i];
    }

    for(int i=0;i<nnz;i++){
        cin>>oszlop[i];
    }


    for(int i=0;i<n;i++){
        cin>>x[i];
        y[i]=0;
    }

    for(int k=0;k<nnz;k++){
        y[sor[k]-1]+=ertek[k]*x[oszlop[k]-1];
    }

    cout<<endl;
    for(int k=0; k<n;k++){
        cout<<y[k]<<endl;
    }

    return 0;
}
