#include <string>
#include <vector>

using namespace std;


int cnt = 0;
int sizeofnum = 0;
void DFS(vector<int>&, int&, int, int);
int solution(vector<int> numbers, int target) {

	sizeofnum = numbers.size();
	DFS(numbers, target, numbers[0], 1);
	DFS(numbers, target, -1 * numbers[0], 1);

	return cnt;

}
void DFS(vector<int> &numbers, int &target, int sum, int idx) {
	if (idx >= sizeofnum) {
		if (sum == target) cnt++;
		return;
	}
	DFS(numbers, target, sum + numbers[idx], idx + 1);
	DFS(numbers, target, sum - numbers[idx], idx + 1);
}
