
#include <string>
#include <chrono>

#define UNIQUE_NAME	UNIQ_ID(__COUNTER__)
#define TIME_TRACKING(message) 							\
			Sys::Profiler UNIQUE_NAME (message)

namespace Sys{
	class Profiler{
			public:
			explicit Profiler(const std::string& message = ""):
					start (std::chrono::steady_clock::now()),
					msg(message) {};

				~Profiler();

			void	set_start(const std::string& message = "");
			void	set_finish();

			private:
				std::chrono::steady_clock::time_point start;
				std::string msg;
		};

		//Private elements
		#define UNIQ_ID_IMPL(lineno) unique_id_##lineno
		#define UNIQ_ID(linelo) UNIQ_ID_IMPL(linelo)
}
