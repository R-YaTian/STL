#include <iostream>
#include <cmath>
#include <cassert>
#include <iomanip>

int main() {
    try {
        std::cout << "Testing Riemann Zeta function from msvcp140_2.dll\n";
        std::cout << "===============================================\n";

        // Test Riemann zeta on 3.0
        const double rz3 = std::riemann_zeta(3.0);

        std::cout << std::setprecision(17);
        std::cout << "RiemannZeta(3) = " << rz3 << "\n";
        std::cout << "Known value: RiemannZeta(3) about 1.2020569031595942\n";

        assert(rz3 > 1.2020569031);
        assert(rz3 < 1.2020569032);

        std::cout << "\nTest passed! RiemannZeta(3) is within expected range.\n";
        return 0;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
}
