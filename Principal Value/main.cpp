/*
   Principal-Value.cpp
 
   Created by Austin Flores on 12/06/13.
   Copyright (c) 2013 Austin Flore. All rights reserved.
 */

#include <iostream>        //required for display output
#include <cmath>           //required for pow and sqrt
#include <iomanip>         //required for setw or setprecision
#include <string>          //required for string class

using namespace std;       //requred to access entities with namespace std

double calculator(double withdraw, double interest, int years)
{
    double deposit;
    deposit = withdraw * pow(1 + interest, -years);
    return deposit;
}
int main()
{
    cout << "\t\tWelcome to Principal Value Calculator\n\n";
    cout << "This will help you determin the about of money needed to deposit into a bank CD account in order to withdraw a predetermined amount of money.";
    
    double deposit, withdraw, interest;
    int years;
    
    float const oneyearrate = .001;
    float const twoyearrate = .002;
    float const fiveyearrate = .0075;
    
    cout << "\n\nHow much would you like to withdraw in the future?\n";
    cin >> withdraw;
    
    while (withdraw < 1)
    {
        cout << "\n\tError please enter a doller amount greater than ZERO";
        cin >> withdraw;
    }
    
    cout << "\nHow many years can you store your money in the bank?\n";
    cin >> years;
    
    while (years < 1)
    {
        cout << "\n\tError please enter number of years greater than ZERO";
        cin >> years;
    }

    if (years == 1)
    {
        interest = oneyearrate;
        deposit = calculator(withdraw, interest, years);
    }
    else if (years > 1 && years < 5)
    {
        interest = twoyearrate;
        deposit = calculator(withdraw, interest , years);
    }
    else
    {
        interest = fiveyearrate;
        deposit = calculator(withdraw, interest, years);
    }
    cout << "\nIn order to withdraw " << withdraw << " your will need to deposit ";
    cout << fixed << setprecision(2) << deposit << " and leave it in the bank for " << years << " years";
    
    cout << "\n\n";
    return 0;
}

