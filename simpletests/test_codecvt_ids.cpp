// test_codecvt_ids.cpp
#include <locale>
#include <codecvt>
#include <iostream>
#include <fstream>
#include <typeinfo>

int main() {
    try {
        // Test codecvt<wchar_t, char, mbstate_t>
        std::locale loc1(std::locale::classic(), new std::codecvt<wchar_t, char, std::mbstate_t>);
        std::cout << "codecvt<wchar_t, char, mbstate_t> is available.\n";

#if defined(_MSC_VER)
        // Only MSVC：Test codecvt<char16_t, char, mbstate_t>
        std::locale loc2(std::locale::classic(), new std::codecvt<char16_t, char, std::mbstate_t>);
        std::cout << "codecvt<char16_t, char, mbstate_t> is available.\n";

        std::basic_filebuf<char16_t> fb;
        fb.pubimbue(loc2); // Bind locale

        if (fb.open("16to8.txt", std::ios::out | std::ios::binary)) {
            std::basic_ostream<char16_t> out(&fb);

            std::u16string data = u"你好, せかい.";
            out << data;
            fb.close();
            std::cout << "16to8 Wirte Done." << std::endl;
        } else {
            std::cerr << "Failed to open file." << std::endl;
        }

        std::locale loc3(std::locale::classic(), new std::codecvt<char32_t, char, std::mbstate_t>);
        std::cout << "codecvt<char32_t, char, mbstate_t> is available.\n";

        std::basic_filebuf<char32_t> fb1;
        fb1.pubimbue(loc3); // Bind locale

        if (fb1.open("32to8.txt", std::ios::out | std::ios::binary)) {
            std::basic_ostream<char32_t> out(&fb1);

            std::u32string data = U"你好, せかい.";
            out << data;
            fb1.close();
            std::cout << "32to8 Wirte Done." << std::endl;
        }
        else {
            std::cerr << "Failed to open file." << std::endl;
        }
#endif

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
