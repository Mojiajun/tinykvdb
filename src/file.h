//
// Created by mojiajun on 2020/1/6.
//
#ifndef TINYKVDB_SRC_FILE_H_
#define TINYKVDB_SRC_FILE_H_

#include <unistd.h>

namespace tinykvdb {

// TODO, 完善这个类
// 先设计API, 然后实现
class File {
 public:
  File(int32_t fd) :
    fd_(fd) { }

  ~File() {
      ::close(fd_);
  }

 private:
  int fd_;
};

}  // namespace tinykvdb

#endif //TINYKVDB_SRC_FILE_H_
