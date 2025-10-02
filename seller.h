#include "buyer.h"
#include "item.h"
#include <string>
#include <vector>

class seller : public Buyer {

private:
    int sellerId;
    std::string sellerName;

    bool idDisplayed(int itemId) const {
        // Example implementation, can be customized
        return itemId > 0; // Assuming valid IDs are positive integers
    }

    std::vector<Item> items; // Assuming seller has a collection of items

public:
    seller() = default;

    seller(Buyer buyer, int sellerId, const std::string& sellerName)
        : Buyer(buyer), sellerId(sellerId), sellerName(sellerName) {}

    virtual ~seller() = default;

    void addNewItem(int newId, const std::string& newName, int newQuantity, double newPrice) {
        Item newItem(newId, newName, newQuantity, newPrice);
        items.push_back(newItem);
    }

    void updateItem(int itemId, const std::string& newName, int newQuantity, double newPrice) {
        for (auto& item : items) {
            if (item.getId() == itemId) {
                item.alterItemById(itemId, newName, newQuantity, newPrice);
            }
        }
    }

    void makeItemVisibleToCustomer(int itemId) {
        for (auto& item : items) {
            if (item.getId() == itemId) {
                item.setDisplay(true);
                break;
            }
        }
    }

    // Add seller-specific members here
};