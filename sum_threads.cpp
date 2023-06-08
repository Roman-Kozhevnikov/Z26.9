#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <numeric>
#include <thread>
#include <time.h>

void sum_func(std::vector<int>&);


int main() {

	int max_v = 12;
	int num_thread = 4;
	int max_sub_v = max_v / num_thread;// 5


	srand(time(0));

	
	std::vector<int> v(max_v);
	std::vector<int>::iterator it;
	

	std::generate(v.begin(), v.end(), []() {return rand() % 100;});

	//std::for_each(v.begin(), v.end(), [](int& x) {(x = rand() % 100);});
	
	std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

	//clock_t tStart = clock(); // 0,16

	int sum_v = std::accumulate(v.begin(), v.end(), 0);
	
	std::cout << std::endl << std::endl;

	std::cout << sum_v << std::endl;		
	
	//printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	clock_t tStart = clock();


	std::vector<int> v_temp;;
	std::vector<std::thread> threads;

	for (int i = 0; i < max_v; i++) {
		
		
		if (!((i) % (max_sub_v))){			
			
			v_temp.clear();			

		}

		
		//std::cout << "v_temp.size() == " << v_temp.size() << std::endl;
		v_temp.push_back(v[i]);
		
		
		if (!(v_temp.size() % (max_sub_v))) {
			
			int i = 0;			

			std::cout << std::endl;
			
			//threads.push_back(std::thread([&v_temp]() {std::cout << "sum = " << std::accumulate(v_temp.begin(), v_temp.end(), 0); std::cout << std::endl;}));
			
			auto t = [](std::vector<int>& v_temp) {std::cout << "sum = " << std::accumulate(v_temp.begin(), v_temp.end(), 0); std::cout << std::endl;};
			
			threads.push_back(std::thread(sum_func, ref(v_temp)));
			//std::cout << std::endl;		
			std::copy(v_temp.begin(), v_temp.end(), std::ostream_iterator<int>(std::cout, " "));
			
			t(v_temp);

			if (threads[i].joinable())
		         threads[i].join();

			i++;
		}	
		
	}

	std::cout << "till for_each()\n";
	
	std::for_each(threads.begin(), threads.end(), [](std::thread& t) {if(t.joinable()) t.join();});	
	
	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);

	std::cout << std::endl << std::endl;

	std::cout << "Done!!!";

}

void sum_func(std::vector<int>& v_temp) {

	std::cout << std::endl;
	std::cout << "sum_func = " << std::accumulate(v_temp.begin(), v_temp.end(), 0); std::cout << std::endl;
}





//vector<int> rand_array(int, int);
//const int sizevec = 3;
//    srand(time(0));
//    vector<int> chose (sizevec);
//       
//    vector<int>::iterator pv;
//        for (auto& number : chose)
//          {                                                           // for (pv = chose.begin(); pv!= chose.end(); pv++)
//                                                                     //chose.pushback(number) т.к. добавляя в конец сдвигает chose.end() каждыц шаг
//              cout << "Enter the last number of ticket from 0 - 51 : ";
//              cin >> number;
//              
//          }
//    cout << "Atanshion - trusted Drow!";  
//    vector<int> winners;
//    winners = rand_array (51,sizevec);
//    cout << "The YOUR's number is : ";
//    for (pv = chose.begin(); pv!= chose.end(); pv++)
//         cout << *pv << " ";                           
//         cout << endl;
//    cout << "The winner's number is : ";
//    for (pv = winners.begin(); pv!= winners.end(); pv++)
//         cout << *pv << " ";
//         cout << endl;
//
//    if (chose == winners)
//        cout << "You winner one million!!! " << endl;
//            else cout << "You looser... " << endl;
//
//    cout << "Done!";
//
//}
//
//vector<int> rand_array (int oll, int chose)
//{
//    vector<int> temp (chose);
//    vector<int>::iterator pv;
//    for (pv = temp.begin(); pv!= temp.end(); pv++)
//         *pv = rand() % oll;
//    
//    //for (pv = temp.begin(); pv!= temp.end(); pv++)
//    //     cout << *pv << " ";
//    cout<<endl;     
//    random_shuffle(temp.begin(),temp.end());
//    //for (pv = temp.begin(); pv!= temp.end(); pv++)
//     //    cout << *pv << " ";
//         return temp;


//}