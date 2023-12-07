#include <iostream>
#include <string>
#include <vector>

// Класс, представляющий товар
class Product {
public:
    Product(const std::string& name, double price, int stock)
        : name(name), price(price), stock(stock) {}

    std::string getName() const {
        return name;
    }

    double getPrice() const {
        return price;
    }

    int getStock() const {
        return stock;
    }

    void setStock(int newStock) {
        stock = newStock;
    }

private:
    std::string name;
    double price;
    int stock;
};

// Класс, представляющий покупателя
class Customer {
public:
    Customer(const std::string& name, const std::string& address)
        : name(name), address(address) {}

    std::string getName() const {
        return name;
    }

    std::string getAddress() const {
        return address;
    }

private:
    std::string name;
    std::string address;
};

// Класс, представляющий заказ
class Order {
public:
    Order(const Customer& customer, const std::vector<Product>& products)
        : customer(customer), products(products) {}

    Customer getCustomer() const {
        return customer;
    }

    std::vector<Product> getProducts() const {
        return products;
    }

private:
    Customer customer;
    std::vector<Product> products;
};

// Класс, представляющий корзину покупок
class ShoppingCart {
public:
    void addProduct(const Product& product) {
        products.push_back(product);
    }

    void removeProduct(const std::string& productName) {
        products.erase(std::remove_if(products.begin(), products.end(),
                                      [&productName](const Product& p) { return p.getName() == productName; }),
                       products.end());
    }

    std::vector<Product> getProducts() const {
        return products;
    }

private:
    std::vector<Product> products;
};

// Класс, представляющий категорию товаров
class ProductCategory {
public:
    explicit ProductCategory(const std::string& name)
        : name(name) {}

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

// Класс, представляющий бренд товаров
class Brand {
public:
   explicit Brand(const std::string& name)
        : name(name) {}

    std::string getName() const {
        return name;
    }

private:
    std::string name;
};

// Класс, представляющий акцию или скидку
class Promotion {
public:
    Promotion(const std::string& name, double discount)
        : name(name), discount(discount) {}

    std::string getName() const {
        return name;
    }

    double getDiscount() const {
        return discount;
    }

private:
    std::string name;
    double discount;
};

// Класс, представляющий отзыв о товаре
class ProductReview {
public:
    ProductReview(const std::string& reviewer, const std::string& comment, int rating)
        : reviewer(reviewer), comment(comment), rating(rating) {}

    std::string getReviewer() const {
        return reviewer;
    }

    std::string getComment() const {
        return comment;
    }

    int getRating() const {
        return rating;
    }

private:
    std::string reviewer;
    std::string comment;
    int rating;
};

// Класс, представляющий систему оплаты
class PaymentSystem {
public:
    void processPayment(const Order& order, double amount) {
        // Логика обработки платежа
        std::cout << "Payment processed for order with amount $" << amount << std::endl;
    }
};

// Класс, представляющий систему доставки
class DeliverySystem {
public:
    void shipOrder(const Order& order, const std::string& shippingAddress) {
        // Логика доставки заказа
        std::cout << "Order shipped to " << shippingAddress << std::endl;
    }
};

int main() {
    // Пример использования классов
    ProductCategory laptops("Laptops");
    std::cout << "Категория товаров: " << laptops.getName() << std::endl;
    Brand dell("Dell");
    std::cout << "Название бренда: " << dell.getName() << std::endl;
    Promotion discount("Black Friday Sale", 0.2);
    std::cout << "Акция: " << discount.getName() << ", Скидка: " << discount.getDiscount() << std::endl;
    PaymentSystem paymentSystem;
    DeliverySystem deliverySystem;

    Product laptop("Dell XPS 13", 1299.99, 50);
    laptop.setStock(10); // Устанавливаем новый запас товара

    Customer customer("John Doe", "123 Main St");
    Order order(customer, {laptop});

    ShoppingCart cart;
    cart.addProduct(laptop);

    // Процесс заказа
    paymentSystem.processPayment(order, 999.99);
    deliverySystem.shipOrder(order, customer.getAddress());

    return 0;
}
