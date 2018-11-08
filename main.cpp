#include <iostream>
#include "src/test_execution/test_execution.h"

int main() {
    locale::global(locale(""));

    /*实验2的实验设置*/
    wstring exp_name = L"experiment_2";
    wstring exp_target = L"exp_01_04_update_test";
    wstring exp_dir_name = L"F:\\云班课作业 2018\\计算机16-1，2，3-数据库系统-课程设计_实验2_实现u/";
    wstring a= L"云班课作业";
    wstring work_dir = L"F:/dongmendb";
    wstring dongmendb_src_dir = L"E:/CLion_workspace/DongmenDB";
    wstring output_dir = L"F:\\dongmendb_output";

    std::map<wstring, wstring> exp_files;
    exp_files[L"exp_01_04_update.c"] = L"/src_experiment/exp_01_stmt_parser/exp_01_04_update.c";
    exp_files[L"exp_07_05_update.c"] = L"/src_experiment/exp_07_physical_operate/exp_07_05_update.c";

    /*实验3的实验设置*/
//    wstring exp_name = L"experiment_3";
//    wstring exp_target = L"exp_01_05_delete_test";
//    wstring exp_dir_name = L"F:\\云班课作业 2018\\计算机16-1，2，3-数据库系统-课程设计_实验3_实现D/";
//    wstring a= L"云班课作业";
//    wstring work_dir = L"F:/dongmendb";
//    wstring dongmendb_src_dir = L"E:/CLion_workspace/DongmenDB";
//    wstring output_dir = L"F:\\dongmendb_output_exp_3";
//
//    std::map<wstring, wstring> exp_files;
//    exp_files[L"exp_01_05_delete.c"] = L"/src_experiment/exp_01_stmt_parser/exp_01_05_delete.c";
//    exp_files[L"exp_07_06_delete.c"] = L"/src_experiment/exp_07_physical_operate/exp_07_06_delete.c";

    TestExecution te;
//    te.run(exp_name, exp_target, exp_dir_name, exp_files, work_dir, dongmendb_src_dir, output_dir);
    te.batchrun(exp_name, exp_target, exp_dir_name, exp_files, work_dir, dongmendb_src_dir, output_dir);
}