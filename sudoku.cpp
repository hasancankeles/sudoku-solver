#include<bits/stdc++.h>

#define FOR(i,j,k) for(i=j;i<k;i++)
using namespace std;
int A[10][10];
int satir[10][10],sutun[10][10],kare[10][10];
int sifir[82][2];
int sifir_sayisi;
void veri_oku()
{
            int i,j,gecici;
            ifstream r("sudoku.in");
            FOR(i,0,9)
                FOR(j,0,9)
                {
                    r>>A[i][j];
                    if(!A[i][j])
                    {
                        sifir[sifir_sayisi][0]=i;
                        sifir[sifir_sayisi++][1]=j;
                    }
                    else
                    {
                            gecici=A[i][j];
                            satir[i][gecici]=1;
                            sutun[j][gecici]=1;
                            kare[i/3*3+(j+3)/3][gecici]=1;
                    }

                }
            r.close();
}
void yaz()
{
        int i,j;
        FOR(i,0,9)
        {
            FOR(j,0,9)
                cout<<A[i][j]<<' ';
            cout<<endl;
        }
        exit(0);
}
void ekle(int i,int j,int a)
{
        A[i][j]=a;
        satir[i][a]=1;
        sutun[j][a]=1;
        kare[i/3*3+(j+3)/3][a]=1;
}
void cikar(int i,int j,int a)
{
        A[i][j]=0;
        satir[i][a]=0;
        sutun[j][a]=0;
        kare[i/3*3+(j+3)/3][a]=0;
}
void yap(int yer)
{
        if(yer==sifir_sayisi) yaz();
        int i=sifir[yer][0],j=sifir[yer][1],a;
        FOR(a,1,10)
            if(!satir[i][a] && !sutun[j][a] && !kare[i/3*3+(j+3)/3][a])
            {
                    ekle(i,j,a);
                    yap(yer+1);
                    cikar(i,j,a);
            }
}
main()
{
        veri_oku();
        yap(0);
        getchar();
}
