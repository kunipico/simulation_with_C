/* 
qe_error.cプログラム
*/

/*暗黙の方変換に関する例題プログラム。結果は正しくない。 */

#include <stdio.h>
#include <math.h>
#include<stdlib.h>

#define BUFSIZE 256

int getdouble(double *x);

int main(){

    double a,b,c;
    int d;

    printf("係数aを入力してください。");
    if(getdouble(&a)==EOF) exit(1);
    if(a==0) exit(1);/*二次方程式ではない */
    printf("係数bを入力してください。");
    if(getdouble(&b)==EOF) exit(1);
    printf("係数cを入力してください。");
    if(getdouble(&c)==EOF) exit(1);

    /*判別式の計算*/
    d=b*b-4*a*c;
    if(d==0)
        printf("x=%lf\n",-b/2/a);
    else if(d<0)
        printf("x=%lf+%lfi,%lf-%lfi\n",-b/2/a,sqrt(-d)/2/a,-b/2/a,sqrt(-d)/2/a);
    else
        printf("x=%lf,%lf\n",-b/2/a+sqrt(d)/2/a,-b/2/a-sqrt(d)/2/a);
    return 0;
}

int getdouble(double *x){
    
    char linebuf[BUFSIZE];
    int result=0;

    if(fgets(linebuf,BUFSIZE,stdin)!=NULL){
        if(sscanf(linebuf,"%lf",x)<=0)
            result=EOF;
    }else{
        result=EOF;
    }
    return result;
}

