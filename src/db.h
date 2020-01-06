#ifndef TINYKVDB_SRC_DB_H_
#define TINYKVDB_SRC_DB_H_

#include <string>

namespace tinykvdb {

class Kvdb {
 public:
  // TODO, ?要不要用 = default, 感觉没区别啊
  Kvdb() { }
  virtual ~Kvdb() { }

  Kvdb(const Kvdb&) = delete;
  Kvdb& operator=(const Kvdb&) = delete;

  // TODO, 这里要设成引用吗?
  // TODO, 加入Option
  static bool Open(const std::string &dbname, Kvdb **dbptr);

  /// Put(key, value)把key, value存入db
  virtual bool Put(const std::string &key, const std::string &value) = 0;

  /// Put(key, value)把key, value存入db
  /// 这里返回的值放入*value, 函数返回值为bool, API尽量与 Put(), Delete()一致.
  virtual bool Get(const std::string &key, std::string *value) = 0;

  /// Put(key, value)把key, value存入db
  virtual bool Delete(const std::string &key) = 0;
};

}  // namespace tinykvdb

#endif  // TINYKVDB_SRC_DB_H_
