#pragma once

#include <algorithm>

#include "ip.h"

namespace filters
{

void filter_1(const std::vector<Ip>& ip_pool, std::vector<Ip>& filtered_ip) {
    std::copy_if(ip_pool.cbegin(), ip_pool.cend(), std::back_inserter(filtered_ip), [](const Ip& ip) {
        return ip.octet_1 == 1;
    });
}

void filter_46_70(const std::vector<Ip>& ip_pool, std::vector<Ip>& filtered_ip) {
    std::copy_if(ip_pool.cbegin(), ip_pool.cend(), std::back_inserter(filtered_ip), [](const Ip& ip) {
        return ip.octet_1 == 46 && ip.octet_2 == 70;
    });
}

void filter_46(const std::vector<Ip>& ip_pool, std::vector<Ip>& filtered_ip) {
    std::copy_if(ip_pool.cbegin(), ip_pool.cend(), std::back_inserter(filtered_ip), [](const Ip& ip) {
        return ip.octet_1 == 46 || ip.octet_2 == 46 || ip.octet_3 == 46 || ip.octet_4 == 46;
    });
}

}