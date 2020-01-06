//
// Created by mojiajun on 2020/1/6.
//
#include "db_impl.h"

#include "env.h"
#include "file.h"

namespace tinykvdb {

static const std::string IndexFileName = "/INDEX-";
static const std::string DataFileName = "/DATA-";

KvdbImpl::KvdbImpl(const std::string &dbname) :
    dbname_(dbname),
    max_file_(MAX_FILES)  { }

KvdbImpl::~KvdbImpl() { }


bool KvdbImpl::Put(const std::string &key, const std::string &value) {

}

bool KvdbImpl::Get(const std::string &key, std::string *value) {

}

bool KvdbImpl::Delete(const std::string &key) {

}

bool Kvdb::Open(const std::string &dbname,
                Kvdb **dbptr) {
    *dbptr = nullptr;
    KvdbImpl *impl = new KvdbImpl(dbname);  // 怎么用std::unique_ptr替换?

    // 获取当前执行的目录
    std::string current_dir;
    if (!env::GetCurrentDir(current_dir)) {
        return false;
    }

    // 打开或制造data目录
    std::string data_dir = current_dir + "/" + dbname;
    if (!env::IsFileOrDirExist(data_dir)) {
        bool res = env::CreateDir(data_dir);
        if (!res) {
            return false;
        }
    }

    // 怎么在Open中构造出std::unique_ptr<File> 然后返回给KvdbImpl里头的*_files;
    for (int i = 0; i < KvdbImpl::MAX_FILES; ++i) {
        std::string data_file = data_dir + DataFileName + std::to_string(i);
        File *
    }

    // 打开data files
    for (int i = 1; i <= KvdbImpl::MAX_FILES; ++i) {
        std::string data_file = data_dir + DataFileName
    }

    // 代开index files

    *dbptr = impl;
    return true;
}

}  // namespace tinykvdb
