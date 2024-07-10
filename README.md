# OOP_Project
My second semester C++ Project called UniQuick which is a restaurant management system at Fast.
<br>
Key Features:
User Authentication:
Sign Up: Allows new users to sign up by providing their name, email, phone number, username, and password. The password is hashed for security.
Login: Enables users to log in using their username and password. If the login fails, users can retry or sign up.
Restaurant Management:

Classes for Different Restaurants: The system includes different restaurant classes like Cafeteria, Pizza_Fast, Fast_Dhabba, Fast_Shawarma, and Fast_Juice_Bar, each with its own menu.
Menu Display: Displays the menu items for each restaurant, including the item code, name, price, and quantity.
Order Management:

Make Order: Allows users to make orders by entering the item codes. It checks the availability of items and updates the quantity accordingly.
Order Confirmation: Users can confirm their orders and proceed to billing.
Order Summary: Displays the order summary with a 10% discount applied to the total price.
Table Booking:

Booking Tables: Users can book tables at different restaurants. The system randomly assigns tables as booked or available and allows users to choose an available table.
Payment Method:

Payment Options: Users can choose between cash and online payment methods. For online payments, users provide their bank name, account number, and OTP code for verification.
Utility Functions:

Screen Management: Functions to clear the screen, set cursor position, and change text color.
File Handling: Functions to read and save menu items from/to files.