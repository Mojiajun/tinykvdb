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
    // 如果用std::string::c_str(), 会不对...why
    // test_key_02test_value_02���
    memcpy(buf, key.c_str(), key.size());
    memcpy(buf + key.size(), value.c_str(), value.size());
    //memcpy(buf, key.data(), key.size());
    //memcpy(buf + key.size(), value.data(), value.size());
}

// 暂时先这样, API设计的感觉不好
/// 数据格式 index_size(uint32_t) + file_index(uint32_t) + file_offset(uint64_t) +
/// key_size(uint32_t) + key(key_size) + value_size(uint32_t)
/// 所以在调用端是uint32_t index_size = key.size() + sizeof(uint32_t) * 4 + sizeof(uint64_t);
void EncodeIndex(char *buf,
                 const std::string &key,
                 uint32_t file_index,
                 uint64_t file_offset,
                 uint32_t key_size,
                 uint32_t value_size) {
    assert(buf);
    size_t pos = 0;

    uint32_t index_size = key_size + sizeof(uint32_t) * 3 + sizeof(uint64_t);
    // The size of index
    memcpy(buf, &index_size, sizeof(uint32_t));
    pos += sizeof(uint32_t);
    // File index
    memcpy(buf + pos, &file_index, sizeof(uint32_t));
    pos += sizeof(uint32_t);
    // File offset
    memcpy(buf + pos, &file_offset, sizeof(uint64_t));
    pos += sizeof(uint64_t);
    // The size of key
    memcpy(buf + pos, &key_size, sizeof(uint32_t));
    pos += sizeof(uint32_t);
    // The key
    memcpy(buf + pos, key.data(), key_size);
    pos += key_size;
    // The size of value
    memcpy(buf + pos, &value_size, sizeof(uint32_t));
}


void DecodeData(char *buf, uint32_t key_size, uint32_t value_size, std::string *value) {
    // 得加个value_size尺寸参数, 不然会多东西
    *value = std::string(buf + key_size, value_size);
}

}  // namespace tinykvdb
