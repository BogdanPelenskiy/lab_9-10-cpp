#include <iostream>
#include "ServoMotor.h"
#include "StepperMotor.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    while (true) {
        cout << "\nВиберіть тип двигуна:\n— Серводвигун\n— Кроковий двигун\nВаш вибір (1/2): ";
        int choice = getIntInput("", 1, 2);

        if (choice == 1) {
            ServoMotor sm;
            sm.input();
            sm.print();
        } else {
            StepperMotor st;
            st.input();
            st.print();
        }

        cout << "\nБажаєте протестувати інший тип двигуна? (y/n): ";
        char c;
        cin >> c;

        if (c == 'n' || c == 'N') {
            cout << "Програма завершила роботу.\n";
            break;
        }
    }

    return 0;
}
