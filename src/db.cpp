#include "db.h"

#include <cstdio>
#include "glog/logging.h"

namespace tinykvdb {

//static bool Open(kvdb **dbptr, const std::string &dbname) {
//
//}

void kvdb::Put(const std::string &key, const std::string &value) {
    records_[key] = value;
}

std::string kvdb::Get(const std::string &key) const {
    auto it = records_.find(key);
    if (it == records_.end()) {
        return "NOT_FOUND";
    }
    // 用records[key]为什么不行?
    return it->second;
}

void kvdb::Delete(const std::string &key) {
    records_.erase(key);
}
}

// TODO, 待删除
//int main(int argc, const char **argv) {
//    FLAGS_log_dir = "/Users/mojiajun/CLionProjects/internship_prepare_project/tinykvdb/log";
//    google::InitGoogleLogging(argv[0]); // 初始化 glog
//    LOG(INFO) << "Hello, GOOGLE!";
//    printf("just test\n");
//    google::ShutdownGoogleLogging();
//}
//
