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

class Product
{
public:
  string name;
  int id;
  int quantity;
  double price;
  string category;

public:
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
    cout << "\n====================================================\n";
    cout << "|               Product Details                    | \n";
    cout << "| ID:       " << setw (38) << id << " |\n";
    cout << "| Name:     " << setw (38) << name << " |\n";
    cout << "| Category: " << setw (38) << category << " |\n";
    cout << "| Quantity: " << setw (38) << quantity << " |\n";
    cout << "| Price:    " << setw (38) << fixed << setprecision (2) << price
         << " |\n";
    cout << "====================================================\n\n";
  }
};

class Category
{
public:
  string name;
  string description;

public:
  Category (string name, string description)
  {
    this->name = name;
    this->description = description;
  }

  void
  display ()
  {
    cout << "\n====================================================\n";
    cout << "|               Category Details                   |\n";
    cout << "| Name: " << setw (42) << name << " |\n";
    cout << "| Description:    " << setw (32) << fixed << setprecision (2)
         << description << " |\n";
    cout << "====================================================\n\n";
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
    cout << "\n====================================================\n";
    cout << "|               Supplier Details                   |\n";
    cout << "| Name: " << setw (42) << name << " |\n";
    cout << "| Contact Info:   " << setw (32) << fixed << setprecision (2)
         << contactInfo << " |\n";
    cout << "====================================================\n\n";
  }
};
class Invoice
{
public:
  vector<Product> products;
  vector<int> quantities;
  double total;

public:
  Invoice () { total = 0; }

  void
  addItem (Product &product, int quantity)
  {
    products.push_back (product);
    quantities.push_back (quantity);
    total += product.price * quantity;
  }

  void
  display ()
  {
    clearTerminal ();

    cout << "\n====================================================\n";
    cout << "|                     Invoice                      |\n";
    cout << "====================================================\n";
    cout << "| ID       Name            Quantity          Price |\n";
    cout << "====================================================\n";

    for (size_t i = 0; i < products.size (); ++i)
      {
        cout << "| " << setw (1) << products[i].id << "  " << setw (10)
             << products[i].name << "  " << setw (12) << quantities[i] << "  "
             << setw (19) << fixed << setprecision (2) << products[i].price
             << " |\n";
      }

    cout << "====================================================\n";
    cout << "| Total: " << setw (41) << fixed << setprecision (2) << total
         << " |\n";
    cout << "====================================================\n\n";
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
    products.push_back (Product ("Bags", 1, 10, 19.99, "Children"));
    products.push_back (Product ("Toys", 2, 10, 19.99, "Children"));
    products.push_back (Product ("Laptop", 3, 15, 29.99, "Electronics"));
    products.push_back (Product ("Charger", 4, 15, 29.99, "Electronics"));
  }

