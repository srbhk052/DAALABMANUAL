#include <iostream>
#include <unordered_map>
using namespace std;
void findMaxOccurringAlphabet(int n, char arr[]) {
unordered_map<char, int> freq;
for (int i = 0; i < n; i++) {
freq[arr[i]]++;
}
char maxChar = '\0';
int maxCount = 0;
for (auto it : freq) {
if (it.second > maxCount) {
maxCount = it.second;
maxChar = it.first;
}
}
if (maxCount == 1)
cout << "No Duplicates Present\n";
else
cout << maxChar << " - " << maxCount << endl;
}
int main() {
int n;
cin >> n;
char arr[n];
for (int i = 0; i < n; i++) {
cin >> arr[i];
}
findMaxOccurringAlphabet(n, arr);
return 0;
}