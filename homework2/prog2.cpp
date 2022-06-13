//Written by Jake Barklund
//October 1 2019
//CodeBlocks
//C++

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

char flipbits(char c) {
    return (c == '0')? '1': '0';
    }

void oneandtwo(string c)
{
    int i, n = c.length();
    string o, t;

    if(c[0]=='0'){
        long oInt = stol(c, 0, 2);
        cout<<oInt<<" ";
        cout<<oInt<<endl;
    }
    if(c[0]=='1'){
        for (i = 0; i < n; i++){
            o += flipbits(c[i]);
        }
        t = o;
        for (i = n - 1; i >= 0; i--){
            if (o[i] == '1'){
                t[i] = '0';
            }
            else{
                t[i] = '1';
                break;
            }
        }
        if (i == -1){
            t = '1' + t;
        }

        long onesInt = stol(o, 0, 2);
        long twosInt = stol(t, 0, 2);
        cout<<"-"<<onesInt<<" ";
        cout<<"-"<<twosInt<<endl;
        }
}
int signedMag(string c){
    string x;
    if(c[0]=='1'){
        c[0] = '0';
        long sInt = stol(c, 0, 2);
        cout<<"-"<<sInt<<" ";
    }
    else if(c[0]=='0'){
        long xInt = stol(c, 0, 2);
        cout<<xInt<<" ";
    }

    return 0;
}

int main(){
    string inputname, num, x;
    cout<<"Enter a valid filename: ";
    cin>>inputname;
    ifstream filename(inputname.c_str());
    filename.is_open();
    while(getline(filename,x)){
        stringstream r(x);
        if(x.length()>0){
            r>>num;
            long integer = stol(num,0,2);
            cout<<integer<<" ";
            signedMag(num);
            cout<<" ";
            oneandtwo(num);
        }
    }
    filename.close();
    return 0;
}
