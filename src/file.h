//
// Created by mojiajun on 2020/1/6.
//
#ifndef TINYKVDB_SRC_FILE_H_
#define TINYKVDB_SRC_FILE_H_

namespace tinykvdb {

// TODO, 完善这个类
// 先设计API, 然后实现
class File {
 public:
  File() = default;

 private:
  int fd_;
  std::string filename_;
};

}  // namespace tinykvdb

#endif //TINYKVDB_SRC_FILE_H_
