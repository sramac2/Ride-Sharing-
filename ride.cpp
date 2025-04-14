#include <iostream>
#include <sstream>
using namespace std;

class Ride
{
public:
    int rideId;
    string pickupLocation;
    string dropoffLocation;
    double distanceInMiles;
    double fare()
    {
        return distanceInMiles;
    }
    string rideDetails()
    {
        std::stringstream ss;
        ss << "Ride ID: " << rideId << ", Pickup: "
           << pickupLocation << ", Dropoff: " << dropoffLocation << "Fare: " << fare();
        return ss.str();
    }
};

class BudgetRide : public Ride
{
public:
    double fare()
    {
        return distanceInMiles * 10;
    }
};

class StandartRide : public Ride
{
public:
    StandartRide(int rideId, string pickupLocation, string dropoffLocation, double distance)
    {
        this->rideId = rideId;
        this->distanceInMiles = distance;
        this->pickupLocation = pickupLocation;
        this->dropoffLocation = dropoffLocation;
    }

    double fare()
    {
        return distanceInMiles * 25;
    }
};

class LuxuryRide : public Ride
{
public:
    LuxuryRide(int rideId, string pickupLocation, string dropoffLocation, double distance)
    {
        this->rideId = rideId;
        this->distanceInMiles = distance;
        this->pickupLocation = pickupLocation;
        this->dropoffLocation = dropoffLocation;
    }
    double fare()
    {
        return distanceInMiles * 50;
    }
};

class Driver
{
private:
    vector<Ride> assignedRides;

public:
    int driverId;
    string name;
    double rating;
    void addRide(Ride ride)
    {
        assignedRides.push_back(ride);
    }
    string getDriverInfo()
    {
        std::stringstream ss;
        ss << "Driver ID: " << driverId << ", Name: " << name << ", Rating: " << rating << ", Assigned rides: ";
        for (Ride ride : assignedRides)
        {
            ss << ride.rideDetails();
        }
        return ss.str();
    }
};

class Rider
{
private:
    vector<Ride> requestedRides;

public:
    int riderId;
    string name;
    void addRide(Ride ride)
    {
        requestedRides.push_back(ride);
    }
    void viewRides()
    {
        for (Ride r : requestedRides)
        {
            cout << r.rideDetails();
        }
    }
};
