//
// Created by mojiajun on 2020/1/7.
//
#ifndef TINYKVDB_SRC_CODING_H_
#define TINYKVDB_SRC_CODING_H_

#include <string>

namespace tinykvdb {

void EncodeData(char *buf,
    const std::string &key,
    const std::string &value);

}  // namespace tinykvdb

#endif //TINYKVDB_SRC_CODING_H_
