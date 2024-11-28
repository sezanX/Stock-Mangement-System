
<!--### Documentation (<a href="Algorithm Steps.pdf">Click Here</a>)-->

# Stock Management System

This application is a simple Stock Management System that allows users to manage stock items through a series of operations such as adding, viewing, updating, and deleting items. It also provides features to generate reports and view the history of changes.

## Features

1. **Add Stock Item**: Add new stock items with details like ID, name, quantity, and price.
2. **View Stock Item**: Retrieve and display details of a stock item using its ID.
3. **Update Stock Item**: Modify the details of an existing stock item.
4. **Delete Stock Item**: Remove a stock item from the records.
5. **List All Stock Items**: Display all available stock items.
6. **Generate Low Stock Report**: Identify and list items with quantities below a specified threshold.
7. **View Update History**: Display the history of all add, update, and delete operations.

## How It Works

### Main Program Flow

1. **Start**: Begin the program.
2. **Open the Stock File (`stock.dat`)**: If the file does not exist, a new one is created.
3. **Display Menu**: Present the user with options and wait for input.

### Operations

#### 1. Add Stock Item
- **Input**: Enter item details (ID, Name, Quantity, Price).
- **Process**: 
  - Record the current date and time.
  - Write the item details to `stock.dat`.
  - Log the addition in `updateHistory.dat`.
- **Output**: Display a confirmation message.

#### 2. View Stock Item
- **Input**: Enter item ID.
- **Process**: Search for the item in `stock.dat`.
- **Output**: 
  - If found, display the item details.
  - If not found, display "Item not found".

#### 3. Update Stock Item
- **Input**: Enter item ID.
- **Process**: 
  - Search for the item in `stock.dat`.
  - If found, input new details and record the current date and time.
  - Update details in a temporary file (`temp.dat`).
  - Log the update in `updateHistory.dat`.
- **Output**: 
  - Replace `stock.dat` with `temp.dat`.
  - Display a confirmation message.
  - If not found, display "Item not found".

#### 4. Delete Stock Item
- **Input**: Enter item ID.
- **Process**: 
  - Search for and remove the item from `stock.dat`.
  - Write remaining items to `temp.dat`.
  - Log the deletion in `updateHistory.dat`.
- **Output**: 
  - Replace `stock.dat` with `temp.dat`.
  - Display a confirmation message.
  - If not found, display "Item not found".

#### 5. List All Stock Items
- **Process**: Read all items from `stock.dat`.
- **Output**: Display all items.

#### 6. Generate Low Stock Report
- **Input**: Enter quantity threshold.
- **Process**: Search for items in `stock.dat` with quantity below the threshold.
- **Output**: Display the list of items.

#### 7. View Update History
- **Process**: Read all entries from `updateHistory.dat`.
- **Output**: Display all entries.

### Exit Program
- **Process**: Close all files.
- **End**: Terminate the program.

This system is ideal for small businesses to keep track of their inventory and manage stock efficiently.
<!--
### Full Documentation - https://sezanx.github.io/Stock-Mangement-System/
-->
## Git clone
`git clone https://github.com/sezanX/Inventory-Mangement-System`

<!--# How To work-
<strong>Add items:</strong> Allow users to input item details (name, quantity, price). <br>
<strong>View items:</strong> Display a list of all items and their details.<br>
<strong>Update items:</strong> Modify item details (quantity, price).<br>
<strong>Delete items:</strong> Remove items from the inventory.

## Features
1. Add Stock Item
2. View Stock Item
3. Update Stock Item
4. Delete Stock Item
5. List All Stock Items
6. Generate Low Stock Report
7. View Update History
8. Exit
-->
