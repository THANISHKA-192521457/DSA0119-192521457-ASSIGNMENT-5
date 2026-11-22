#include <iostream>
#include <new>
#include <stdexcept>
#include <string>
int main() {
    try {
        std::string text = "not-a-number";
        try { (void)std::stod(text); }
        catch (const std::invalid_argument& e) {
            std::cout << "invalid input: " << e.what() << '\n';
        }
        try { throw std::bad_alloc(); }
        catch (const std::bad_alloc&) {
            std::cout << "allocation failure handled\n";
        }
        throw std::runtime_error("unknown package code");
    } catch (const std::exception& e) {
        std::cout << "top-level: " << e.what() << '\n';
    } catch (...) {
        std::cout << "top-level: unknown failure\n";
    }
}
