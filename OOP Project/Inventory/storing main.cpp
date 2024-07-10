#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Product {
    string code;
    string name;
    double price;
    int quantity;
};

void saveData(const vector<Product>& products, const string& filename) {
    ofstream file(filename, ios::app); 

    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }


    file.seekp(0, ios::end);
    bool isEmpty = (file.tellp() == 0);
    file.seekp(0, ios::beg);


    if (isEmpty) {
        file << "Code " << "Name " << "Price " << "Quantity" << endl;
    }

    for (const auto& product : products) {
        file << product.code << " " << product.name << " " << fixed << setprecision(2) << product.price << product.quantity << endl;
    }

    file.close();

    cout << "Data appended successfully to " << filename << endl;
}



int main() {
    vector<Product> products;

    char addMore;
    do {
        Product newProduct;
        cout << "Enter product code: ";
        cin >> newProduct.code;
        cin.ignore();
        cout << "Enter product name: ";
        getline(cin, newProduct.name);
        cout << "Enter product price: ";
        cin >> newProduct.price;

        products.push_back(newProduct);

        cout << "Do you want to add another product? (y/n): ";
        cin >> addMore;
    } while (addMore == 'y' || addMore == 'Y');

    string filename = "juzer.txt";
    saveData(products, filename);

    return 0;
}
