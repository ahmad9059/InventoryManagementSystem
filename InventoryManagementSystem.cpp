// Inventory Management System: Build a system to track and manage inventory
// for a store or warehouse. Define classes such as Product, Category, and
// Supplier with methods for adding, updating, and querying inventory items.

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void
clearTerminal ()
{
#ifdef _WIN32
  system ("cls");
#else
  system ("clear");
#endif
}
const string RESET = "\033[0m";
const string BOLD = "\033[1m";
const string UNDERLINE = "\033[4m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string CYAN = "\033[36m";

class Product
{
public:
  string name;
  int id;
  int quantity;
  double price;
  string category;
  Product (string name, int id, int quantity, double price, string category)
  {
    this->name = name;
    this->id = id;
    this->quantity = quantity;
    this->price = price;
    this->category = category;
  }
  void
  display ()
  {
    cout << BLUE << BOLD;
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║               Product Details                    ║\n";
    cout << "║ ID:       " << setw (39) << id << "║\n";
    cout << "║ Name:     " << setw (39) << name << "║\n";
    cout << "║ Category: " << setw (39) << category << "║\n";
    cout << "║ Quantity: " << setw (39) << quantity << "║\n";
    cout << "║ Price:    " << setw (39) << fixed << setprecision (2) << price
         << "║\n";
    cout << "╚══════════════════════════════════════════════════╝\n\n";
  }
};

class Category
{
public:
  string name;
  string description;

  Category (string name, string description)
  {
    this->name = name;
    this->description = description;
  }

  void
  display ()
  {
    cout << BLUE << BOLD;
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║               Category Details                   ║\n";
    cout << "║ Name: " << setw (43) << name << "║\n";
    cout << "║ Description:    " << setw (33) << fixed << setprecision (2)
         << description << "║\n";
    cout << "╚══════════════════════════════════════════════════╝\n\n";
  }
};
class Supplier
{
public:
  string name;
  string contactInfo;

  Supplier (string name, string contactInfo)
  {
    this->name = name;
    this->contactInfo = contactInfo;
  }
  void
  display ()
  {
    cout << "Name: " << name << endl;
    cout << "Contact Info: " << contactInfo << endl;

    cout << BLUE << BOLD;
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║               Supplier Details                   ║\n";
    cout << "║ Name: " << setw (43) << name << "║\n";
    cout << "║ Contact Info:   " << setw (33) << fixed << setprecision (2)
         << contactInfo << "║\n";
    cout << "╚══════════════════════════════════════════════════╝\n\n";
  }
};
class Invoice
{
public:
  vector<pair<Product, int> > items;
  double total;

  Invoice () : total (0) {}

  void
  addItem (Product &product, int quantity)
  {
    items.push_back (make_pair (product, quantity));
    total += product.price * quantity;
  }

  void
  display ()
  {
    clearTerminal ();
    cout << BLUE << BOLD;
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║                     Invoice                      ║\n";
    cout << "╠══════════════════════════════════════════════════╣\n";
    cout << "║ ID       Name            Quantity          Price ║\n";
    cout << "╠══════════════════════════════════════════════════╣\n";

    for (auto &item : items)
      {
        cout << "║ " << setw (1) << item.first.id << "  " << setw (10)
             << item.first.name << "  " << setw (12) << item.second << "  "
             << setw (19) << fixed << setprecision (2) << item.first.price
             << " ║\n";
      }

    cout << "╠══════════════════════════════════════════════════╣\n";
    cout << "║ Total: " << setw (41) << fixed << setprecision (2) << total
         << " ║\n";
    cout << "╚══════════════════════════════════════════════════╝\n\n";
  }
};

class Inventory
{
  vector<Product> products;
  vector<Category> categories;
  vector<Supplier> suppliers;

public:
  void
  addSampleProducts ()
  {
    products.push_back (Product ("Bags", 01, 10, 19.99, "Children"));
    products.push_back (Product ("Toys", 01, 10, 19.99, "Children"));
    products.push_back (Product ("Laptop", 02, 15, 29.99, "Electronics"));
    products.push_back (Product ("Charger", 02, 15, 29.99, "Electronics"));
  }

  void
  addSampleCategories ()
  {
    categories.push_back (
        Category ("Children", "This Category is for Children"));
    categories.push_back (
        Category ("Laptop", "This Category is for Electronics"));
  }

  void
  addSampleSuppliers ()
  {
    suppliers.push_back (Supplier ("Supplier1", "ContactInfo1"));
    suppliers.push_back (Supplier ("Supplier2", "ContactInfo2"));
  }

  void
  addProduct (Product &product)
  {
    products.push_back (product);
    clearTerminal ();
    cout << BLUE << BOLD;
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║            Product Added Successfully            ║\n";
    cout << "╚══════════════════════════════════════════════════╝\n\n";
  }
  void
  updateProduct (int id, Product &updatedProduct)
  {
    bool found = false;
    for (int i = 0; i < products.size (); ++i)
      {
        if (products[i].id == id)
          {
            products[i] = updatedProduct;
            clearTerminal ();
            cout << BLUE << BOLD;
            cout << "\n╔══════════════════════════════════════════════════╗\n";
            cout << "║           Product Updated Successfully           ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n\n";
            found = true;
            break;
          }
      }
    if (found == false)
      {
        clearTerminal ();
        cout << BLUE << BOLD;
        cout << "\n╔══════════════════════════════════════════════════╗\n";
        cout << "║               Product Not Found!!                ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n\n";
      }
  }
  void
  queryProduct (int id)
  {
    bool found = false;
    for (int i = 0; i < products.size (); ++i)
      {
        if (products[i].id == id)
          {
            clearTerminal ();
            products[i].display ();
            found = true;
            break;
          }
      }
    if (found == false)
      {
        clearTerminal ();
        cout << BLUE << BOLD;
        cout << "\n╔══════════════════════════════════════════════════╗\n";
        cout << "║               Product Not Found!!                ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n\n";
      }
  }
  void
  removeProduct (int id)
  {
    for (int i = 0; i < products.size (); ++i)
      {
        if (products[i].id == id)
          {
            products.erase (products.begin () + i);
            clearTerminal ();
            cout << BLUE << BOLD;
            cout << "\n╔══════════════════════════════════════════════════╗\n";
            cout << "║             Product Removed Successfully         ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n\n";
            return;
          }
      }
    clearTerminal ();
    cout << BLUE << BOLD;
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║               Product Not Found!!                ║\n";
    cout << "╚══════════════════════════════════════════════════╝\n\n";
  }
  void
  buyProduct (string name, int quantity)
  {
    Invoice invoice;
    for (int i = 0; i < products.size (); ++i)
      {
        if (products[i].name == name)
          {
            if (products[i].quantity >= quantity)
              {
                products[i].quantity -= quantity;
                invoice.addItem (products[i], quantity);
                clearTerminal ();
                invoice.display ();
                return;
              }
            else
              {
                clearTerminal ();
                cout << BLUE << BOLD;
                cout << "\n╔══════════════════════════════════════════════════"
                        "╗\n";
                cout << "║        Insufficient quantity available.          "
                        "║\n";
                cout << "╚══════════════════════════════════════════════════╝"
                        "\n\n";
                return;
              }
          }
      }
    cout << BLUE << BOLD;
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║               Product Not Found!!                ║\n";
    cout << "╚══════════════════════════════════════════════════╝\n\n";
  }

  void
  displayAllProducts ()
  {
    clearTerminal ();
    for (int i = 0; i < products.size (); ++i)
      {
        products[i].display ();
      }
  }

  void
  addCategory (Category &category)
  {
    categories.push_back (category);
    clearTerminal ();
    cout << BLUE << BOLD;
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║           Category Added Successfully            ║\n";
    cout << "╚══════════════════════════════════════════════════╝\n\n";
  }

  void
  updateCategory (string name, Category &updatedCategory)
  {
    bool found = false;
    for (int i = 0; i < categories.size (); ++i)
      {
        if (categories[i].name == name)
          {
            categories[i] = updatedCategory;
            clearTerminal ();
            cout << BLUE << BOLD;
            cout << "\n╔══════════════════════════════════════════════════╗\n";
            cout << "║          Category Updated Successfully           ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n\n";
            found = true;
            break;
          }
      }
    if (found == false)
      {
        clearTerminal ();
        cout << BLUE << BOLD;
        cout << "\n╔══════════════════════════════════════════════════╗\n";
        cout << "║              Category Not Found!!                ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n\n";
      }
  }

  void
  queryCategory (string name)
  {
    bool found = false;
    for (int i = 0; i < categories.size (); ++i)
      {
        if (categories[i].name == name)
          {
            clearTerminal ();
            categories[i].display ();
            found = true;
            break;
          }
      }
    if (!found)
      {
        clearTerminal ();
        cout << BLUE << BOLD;
        cout << "\n╔══════════════════════════════════════════════════╗\n";
        cout << "║              Category Not Found!!                ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n\n";
      }
  }
  void
  removeCategory (string name)
  {
    for (int i = 0; i < categories.size (); ++i)
      {
        if (products[i].name == name)
          {
            products.erase (products.begin () + i);
            clearTerminal ();
            cout << BLUE << BOLD;
            cout << "\n╔══════════════════════════════════════════════════╗\n";
            cout << "║            Category Removed Successfully         ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n\n";
            return;
          }
      }
  }
  void
  displayAllCategories ()
  {
    clearTerminal ();
    for (int i = 0; i < categories.size (); ++i)
      {
        categories[i].display ();
      }
  }
  void
  displayProductByCategory (string &category)
  {
    bool found = false;
    clearTerminal ();
    for (int i = 0; i < products.size (); i++)
      {
        if (products[i].category == category)
          {
            products[i].display ();

            found = true;
          }
      }
    if (!found)
      {
        clearTerminal ();
        cout << BLUE << BOLD;
        cout << "\n╔══════════════════════════════════════════════════╗\n";
        cout << "║        No products found in this category        ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n\n";
      }
  }

  void
  addSupplier (Supplier &supplier)
  {
    suppliers.push_back (supplier);
    clearTerminal ();
    cout << BLUE << BOLD;
    cout << "\n╔══════════════════════════════════════════════════╗\n";
    cout << "║           Supplier Added Successfully            ║\n";
    cout << "╚══════════════════════════════════════════════════╝\n\n";
  }

  void
  updateSupplier (string name, Supplier &updatedSupplier)
  {
    bool found = false;
    for (int i = 0; i < suppliers.size (); ++i)
      {
        if (suppliers[i].name == name)
          {
            suppliers[i] = updatedSupplier;
            clearTerminal ();
            cout << BLUE << BOLD;
            cout << "\n╔══════════════════════════════════════════════════╗"
                    "\n";
            cout << "║          Supplier Updated Successfully           ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n"
                    "\n";
            found = true;
            break;
          }
      }
    if (!found)
      {
        clearTerminal ();
        cout << BLUE << BOLD;
        cout << "\n╔══════════════════════════════════════════════════╗\n";
        cout << "║              Supplier Not Found!!                ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n\n";
      }
  }

  void
  querySupplier (string name)
  {
    bool found = false;
    for (int i = 0; i < suppliers.size (); ++i)
      {
        if (suppliers[i].name == name)
          {
            clearTerminal ();
            suppliers[i].display ();
            found = true;
            break;
          }
      }
    if (!found)
      {
        clearTerminal ();
        cout << BLUE << BOLD;
        cout << "\n╔══════════════════════════════════════════════════╗\n";
        cout << "║              Supplier Not Found!!                ║\n";
        cout << "╚══════════════════════════════════════════════════╝\n\n";
      }
  }
  void
  removeSupplier (string name)
  {
    for (int i = 0; i < suppliers.size (); ++i)
      {
        if (products[i].name == name)
          {
            products.erase (products.begin () + i);
            clearTerminal ();
            cout << BLUE << BOLD;
            cout << "\n╔══════════════════════════════════════════════════╗\n";
            cout << "║            Supplier Removed Successfully         ║\n";
            cout << "╚══════════════════════════════════════════════════╝\n\n";
            return;
          }
      }
  }
  void
  displayAllSuppliers ()
  {
    clearTerminal ();
    for (int i = 0; i < suppliers.size (); ++i)
      {
        suppliers[i].display ();
      }
  }
};
int
main ()
{
  Inventory inventory;
  inventory.addSampleCategories ();
  inventory.addSampleProducts ();
  inventory.addSampleSuppliers ();
  int choice;

  do
    {

      cout << BLUE << BOLD;
      cout << "╔══════════════════════════════════════════════════╗\n";
      cout << "║                                                  ║\n";
      cout << "║            Inventory Management System        "
              "   ║\n";
      cout << "║                                                  ║\n";
      cout << "╠══════════════════════════════════════════════════╣\n";
      cout << "║" << RESET << GREEN << "  --Product Options--" << RESET << BLUE
           << "                             ║\n";
      cout << "║  " << YELLOW << "1. Add Product" << RESET << BLUE
           << "                                  ║\n";
      cout << "║  " << YELLOW << "2. Update Product" << RESET << BLUE
           << "                               ║\n";
      cout << "║  " << YELLOW << "3. Query Product" << RESET << BLUE
           << "                                ║\n";
      cout << "║  " << YELLOW << "4. Remove Product" << RESET << BLUE
           << "                               ║\n";
      cout << "║  " << YELLOW << "5. Display All Product" << RESET << BLUE
           << "                          ║\n";
      cout << "║  " << YELLOW << "6. Buy Product" << RESET << BLUE
           << "                                  ║\n";
      cout << "║  " << YELLOW << "7. Display Products by Category" << RESET
           << BLUE << "                 ║\n";

      cout << "╠══════════════════════════════════════════════════╣\n";
      cout << "║" << RESET << GREEN << "  --Category Options--" << RESET
           << BLUE << "                            ║\n";
      cout << "║  " << YELLOW << "8. Add Category" << RESET << BLUE
           << "                                 ║\n";
      cout << "║  " << YELLOW << "9. Update Category" << RESET << BLUE
           << "                              ║\n";
      cout << "║  " << YELLOW << "10. Query Category" << RESET << BLUE
           << "                              ║\n";
      cout << "║  " << YELLOW << "11. Display All Category" << RESET << BLUE
           << "                        ║\n";
      cout << "║  " << YELLOW << "12. Remove Category" << RESET << BLUE
           << "                             ║\n";
      cout << "╠══════════════════════════════════════════════════╣\n";
      cout << "║" << RESET << GREEN << "  --Supplier Options--" << RESET
           << BLUE << "                            ║\n";
      cout << "║  " << YELLOW << "13. Add Supplier" << RESET << BLUE
           << "                                ║\n";
      cout << "║  " << YELLOW << "14. Update Supplier" << RESET << BLUE
           << "                             ║\n";
      cout << "║  " << YELLOW << "15. Query Supplier" << RESET << BLUE
           << "                              ║\n";
      cout << "║  " << YELLOW << "16. Display All Supplier" << RESET << BLUE
           << "                        ║\n";
      cout << "║  " << YELLOW << "17. Remove Supplier" << RESET << BLUE
           << "                             ║\n";
      cout << "╠══════════════════════════════════════════════════╣\n";
      cout << "║  " << RED << "0. Exit" << RESET << BLUE
           << "                                         ║\n";
      cout << "╚══════════════════════════════════════════════════╝\n";
      cout << CYAN << BOLD << "Enter your choice: " << RESET;
      cin >> choice;

      switch (choice)
        {
        case 1:
          {
            string name;
            int id, quantity;
            double price;
            string category;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter the Category name: ";
            cin >> category;
            cout << "Enter product quantity: ";
            cin >> quantity;
            cout << "Enter product price: ";
            cin >> price;

            Product product (name, id, quantity, price, category);
            inventory.addProduct (product);
            break;
          }
        case 2:
          {
            int id;
            string name;
            int quantity;
            double price;
            string category;
            cout << "Enter product ID to update: ";
            cin >> id;
            cout << "Enter new product name: ";
            cin >> name;
            cout << "Enter new product quantity: ";
            cin >> quantity;
            cout << "Enter new product price: ";
            cin >> price;
            Product updatedProduct (name, id, quantity, price, category);
            inventory.updateProduct (id, updatedProduct);
            break;
          }
        case 3:
          {
            int id;
            cout << "Enter product ID to query: ";
            cin >> id;
            inventory.queryProduct (id);
            break;
          }
        case 4:
          {
            int id;
            cout << "Enter product ID to remove: ";
            cin >> id;
            inventory.removeProduct (id);
            break;
          }
        case 5:
          {
            inventory.displayAllProducts ();
            break;
          }
        case 6:
          {
            string name;
            int quantity;
            cout << "Enter product name to buy: ";
            cin.ignore ();
            getline (cin, name);
            cout << "Enter quantity to buy: ";
            cin >> quantity;
            inventory.buyProduct (name, quantity);
            break;
          }
        case 7:
          {
            {
              string categoryName;
              cout << "Enter category name: ";
              cin >> categoryName;
              inventory.displayProductByCategory (categoryName);
              break;
            }
          }

        case 8:
          {
            string name, description;
            cout << "Enter category name: ";
            cin >> name;
            cin.ignore ();
            cout << "Enter category description: ";
            getline (cin, description);
            Category category (name, description);
            inventory.addCategory (category);
            break;
          }
        case 9:
          {
            string name, description;
            cout << "Enter category name to update: ";
            cin >> name;
            cin.ignore ();
            cout << "Enter new category description: ";
            getline (cin, description);
            Category updatedCategory (name, description);
            inventory.updateCategory (name, updatedCategory);
            break;
          }
        case 10:
          {
            string name;
            cout << "Enter category name to query: ";
            cin >> name;
            inventory.queryCategory (name);
            break;
          }
        case 11:
          {
            inventory.displayAllCategories ();
            break;
          }
        case 12:
          {
            string name;
            cout << "Enter category name to remove: ";
            cin >> name;
            inventory.removeCategory (name);
            break;
          }
        case 13:
          {
            string name, contactInfo;
            cout << "Enter supplier name: ";
            cin >> name;
            cout << "Enter supplier contact information: ";
            cin >> contactInfo;
            Supplier supplier (name, contactInfo);
            inventory.addSupplier (supplier);
            break;
          }
        case 14:
          {
            string name, contactInfo;
            cout << "Enter supplier name to update: ";
            cin >> name;
            cout << "Enter new supplier contact information: ";
            cin >> contactInfo;
            Supplier updatedSupplier (name, contactInfo);
            inventory.updateSupplier (name, updatedSupplier);
            break;
          }
        case 15:
          {
            string name;
            cout << "Enter supplier name to query: ";
            cin >> name;
            inventory.querySupplier (name);
            break;
          }
        case 16:
          {
            inventory.displayAllSuppliers ();
            break;
          }
        case 17:
          {
            string name;
            cout << "Enter supplier name to remove : ";
            cin >> name;
            inventory.removeSupplier (name);
            break;
          }

        case 0:
          cout << GREEN << "Exiting program. Goodbye!" << RESET << endl;
          break;
        default:
          {
            clearTerminal ();
            cout << RED << "Invalid choice. Please try again." << RESET
                 << endl;
            break;
          }
        }
    }
  while (choice != 0);

  return 0;
}
