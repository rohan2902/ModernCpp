#include "Product.h"
 
Product::Product(std::string Id, float price, std::string brand, float taxAmount, productType ptype, productOrigin porigin):_productId(Id),_productPrice(price),_productBrand(brand),_productTaxAmount(taxAmount),_pType(ptype),_pOrigin(porigin)
{
}
std::ostream &operator<<(std::ostream &os, const Product &rhs) {
    os << "_productId: " << rhs._productId
       << " _productPrice: " << rhs._productPrice
       << " _productBrand: " << rhs._productBrand
       << " _productTaxAmount: " << rhs._productTaxAmount
       << " _pType: " <<static_cast<int> (rhs._pType)
       << " _pOrigin: " <<static_cast<int> (rhs._pOrigin);
    return os;
}
