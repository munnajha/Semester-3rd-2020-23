/*Question:
  An electriciy board charges the following rates to domestic users to discourage large consumption of energy:
  For the first 100 units - 50 Paisa/Unit,
  For the next 200 units - 80 Paisa/Unit,
  Beyond 300 units - 90 Paisa/Unit,
  All users are changed a minimum of rupees 50.00.
  If the total amount is more than Rs 300 then and additional surchange of 15% is added.
  Write a C++ program to read the names of users and number of units consumed and print out the charges with name.

*/
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
    char name[30];
    cout << "write name of user: ";
    cin >> name;
    cout << "Write your electriciy consumption(in units): ";
    cin >> unit;
    ElectricBill bill(unit);

    cout << "==========BILL DETAILS==========" << endl;
    cout << "Name " << name << endl;
    cout << "Units consumed: " << unit << endl;
    cout << "Total charge: Rs " << bill.calculateCharge() << endl;
    return 0;
}