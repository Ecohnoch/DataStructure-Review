#include <iostream>

using namespace std;


// From 000000 - 111111
int a[6];
int main(){
    for(int i = 0; i < 6; ++i){
        a[i] = 0;
        cout<<a[i]<<" ";
    }
    cout<<endl;

    int count = 0;
    while(count < 63){
        int c = 0;
        a[0]++;
        while(a[c] > 1){
            a[c] = 0;
            c++;
            a[c]++;
        }

        for(int i = 0; i < 6; ++i)
            cout<<a[i]<<" ";
        cout<<endl;

        count ++;
    }
}
