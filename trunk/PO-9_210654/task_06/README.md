
# Лабораторная работа № 6 #

## Тема ##

Изучение UML. Диаграмма классов.

## Цель работы ##

Освоить построение диаграммы классов.

## Порядок выполнения ##

1. Изучить теоретический материал из [документации](https://mermaid.js.org/intro/getting-started.html).
2. Выбрать свой вариант.
3. Нарисовать каждый класс отдельно с методами и полями.
4. Оформить отчет.

## Вариант 5 ##

- Постройте UML диаграмму классов для системы управления заказами в ресторане.

## Диаграмма ##

```mermaid

classDiagram
    class Restaurant {
        +String name
        +List<Table> tables
        +List<Order> orders
        +List<Menu> menus
        +void addTable(Table table)
        +void removeTable(Table table)
        +void addOrder(Order order)
        +void removeOrder(Order order)
        +void addMenu(Menu menu)
        +void removeMenu(Menu menu)
        +List<Table> getAvailableTables()
        +List<Order> getOrdersByTable(Table table)
        +List<Order> getOrdersByStatus(String status)
    }
  
    class Table {
        +int tableNumber
        +int capacity
    }
  
    class Order {
        +int orderNumber
        +Table table
        +List<OrderItem> items
        +String status
        +void addItem(OrderItem item)
        +void removeItem(OrderItem item)
        +void updateStatus(String status)
    }
  
    class Menu {
        +String name
        +List<MenuItem> items
        +void addItem(MenuItem item)
        +void removeItem(MenuItem item)
    }
  
    class OrderItem {
        +MenuItem menuItem
        +int quantity
    }
  
    class MenuItem {
        +String name
        +String description
        +double price
    }
  
    Restaurant --> Table
    Restaurant --> Order
    Restaurant --> Menu
    Table "1" *-- "0..1" Order
    Order --> OrderItem
    Menu --> MenuItem
    OrderItem --> MenuItem

```

## Код ##

- [main.cpp](./src/main.cpp)

### Вывод ###

Освоил построение диаграммы классов.
