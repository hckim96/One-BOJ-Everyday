#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for (auto e: a) ans += e;
	return ans;
}
