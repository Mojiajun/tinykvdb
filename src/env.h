//
// Created by mojiajun on 2020/1/6.
//
#ifndef TINYKVDB_SRC_ENV_H_
#define TINYKVDB_SRC_ENV_H_

#include <string>

namespace tinykvdb {

namespace env {

bool GetCurrentDir(std::string &dir);
bool IsFileOrDirExist(const std::string &filepath);
bool CreateDir(const std::string &dirname);

}  // namespace Env

}  // namespace tinykvdb

#endif //TINYKVDB_SRC_ENV_H_
