#include<iostream>
#include<fstream>
#include<random>
#include<time.h>


using namespace std;

fstream fout;
int i,j;
int r = 0;
int Matri[0][0];

int Generate1(int rows, int columns)
{
 //fout.open("matrix_input.csv", ios::out);
 srand(time(0));
    for(i=0;i<rows;i++)
        {
         for(j=0;j<columns;j++)
         {
          r = 1 + (rand() % 9);
          Matri[i][j] = r;
          fout<<r<<",";
          cout<<"["<<r<<"]";
         }
          cout<<endl;
        }
        //cout<<endl;

    cout<<endl;
    cout<<"Note!: This will be saved to .csv file";
    cout<<endl;
    cout<<endl;
    fout.close();
    //return 0;
}

int Generate2(int rows, int columns)
{
 //fout.open("matrix_input.csv", ios::out);
 srand(time(0));
    for(i=0;i<rows;i++)
        {
         for(j=0;j<columns;j++)
         {
          r = 1 + (rand() % 9);
          Matri[i][j] = r;
          fout<<r<<",";
          cout<<"["<<r<<"]";
         }
          cout<<endl;
        }
        //cout<<endl;

    cout<<endl;
    cout<<"Note!: This will be saved to .csv file";
    cout<<endl;
    cout<<endl;
    fout.close();
    //return 0;
}

void read()
{
    vector<int> numbers;
    string line;
    fstream fin;
    fin.open("matrix_input.csv", ios::in);

    while(getline(fin, line, ','))
        {
        numbers.push_back(stoi(line));
        }
 cout << numbers[2] << endl;
}





