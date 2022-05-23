#include <vector>
#include <iostream>
#include <exception>
using namespace std;

int main()
{
	vector<char> tmp;

	tmp.push_back('1');
	tmp.push_back('2');
	cout << "1: " << tmp.at(1) << endl;
	// try
	// {
		cout << "4: " << tmp[500000] << endl;
	// }
	// catch (exception &e)
	// {
	// 	cout << e.what() << endl;
	// }
	// try
	// {

		cout << "2: " << tmp[2] << endl;
	// }
	// catch (exception &e)
	// {
	// 	cout << e.what() << endl;
	// }
	return 0;
}
