//
// Created by mojiajun on 2020/1/6.
//
#include "db_impl.h"

#include <memory>
#include <utility>
#include "env.h"
#include "file.h"

namespace tinykvdb {

static const std::string IndexFileName = "/INDEX-";
static const std::string DataFileName = "/DATA-";

KvdbImpl::KvdbImpl(const std::string &dbname) :
    dbname_(dbname),
    max_file_(MAX_FILES),
    cursor_(0) {}

KvdbImpl::~KvdbImpl() {}

bool KvdbImpl::Put(const std::string &key, const std::string &value) {
    uint32_t cursor = cursor++;
    uint32_t file_index = (cursor & (max_file_ - 1));
    File* data_file = data_files_[file_index].get();
    uint64_t file_offset;
    bool ok = data_file->AppendData(key, value, &file_offset);
    if (ok) {
        File *index_file = index_files_[file_index].get();
        ok = index_file->AppendIndex(key, file_index, file_offset,
            key.size(), value.size());
        if (ok) {
            Index index(key, file_index, file_offset, key.size(), value.size());
            tables_.insert(index);
        }
    }
}

bool KvdbImpl::Get(const std::string &key, std::string *value) {

}

bool KvdbImpl::Delete(const std::string &key) {

}

std::unique_ptr<Kvdb> Kvdb::Open(const std::string &dbname,
                                 bool *status) {
    auto dbptr = std::unique_ptr<Kvdb>(nullptr);
    std::unique_ptr<KvdbImpl> impl = std::make_unique<KvdbImpl>(dbname);

    // 获取当前执行的目录
    std::string current_dir;
    if (!env::GetCurrentDir(current_dir)) {
        *status = false;
        return dbptr;
    }

    // 打开或制造data目录
    std::string data_dir = current_dir + "/" + dbname;
    if (!env::IsFileOrDirExist(data_dir)) {
        bool res = env::CreateDir(data_dir);
        if (!res) {
            *status = false;
            return dbptr;
        }
    }

    // 怎么在Open中构造出std::unique_ptr<File> 然后返回给KvdbImpl里头的*_files;
    // 打开数据文件
    for (int i = 0; i < KvdbImpl::MAX_FILES; ++i) {
        std::string data_file = data_dir + DataFileName + std::to_string(i);
        std::unique_ptr<File> res = env::Newfile(data_file);
        if (!res) {
            *status = false;
            return dbptr;
        }
        // 这里用emplace_back会出什么问题吗?
        impl->data_files_.push_back(std::move(res));
    }

    // 打开index files
    for (int i = 0; i < KvdbImpl::MAX_FILES; ++i) {
        std::string index_file = data_dir + IndexFileName + std::to_string(i);
        std::unique_ptr<File> res = env::Newfile(index_file);
        if (!res) {
            *status = false;
            return dbptr;
        }
        // 这里用emplace_back会出什么问题吗?
        impl->data_files_.push_back(std::move(res));
    }
    dbptr = std::move(impl);
    *status = true;
    return dbptr;
}

}  // namespace tinykvdb
