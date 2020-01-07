//
// Created by mojiajun on 2020/1/6.
//
#ifndef TINYKVDB_SRC_INDEX_H_
#define TINYKVDB_SRC_INDEX_H_

#include <cstdint>  // TODO, 貌似不需要这个uint32_t这种也能定义出来啊
#include <string>

namespace tinykvdb {

// 可拷贝的类
class Index {
 public:
  Index() { }

  Index(const std::string &key, uint32_t file_index, uint64_t file_offset, uint32_t key_size, uint32_t value_size) :
    key_(key),
    file_index_(file_index),
    file_offset_(file_offset),
    key_size_(key_size),
    value_size_(value_size) { }

 ~Index() {}

  std::string Key() const { return key_; }

  uint32_t FileIndex() const { return file_index_; }

  uint64_t FileOffset() const { return file_offset_; }

  uint32_t KeySize() const { return key_size_; }

  uint32_t ValueSize() const { return value_size_; }

  uint32_t DataSize() const { return key_size_ + value_size_; }

  uint32_t IndexSize() const {
      return key_size_ + sizeof(uint32_t) * 3 + sizeof(uint64_t);
  }

  void SetDeleted() {
      key_size_ = 0;
      value_size_ = 0;
  }


 private:
  std::string key_;
  uint32_t file_index_;
  uint64_t file_offset_;
  uint32_t key_size_;
  uint32_t value_size_;
};

}  // namespace tinykvdb

#endif //TINYKVDB_SRC_INDEX_H_
