#include <iostream>
#include "ride.cpp"
using namespace std;

int main()
{

    BudgetRide budgetRide;
    budgetRide.rideId = 101;
    budgetRide.pickupLocation = "Downtown";
    budgetRide.dropoffLocation = "Airport";
    budgetRide.distanceInMiles = 5.0;

    StandartRide standardRide(102, "Mall", "Train Station", 8.5);
    LuxuryRide luxuryRide(103, "Hotel", "Conference Center", 12.0);

    // Create driver
    Driver driver1;
    driver1.driverId = 1;
    driver1.name = "Alice";
    driver1.rating = 4.8;

    // Add rides to driver
    driver1.addRide(budgetRide); // Note: object slicing will occur here if not using pointers
    driver1.addRide(standardRide);
    driver1.addRide(luxuryRide);

    // Create rider
    Rider rider1;
    rider1.riderId = 201;
    rider1.name = "Bob";

    // Add rides to rider
    rider1.addRide(budgetRide);
    rider1.addRide(standardRide);
    rider1.addRide(luxuryRide);

    // Print driver info
    cout << driver1.getDriverInfo() << endl;

    // View rider's rides
    cout << "Rider's Rides:\n";
    rider1.viewRides();

    return 0;
}