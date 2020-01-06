#ifndef PROJECT_SERVER_H
#define PROJECT_SERVER_H

#include <string>
#include <unordered_map>

namespace tinykvdb {

class kvdb {
 public:
  //static bool Open(kvdb **dbptr, const std::string &dbname);
  // 这里要设成引用吗?
  kvdb(std::string dbname) : dbname_(dbname) {

  }

  ~kvdb() {

  }

  void Put(const std::string &key, const std::string &value);
  std::string Get(const std::string &key) const;
  void Delete(const std::string &key);

 private:
   std::unordered_map<std::string, std::string> records_;
   std::string dbname_;
};

}

#endif  // PROJECT_SERVER_H
