#include <map>
#include <string>
#include <iomanip>
#include <iostream>

using namespace std;

struct GFinance {
  string name;
  double price;
};

map<string, GFinance> finances;

void add_finance() {
  string name;
  float price;

  cout << "Input finance name : ";
  cin >> name;

  cout << "Input finance price per paper : ";
  cin >> price;

  finances[name] = GFinance { name, price };
}

void show_finance() {
  cout << "\n===========================" << endl;

  for (const auto& finance : finances) {
    cout << "Finance name : " << finance.second.name << endl;
    cout << "Finance price per paper : " << finance.second.price << endl;
    cout << "==========================" << endl;
  }

  cout << endl;
}

void check_modal_by_lot() {
  double modal;
  string target;
  int total, found = false;

  cout << "Input finance name that you want to buy : ";
  cin >> target;

  if (finances.find(target) != finances.end()) {
    found = true;

    cout << "Input total lot (100 paper) that you want to buy : ";
    cin >> total;

    modal = total * 100 * finances.at(target).price;
  }

  if (found) cout << "The amount of money that must be prepared is : Rp " << fixed << setprecision(0) << modal << endl;
  else cout << "Finance name is unknown, please enter valid finance name" << endl;

  cout << endl;
}

void check_lot_by_modal() {
  double modal;

  cout << "Input money that you have : ";
  cin >> modal;

  cout << "With total money Rp " << fixed << setprecision(0) << modal << " you can buy total lot : " << endl;
  cout << "========================" << endl;

  for (const auto& finance : finances) {
    cout << "Finance name : " << finance.first << endl;
    cout << "Finance price per lot : " << finance.second.price * 100 << endl;
    cout << "Total lot you can buy : " << modal / 100 /finance.second.price << endl;
    cout << "=======================" << endl;
  }

  cout << endl;
}

void price_prediction() {
  string target;

  cout << "Input finance name that you want to predict : ";
  cin >> target;

  GFinance finance;

  if (finances.find(target) != finances.end()) finance = finances.at(target);

  if (finance.name.empty()) {
    cout << "Finance name is unknown, please enter valid finance name" << endl;
    return;
  }

  int iteration = 0;

  while (iteration < 30) {
    finance.price += finance.price * 0.001;

    cout << "Price prediction for day " << iteration + 1 << " is " << finance.price << endl;

    iteration++;
  }

  cout << endl;
}

int main() {
  int choice;
  bool isRunning = true;

  do {
    cout << "Market Stock Calculation" << endl;
    cout << "================================" << endl;
    cout << "1. Input Finance Data" << endl;
    cout << "2. Show Finance Data" << endl;
    cout << "3. Check Modal by Lot" << endl;
    cout << "4. Check Lot by Modal" << endl;
    cout << "5. Price Prediction for 30 days" << endl;
    cout << "6. Exit" << endl;
    cout << "================================" << endl;
    cout << "Input your choice : ";
    cin >> choice;

    switch (choice) {
      case 1:
        add_finance();
        break;
      case 2:
        show_finance();
        break;
      case 3:
        check_modal_by_lot();
        break;
      case 4:
        check_lot_by_modal();
        break;
      case 5:
        price_prediction();
        break;
      case 6:
        isRunning = false;
        break;
      default:
        cout << "Invalid choice" << endl;
        break;
    }
  } while (isRunning);

  return 0;
}

