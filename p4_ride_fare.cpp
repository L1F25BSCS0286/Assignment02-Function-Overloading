#include <iostream>
#include <fstream>
using namespace std;

double fare(double km, double ratePerKm = 40.0);
double fare(double km, double ratePerKm, bool peakHour);
double fare(double km, char vehicle);
double fare(double km, char vehicle, int promoPercent);

int main() {
    cout << "fare(10) = " << fare(10) << endl;
    cout << "fare(10, 30.0) = " << fare(10, 30.0) << endl;
    cout << "fare(10, 30.0, true) = " << fare(10, 30.0, true) << endl;
    cout << "fare(8, 'B') = " << fare(8, 'B') << endl;
    cout << "fare(8, 'C') = " << fare(8, 'C') << endl;
    cout << "fare(8, 'C', 10) = " << fare(8, 'C', 10) << endl;

    // ---- Part B: write your code below this line ----

    int n;
    cout << "How many rides? ";
    cin >> n;

    ofstream file("rides.txt");
    double total = 0.0;

    for (int i = 1; i <= n; i++) {
        char vehicle;
        double km;
        int promo;

        cout << "Ride " << i
            << " vehicle (B/R/C), km, promo %: ";
        cin >> vehicle >> km >> promo;

        double amount;

        if (promo == 0)
            amount = fare(km, vehicle);
        else
            amount = fare(km, vehicle, promo);

        file << "Ride " << i << " (" << vehicle << "), "
            << km << " km -> Rs. " << amount << endl;

        total += amount;
    }

    file << "Total collected: Rs. " << total << endl;
    file.close();


    return 0;
}

double fare(double km, double ratePerKm) {
    return 100 + km * ratePerKm;
}

double fare(double km, double ratePerKm, bool peakHour) {
    double amount = fare(km, ratePerKm);

    if (peakHour)
        amount *= 1.20;

    return amount;
}

double fare(double km, char vehicle) {
    double rate;

    if (vehicle == 'B')
        rate = 25.0;
    else if (vehicle == 'R')
        rate = 35.0;
    else if (vehicle == 'C')
        rate = 50.0;
    else
        return 0.0;

    return fare(km, rate);
}

double fare(double km, char vehicle, int promoPercent) {
    double amount = fare(km, vehicle);
    return amount - (amount * promoPercent / 100.0);
}