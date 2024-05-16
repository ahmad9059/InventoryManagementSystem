# Inventory Management System

## Project Overview

This Inventory Management System is a comprehensive software application designed to track and manage inventory for a store or warehouse. The system allows users to add, update, and query information about products, categories, and suppliers. It is built using C++ and demonstrates the application of Object-Oriented Programming (OOP) principles.

## Classes and Their Responsibilities

### 1. Product Class
**Attributes:**
- `string name`: The name of the product.
- `int id`: The unique identifier for the product.
- `int quantity`: The quantity of the product available in the inventory.
- `double price`: The price of the product.

**Methods:**
- `Product(string name, int id, int quantity, double price)`: Constructor to initialize product details.
- `void display()`: Displays the product information.

### 2. Category Class
**Attributes:**
- `string name`: The name of the category.
- `string description`: A brief description of the category.

**Methods:**
- `Category(string name, string description)`: Constructor to initialize category details.
- `void display()`: Displays the category information.

### 3. Supplier Class
**Attributes:**
- `string name`: The name of the supplier.
- `string contactInfo`: The contact information of the supplier.

**Methods:**
- `Supplier(string name, string contactInfo)`: Constructor to initialize supplier details.
- `void display()`: Displays the supplier information.

### 4. Inventory Class
**Attributes:**
- `vector<Product> products`: A list of products in the inventory.
- `vector<Category> categories`: A list of categories.
- `vector<Supplier> suppliers`: A list of suppliers.

**Methods:**
- `void addProduct(Product &product)`: Adds a new product to the inventory.
- `void updateProduct(int id, Product &updatedProduct)`: Updates the details of an existing product.
- `void queryProduct(int id)`: Queries and displays details of a product by ID.
- `void addCategory(Category &category)`: Adds a new category.
- `void updateCategory(string name, Category &updatedCategory)`: Updates the details of an existing category.
- `void queryCategory(string name)`: Queries and displays details of a category by name.
- `void addSupplier(Supplier &supplier)`: Adds a new supplier.
- `void updateSupplier(string name, Supplier &updatedSupplier)`: Updates the details of an existing supplier.
- `void querySupplier(string name)`: Queries and displays details of a supplier by name.

## Usage and Workflow

### Adding a Product
1. Enter the product's name, ID, quantity, and price.
2. The product is added to the inventory, and a confirmation message is displayed.

### Updating a Product
1. Enter the product ID to be updated.
2. Provide the new details for the product.
3. The product information is updated, and a confirmation message is displayed.

### Querying a Product
1. Enter the product ID.
2. The system displays the product details if found, or an error message if the product does not exist.

### Adding a Category
1. Enter the category name and description.
2. The category is added to the list of categories, and a confirmation message is displayed.

### Updating a Category
1. Enter the category name to be updated.
2. Provide the new description for the category.
3. The category information is updated, and a confirmation message is displayed.

### Querying a Category
1. Enter the category name.
2. The system displays the category details if found, or an error message if the category does not exist.

### Adding a Supplier
1. Enter the supplier's name and contact information.
2. The supplier is added to the list of suppliers, and a confirmation message is displayed.

### Updating a Supplier
1. Enter the supplier name to be updated.
2. Provide the new contact information for the supplier.
3. The supplier information is updated, and a confirmation message is displayed.

### Querying a Supplier
1. Enter the supplier name.
2. The system displays the supplier details if found, or an error message if the supplier does not exist.

## Why Use This System?

This Inventory Management System is designed to streamline the process of managing inventory in a store or warehouse setting. Key benefits include:

- **Efficiency:** Quickly add, update, and query information, reducing manual workload.
- **Organization:** Keep all inventory data organized in one place.
- **Accuracy:** Reduce errors associated with manual tracking of products, categories, and suppliers.
- **Scalability:** Easily extend the system to include more features or handle larger volumes of data.

## Conclusion

This project demonstrates the practical application of OOP principles in solving real-world problems. By encapsulating data and behaviors within well-defined classes, the system achieves modularity, reusability, and maintainability. The Inventory Management System serves as a solid foundation for further development and customization to meet specific business needs.
