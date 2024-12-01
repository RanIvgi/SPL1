#pragma once
#include <vector>
#include "Facility.h"
#include "Settlement.h"
#include "SelectionPolicy.h"
using std::vector;

enum class PlanStatus
{
    AVALIABLE,
    BUSY,
};

class Plan
{
public:
    Plan(const int planId, const Settlement &settlement, SelectionPolicy *selectionPolicy, const vector<FacilityType> &facilityOptions);
    const int getlifeQualityScore() const;
    const int getEconomyScore() const;
    const int getEnvironmentScore() const;
    void setSelectionPolicy(SelectionPolicy *selectionPolicy);
    void step();
    void printStatus();
    const vector<Facility *> &getFacilities() const;
    void addFacility(Facility *facility);
    const string toString() const;
    int limit(const Settlement &settle); // return the limit to construction facility
    const std::string getStatus();
    const int getID() const; // returns the plan's ID
    const SelectionPolicy* getSelectionPolicy() const;
    const vector<Facility*> getUnderConstruction() const;
    // complete - Rule of 5 //
    Plan &operator=(const Plan &other) = delete;
    Plan &operator=(const Plan &&other) = delete;
    ~Plan();
    Plan(const Plan &other);
    Plan(Plan &&other); // move func

private:
    int plan_id;
    const Settlement &settlement;
    SelectionPolicy *selectionPolicy;
    PlanStatus status;
    vector<Facility *> facilities;
    vector<Facility *> underConstruction;
    const vector<FacilityType> &facilityOptions;
    int life_quality_score, economy_score, environment_score;
};