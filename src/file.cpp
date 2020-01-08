//
// Created by mojiajun on 2020/1/7.
//

#include "file.h"

#include <sys/fcntl.h>
#include <cerrno>
#include <cstdint>
#include <string>
#include "glog/logging.h"
#include "env.h"
#include "coding.h"

namespace tinykvdb {

std::unique_ptr<File> File::Newfile(const std::string &filename) {
    int32_t fd = ::open(filename.c_str(), O_RDWR | O_CREAT | O_APPEND, 0645);
    if (fd < 0) {
        return std::unique_ptr<File>(nullptr);
    } else {
        uint64_t offset;
        if (!env::GetFileSize(filename, &offset)) {
            return std::unique_ptr<File>(nullptr);
        }
        return std::make_unique<File>(fd);
    }
}

bool File::AppendData(const std::string &key,
                      const std::string &value,
                      uint64_t *file_offset_out) {
    uint32_t data_size = key.size() + value.size();
    char data_buf[data_size];
    EncodeData(data_buf, key, value);
    LOG(INFO) << data_buf;

    *file_offset_out = file_offset_;
    file_offset_ += data_size;
    int64_t cnt = 0;
    while (cnt < data_size) {
        ssize_t n = pwrite(fd_,
                           data_buf + cnt,
                           data_size - cnt,
                           *file_offset_out + cnt);
        if (n > 0) {
            cnt += n;
        } else if (n < 0) {
            if (errno != EINTR) {
                cnt = -1;
                break;
            }
        } else {
            break;
        }
    }

    return cnt != -1;
}

bool File::AppendIndex(const std::string &key,
                       uint32_t file_index,
                       uint64_t file_offset,
                       uint32_t key_size,
                       uint32_t value_size) {

    return false;
}

}  // namespace tinykvdb
