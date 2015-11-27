/* chomado.cpp - ちょまどコマンド(((o(*ﾟ▽ﾟ*)o)))
 *
 * Copyright (C) 2015 Shun Terabayashi <shunonymous@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include <iostream>
#include <vector>
#include <iterator>
#include <boost/program_options.hpp>
#include <chrono>
#include <thread>

namespace po = boost::program_options;
using namespace std::chrono_literals;

namespace Chomado
{
    extern std::vector<std::string> HomoAA;
    extern std::string ChomagyoAA;
    extern std::string ChomagyoSpeaking;
    extern std::vector<std::string> ChomadoAA;
}

void PrintChomado(po::variables_map vm)
{
    // Display animation
    if(vm.count("homo"))
    {
	while(true)
	{
	    for(auto& AA:Chomado::HomoAA)
	    {
		std::cerr << AA << "\r";
		std::this_thread::sleep_for(1s);
	    }
	}
    }
    if(vm.count("fish"))
    {
	std::string spaces = "                              "; // 30 spaces
	for(;spaces.empty() == false; spaces.erase(spaces.size() - 1))
	{
	    std::cerr << spaces << Chomado::ChomagyoAA;
	    if(spaces.size() % 3 == 0)
		std::cerr << Chomado::ChomagyoSpeaking;
	    std::this_thread::sleep_for(250ms);
	    std::cerr << "\r";
	}
    }
    if(vm.count("plain"))
    {
	while(true)
	{
	    for(auto& AA:Chomado::ChomadoAA)
	    {
		std::cerr << AA << "\r";
		std::this_thread::sleep_for(250ms);
	    }
	}
    }
}

int main(int argc,char **argv)
{
    po::options_description Options("Options");

    // Declare options
    Options.add_options()
	("help,h","ヘルプを表示して終了します\n(((o(*ﾟ▽ﾟ*)o)))")
	("homo","┌（┌ *ﾟ▽ﾟ*）┐!!!")
	("fish","(*ﾟ▽ﾟ* っ)Зちょまぎょ!")
	("plain","(((o(*ﾟ▽ﾟ*)o)))")
	;

    po::variables_map vm;
    po::store(po::parse_command_line(argc,argv,Options),vm);
    po::notify(vm);

    try{
	if(vm.count("help"))
	{
	    std::cout << "ちょまどコマンド!(((o(*ﾟ▽ﾟ*)o)))" << std::endl;
	    std::cout << Options << std::endl;
	    std::cout << "つまりホモってことですね!" << std::endl;
	    return 0;
	}
	PrintChomado(vm);
    } // try

    // Undefined arguments
    catch(std::exception& e)
    {
	std::cerr << "Error" << e.what() << std::endl;
	std::cerr << Options << std::endl;
    }
    catch(...)
    {
	std::cerr << "Exception of unknown type." << std::endl;
    }
} // int main(int argc,char **argv)
