#pragma once

#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

namespace smark {

  enum class LanguageCode { EN, DE, ES, FR };

  class SmarkSetting {
  public:
    uint connection_count = 0;
    uint thread_count = 0;
    int timeout_us = -1;
    std::string ip;
    uint16_t port;
  };

  class Status {
  public:
    uint request_count = 0;
    uint finish_count = 0;
  };

  class Smark {
    std::string name;

  public:
    Smark(std::string name);
    Smark() {}
    std::string greet(LanguageCode lang = LanguageCode::EN) const;
    void Run();
    SmarkSetting setting;
    Status status;

  private:
    std::vector<std::shared_ptr<std::thread>> thread_pool_;
    std::mutex status_mutex_;
  };

}  // namespace smark
