#include <iostream>
#include <vector>
#include <memory_resource>
#include <string>

int main() {
    // Create Buffer
    constexpr size_t buffer_size = 1024;
    char buffer[buffer_size];

    // Create pmr::monotonic_buffer_resource
    std::pmr::monotonic_buffer_resource resource(buffer, buffer_size);

    // Create pmr::vector
    std::pmr::vector<std::pmr::string> vec{ &resource };

    // Append strings to vector
    vec.emplace_back("Hello, ");
    vec.emplace_back("world.\n");
    vec.emplace_back("STL ");
    vec.emplace_back("memory_resource tester!\n");

    // Output to stdout
    for (const auto& str : vec) {
        std::cout << str;
    }

    return 0;
}
