#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include"productType.h" 
#include"productOrigin.h" 

class Product
{
private:
    std::string _productId;
    float _productPrice;
    std::string _productBrand;
    float _productTaxAmount = 0.5*_productPrice;
    productType _pType;
    productOrigin _pOrigin;

public:
    Product() = default;
    Product(std::string Id,float price,std::string brand,float taxAmount,productType ptype,productOrigin porigin);
    Product(const Product&) = delete;
    Product(Product&&) = delete;
    Product& operator = (const Product&) = delete;
    Product& operator = (Product&&) = delete;
    ~Product() = default;

    std::string productId() const { return _productId; }

    float productPrice() const { return _productPrice; }

    std::string productBrand() const { return _productBrand; }

    float productTaxAmount() const { return _productTaxAmount; }

    productType pType() const { return _pType; }

    productOrigin pOrigin() const { return _pOrigin; }

    friend std::ostream &operator<<(std::ostream &os, const Product &rhs);
};

#endif // PRODUCT_H