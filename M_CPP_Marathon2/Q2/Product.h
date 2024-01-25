#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include"ProductOrigin.h"
#include"ProductType.h"


class Product
{
private:
    
    std::string productID;
    ProductType productType;
    float productPrice;
    std::string productBrand;
    ProductOrigin productOrigin;
    float productTaxAmount;



public:
    Product() = delete;

    Product(std::string id,
            ProductType type,
            float price,
            std::string brand,
            ProductOrigin origin);
            
    Product(const Product &) = delete;
    Product &operator=(Product &) = delete;
    Product(const Product &&) = delete;
    Product &operator=(Product &&) = delete;
    ~Product() = default;

    std::string getProductID() const { return productID; }

    ProductType getProductType() const { return productType; }

    float getProductPrice() const { return productPrice; }

    std::string getProductBrand() const { return productBrand; }

    ProductOrigin getProductOrigin() const { return productOrigin; }

    float getProductTaxAmount() const { return productTaxAmount; }

    friend std::ostream &operator<<(std::ostream &os, const Product &rhs);
};

#endif // PRODUCT_H
