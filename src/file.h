//
// Created by mojiajun on 2020/1/6.
//
#ifndef TINYKVDB_SRC_FILE_H_
#define TINYKVDB_SRC_FILE_H_

#include <cstdint>
#include <memory>
#include <unistd.h>

namespace tinykvdb {

// TODO, 完善这个类
// 先设计API, 然后实现
class File {
 public:
  File(int32_t fd) :
      fd_(fd) {}

  ~File() {
      ::close(fd_);
  }

  static std::unique_ptr<File> Newfile(const std::string &filename);

  bool AppendData(const std::string &key,
                  const std::string &value,
                  uint64_t *file_offset_out);

  bool AppendIndex(const std::string &key,
                   uint32_t file_index,
                   uint64_t file_offset,
                   uint32_t key_size,
                   uint32_t value_size);

 private:
  int fd_;
  uint64_t file_offset_ = 0;
};


}  // namespace tinykvdb

#endif //TINYKVDB_SRC_FILE_H_
