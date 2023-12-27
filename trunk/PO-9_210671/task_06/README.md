# Лабораторная работа № 6

## UML - диаграммы

## Цель работы

Изучить UML-диаграммы, применить их на практике.

## Задания для выполнения (Вариант 22)

Постройте UML диаграмму классов для онлайн-магазина, который продает электронику.

```mermaid
---
title: Онлайн-магазин
---
classDiagram
    class Product {
        +getName(): string
        +getPrice(): double
        +getStock(): int
        +setStock(newStock: int): void
    }

    class Customer {
        +getName(): string
        +getAddress(): string
    }

    class Order {
        +getCustomer(): Customer
        +getProducts(): vector<Product>
    }

    class ShoppingCart {
        +addProduct(product: Product): void
        +removeProduct(productName: string): void
        +getProducts(): vector<Product>
    }

    class ProductCategory {
        +getName(): string
    }

    class Brand {
        +getName(): string
    }

    class Promotion {
        +getName(): string
        +getDiscount(): double
    }

    class ProductReview {
        +getReviewer(): string
        +getComment(): string
        +getRating(): int
    }

    class PaymentSystem {
        +processPayment(order: Order, amount: double): void
    }

    class DeliverySystem {
        +shipOrder(order: Order, shippingAddress: string): void
    }

    Product --|> ShoppingCart : contains
    ShoppingCart --|> Order : creates
    Customer --|> Order : places
    Order --|> ProductCategory : belongs to
    Order --|> Promotion : applies
    Product --|> Brand : has
    Product --|> ProductReview : has
    Order --|> Customer : has
    Order --|> PaymentSystem : uses
    Order --|> DeliverySystem : uses
```

## Вывод

Изучили UML-диаграммы и применили их на практике.
