//
// Created by mojiajun on 2020/1/6.
//
#ifndef TINYKVDB_SRC_DB_IMPL_H_
#define TINYKVDB_SRC_DB_IMPL_H_

#include <cstdint>  // uint32_t 需要吗?
#include <memory>
#include <set>
#include <vector>

#include "db.h"
#include "index.h"
// ???为什么用前向声明不行...然后发送一个函数匹配问题...感觉是给的信息不够多.然后又让push_back(std::move)这个push_back函数进行函数匹配
#include "file.h"

namespace tinykvdb {

// TODO, 和pimpl idiom相比?
// 不用继承怎么实现?替代方案?
class KvdbImpl : public Kvdb {
 public:
  KvdbImpl(const std::string &dbname);

  virtual ~KvdbImpl();

  // 要加override吗?为什么这里要加virtual?
  virtual bool Put(const std::string &key, const std::string &value);

  virtual bool Get(const std::string &key, std::string *value);

  virtual bool Delete(const std::string &key);

  static const int MAX_FILES = 10;
 private:
  friend Kvdb;

  std::string dbname_;
  std::vector<std::unique_ptr<File>> data_files_;
  std::vector<std::unique_ptr<File>> index_files_;
  std::set<Index> tables_;
  uint32_t max_file_;
  uint32_t cursor_;
};

}  // namespace tinykvdb

#endif //TINYKVDB_SRC_DB_IMPL_H_
