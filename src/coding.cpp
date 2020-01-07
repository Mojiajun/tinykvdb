//
// Created by mojiajun on 2020/1/7.
//
#include "coding.h"

#include <cstring>
#include <string>

namespace tinykvdb {

void EncodeData(char *buf,
                const std::string &key,
                const std::string &value) {
    memcpy(buf, key.c_str(), key.size());
    memcpy(buf + key.size(), value.c_str(), value.size());
}

}  // namespace tinykvdb
