
#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

long long  iterativeFactorial(int n) {
    long long result = 1;

    for (int i = 1; i <= n; ++i) 
        result *= i;
    
    return result;
}

long long  recursiveFactorial(int n) {
    if (n == 0 || n == 1) 
        return 1;
    
    else 
        return n * recursiveFactorial(n - 1);
    
}

double testOfFactorial(long long (*functionOfFactorial)(int), int n) {
    auto begin = high_resolution_clock::now();
    functionOfFactorial(n);
    auto end = high_resolution_clock::now();

    duration<double, milli> timeOfFactorial = duration_cast<duration<double>>(end - begin);
    return timeOfFactorial.count();
}

int main() {
    int numberToTest;
    cout << "enter the number you want to calculate factorial:" << endl;
    cin >> numberToTest;

    cout << "Iterative factorial of " << numberToTest << " is: " << iterativeFactorial(numberToTest) << endl;
    cout << "Time taken for iterative factorial: " << testOfFactorial(iterativeFactorial, numberToTest) << " milliseconds" << endl;


    cout << "Recursive factorial of " << numberToTest << " is: " << recursiveFactorial(numberToTest) << endl;
    cout << "Time taken for recursive factorial: " << testOfFactorial(recursiveFactorial, numberToTest) << " milliseconds" << endl;

    return 0;
}
