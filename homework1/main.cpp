#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 2;
        temp = temp / 2;

        dec_value += last_digit * base;

        base = base * 10;
    }

    return dec_value;
}

int main(){
    int x=0;
    ofstream myfile;
    myfile.open ("file.txt");
    for(int i = 0; i<1024; i++){
        myfile<<binaryToDecimal(x)<<endl;
        x++;
    }
    myfile.close();
    return 0;
}
