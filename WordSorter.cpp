#include "WordSorter.hpp"

using namespace std;

void WordSorter::AToZSort() {
	sort(array.begin(), array.end(), [](string a, string b) { return a < b; });
}

void WordSorter::ZToASort() {
	sort(array.begin(), array.end(), [](string a, string b) { return a > b; });
}