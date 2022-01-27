#include<iostream>
#include<fstream>
#include<random>
#include<time.h>
#include "random.h"


using namespace std;

class Matrix{
    int **ptr;
    int rows,columns;

public:
    Matrix(int x,int y){
        rows=x;
        columns=y;
        ptr=new int*[x];
        int i,j;
        float determinant = 0;
        for(i=0;i<x;i++){
            ptr[i]=new int[y];
        }
        for(i=0;i<x;i++){
            for(j=0;j<y;j++){
                ptr[i][j]=0;
            }
        }
    }
    /*
    matrix:: ~matrix(){
        int i;
        for(i=0;i<m;i++){
            delete a[i];
        }
    }*/

    void initialize1(){
        vector<int> numbers;
        fstream fin;
        fin.open("matrix1_input.csv", ios::in);
        string line;
        int i,j;
        while(getline(fin, line, ','))
        {
            numbers.push_back(stoi(line));
        }
        int size = sizeof(numbers);                // partea asta este adaptata dupa
        int idx = 0;                               //  un exemplu de pe internet
        for(i=0;i<rows;i++){                       //  m-am chinuit prea mult sa
            for(j=0;j<columns && idx<size; j++){   // transform o martrice 1d in xd
             ptr[i][j]=numbers[idx++];             // asa ca m-am ajutat cu asta si pare ca merge
             //cout<<ptr[i][j]<<"s"<<endl;
            }
            }
}
///////////Same but for second array/////////////////////////////
        void initialize2(){
        vector<int> numbers;
        fstream fin;
        fin.open("matrix2_input.csv", ios::in);
        string line;
        int i,j;
        while(getline(fin, line, ','))
        {
            numbers.push_back(stoi(line));
        }
        int size = sizeof(numbers);                // partea asta este adaptata dupa
        int idx = 0;                               //  un exemplu de pe internet
        for(i=0;i<rows;i++){                       //  m-am chinuit prea mult sa
            for(j=0;j<columns && idx<size; j++){   // transform o martrice 1d in xd
             ptr[i][j]=numbers[idx++];             // asa ca m-am ajutat cu asta si pare ca merge
             //cout<<ptr[i][j]<<"s"<<endl;
            }
            }
}
//////////////////////////////////////////////////////////////////
    void add(Matrix p,Matrix q){
        int i,j;
        for(i=0;i<rows;i++){
            for(j=0;j<columns;j++){
                    ptr[i][j]=p.ptr[i][j]+q.ptr[i][j];
            }
        }
    }

    void multiply(Matrix p,Matrix q){
        int i,j,k;
        for(i=0; i<p.rows; i++){
            for(j=0;j<q.columns; j++){
                ptr[i][j]=0;
                for (k=0; k <q.rows; k++) {
                    ptr[i][j] += p.ptr[i][k]*q.ptr[k][j];
                }
                cout<<"["<<ptr[i][j]<<"]";
            }
             cout<<endl;
        }
    }

    void print(){
         int i,j;
         for(i=0;i<rows;i++){
            for(j=0;j<columns;j++){
                cout<<"["<<ptr[i][j]<<"]";
            }
            cout<<endl;
        }
    }
};

int main()
{
    //string line;
    int p,q,x,y;
    fstream fin;
    cout<<"First operation is addition"<<endl;
    cout<<endl;
    system("pause");
    cout<<"Enter the number of rows..";
    cin>>x;
    cout<<"Enter the no of columns..";
    cin>>y;

    fout.open("matrix1_input.csv", ios::out);
    Generate1(x,y);
    //fin.open("matrix1_input.csv", ios::in);
    Matrix a(x,y);
    a.initialize1();
    cout<<"This is your first array. The second one is coming right away!"<<endl;
    system("pause");

    fout.open("matrix2_input.csv", ios::out);
    Generate2(x,y);
    //fin.open("matrix2_input.csv", ios::in);
    Matrix b(x,y);
    b.initialize2();

    cout<<"Your workspace is:"<<endl;
    a.print();
    cout<<"and"<<endl;
    b.print();
    system("pause");
    Matrix c(x,y);
    c.add(a,b);
    cout<<"The sum of the two is.."<<endl;
    c.print();

/*
    cout<<"MULTIPLICATION!!!"<<endl;
            cout<<"Enter the no of rows first matrix..";
            cin>>x;
            cout<<"Enter the no of columns of first matrix..";
            cin>>y;
            Matrix d(x,y);
            d.initialize();
            p = y;
            cout<<"The no of rows in second matrix is automatically set to "<< p <<endl;
            cout<<"Enter the no of columns of second matrix..";
            cin>>q;
            Matrix e(p,q);
            e.initialize();
            cout<<"Your workspace is:"<<endl;
            d.print();
            cout<<"and"<<endl;
            e.print();
            cout<<"The multiplication of the two is.."<<endl;
            Matrix f(x,y);
            f.multiply(a,b);
            //cout<<"The multiplication of the two is.."<<endl;
            //c.print();
*/
    return 0;
}
