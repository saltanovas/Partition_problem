#include <stdio.h>
#include <stdlib.h>

void arFailasEgzistuoja(FILE *duomf)
{
    if  (!duomf)
    {
        printf("Toks duomenu failas neegzistuoja!\n");
        exit(1);
    }
}

void arFailasTuscias(FILE *duomf)
{
    fseek(duomf, 0, SEEK_END);
    if (ftell(duomf) == 0)
    {
        printf("Duomenu failas yra tuscias!\n");
        exit(1);
    }
    fseek(duomf, 0, SEEK_SET);
}

int kiekElementu(FILE *duomf)
{
    int n = 0;
    double reiksme;
    while(fscanf(duomf, "%lf", &reiksme) != EOF)
        n++;

    rewind(duomf);
    return n;
}

void uzpildytiMasyva(FILE *duomf, double A[], int n)
{
    double reiksme;
    int i = 0;

    while(fscanf(duomf, "%lf", &reiksme) == 1)
    {
        A[i] = reiksme;
        i++;
    }
}

void isrikiuoti(double A[], int n)
{
    double laik;

    for(int i=0; i<n-1; i++)
        for(int j=i+1; j<n; j++)
            if(A[i] < A[j])
            {
                laik = A[i];
                A[i] = A[j];
                A[j] = laik;
            }
}

int atrinkti(double A[], double A1[], double A2[], int n)
{
    double sum = 0;
    for(int i=0; i<n; i++)
        sum += A[i];
    double s = sum/2;

    sum = 0;
    int index1 = 0;
    int index2 = 0;

    for(int i=0; i<n; i++)
    {
        if(s >= (sum+A[i]))
        {
            sum += A[i];
            A1[index1] = A[i];
            index1++;
        }
        else
        {
            A2[index2] = A[i];
            index2++;
        }
    }
    return index1;
}

void isvedimas(double A1[], double A2[], int n, int sk)
{
    for(int i=0; i<sk; i++)
        printf("%.2f ", A1[i]);
    printf("\n");

    for(int i=0; i<n-sk; i++)
        printf("%.2f ", A2[i]);
    printf("\n");
}


int main(int argc, char *argv[])
{

    FILE *duomf = fopen(*(argv+1), "r");

    arFailasEgzistuoja(duomf);
    arFailasTuscias(duomf);
    int n = kiekElementu(duomf);
    double *A = (double*) malloc (n*sizeof(double));
    uzpildytiMasyva(duomf, A, n);
    fclose(duomf);

    isrikiuoti(A, n);
    double *A1 = (double*) malloc (n*sizeof(double));
    double *A2 = (double*) malloc (n*sizeof(double));
    int sk = atrinkti(A, A1, A2, n);
    isvedimas(A1, A2, n, sk);

    free(A);
    free(A1);
    free(A2);

    return 0;
}
