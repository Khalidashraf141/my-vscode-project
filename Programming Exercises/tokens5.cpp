#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //practice 
    int N;
    cout << "Enter number of elements: ";
    cin >> N;

    double arr[100]; //assuming max 100 numbers
    double sum = 0;

    //input numbers
    cout << "Enter " << N << "numbers: ";
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        sum +=arr[i];
    }

    double mean = sum/N;

    //variance
    double variance = 0;
    for(int i = 0; i < N; i++){
        variance += (arr[i]-mean) * (arr[i]-mean);
    }
    variance = variance/N;

    //Standard Deviation
    double std_dev = sqrt(variance);

    //Output
    cout << "Mean = "<< mean <<"\n";
    cout << "Variance = "<< variance <<"\n";
    cout << "Standard Deviation = "<< std_dev <<"\n";
    return 0;
}