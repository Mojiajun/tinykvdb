tinykvdb
==========================

### 依赖问题
    为了便于在macOS上用Clion远程部署到云环境Ubuntu18.04上.采用把依赖包统一装在~/.tinykvdb_deps这个路径下.
    这部分目前是手动安装.可能需要先git克隆子模块,然后手动安装,配置用的cmake -DCMAKE_INSTALL_PREFIX=~/.tinykvdb_deps -DGTEST_HAS_PTHREAD=1 ..
    感觉-DGTEST_HAS_PTHREAD=1不用也可以,这个流程还没试过,TODO待试
    
### 开发计划    
