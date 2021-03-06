/* 
 * File:   main.cpp
 * Author: Haolan Ye(Benjamin)
 * Created on February 4, 2015, 10:58 AM
 */

#include <iostream>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
const int COL1=30;

//Function Prototypes
void filAry(char[][COL1],int,char);
void pntAry(char[][COL1],int);
void prntMap(char [][COL1],int,char);
void inject(char[][COL1],int,int,char);
void pause(int);
void gnrashn(char[][COL1],char[][COL1],int,char,char);
int cntNbor(char[][COL1],int,char,int,int);

//Execution begins here
int main(int argc, char** argv) {
    const int ROW=10;
    int nGen=20;
    //declare 2d char array
    char array[ROW][COL1]={};
    char brray[ROW][COL1]={};
    //Fill the array
    filAry(array,ROW,'*');
    filAry(brray,ROW,'*');
    //print the array without glider
    pntAry(array,ROW);
    //Inject the glider
    inject(array,1,10,'X');
    //print the array with glider
    pntAry(array,ROW);
    pause(1);
    //Game of life for generation stipulated
    for(int gen=1;gen<=nGen;gen++) {
        cout<<"Gen "<<gen<<endl;
        if(gen%2) {
            gnrashn(array,brray,ROW,'*','X');
            pntAry(brray,ROW);
        } else {
            gnrashn(brray,array,ROW,'*','X');
            pntAry(array,ROW);
        }
        pause(1);
    }
    return 0;
}

void pause(int secs) {
    //start the timer
    int end;
    int strt=static_cast<unsigned int>(time(0));
    do {
        end=static_cast<unsigned int>(time(0));
    }while(secs>(end-strt));
}


void inject(char a[][COL1],int pRow,int pCol,char c) {
    a[pRow+0][pCol+1]=c;
    a[pRow+1][pCol+2]=c;
    a[pRow+2][pCol+0]=c;
    a[pRow+2][pCol+1]=c;
    a[pRow+2][pCol+2]=c;
}

void filAry(char a[][COL1],int ROW,char d) {
    for(int r=0;r<ROW;r++) {
        for(int c=0;c<COL1;c++) {
            if(r==0) {
                a[r][c]=c%10+48;
            }else if(r==(ROW-1)) {
                a[r][c]=c%10+48;
            }else if(c==0){
                a[r][c]=c%10+48;
            }else if(c==(COL1-1)){
                a[r][c]=c%10+48;
            }else{
                a[r][c]=d;
            }
        }
    }
}
void pntAry(char a[][COL1],int ROW) {
    cout<<endl;
    for(int r=0;r<ROW;r++) {
        for(int c=0;c<COL1;c++) {
            cout<<a[r][c];
        }
        cout<<endl;
    }
    cout<<endl;
}
void prntMap(char a[][COL1],int ROW,char nd) {
    cout<<endl;
    for(int r=1;r<ROW-1;r++) {
        cout<<" ";
        for(int c=1;c<COL1-1;c++) {
            int nBr=cntNbor(a,ROW,nd,r,c);
            cout<<nBr;
        }
        cout<<endl;
    }
}

void gnrashn(char a[][COL1],char b[][COL1],int ROW,char d,char nd) {
    for(int r=1;r<ROW-1;r++) {
        for(int c=1;c<COL1-1;c++) {
            int nBr=cntNbor(a,ROW,nd,r,c);
            if(a[r][c]==nd&&nBr<=1) b[r][c]=d;
            else if(a[r][c]==nd&&(nBr==2||nBr==3)) b[r][c]=nd;
            else if(a[r][c]==nd&&nBr>=4) b[r][c]=d;
            else if(a[r][c]==d&&nBr==3) b[r][c]=nd;
            else b[r][c]=a[r][c];
        }
    }
}

int cntNbor(char a[][COL1],int ROW,char d,int r,int c) {
    //Count your neighbors
    int count=0;
    //3 TOP
    if(a[r-1][c-1]==d)  count++;
    if(a[r-1][c]==d)  count++;
    if(a[r-1][c+1]==d)  count++;
    //2 MID
    if(a[r][c-1]==d)  count++;
    if(a[r][c+1]==d)  count++;
    //3 BOTTOM
    if(a[r+1][c-1]==d)  count++;
    if(a[r+1][c]==d)  count++;
    if(a[r+1][c+1]==d)  count++;
    return count;
}