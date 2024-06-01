# Inventory Management System

This Inventory Management System is designed to efficiently track and manage inventory for a store or warehouse. The system includes classes for Product, Category, Supplier, and Invoice, and provides methods for adding, updating, and querying inventory items. It features a command-line interface for user interaction.

## Features

- **Product Management**
  - Add new products
  - Update existing products
  - Query product details
  - Remove products
  - Display all products
  - Buy products and generate invoices
  - Display products by category

- **Category Management**
  - Add new categories
  - Update existing categories
  - Query category details
  - Display all categories
  - Remove categories

- **Supplier Management**
  - Add new suppliers
  - Update existing suppliers
  - Query supplier details
  - Display all suppliers
  - Remove suppliers

## Class Definitions

### Product
Represents a product in the inventory.

#### Attributes:
- `name`: Name of the product
- `id`: Unique identifier for the product
- `quantity`: Quantity of the product available
- `price`: Price of the product
- `category`: Category to which the product belongs

#### Methods:
- `display()`: Displays the details of the product

### Category
Represents a category of products.

#### Attributes:
- `name`: Name of the category
- `description`: Description of the category

#### Methods:
- `display()`: Displays the details of the category

### Supplier
Represents a supplier for the products.

#### Attributes:
- `name`: Name of the supplier
- `contactInfo`: Contact information of the supplier

#### Methods:
- `display()`: Displays the details of the supplier

### Invoice
Represents an invoice generated when products are purchased.

#### Attributes:
- `products`: List of purchased products
- `quantities`: List of quantities for the purchased products
- `total`: Total amount for the invoice

#### Methods:
- `addItem(Product &product, int quantity)`: Adds an item to the invoice
- `display()`: Displays the details of the invoice

### Inventory
Manages the overall inventory, including products, categories, and suppliers.

#### Methods:
- `addSampleProducts()`: Adds sample products to the inventory
- `addSampleCategories()`: Adds sample categories to the inventory
- `addSampleSuppliers()`: Adds sample suppliers to the inventory
- `addProduct(Product &product)`: Adds a new product to the inventory
- `updateProduct(int id, Product &updatedProduct)`: Updates an existing product in the inventory
- `queryProduct(int id)`: Queries a product by its ID
- `removeProduct(int id)`: Removes a product by its ID
- `buyProduct(string name, int quantity)`: Buys a product and generates an invoice
- `displayAllProducts()`: Displays all products in the inventory
- `addCategory(Category &category)`: Adds a new category to the inventory
- `updateCategory(string name, Category &updatedCategory)`: Updates an existing category
- `queryCategory(string name)`: Queries a category by its name
- `removeCategory(string name)`: Removes a category by its name
- `displayAllCategories()`: Displays all categories in the inventory
- `displayProductByCategory(string &category)`: Displays products by their category
- `addSupplier(Supplier &supplier)`: Adds a new supplier to the inventory
- `updateSupplier(string name, Supplier &updatedSupplier)`: Updates an existing supplier
- `querySupplier(string name)`: Queries a supplier by its name
- `removeSupplier(string name)`: Removes a supplier by its name
- `displayAllSuppliers()`: Displays all suppliers in the inventory

## Usage

To run the Inventory Management System, simply compile and execute the `main` function. You will be presented with a command-line interface to interact with the system.

### Sample Usage Example

 **Add a Product**
   ```plaintext
   Enter product ID: 1
   Enter the Category name: Electronics
   Enter product quantity: 10
   Enter product price: 199.99
```
## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
