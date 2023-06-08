#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <numeric>
#include <thread>
#include <time.h>

//void sum_func(std::vector<int>&);


int main() {

	int max_v = 10000000;
	int num_thread = 2;
	int max_sub_v = max_v / num_thread;


	srand(time(0));


	std::vector<int> v(max_v);
	
	std::generate(v.begin(), v.end(), []() {return rand() % 100;});

	//std::for_each(v.begin(), v.end(), [](int& x) {(x = rand() % 100);});

	//std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

	clock_t tStart = clock(); // 10 млн - 0,51 с

	int sum_v = std::accumulate(v.begin(), v.end(), 0);

	//std::cout << std::endl << std::endl;

	//std::cout << sum_v << std::endl;

	printf("Time taken: %.2fs\n", (double)(clock() - (double)tStart) / CLOCKS_PER_SEC);

	//clock_t tStart = clock(); //10 млн - 0,41

	std::vector<int> v_temp;;
	std::vector<std::thread> threads;
	std::vector<int>::iterator start = v.begin();
	//
	int i = 0;
	//
	while (num_thread--) {
	
		int count = 0;
		count += max_sub_v;
	//	std::cout << " i = " << i << std::endl;
	//	
	//	std::cout << "func = " << std::accumulate(start, start + count, 0); std::cout << std::endl;
		threads.push_back(std::thread([&]() {std::accumulate(start, start + count, 0);}));
		
		while (threads[i].joinable()) {
			//std::cout << "joinable - " << i << std::endl;
			threads[i].join();
		}
	//	//std::copy(start, start + count, std::ostream_iterator<int>(std::cout, " "));
	//	//std::cout << std::endl;
		start += count;
		i++;

	}

	//printf("Time taken: %.2fs\n", (double)(clock() - (double)tStart) / CLOCKS_PER_SEC);

	//i = 0;

	//while (i < threads.size()) {

	//	if (threads[i].joinable()) {
	//	     std::cout << "2-nd round! -  " << i << std::endl;
	//	     threads[i].join();
	//       }

	//		i++;
	//}	
	//	
	////}

	std::cout << "till for_each()\n";
	
	//std::for_each(threads.begin(), threads.end(), [](std::thread& t) {if(t.joinable()) t.join();});	
	
    

	std::cout << std::endl << std::endl;

	std::cout << "Done!!!";

	return 0;

}


	//for (int i = 0; i < max_v; i++) {
	//	
	//	
	//	if (!((i) % (max_sub_v))){			
	//		
	//		v_temp.clear();			

	//	}

	//	
	//	//std::cout << "v_temp.size() == " << v_temp.size() << std::endl;
	//	v_temp.push_back(v[i]);
	//	
	//	
	//	if (!(v_temp.size() % (max_sub_v))) {
	//		
	//		int i = 0;			

	//		std::cout << std::endl;
	//		
	//		//threads.push_back(std::thread([&v_temp]() {std::cout << "sum = " << std::accumulate(v_temp.begin(), v_temp.end(), 0); std::cout << std::endl;}));
	//		
	//		auto t = [](std::vector<int>& v_temp) {std::cout << "sum = " << std::accumulate(v_temp.begin(), v_temp.end(), 0); std::cout << std::endl;};
	//		
	//		threads.push_back(std::thread(sum_func, ref(v_temp)));
	//		//std::cout << std::endl;		
	//		std::copy(v_temp.begin(), v_temp.end(), std::ostream_iterator<int>(std::cout, " "));
	//		
	//		t(v_temp);
	//
	//if (threads[i].joinable())
	//threads[i].join();

	//i++;
	//	}

	//}
	//
	/*std::cout << "till for_each()\n";

	std::for_each(threads.begin(), threads.end(), [](std::thread& t) {if (t.joinable()) t.join();});

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	std::cout << std::endl << std::endl;

	std::cout << "Done!!!";*/

//void sum_func(std::vector<int>& v_temp) {
//
//	std::cout << std::endl;
//	std::cout << "sum_func = " << std::accumulate(v_temp.begin(), v_temp.end(), 0); std::cout << std::endl;
//}