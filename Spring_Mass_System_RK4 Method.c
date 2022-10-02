#include <stdio.h>
#include <math.h>

float gfxn1(float x1, float x2)
{
    return(-3*x1+2*x2);
}

float gfxn2(float x1, float x2, float t)
{
    return(x1-1.5*x2+sin(t));
}
void main ()
{
int i,j,n;
float h, t, y[30], x[30], f1[30], f2[30], f3[30], f4[30], g1[30], g2[30], g3[30], g4[30], maxtime;

printf("Enter until what time the values will be computed:");
scanf("%f", &maxtime);
printf("Enter step size: ");
scanf("%f", &h);

printf("\n\nGiven that initial at time = 0, x(0) = 0 and x'(0) = 0 \n\n");

for(i=0;i<2;i++)
{
    f1[i]=0;
    f2[i]=0;
    f3[i]=0;
    f4[i]=0;
    g1[i]=0;
    g2[i]=0;
    g3[i]=0;
    g4[i]=0;
    x[i]=0;
    y[i]=0;
}

t=0;
n=0;
printf("\nIteration\tTIME\t\tf1\t\tf2\t\tf3\t\tf4\t\tx-vector\tg1\t\tg2\t\tg3\t\tg4\t\ty-vector\n");
do
{

printf("%d\t\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n",n, t,f1[0],f2[0], f3[0], f4[0],x[0], g1[0], g2[0], g3[0], g4[0],y[0] );
printf("\t\t\t\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\t%f\n\n",f1[1],f2[1], f3[1], f4[1],x[1], g1[1], g2[1], g3[1], g4[1],y[1]);

f1[0] = y[0];
g1[0] = gfxn1(x[0],x[1]);
f1[1] = y[1];
g1[1] = gfxn2(x[0],x[1],t);
f2[0] = (y[0] + (h*0.5*g1[0]));
g2[0] = gfxn1(x[0]+(h*0.5*f1[0]),x[1]+(h*0.5*f1[1]));
f2[1] = (y[1] + (h*0.5*g1[1]));
g2[1] = gfxn2(x[0]+(h*0.5*f1[0]),x[1]+(h*0.5*f1[1]),t+(h*0.5));
f3[0] = (y[0] + (h*0.5*g2[0]));
g3[0] = gfxn1(x[0]+(h*0.5*f2[0]),x[1]+(h*0.5*f2[1]));
f3[1] = (y[1] + (h*0.5*g2[1]));
g3[1] = gfxn2(x[0]+(h*0.5*f2[0]),x[1]+(h*0.5*f2[1]),t+(h*0.5));
f4[0] = (y[0] + (h*g3[0]));
g4[0] = gfxn1(x[0]+(h*f3[0]),x[1]+(h*f3[1]));
f4[1] = (y[1] + (h*g3[1]));
g4[1] = gfxn2(x[0]+(h*f3[0]),x[1]+(h*f3[1]),t+(h));

 x[0] =  x[0] + (h*(f1[0]+2*f2[0]+2*f3[0]+f4[0])/6);
 y[0] =  y[0] + (h*(g1[0]+(2*g2[0])+(2*g3[0])+g4[0])/6);
 x[1] =  x[1] + (h*(f1[1]+2*f2[1]+2*f3[1]+f4[1])/6);
 y[1] =  y[1] + (h*(g1[1]+(2*g2[1])+(2*g3[1])+g4[1])/6);
t = t+h;
n+=1;
}
while (t<maxtime+0.1);

getch(0);


}
