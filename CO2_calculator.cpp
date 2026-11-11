#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

double getPositiveNumber(const string& prompt) {
    double value;

    while (true) {
        cout << prompt;

        if (cin >> value && value > 0) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        cout << "Please enter a positive number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void calculateTransport() {
    cout << "\nTransport options:\n";
    cout << "1. Car (petrol)\n";
    cout << "2. Bus\n";
    cout << "3. Train\n";
    cout << "4. Flight\n";

    int choice = static_cast<int>(getPositiveNumber("Choose transport (1-4): "));

    if (choice < 1 || choice > 4) {
        cout << "Invalid transport choice.\n";
        return;
    }

    double distance = getPositiveNumber("Enter distance travelled in km: ");

    double factor;

    if (choice == 1) {
        factor = 0.20;
        cout << "Car (petrol) selected.\n";
    } else if (choice == 2) {
        factor = 0.10;
        cout << "Bus selected.\n";
    } else if (choice == 3) {
        factor = 0.04;
        cout << "Train selected.\n";
    } else {
        factor = 0.25;
        cout << "Flight selected.\n";
    }

    double emissions = distance * factor;

    cout << fixed << setprecision(2);
    cout << "Estimated CO2e emissions: " << emissions << " kg\n\n";
}

void calculateElectricity() {
    double kWh = getPositiveNumber("Enter electricity usage in kWh: ");

    double factor = 0.40;
    double emissions = kWh * factor;

    cout << fixed << setprecision(2);
    cout << "Estimated CO2e emissions: " << emissions << " kg\n\n";
}

void calculateBookPrinting() {
    int pages = static_cast<int>(getPositiveNumber("Enter number of pages printed: "));

    double factorPerPage = 0.0007;
    double emissions = pages * factorPerPage;

    cout << fixed << setprecision(4);
    cout << "Estimated CO2e emissions: " << emissions << " kg\n\n";
}

int main() {
    cout << "=== CO2 Calculator ===\n";
    cout << "Estimate carbon dioxide emissions from common activities.\n\n";

    while (true) {
        cout << "Menu:\n";
        cout << "1. Transport\n";
        cout << "2. Electricity\n";
        cout << "3. Book Printing (related to Book Manager data)\n";
        cout << "0. Exit\n";
        cout << "Choice: ";

        int choice;

        if (!(cin >> choice)) {
            break;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 0) {
            cout << "Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1:
                calculateTransport();
                break;
            case 2:
                calculateElectricity();
                break;
            case 3:
                calculateBookPrinting();
                break;
            default:
                cout << "Invalid choice. Please select 0, 1, 2, or 3.\n\n";
                break;
        }
    }

    return 0;
}
