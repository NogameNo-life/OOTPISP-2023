#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Table {
public:
    int tableNumber;
    int capacity;

    Table(int number, int capacity) : tableNumber(number), capacity(capacity) {}

    bool operator==(const Table& other) const {
        return (tableNumber == other.tableNumber && capacity == other.capacity);
    }
};

class MenuItem {
public:
    std::string name;
    std::string description;
    double price;

    MenuItem(const std::string& name, const std::string& description, double price)
        : name(name), description(description), price(price) {}

    bool operator==(const MenuItem& other) const {
        return (name == other.name && description == other.description && price == other.price);
    }
};

class OrderItem {
public:
    MenuItem menuItem;
    int quantity;

    OrderItem(const MenuItem& menuItem, int quantity) : menuItem(menuItem), quantity(quantity) {}

    bool operator==(const OrderItem& other) const {
        return (menuItem == other.menuItem && quantity == other.quantity);
    }
};

class Order {
public:
    int orderNumber;
    Table table;
    std::vector<OrderItem> items;
    std::string status;

    Order(int orderNumber, const Table& table) : orderNumber(orderNumber), table(table), status("PLACED") {}

    void addItem(const OrderItem& item) {
        items.push_back(item);
    }

    void removeItem(const OrderItem& item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }

    void updateStatus(const std::string& status) {
        this->status = status;
    }

    bool operator==(const Order& other) const {
        return (orderNumber == other.orderNumber && table == other.table && items == other.items && status == other.status);
    }
};

class Menu {
public:
    std::string name;
    std::vector<MenuItem> items;

    void addItem(const MenuItem& item) {
        items.push_back(item);
    }

    void removeItem(const MenuItem& item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }

    bool operator==(const Menu& other) const {
        return (name == other.name && items == other.items);
    }
};

class Restaurant {
public:
    std::string name;
    std::vector<Table> tables;
    std::vector<Order> orders;
    std::vector<Menu> menus;

    void addTable(const Table& table) {
        tables.push_back(table);
    }

    void removeTable(const Table& table) {
        tables.erase(std::remove(tables.begin(), tables.end(), table), tables.end());
    }

    void addOrder(const Order& order) {
        orders.push_back(order);
    }

    void removeOrder(const Order& order) {
        orders.erase(std::remove(orders.begin(), orders.end(), order), orders.end());
    }

    void addMenu(const Menu& menu) {
        menus.push_back(menu);
    }

    void removeMenu(const Menu& menu) {
        menus.erase(std::remove(menus.begin(), menus.end(), menu), menus.end());
    }

    std::vector<Table> getAvailableTables() {
        std::vector<Table> availableTables;
        for (const Table& table : tables) {
            bool isTableOccupied = false;
            for (const Order& order : orders) {
                if (order.table == table) {
                    isTableOccupied = true;
                    break;
                }
            }
            if (!isTableOccupied) {
                availableTables.push_back(table);
            }
        }
        return availableTables;
    }

    std::vector<Order> getOrdersByTable(const Table& table) {
        std::vector<Order> ordersByTable;
        for (const Order& order : orders) {
            if (order.table == table) {
                ordersByTable.push_back(order);
            }
        }
        return ordersByTable;
    }

    std::vector<Order> getOrdersByStatus(const std::string& status) {
        std::vector<Order> ordersByStatus;
        for (const Order& order : orders) {
            if (order.status == status) {
                ordersByStatus.push_back(order);
            }
        }
        return ordersByStatus;
    }
};

int main() {
    // Создание ресторана
    Restaurant restaurant;
    restaurant.name = "My Restaurant";

    // Создание столов
    Table table1(1, 4);
    Table table2(2, 6);
    Table table3(3, 2);

    // Добавление столов в ресторан
    restaurant.addTable(table1);
    restaurant.addTable(table2);
    restaurant.addTable(table3);

    // Создание меню
    Menu menu;
    menu.name = "Main Menu";

    // Создание пунктов меню
    MenuItem item1("Burger", "Delicious beef burger", 9.99);
    MenuItem item2("Pizza", "Classic margherita pizza", 12.99);
    MenuItem item3("Salad", "Fresh garden salad", 7.99);

    // Добавление пунктов меню в меню
    menu.addItem(item1);
    menu.addItem(item2);
    menu.addItem(item3);

    // Добавление меню в ресторан
    restaurant.addMenu(menu);

    // Создание заказов
    Order order1(1, table1);
    order1.addItem(OrderItem(item1, 2));
    order1.addItem(OrderItem(item3, 1));

    Order order2(2, table2);
    order2.addItem(OrderItem(item2, 1));

    // Добавление заказов в ресторан
    restaurant.addOrder(order1);
    restaurant.addOrder(order2);

    // Получение доступных столов и вывод их на экран
    std::vector<Table> availableTables = restaurant.getAvailableTables();
    std::cout << "Available Tables:\n";
    for (const Table& table : availableTables) {
        std::cout << "Table " << table.tableNumber << " (Capacity: " << table.capacity << ")\n";
    }

    // Получение заказов для определенного стола и вывод их на экран
    Table targetTable(1, 4);
    std::vector<Order> ordersByTable = restaurant.getOrdersByTable(targetTable);
    std::cout << "\nOrders for Table " << targetTable.tableNumber << ":\n";
    for (const Order& order : ordersByTable) {
        std::cout << "Order " << order.orderNumber << " (Status: " << order.status << ")\n";
    }

    // Получение заказов по определенному статусу и вывод их на экран
    std::string targetStatus = "PLACED";
    std::vector<Order> ordersByStatus = restaurant.getOrdersByStatus(targetStatus);
    std::cout << "\nOrders with Status '" << targetStatus << "':\n";
    for (const Order& order : ordersByStatus) {
        std::cout << "Order " << order.orderNumber << " (Table: " << order.table.tableNumber << ")\n";
    }

    return 0;
}
