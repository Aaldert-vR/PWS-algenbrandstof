#include <bits/stdc++.h>
using namespace std;
int handleArduino(){
    setup();
    while (true){
        loop();
    }
    return 0;
}


int main(){
    cout << "hoi";
    thread t(environment);
    cout << "Thread made";
    t.detach();
    cout << "Thread detached";
    handleArduino();
    return 0;
}

