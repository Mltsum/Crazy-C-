#include <iostream>
#include <vector>
#include <map>
#include <array>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"

int main(){
    // 分等级打印
    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // 分模块打印
    auto module1 = spdlog::stdout_color_mt("module1");
    spdlog::get("module1")->info("this is module1 log");
    auto module2 = spdlog::stdout_color_mt("module2");
    spdlog::get("module2")->info("this is module2 log");

    // 将打印写入日志
    try
    {
        auto logger = spdlog::basic_logger_mt("basic_logger", "/Users/mingren/Documents/11.learnning/cpp-excellent-libs-usage/spdlog/logs/basic-log.txt");
        spdlog::get("basic_logger")->info("write info to log");
    }
    catch (const spdlog::spdlog_ex &ex)
    {
        std::cout << "Log init failed: " << ex.what() << std::endl;
    }

    return 0;
}