  void
  addSampleCategories ()
  {
    categories.push_back (
        Category ("Children", "This Category is for Children"));
    categories.push_back (
        Category ("Electronics", "This Category is for Electronics"));
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

    cout << "\n====================================================\n";
    cout << "|            Product Added Successfully            |\n";
    cout << "====================================================\n\n";
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
            cout << "\n====================================================\n";
            cout << "|           Product Updated Successfully           |\n";
            cout << "====================================================\n\n";
            found = true;
            break;
          }
      }
    if (found == false)
      {
        clearTerminal ();

        cout << "\n====================================================\n";
        cout << "|               Product Not Found!!                |\n";
        cout << "====================================================\n\n";
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
        cout << "\n====================================================\n";
        cout << "|               Product Not Found!!                |\n";
        cout << "====================================================\n\n";
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

            cout << "\n====================================================\n";
            cout << "|             Product Removed Successfully         |\n";
            cout << "====================================================\n\n";
            return;
          }
      }
    clearTerminal ();

    cout << "\n====================================================\n";
    cout << "|               Product Not Found!!                |\n";
    cout << "====================================================\n\n";
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
                cout << "\n==================================================="
                        "=\n";
                cout << "|        Insufficient quantity available.          "
                        "|\n";
                cout << "==================================================="
                        "=\n\n";
                return;
              }
          }
      }
    cout << "\n====================================================\n";
    cout << "|               Product Not Found!!                |\n";
    cout << "====================================================\n\n";
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

    cout << "\n====================================================\n";
    cout << "|           Category Added Successfully            |\n";
    cout << "====================================================\n\n";
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

            cout << "\n====================================================\n";
            cout << "|          Category Updated Successfully           |\n";
            cout << "====================================================\n\n";
            found = true;
            break;
          }
      }
    if (found == false)
      {
        clearTerminal ();

        cout << "\n====================================================\n";
        cout << "|              Category Not Found!!                |\n";
        cout << "====================================================\n\n";
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

        cout << "\n====================================================\n";
        cout << "|              Category Not Found!!                |\n";
        cout << "====================================================\n\n";
      }
  }
  void
  removeCategory (string name)
  {
    for (int i = 0; i < categories.size (); ++i)
      {
        if (categories[i].name == name)
          {
            categories.erase (categories.begin () + i);
            clearTerminal ();

            cout << "\n====================================================\n";
            cout << "|            Category Removed Successfully         |\n";
            cout << "====================================================\n\n";
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

        cout << "\n====================================================\n";
        cout << "|        No products found in this category        |\n";
        cout << "====================================================\n\n";
      }
  }

  void
  addSupplier (Supplier &supplier)
  {
    suppliers.push_back (supplier);
    clearTerminal ();

    cout << "\n====================================================\n";
    cout << "|           Supplier Added Successfully            |\n";
    cout << "====================================================\n\n";
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

            cout << "\n====================================================\n";
            cout << "|          Supplier Updated Successfully           |\n";
            cout << "====================================================\n\n";
            found = true;
            break;
          }
      }
    if (!found)
      {
        clearTerminal ();

        cout << "\n====================================================\n";
        cout << "|              Supplier Not Found!!                |\n";
        cout << "====================================================\n\n";
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

        cout << "\n====================================================\n";
        cout << "|              Supplier Not Found!!                |\n";
        cout << "====================================================\n\n";
      }
  }
  void
  removeSupplier (string name)
  {
    for (int i = 0; i < suppliers.size (); ++i)
      {
        if (suppliers[i].name == name)
          {
            suppliers.erase (suppliers.begin () + i);
            clearTerminal ();
            cout << "\n====================================================\n";
            cout << "|            Supplier Removed Successfully         |\n";
            cout << "====================================================\n\n";
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

      cout << "====================================================\n";
      cout << "|                                                  |\n";
      cout << "|            Inventory Management System           |\n";
      cout << "|                                                  |\n";
      cout << "====================================================\n";
      cout << "|  --Product Options--                             |\n";
      cout << "|  1. Add Product                                  |\n";
      cout << "|  2. Update Product                               |\n";
      cout << "|  3. Query Product                                |\n";
      cout << "|  4. Remove Product                               |\n";
      cout << "|  5. Display All Product                          |\n";
      cout << "|  6. Buy Product                                  |\n";
      cout << "|  7. Display Products by Category                 |\n";
      cout << "====================================================\n";
      cout << "|  --Category Options--                            |\n";
      cout << "|  8. Add Category                                 |\n";
      cout << "|  9. Update Category                              |\n";
      cout << "|  10. Query Category                              |\n";
      cout << "|  11. Display All Category                        |\n";
      cout << "|  12. Remove Category                             |\n";
      cout << "====================================================\n";
      cout << "|  --Supplier Options--                            |\n";
      cout << "|  13. Add Supplier                                |\n";
      cout << "|  14. Update Supplier                             |\n";
      cout << "|  15. Query Supplier                              |\n";
      cout << "|  16. Display All Supplier                        |\n";
      cout << "|  17. Remove Supplier                             |\n";
      cout << "====================================================\n";
      cout << "|  0. Exit                                         |\n";
      cout << "====================================================\n";
      cout << "Enter your choice: ";
      cin >> choice;

      switch (choice)
        {
        case 1:
          {
            string name;
            int id, quantity;
            double price;
            string category;
            cout << "Enter the product name: ";
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
            cout << "Enter the new category name: ";
            cin >> category;
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
          cout << "Exiting program. Goodbye!" << endl;
          break;
        default:
          {
            clearTerminal ();
            cout << "Invalid choice. Please try again." << endl;
            break;
          }
        }
    }
  while (choice != 0);

  return 0;
}
