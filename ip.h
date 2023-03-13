#pragma once

#include <iostream>
#include <cstdint>
#include <tuple>
#include <vector>

struct Ip
{
    explicit Ip()
    : octet_1 (0),
      octet_2 (0),
      octet_3 (0),
      octet_4 (0)
    {}

    void initialize(const std::vector<std::string>& str) {
        if (str.size() != 4) {
            throw std::invalid_argument("IP must contain four octets!");
        }

        for (const auto& octet : str)
            if (std::stoi(octet) < 0 || std::stoi(octet) > 255)
                throw std::invalid_argument("Octet must be from 0 to 255");

        octet_1 = std::stoi(str[0]);
        octet_2 = std::stoi(str[1]);
        octet_3 = std::stoi(str[2]);
        octet_4 = std::stoi(str[3]);
    };

    std::uint8_t octet_1;
    std::uint8_t octet_2;
    std::uint8_t octet_3;
    std::uint8_t octet_4;

    void print() const {
        std::cout << static_cast<int>(octet_1) << '.'
                  << static_cast<int>(octet_2) << '.'
                  << static_cast<int>(octet_3) << '.'
                  << static_cast<int>(octet_4) << '\n';
    }

    bool operator > (const Ip& ip) const {
        return std::tie(octet_1, octet_2, octet_3, octet_4) > std::tie(ip.octet_1, ip.octet_2, ip.octet_3, ip.octet_4);
    }

    bool operator == (const Ip& ip) const {
        return std::tie(octet_1, octet_2, octet_3, octet_4) == std::tie(ip.octet_1, ip.octet_2, ip.octet_3, ip.octet_4);
    }
};