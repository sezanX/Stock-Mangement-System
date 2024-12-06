
<!--### Documentation (<a href="Algorithm Steps.pdf">Click Here</a>)-->

# Stock Management System

A simple yet effective stock management system written in C, designed to handle stock items, track their quantities, prices, and maintain an update history. This system is perfect for small-scale businesses or educational purposes to understand file handling and data management in C.

## Features

- **Add Stock Item**: Add new stock items with details like ID, Name, Quantity, and Price.
- **View Stock Item**: View details of a specific stock item using its ID.
- **Update Stock Item**: Update the details of an existing stock item.
- **Delete Stock Item**: Remove a stock item from the database.
- **List All Stock Items**: Display all stock items in the inventory.
- **Generate Low Stock Report**: Report stock items below a specified quantity threshold.
- **View Update History**: Track all changes made to the stock items.

## How It Works

1. **Adding Stock**: When a new stock item is added, the current date and time are recorded, and the details are saved in `stock.dat`. An entry is also added to `updateHistory.dat` to log this operation.
2. **Viewing Stock**: Enter the item ID to view its details. The system searches the database and displays the information if found.
3. **Updating Stock**: Modify the details of an existing stock item. The changes are saved, and the update is logged.
4. **Deleting Stock**: Remove a stock item by its ID. The item is deleted, and the operation is recorded in the history file.
5. **Listing All Stocks**: Display all stock items with their details.
6. **Generating Low Stock Report**: Input a quantity threshold to list all stock items below this quantity.
7. **Viewing Update History**: Review all additions, updates, and deletions performed on stock items.

## Files

- **main.c**: The main source file containing the implementation of the stock management system.
- **stock.dat**: The binary file where stock items are stored.
- **updateHistory.dat**: The binary file where update logs are stored.

## Usage

1. **Compile** the program:
   ```sh
   gcc main.c -o stock_management
   ```

2. **Run** the executable:
   ```sh
   ./stock_management
   ```

3. Follow the on-screen instructions to manage your stock items.

## Example

Here's a snippet of how the stock details and update history look in the system:

```
Item ID: 101
Item Name: WidgetA
Quantity: 50
Price: 19.99
Date Added: 2023-12-07 00:00:00

Update History:
Item ID    Item Name     Quantity    Price   Date                 Operation
--------------------------------------------------------------------------------
101        WidgetA       50          19.99   2023-12-07 00:00:00  Added
101        WidgetA       60          18.99   2023-12-08 00:00:00  Updated
101        WidgetA       0           0.00    2023-12-09 00:00:00  Deleted
```

## Contributing

Feel free to contribute to this project by forking the repository and submitting pull requests. Your contributions are welcome!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

_Enhance your stock management with simplicity and efficiency._


<!--
### Full Documentation - https://sezanx.github.io/Stock-Mangement-System/
-->
## Git clone
`git clone https://github.com/sezanX/Inventory-Mangement-System`