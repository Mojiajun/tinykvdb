#include <cstdio>
#include "glog/logging.h"

#include "server.h"

int main(int argc, const char **argv) {
    FLAGS_log_dir = "/Users/mojiajun/CLionProjects/internship_prepare_project/tinykvdb/log";
    google::InitGoogleLogging(argv[0]); // 初始化 glog
    LOG(INFO) << "Hello, GOOGLE!";
    printf("just test\n");
    google::ShutdownGoogleLogging();
}
