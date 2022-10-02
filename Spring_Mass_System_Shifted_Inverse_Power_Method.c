#include<stdio.h>
#include<conio.h>
#include<math.h>

float determinant(float[][40], float);

void main()
{

    int i,j,n,q,p,m, axe,k;
    float InitialA[40][40],InitialA2[40][40], x[40],z[40],e[40],mu,tol, alpha, det=0, InverseA[40][40], fac[40][40], trans[40][40], b[40][40];


    /////////////INITIAL A-MATRIX//////////////
    n=2;
    printf("\nEnter A-matrix elements\n");
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("A[%d][%d]=", i+1,j+1);
            scanf("%f",&InitialA[i][j]);
        }
    }
     printf("\nThe Initial Matrix: \n");
    for(i=0;i<2;i++)
    {
        for(j=0;j<2;j++)
        {
           printf("%f\t", InitialA[i][j]);
        }
        printf("\n");
    }

    ///////////////ALPHA VALUE////////////////

    printf("\nEnter the value of alpha:");
    scanf("%f",&alpha);




    /////////////INITIAL COLUMN VECTOR///////////

    printf("\nEnter the column vector\n");
    for(i=0; i<n; i++)
    {
        printf("X[%d]=",i+1);
        scanf("%f",&x[i]);
    }


    /////////A-matrix1 subtracted by alpha////////

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
            {
                InitialA2[i][j] = InitialA[i][j] - alpha;
            }
            else
            {
                InitialA2[i][j] = InitialA[i][j];
            }
        }
    }


     printf("\nThe Initial Matrix subtracted by user inputted alpha: \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
           printf("%f\t", InitialA2[i][j]);
        }
        printf("\n");
    }
    det = determinant(InitialA2, n);
    printf("\nThe Determinant of this (A-alphaI)-matrix is: %f \n", det);

    ////////Inversing the Initial A2-matrix////////

    axe = n;
     for (q = 0;q < axe; q++)
        {
        for (p = 0;p < axe; p++)
        {
            m = 0;
            n = 0;

            for (i = 0;i < axe; i++)
            {
                for (j = 0;j < axe; j++)
                {
                    if (i != q && j != p)
                    {

                        b[m][n] = InitialA2[i][j];
                        if (n < (axe - 2))
                            {
                            n++;
                            }
                            else
                            {
                                n = 0;
                                m++;
                            }
                    }
                }
            }
            fac[q][p] = pow(-1, q + p) * determinant(b, axe - 1);
        }
        }

        for (i = 0;i <axe; i++)
        {
            for (j = 0;j<axe; j++)
            {
            trans[i][j] = fac[j][i];
            }
        }

          for (i = 0;i<axe; i++)
        {
            for (j = 0;j<axe;j++)
            {
                InverseA[i][j] = trans[i][j] / det;
            }
        }

           printf("\n\n\nThe inverse of (A-alphaI)-matrix is : \n");
            for (i = 0;i < axe; i++)
            {
                for (j = 0;j < axe; j++)
                    {
                    printf("\t%f", InverseA[i][j]);
                    }
            printf("\n");
            }


    //////// Power Method of (A-alphaI)-matrix ////////

    printf("\nIteration \t\t X-vector \t mu-value\t\t Eigenvector\tLambda-value\tomega-value\n");
    n = axe;
    for(i=0;i<n;i++)
       {
           z[i]=0;
       }


       mu = 0;
         k=0;
   do
   {

       printf("%d \t\t", k);
       k+=1;
       printf("(%f,%f)\t", x[0],x[1]);
       printf("%f\t", mu);
       printf("(%f,%f)\t", z[0],z[1]);
       printf("%f\t", ((1/mu)+alpha));
       if (((1/mu)+alpha)>0)
       {
           printf("%f\n", sqrt(((1/mu)+alpha)));
       }
       else
       {
           printf("%f\n", sqrt(-1*((1/mu)+alpha)));
       }


       for (i=0;i<n;i++)
       {
           z[i]=0;
           for(j=0;j<n;j++)
           {
               z[i]=z[i]+(InverseA[i][j]*x[j]);
           }
       }
       mu=fabs(z[0]);
       for(i=1;i<n;i++)
       {
           if((fabs(z[i]))>mu)
                mu=fabs(z[i]);
       }
       for(i=0;i<n;i++)
       {
           z[i]=z[i]/mu;
       }
       for(i=0;i<n;i++)
       {
           e[i]=0;
           e[i]=fabs((fabs(z[i]))-(fabs(x[i])));
       }
       tol=e[0];
       for(i=1;i<n;i++)
       {
           if(e[i]>tol)
             tol=e[i];
       }

       for(i=0;i<n;i++)
       {
           x[i]=z[i];
       }
   }
   while(tol>0.000001);
    printf("\nIteration \t\t X-vector \t mu-value\t\t Eigenvector\tLambda-value\tomega-value\n");

   printf("\n\n\n~~FINAL OUTPUT~~\n");
   printf("Dominant mu-value = %f\n", mu);
   printf("Dominant eigenvalue = %f\n", sqrt((1/mu)+alpha));
   printf("mode shapes: (%f,%f)", z[0],z[1]);

    getch();
}

float determinant (float a[40][40], float k)
{

    float s=1, det = 0, b[25][25];
    int i, j, m, n, c;

    if (k == 1)
    {
        return a[0][0];
    }
    else
    {
        det=0;
        for (c = 0; c<k ; c++)
            {
                m = 0;
                n = 0;
                for (i = 0; i<k ; i++)
                    {
                        for (j = 0; j<k ; j++)
                        {
                            b[i][j] = 0;
                            if (i != 0 && j != c)
                            {
                                b[m][n] = a[i][j];
                                if(n < (k-2))
                                    n++;
                                else
                                {
                                    n = 0;
                                    m++;
                                }
                            }
                        }
                    }
                    det = det + s * (a[0][c] * determinant(b, k-1));
                    s = -1 * s;
            }
    }
    return(det);
}

