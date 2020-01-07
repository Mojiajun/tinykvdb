//
// Created by mojiajun on 2020/1/6.
//
#ifndef TINYKVDB_SRC_ENV_H_
#define TINYKVDB_SRC_ENV_H_

#include <string>
#include <memory>
#include "file.h"

namespace tinykvdb {

namespace env {

std::unique_ptr<File> Newfile(const std::string &filename);
bool GetCurrentDir(std::string &dir);
bool IsFileOrDirExist(const std::string &filepath);
bool CreateDir(const std::string &dirname);
bool GetFileSize(const std::string &filename, uint64_t *size);

}  // namespace Env

}  // namespace tinykvdb

#endif //TINYKVDB_SRC_ENV_H_
