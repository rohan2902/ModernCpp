#include "Product.h"

Product::Product(std::string id, ProductType type, float price, std::string brand, ProductOrigin origin)
:productID(id),productType(type),productPrice(price),productBrand(brand),productOrigin(origin)
{
    productTaxAmount=0.05*productPrice;
}

std::ostream &operator<<(std::ostream &os, const Product &rhs) {
    os << "\nproductID: " << rhs.productID
       << "\nproductType: " << static_cast<int>(rhs.productType)
       << "\nproductPrice: " << rhs.productPrice
       << "\nproductBrand: " << rhs.productBrand
       << "\nproductOrigin: " << static_cast<int>(rhs.productOrigin)
       << "\nproductTaxAmount: " << rhs.productTaxAmount;
    return os;
}

