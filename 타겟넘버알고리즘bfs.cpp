#include <string>
#include <vector>
#include <queue>
using namespace std;

queue<int> *bfsque;
void bfs(int);
int solution(vector<int> numbers, int target) {
	int answer = 0;
	int cnt = 0;
	int numSize = numbers.size();

	bfsque = new queue<int>;

	bfsque->push(numbers[0]);
	bfsque->push(numbers[0] * -1);
	for (int i = 1; i < numSize; i++) {
		int size = bfsque->size();
		for (int j = 0; j < size; j++) {
			bfs(numbers[i]);
		}
	}
	int size = bfsque->size();
	for (int i = 0; i < size; i++) {
		answer = bfsque->front();
		if (answer == target) {
			cnt++;
		}
		bfsque->pop();
	}
	return cnt;
}
void bfs(int num) {
	int queElem = bfsque->front();
	bfsque->pop();
	for (int i = 0; i < 2; i++) {
		i % 2 == 0 ? bfsque->push(queElem + num) : bfsque->push(queElem - num);
	}
}