//
// Created by mojiajun on 2020/1/6.
//

#include "env.h"

#include <sys/stat.h>  // ::mkdir, ::stat
#include <sys/fcntl.h>
#include <unistd.h>

namespace tinykvdb {

namespace env {

std::unique_ptr<File> Newfile(const std::string &filename) {
    int32_t fd = ::open(filename.c_str(), O_RDWR | O_CREAT | O_APPEND, 0645);
    if (fd < 0) {
        return std::unique_ptr<File>(nullptr);
    } else {
        uint64_t offset;
        if (!GetFileSize(filename, &offset)) {
            return std::unique_ptr<File>(nullptr);
        }
        return std::make_unique<File>(fd);
    }
}

bool CreateDir(const std::string &dirname) {
    // 如果制造目录成功, 返回0
    return ::mkdir(dirname.c_str(), 0755) == 0;
}

bool GetCurrentDir(std::string &dir) {
    char cwd[256];
    // cur work dir
    if (::getcwd(cwd, sizeof(cwd)) == nullptr) {
        return false;
    }
    dir = std::string(cwd);
    return true;
}

bool IsFileOrDirExist(const std::string &filepath) {
    // 如果文件存在, 返回0
    return ::access(filepath.c_str(), F_OK) == 0;
}

bool GetFileSize(const std::string &filename, uint64_t *size) {
    struct stat sbuf;
    if (stat(filename.c_str(), &sbuf) != 0) {
        *size = 0;
        return false;
    }
    *size = sbuf.st_size;
    return true;
}

}  // namespace Env

}  // namespace tinykvdb
