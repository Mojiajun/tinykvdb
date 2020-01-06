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
  ~Index() { }

  std::string Key() const { return key_; }

 private:
  std::string key_;
  uint32_t file_index_;
  uint64_t file_offset_;

  uint32_t key_size_;
  uint32_t value_size_;
};

}  // namespace tinykvdb

#endif //TINYKVDB_SRC_INDEX_H_
