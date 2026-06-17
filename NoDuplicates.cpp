#include "NoDuplicates.hpp"

using namespace std;

void NoDuplicates::DeleteDuplicates()
{
	unordered_set<string> seen;
	seen.reserve(array.size());
	auto new_end = std::remove_if(array.begin(), array.end(), [&seen](const string& str) {
		return !seen.insert(str).second;
		});
	array.erase(new_end, array.end());
}