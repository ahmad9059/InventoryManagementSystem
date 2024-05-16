// Inventory Management System: Build a system to track and manage inventory
// for a store or warehouse. Define classes such as Product, Category, and
// Supplier with methods for adding, updating, and querying inventory items.

#include <bits/stdc++.h>
using namespace std;

class Product
{
public:
  string name;
  int id;
  int quantity;
  double price;

  Product (string name, int id, int quantity, double price)
  {
    this->name = name;
    this->id = id;
    this->quantity = quantity;
    this->price = price;
  }

  void
  display ()
  {
    cout << "\n\n\t(@)====Product Options====(@)\n";
    cout << "ID: " << id << endl;
    cout << "Name: " << name << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Price: " << price << endl;
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
    cout << "Name: " << name << endl;
    cout << "Description: " << description << endl;
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
  }
};

class Inventory
{
  vector<Product> products;
  vector<Category> categories;
  vector<Supplier> suppliers;

public:
  void
  addProduct (Product &product)
  {
    products.push_back (product);
    cout << "\nProduct added successfully!\n" << endl;
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
            cout << "\nProduct updated successfully!\n" << endl;
            found = true;
            break;
          }
      }
    if (!found)
      {
        cout << "Product not found!" << endl;
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
            products[i].display ();
            found = true;
            break;
          }
      }
    if (!found)
      {
        cout << "\nProduct not found!\n" << endl;
      }
  }

  void
  addCategory (Category &category)
  {
    categories.push_back (category);
    cout << "\nCategory added successfully!\n" << endl;
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
            cout << "\nCategory updated successfully!\n" << endl;
            found = true;
            break;
          }
      }
    if (!found)
      {
        cout << "\nCategory not found!\n" << endl;
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
            categories[i].display ();
            found = true;
            break;
          }
      }
    if (!found)
      {
        cout << "\nCategory not found!\n" << endl;
      }
  }

  void
  addSupplier (Supplier &supplier)
  {
    suppliers.push_back (supplier);
    cout << "\nSupplier added successfully!\n" << endl;
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
            cout << "\nSupplier updated successfully!\n" << endl;
            found = true;
            break;
          }
      }
    if (!found)
      {
        cout << "\nSupplier not found!\n" << endl;
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
            suppliers[i].display ();
            found = true;
            break;
          }
      }
    if (!found)
      {
        cout << "\nSupplier not found!\n" << endl;
      }
  }
};

int
main ()
{
  Inventory inventory;
  int choice;

  do
    {
      cout << "\t(!!)====Inventory Management System====(!!)\t" << endl;
      cout << "\n!--Product Options--!" << endl;
      cout << "1. Add Product" << endl;
      cout << "2. Update Product" << endl;
      cout << "3. Query Product" << endl;
      cout << "\n!--Category Options--!" << endl;
      cout << "4. Add Category" << endl;
      cout << "5. Update Category" << endl;
      cout << "6. Query Category" << endl;
      cout << "\n!--Supplier Options--!" << endl;
      cout << "7. Add Supplier" << endl;
      cout << "8. Update Supplier" << endl;
      cout << "9. Query Supplier" << endl;
      cout << "0. Exit" << endl;
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice)
        {
        case 1:
          {
            string name;
            int id, quantity;
            double price;
            cout << "Enter product name: ";
            cin >> name;
            cout << "Enter product ID: ";
            cin >> id;
            cout << "Enter product quantity: ";
            cin >> quantity;
            cout << "Enter product price: ";
            cin >> price;
            Product product (name, id, quantity, price);
            inventory.addProduct (product);
            break;
          }
        case 2:
          {
            int id;
            string name;
            int quantity;
            double price;
            cout << "Enter product ID to update: ";
            cin >> id;
            cout << "Enter new product name: ";
            cin >> name;
            cout << "Enter new product quantity: ";
            cin >> quantity;
            cout << "Enter new product price: ";
            cin >> price;
            Product updatedProduct (name, id, quantity, price);
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
            string name, description;
            cout << "Enter category name: ";
            cin >> name;
            cout << "Enter category description: ";
            cin >> description;
            Category category (name, description);
            inventory.addCategory (category);
            break;
          }
        case 5:
          {
            string name, description;
            cout << "Enter category name to update: ";
            cin >> name;
            cout << "Enter new category description: ";
            cin >> description;
            Category updatedCategory (name, description);
            inventory.updateCategory (name, updatedCategory);
            break;
          }
        case 6:
          {
            string name;
            cout << "Enter category name to query: ";
            cin >> name;
            inventory.queryCategory (name);
            break;
          }
        case 7:
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
        case 8:
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
        case 9:
          {
            string name;
            cout << "Enter supplier name to query: ";
            cin >> name;
            inventory.querySupplier (name);
            break;
          }
        case 0:
          cout << "Exiting..." << endl;
          break;
        default:
          cout << "Invalid choice! Please try again." << endl;
          break;
        }
    }
  while (choice != 0);

  return 0;
}