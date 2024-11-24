#include <iostream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

#include "stockmanger_withoutObserver.hpp"

namespace stockmanger_withoutObserver {
    class StockManager {
    private:
        bool productInStock;

    public:
        StockManager() : productInStock(false) {}

        void setStockStatus(bool inStock) {
            if (productInStock != inStock) {
                productInStock = inStock;
                if (inStock)
                    notifyCustomers();
            }
        }

        void notifyCustomers() {
            std::cout << "Product A is back in stock!" << std::endl;
        }

        bool isInStock() const {
            return productInStock;
        }
    };

    class Customer {
    private:
        std::string name;

    public:
        Customer(const std::string& name) : name(name) {}

        void notify(const std::string& message) {
            std::cout << "Notification for " << name << ": " << message << std::endl;
        }
    };


    void main(unsigned int ntimes) {
        StockManager stockManager;

        Customer customer1("Customer 1");
        Customer customer2("Customer 2");

        bool previousStockStatus = false;

        do {
            bool currentStockStatus = stockManager.isInStock();
            if (currentStockStatus && !previousStockStatus) {
                customer1.notify("Product A is back in stock!");
                customer2.notify("Product A is back in stock!");
            }
            previousStockStatus = currentStockStatus;

            // Wait for a while before checking again (simulate real-time scenario)
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            stockManager.setStockStatus(bool(ntimes % 3));
            if (ntimes > 0u) --ntimes;
        } while (ntimes);
    }
}
