#include <QCoreApplication>
#include <QString>
#include <QVector>
#include <QDebug>

class Product {
private:
    int id;
    QString name;
    QString description;
    double price;
    int stockQuantity;

public:
    Product(int id, const QString& name, const QString& description, double price, int stockQuantity)
        : id(id), name(name), description(description), price(price), stockQuantity(stockQuantity) {}

    int getId() const { return id; }
    QString getName() const { return name; }
    QString getDescription() const { return description; }
    double getPrice() const { return price; }
    int getStockQuantity() const { return stockQuantity; }
};


class ElectronicProduct : public Product {
private:
    QString brand;
    QString model;

public:
    ElectronicProduct(int id, const QString& name, const QString& description, double price, int stockQuantity, const QString& brand, const QString& model)
        : Product(id, name, description, price, stockQuantity), brand(brand), model(model) {}

    QString getBrand() const { return brand; }
    QString getModel() const { return model; }
};


class ShoppingCartItem {
private:
    const Product& product;
    int quantity;

public:
    ShoppingCartItem(const Product& product, int quantity)
        : product(product), quantity(quantity) {}

    const Product& getProduct() const { return product; }
    int getQuantity() const { return quantity; }
};


class User {
private:
    int id;
    QString username;
    QString email;
    QString password;

public:
    User(int id, const QString& username, const QString& email, const QString& password)
        : id(id), username(username), email(email), password(password) {}

    int getId() const { return id; }
    QString getUsername() const { return username; }
    QString getEmail() const { return email; }
};


class Order {
private:
    int id;
    const User& user;
    QVector<ShoppingCartItem> items;
    double totalAmount;

public:
    Order(int id, const User& user, const QVector<ShoppingCartItem>& items, double totalAmount)
        : id(id), user(user), items(items), totalAmount(totalAmount) {}

    int getId() const { return id; }
    const User& getUser() const { return user; }
    const QVector<ShoppingCartItem>& getItems() const { return items; }
    double getTotalAmount() const { return totalAmount; }
};


class ElectronicStore {
private:
    QVector<ElectronicProduct> products;
    QVector<User> users;

public:
    void addProduct(const ElectronicProduct& product) {
        products.push_back(product);
    }

    const ElectronicProduct* findProductById(int productId) const {
        for (const ElectronicProduct& product : products) {
            if (product.getId() == productId) {
                return &product;
            }
        }
        return nullptr;
    }

    void registerUser(const User& user) {
        users.push_back(user);
    }
};

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    ElectronicStore electronicStore;

    ElectronicProduct laptop(1, "Laptop", "Perfect laptop for work and programming", 1999.99, 10, "Brand_SupStar", "Model_P");
    electronicStore.addProduct(laptop);

    User user(1, "PeterGriffin", "peter.gr@example.com", "p1239");
    electronicStore.registerUser(user);

    const ElectronicProduct* foundProduct = electronicStore.findProductById(1);
    if (foundProduct) {
        qDebug() << "Found product:" << foundProduct->getName();
    } else {
        qDebug() << "Product not found.";
    }

    return a.exec();
}
