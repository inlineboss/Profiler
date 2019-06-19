#include "Profiler.h"
#include <iostream>

using namespace std;
using namespace chrono;

Sys::Profiler::~Profiler(){
	auto finish = std::chrono::steady_clock::now();
	auto result = finish - start;
	string message =  (msg != "") ? (msg) : (" ");
	auto tr = duration_cast<milliseconds>(result).count();
	cerr << message <<" "<< tr << "ms" << std::endl;
}

void Sys::Profiler::set_start(const std::string& message){
	start = std::chrono::steady_clock::now();
}

void Sys::Profiler::set_finish(){
	auto finish = std::chrono::steady_clock::now();
	auto result =finish - start ;

	string message =  (msg != "") ? (msg) : (" ");
	cerr << message << " " << duration_cast<milliseconds>(result).count() << "ms" << endl;
}
