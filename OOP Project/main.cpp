#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <conio.h>
#include <ctime>
#include <fstream>
#include <windows.h>
#include <cctype>
#include <functional>
#include <limits>

using namespace std;

void goto_xy(int x, int y){
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    coord.X = x;  
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clear_screen(){
	system("cls");
	for(int i=0; i<120; i++){
		goto_xy(i,0); cout << "-";
	}
	for(int i=0; i<30; i++){
		goto_xy(0,i); cout << "-";
	}
	for(int i=1; i<120; i++){
		goto_xy(i,30); cout << "-";
	}
	for(int i=1; i<30; i++){
		goto_xy(118,i); cout << "-";
	}
	setColor(FOREGROUND_BLUE);
	goto_xy(55,2); cout << "UNI QUICK" << endl;
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void printing_message(string s, int x, int y, int delay){
	goto_xy(x,y);
	for(int i=0; i < s.length(); i++){
		cout << s[i];
		Sleep(delay);
	}	
}

void intro(){
	system("cls");
	for(int i=0; i<120; i++){
		goto_xy(i,0); cout << "-";
	}
	for(int i=0; i<30; i++){
		goto_xy(0,i); cout << "-";
	}
	for(int i=1; i<120; i++){
		goto_xy(i,30); cout << "-";
	}
	for(int i=1; i<30; i++){
		goto_xy(118,i); cout << "-";
	}
	setColor(FOREGROUND_GREEN);
	string h1 = " ##    ##  ###     ##  ########      #####    ##    ##  ########   ######  ##   ## ";
	string h2 = " ##    ##  ## ##   ##     ##        ##    ##  ##    ##     ##     ##       ## ##   ";
	string h3 = " ##    ##  ##  ##  ##     ##        ##    ##  ##    ##     ##     ##       ###     ";
	string h4 = " ##    ##  ##   ## ##     ##        ##  # ##  ##    ##     ##     ##       ## ##   ";
	string h5 = " ########  ##     ###  ########      ##### #  ########  ########   ######  ##   ## ";
	
	printing_message(h1,23,11,1);
	printing_message(h2,23,12,1);
	printing_message(h3,23,13,1);
	printing_message(h4,23,14,1);
	printing_message(h5,23,15,1);
	
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

void exit(){
	system("cls");
	for(int i=0; i<120; i++){
		goto_xy(i,0); cout << "-";
	}
	for(int i=0; i<30; i++){
		goto_xy(0,i); cout << "-";
	}
	for(int i=1; i<120; i++){
		goto_xy(i,30); cout << "-";
	}
	for(int i=1; i<30; i++){
		goto_xy(118,i); cout << "-";
	} 
	setColor(FOREGROUND_GREEN);
	string h1 = " ########## ##     ##      ##       ###     ## ##   ##    ##     ##  ######  ##    ##";
	string h2 = "    ##      ##     ##    ##  ##     ## ##   ## ## ##       ##   ##  ##    ## ##    ##";
	string h3 = "    ##      ## ### ##   ##     ##   ##  ##  ## ###           ##     ##    ## ##    ##";
	string h4 = "    ##      ##     ##  ## ##### ##  ##   ## ## ## ##         ##     ##    ## ##    ##";
	string h5 = "    ##      ##     ## ##         ## ##     ### ##   ##       ##      ######  ########";	
	
	printing_message(h1,17,11,1);
	printing_message(h2,17,12,1);
	printing_message(h3,17,13,1);
	printing_message(h4,17,14,1);
	printing_message(h5,17,15,1);
	
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}

struct Item {
	string code;
	string name;
	double price;
	int quantity;
};

class Restuarants {
	protected:
		
	virtual void booking_table(){}
	
	void saveData(const vector<Item>& products, const string& filename) {
    ofstream outFile(filename, ofstream::out | ofstream::trunc);

    if (!outFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    outFile.seekp(0, ios::end);
    bool isEmpty = (outFile.tellp() == 0);
    outFile.seekp(0, ios::beg);

    if (isEmpty) {
        outFile << "Code " << "Name " << "Price " << "Quantity" << endl;
    }

    for (const auto& product : products) {
        outFile << product.code << " " << product.name << " " << fixed << setprecision(2) << product.price << " " << product.quantity << endl;
    }

    outFile.close();
	}
		
	vector<Item> read_items_from_file(const string& filename) {
    vector<Item> items;
    ifstream file(filename);
    if (!file.is_open()) {
    	setColor(FOREGROUND_RED);
        goto_xy(60,7); cerr << "Error opening file: " << filename << endl;
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        return items;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        Item item;

        if (!(file >> item.code >> item.name >> item.price >> item.quantity)) {
            continue;
        }

        items.push_back(item);
    }

    file.close();
    return items;
}

	void display() {
		goto_xy(30,6);  cout << left << setw(15) << "Code" << setw(40) << "Name" << "Price" << endl;
		goto_xy(30,7); cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

		for (int i = 0; i < Menu.size(); i++) {
			goto_xy(30,8+i);  cout << left << setw(15) << Menu[i].code << setw(40) << Menu[i].name << fixed << setprecision(2) << Menu[i].price << endl;
		}
		goto_xy(30,8+Menu.size()); cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
	}
	
	vector<Item> Menu;
	
	vector<int> table;
	
	public:

	static void display(vector<Item> Order) {
		goto_xy(30,6); cout << left << setw(15) << "Code" << setw(40) << "Name" << "Price" << endl;
		goto_xy(30,7); cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

		for (int i = 0; i < Order.size(); i++) {
			goto_xy(30,8+i); cout << left << setw(15) << Order[i].code << setw(40) << Order[i].name << fixed << setprecision(2) << Order[i].price << endl;
		}
		goto_xy(30,8+Order.size()); cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;

		char addmore;
		goto_xy(30,10+Order.size()); cout << "Is your Order Confirm? (y/n): ";
		cin >> addmore;
		addmore = tolower(addmore);
		if (addmore == 'y') {
			goto_xy(30,12+Order.size()); cout << "Proceeding to Bill: " << endl;
			goto_xy(30,14+Order.size());cout << "Enter Any Key To Continue: ";
			getch();
			print_order_summary(Order);
		} else {
			clear_screen();
		}
	}

	static void print_order_summary(vector<Item> Order) {
		clear_screen();

		goto_xy(30,6); cout << left << setw(15) << "Code" << setw(40) << "Name" << "Price" << endl;
		goto_xy(30,7); cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
		
		double total_price;
		
		for (int i = 0; i < Order.size(); i++) {
			goto_xy(30,8+i); cout << left << setw(15) << Order[i].code << setw(40) << Order[i].name << fixed << setprecision(2) << Order[i].price << endl;
			total_price += Order[i].price;
		}
		goto_xy(30,8+Order.size()); cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
		
		string disc = "10%";  
		double discount = 10;
		double discounted_price = total_price - (total_price*(discount/100));
		cout << endl;
		goto_xy(30,10+Order.size()); cout << left << setw(25) << "Total Price"; goto_xy(80,10+Order.size()); cout << total_price << endl;
		goto_xy(30,11+Order.size()); cout << left << setw(25) << "Discount"; goto_xy(80,11+Order.size()); cout << disc << endl;
		goto_xy(30,12+Order.size()); cout << left << setw(25) << "Total Price After Discount "; goto_xy(80,12+Order.size()); cout << discounted_price << endl; 
		goto_xy(30,14+Order.size()); cout << setfill('-') << setw(60) << "" << setfill(' ') << endl;
	}

	vector<Item> make_order(vector<Item> Order) {
		display();
		string code;
		char addmore;
		
		int j = 0;
		while(1) {
			goto_xy(30,21+j); cout << "Enter The Item Code want to Order or -1 to Change Restuarant: ";
			cin >> code;
			for(int i=0; i<code.size(); i++){
				code[i] = toupper(code[i]);
			}
			
			if(code == "-1"){
				break;
			}
			
			bool flag = true;
			for (int i=0; i<Menu.size(); i++) {
				
				if (Menu[i].code == code) {
					if(Menu[i].quantity > 0){
					Order.push_back(Menu[i]);
					Menu[i].quantity--;
					goto_xy(100,21+j); cout << "Item Added: " << endl;
					}else{
						setColor(FOREGROUND_RED);
						goto_xy(100,21+j); cout << "Out of Stock: " << endl;
						setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
					}
						flag = false;
						break;
				}
			}
			if(flag){
				setColor(FOREGROUND_RED);
				goto_xy(100,21+j); cout << "Invalid Input: " << endl;
				setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
			}
			j++;
		}
		clear_screen();
		return Order;
	}
};

class Cafeteria : public Restuarants {
public:
	Cafeteria() {
		Menu = read_items_from_file("Cafeteria.txt");
	}
	~Cafeteria(){
		saveData(Menu,"Cafeteria.txt");
	}
	
	void booking_table() {
    	clear_screen();
    int table[10];

    for (int i = 0; i < 10; i++) {
        table[i] = rand() % 2; 
    }
	int j=0;
    goto_xy(40,8); cout << "Booked Tables:" << endl;
    for (int i = 0; i < 10; i++) {
        if (table[i] == 1) {
            goto_xy(43,10+j); cout << "Table no." << i + 1 << endl;
            j++;
        }
    }

    goto_xy(40,11+j); cout << "Available Tables:" << endl;
    j++;
    for (int i = 0; i < 10; i++) {
        if (table[i] == 0) {
            goto_xy(43,11+j); cout << "Table no." << i + 1 << endl;
            j++;
        }
    }
	int flag = 1;
	do{
    int book_table;
    goto_xy(43,12+j); cout << "Enter the Table You Want to Book (1-10): ";
    cin >> book_table;
    

    if (book_table >= 1 && book_table <= 10 && table[book_table - 1] == 0) {
        table[book_table - 1] = 1;
        goto_xy(43,12+j); cout << "Table no." << book_table << " is Booked at Fast Cafeteria: " << endl;
        flag = 0;
        j++;
    } else {
    	setColor(FOREGROUND_RED);
        goto_xy(43,15+j); cout << "Invalid Input. Please Enter a Valid and Available Table: " << endl;
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
	}while(flag == 1);
	
	goto_xy(50,16+j); cout << "Enter Any Key to Continue: ";
	getch();
}
	
};

class Pizza_Fast : public Restuarants {
public:
    Pizza_Fast() {
        Menu = read_items_from_file("Pizza_Fast.txt");
    }
    ~Pizza_Fast(){
    	saveData(Menu,"Pizza_Fast.txt");
	}
    
    	void booking_table() {
    	clear_screen();
    int table[10];

    for (int i = 0; i < 10; i++) {
        table[i] = rand() % 2; 
    }
	int j=0;
    goto_xy(40,8); cout << "Booked Tables:" << endl;
    for (int i = 0; i < 10; i++) {
        if (table[i] == 1) {
            goto_xy(43,10+j); cout << "Table no." << i + 1 << endl;
            j++;
        }
    }

    goto_xy(40,11+j); cout << "Available Tables:" << endl;
    j++;
    for (int i = 0; i < 10; i++) {
        if (table[i] == 0) {
            goto_xy(43,11+j); cout << "Table no." << i + 1 << endl;
            j++;
        }
    }
	int flag = 1;
	do{
    int book_table;
    goto_xy(43,12+j); cout << "Enter the Table You Want to Book (1-10): ";
    cin >> book_table;
    

    if (book_table >= 1 && book_table <= 10 && table[book_table - 1] == 0) {
        table[book_table - 1] = 1;
        goto_xy(43,12+j); cout << "Table no." << book_table << " is Booked at Pizza Fast: " << endl;
        flag = 0;
        j++;
    } else {
    	setColor(FOREGROUND_RED);
        goto_xy(43,15+j); cout << "Invalid Input. Please Enter a Valid and Available Table: " << endl;
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
	}while(flag == 1);
	
	goto_xy(50,16+j); cout << "Enter Any Key to Continue: ";
	getch();
}

};

class Fast_Dhabba : public Restuarants {
public:
    Fast_Dhabba() {
        Menu = read_items_from_file("Fast_Dhabba.txt");
    }
    ~Fast_Dhabba(){
    	saveData(Menu,"Fast_Dhabba.txt");
	}
    
    	void booking_table() {
    	clear_screen();
    int table[10];

    for (int i = 0; i < 10; i++) {
        table[i] = rand() % 2; 
    }
	int j=0;
    goto_xy(40,8); cout << "Booked Tables:" << endl;
    for (int i = 0; i < 10; i++) {
        if (table[i] == 1) {
            goto_xy(43,10+j); cout << "Table no." << i + 1 << endl;
            j++;
        }
    }

    goto_xy(40,11+j); cout << "Available Tables:" << endl;
    j++;
    for (int i = 0; i < 10; i++) {
        if (table[i] == 0) {
            goto_xy(43,11+j); cout << "Table no." << i + 1 << endl;
            j++;
        }
    }
	int flag = 1;
	do{
    int book_table;
    goto_xy(43,12+j); cout << "Enter the Table You Want to Book (1-10): ";
    cin >> book_table;
    

    if (book_table >= 1 && book_table <= 10 && table[book_table - 1] == 0) {
        table[book_table - 1] = 1;
        goto_xy(43,12+j); cout << "Table no." << book_table << " is Booked at Fast Dhabba: " << endl;
        flag = 0;
        j++;
    } else {
    	setColor(FOREGROUND_RED);
        goto_xy(43,15+j); cout << "Invalid Input. Please Enter a Valid and Available Table: " << endl;
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    }
	}while(flag == 1);
	
	goto_xy(50,16+j); cout << "Enter Any Key to Continue: ";
	getch();
}
	
};

class Fast_Juice_Bar : public Restuarants {
public:
    Fast_Juice_Bar() {
        Menu = read_items_from_file("Fast_Juice_Bar.txt");
    }
    ~Fast_Juice_Bar(){
    	saveData(Menu,"Fast_Juice_Bar.txt");
	}
    
};

class Fast_Shawarma : public Restuarants {
public:
    Fast_Shawarma() {
        Menu = read_items_from_file("Fast_Shawarma.txt");
    }
    ~Fast_Shawarma(){
    	saveData(Menu,"Fast_Shawarma.txt");
	}
};

class User : public Cafeteria, public Pizza_Fast, public Fast_Dhabba, public Fast_Shawarma, public Fast_Juice_Bar{

private:
	string username;
	string password;

	void encrpt(string input){
		hash<string> hasher;
    	size_t hashValue = hasher(input); 
		stringstream ss;
    	ss << hex << setw(16) << setfill('0') << hashValue;
    	password = ss.str();
	}

	string hide_password() {
    string temp_pass;
    char ch;
    while (true) {
        ch = _getch();
        if (ch == '\r' || ch == '\n') {
            cout << endl;
            break;
        } else if (ch == '\b') {
            if (!temp_pass.empty()) {
                cout << "\b \b";
                temp_pass.pop_back();
            }
        } else {
            temp_pass.push_back(ch);
            cout << '*';
        }
    }
    return temp_pass;
}

public:
	vector<Item> Order;
	string name;
	string email;
	string phone_number;

	void sign_up(){
		ofstream file("Uniquick_User_Data.txt", ios::app);

		clear_screen();

		goto_xy(40,10); cout << "S  I  G  N    U  P" << endl;
		goto_xy(30,12);cout << "Enter Name: ";
		cin >> name;
		goto_xy(30,14); cout << "Enter Email: ";
		cin >> email;
		goto_xy(30,16); cout << "Enter Phone Number: ";
		cin >> phone_number;
		goto_xy(30,18); cout << "Enter Username: ";
		cin >> username;

		string temp1 = "", temp2 = "";
		do {
			if(temp1 != temp2) {
				goto_xy(30,25); cout << "Password Does Not Match: " << endl;
			}
			goto_xy(30,20); cout << "Enter Password: ";
			temp1 = hide_password();
			goto_xy(30,22); cout << "Confirm Password: ";
			temp2 = hide_password();

		} while(temp1 != temp2);

		password = temp1;

		encrpt(password);

		file << username << " " << password << endl;
		clear_screen();
		goto_xy(30,14); cout << "User registered successfully!!!" << endl;
		file.close();
		goto_xy(30,16);cout << "Enter Any Key To Conitnue: ";
		getch();
	}

	void login(){
		ifstream file("Uniquick_User_Data.txt");

		int flag = 1;

		while(flag){
			clear_screen();
			goto_xy(40,10); cout << "L  O  G  I  N" << endl;
			goto_xy(30,12); cout << "Enter Username: ";
			cin >> username;
			goto_xy(30,14);cout << "Enter Password: ";
			password = hide_password();
			encrpt(password);

			while (!file.eof()){
				string temp_username, temp_password;
				file >> temp_username >>  temp_password;
				if(username == temp_username && password == temp_password){
					goto_xy(30,17);cout << "Login successfully!!!" << endl;
					flag=0;
					break;
				}
			}

			if(flag){
				setColor(FOREGROUND_RED );
				goto_xy(30,17); cout << "Login failed!!!" << endl;
				setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
				goto_xy(30,19); cout << "Enter 0 to Try Agian or 1 to Signup: ";
				cin >> flag;
				if(flag){
					sign_up();
				}
				file.clear();
				file.seekg(0, ios::beg);
				flag = 1;
			}
		}
		file.close();
		goto_xy(30,19);cout << "Enter Any Key To Conitnue: ";
		getch();		
	}
	
void Payment_method() {
    int method;
    goto_xy(30,16+Order.size()); cout << "Choose the Method of Payment:" << endl;   
    goto_xy(30,17+Order.size()); cout << "1. Cash "; goto_xy(50,17+Order.size()); cout << "2. Online Payment" << endl;
    goto_xy(30,18+Order.size()); cout << "Enter Your Choice: ";
    cin >> method;
    
    clear_screen();
    
    if (method == 2) {
        string bank;
        cin.ignore();
        goto_xy(30, 8); cout << "Enter Your Bank Name: ";
        getline(cin, bank);
        for (int i = 0; i < bank.size(); i++) {
            bank[i] = toupper(bank[i]);
        }

        int count = 0;

        do {
            count = 0;
            long long accnumber;
            goto_xy(30, 10); cout << "Enter Your 11 Digit Account Number: ";
            cin >> accnumber;

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            long long tempAccNum = accnumber;
            while (tempAccNum != 0) {
                tempAccNum /= 10;
                count++;
            }
            if (count != 10 && count != 11) {
                setColor(FOREGROUND_RED);
                goto_xy(80, 10); cout << "Invalid Input: " << endl;
                setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }

        } while (count != 10 && count != 11);
        
        do{
        int code;
        goto_xy(30, 12); cout << "Enter the 5 Digit OTP Code: ";
        cin >> code;
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        count = 0;
        int opt = code;
		
		while(opt != 0){
			opt /= 10;
			count++;
		}	
		if(count != 5){
			setColor(FOREGROUND_RED);
            goto_xy(80, 12); cout << "Invalid Input: " << endl;
            setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		}
		}while(count != 5);

        goto_xy(50, 16); cout << "Payment Successful." << endl;
    }

    goto_xy(10, 18); cout << "Your order will be ready in 5-10 minutes. You may collect your order from the respective restaurant." << endl;

    goto_xy(50, 23); cout << "Enter Any Key to Continue ";
    getch();
}
};

int main() {
	srand(time(nullptr));
	getch();
	intro();
	getch();
	clear_screen();
	
	User user;
	int choice;
	do{
	goto_xy(30,10); cout << "Enter 0 for Signup or 1 for login: ";
	cin >> choice;
	if(choice != 0 && choice != 1){
		goto_xy(30,18); cout << "Invalid Input." << endl; 
	}
	}while(choice != 0 && choice != 1);
	clear_screen();
	
	if(choice){
		user.login();
	}else{
		user.sign_up();
		user.login();
	}
	
	clear_screen();

do{	
	goto_xy(45,7); cout << "Choose Your Restuarant: " << endl;
	goto_xy(40,10); cout << "1. Cafeteria: ";
	goto_xy(65,10); cout << "2. Pizza Fast: " << endl;
	goto_xy(40,13); cout << "3. Fast Shawarma: ";
	goto_xy(65,13); cout << "4. Fast Dhabba: " << endl;
	goto_xy(40,16); cout << "5. Fast_Juice_Bar: ";
	goto_xy(65,16); cout << "6. Proceed to Bill: " << endl;
	goto_xy(50,19); cout << "Enter Your Choice: ";
	cin >> choice;
	
	clear_screen();
	
	switch(choice){
		case 1:
			user.Order = user.Cafeteria::make_order(user.Order);
		break;
		case 2:
			user.Order = user.Pizza_Fast::make_order(user.Order);
		break;
		case 3:
			user.Order = user.Fast_Shawarma::make_order(user.Order);
		break;
		case 4:
			user.Order = user.Fast_Dhabba::make_order(user.Order);
		break;
		case 5:
			user.Order = user.Fast_Juice_Bar::make_order(user.Order);
		break;
		case 6:
			Restuarants::display(user.Order);
			user.Payment_method();
		break;
	}
}while(choice != 6);
	choice = 1;
do{
	clear_screen();
	if(choice < 1 || choice > 4){
		setColor(FOREGROUND_RED);
		goto_xy(40,19); cout << "Invalid Input: ";
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	}
	goto_xy(45,7);  cout << "Choose Your Restuarant for Table Booking: " << endl;
	goto_xy(40,9);  cout << "1. Cafeteria: " << endl;
	goto_xy(40,11); cout << "2. Pizza Fast: " << endl;
	goto_xy(40,13); cout << "3. Fast Dhabba: " << endl;
	goto_xy(40,15); cout << "4. Don't Want to Book Table: " << endl;
	goto_xy(40,17); cout << "Enter Your Choice: ";
	cin >> choice;
	
	
	switch(choice){
		case 1:
			user.Cafeteria::booking_table();
		break;
		case 2:
			user.Pizza_Fast::booking_table();
		break;
		case 3:
			user.Fast_Dhabba::booking_table();
		break;
		case 4:
			exit();
			getch();
		break;	
		"jehehheifo ieuriheehf elwo3ii3 ";
	}
}while (choice < 1 || choice > 4);

	if(choice != 4){
		exit();
		getch();
	}
	clear_screen();
	return 0;
}