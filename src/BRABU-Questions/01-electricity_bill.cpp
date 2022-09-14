#include <iostream>
using namespace std;
class ElectricBill
{
    int totalUnits;
    float totalCharge;
    float basicCharge()
    {
        if (totalUnits <= 100)
            return totalUnits * 0.5;
        else if (totalUnits <= 300)
            return (100 * 0.5) + ((totalUnits - 100) * 0.8);
        else /*beyond 300 units*/
            return (100 * 0.5) + (200 * 0.8) + ((totalUnits - 300) * 0.9);
    }

    void totalChargeCalculator()
    {
        float baseCharge = basicCharge();
        totalCharge = baseCharge + 50; /*fixed compulsory charge for everyone*/
        if (totalCharge > 300)
            totalCharge += totalCharge * 0.15;
    }

public:
    ElectricBill(int unit)
    {
        totalUnits = unit;
        totalCharge = 0;
    }

    float calculateCharge()
    {
        totalChargeCalculator();
        return totalCharge;
    }
};

int main()
{
    int unit = 0;
    cout << "Write your electriciy consumption(in units): ";
    cin >> unit;
    ElectricBill bill(unit);
    cout << "Total charge: " << bill.calculateCharge() << endl;
    return 0;
}