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

void EncodeIndex(char* buf,
                 const std::string& key,
                 uint32_t file_index,
                 uint64_t file_offset,
                 uint32_t key_size,
                 uint32_t value_size);

}  // namespace tinykvdb

#endif //TINYKVDB_SRC_CODING_H_
