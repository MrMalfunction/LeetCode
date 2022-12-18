// Problem : 1396.
// Link :

#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class UndergroundSystem {
private:
    unordered_map<int, pair<int, string>> movingCustomers;
    unordered_map<string , unordered_map<string, pair<int,int>>> averageTime;

public:
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        movingCustomers[id] = make_pair(t, stationName);
    }

    void checkOut(int id, string stationName, int t) {
        string lastStation = movingCustomers[id].second;
        int startTime = movingCustomers[id].first;
        int lastAvg = averageTime[lastStation][stationName].first;
        int avgTime = 0;
        if (lastAvg != 0)
            avgTime = ((t - startTime) + lastAvg) / averageTime[lastStation][stationName].second + 1;
        else
            avgTime = ((t - startTime)) / 1;
        if (lastStation.at(0) < stationName.at(0))
            averageTime[lastStation].insert(make_pair(stationName, make_pair(avgTime,averageTime[lastStation][stationName].second + 1)));
        else
            averageTime[stationName].insert(make_pair(lastStation, make_pair(avgTime,averageTime[lastStation][stationName].second + 1)));
        movingCustomers.erase(id);
    }

    double getAverageTime(string startStation, string endStation) {
        if (startStation.at(0) < endStation.at(0))
            return averageTime[startStation][endStation].first;
        else
            return averageTime[endStation][startStation].first;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */

int main() {
    UndergroundSystem* obj = new UndergroundSystem();
    obj->checkIn(45,"Leyton",3);
    obj->checkOut(45,"Waterloo",15);
    double param_3 = obj->getAverageTime("Leyton","Waterloo");
    cout << param_3;
    return 0;
}