#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include <ctime> 
#include <cstdlib>

using namespace std;
string babbleN(string fileName, int n, int length);

int main(){
  cout << "a????" << endl;
  cout << "trying a new line";
  string s = "oijfoj";
  cout << s;
  return 0;
}

// Gets list of keys from map
list<string> extract_keys(map<string, list<string>> const& input_map) {
  list<string> l;
  for (auto const& element : input_map) {
    l.push_back(element.first);
  }
  return l;
}

// Does list<string> contain element?
bool cont(list<string> listOfElements, string element) {
    // Find the iterator if element in list
    auto it = find(listOfElements.begin(), listOfElements.end(), element);
    //return if iterator points to end or not. It points to end then it means element
    // does not exists in list
    return it != listOfElements.end();
}

// build map of values
map<string, list<string>> buildNgramDict(string fileName, int n){
  cout << "Beginning of buildNgramDict";
  string NON_WORD = "NON_WORD";
		map<string, list<string>> source = map<string, list<string>>();
    list<string> all = list<string>();
    // reading from file
    fstream file;
    string word;
    file.open(fileName.c_str());
    while(file >> word) { //take word and print
      all.push_back(word);
    }
    file.close();

		// Pad beginning and end with NON_WORDs
		for(int j=1; j<n; j++){
			all.push_front(NON_WORD);
			all.push_back(NON_WORD);
		}
       
    for(int i=0; i<all.size()-n; i++) {
      // Make key n-1 words long
      // Iterator
      auto it = all.begin();
      advance(it, i);

			string currKey = "";
			for(int k=0; k<n; k++){
				currKey = currKey + *it + " ";
        advance(it, 1);
			}

      it = all.begin();
      advance(it, i+n);
			// If already a key
			if(source.count(currKey) > 0) {
        list<string> curr = source.at(currKey);
				if(!cont(source.at(currKey), *it)){
					source.at(currKey).push_back(*it);
				}
			}
			else{
				list<string> val;
				val.push_back(*it);
				source.insert_or_assign(currKey, val);
			}
		}

		return source;
	}

// Babbler, let n<6 for best
string babbleN(string fileName, int n, int length){
		string result = "";
		map<string, list<string>> ngrams = buildNgramDict(fileName, n);
		list<string> keys = extract_keys(ngrams);

		// Get a first random prefix
    srand(time(NULL));

    auto it = keys.begin();
    advance(it, (rand() % keys.size()));
		string prefix = *it;

    auto it2 = ngrams.at(prefix).begin();
    advance(it2, rand() % ngrams.at(prefix).size());
		string suffix = *it2;

		// Make the string
		for(int i=n; i<length; i++){
			if(i % 2 == 0)
				result += prefix;

			// If suffix is directly a key
			if(ngrams.count(suffix) > 0){
				prefix = suffix;

        auto it2 = ngrams.at(prefix).begin();
        advance(it2, rand() % ngrams.at(prefix).size());
		    suffix = *it2;
			}
			else{
				list<string> suffixes;
				for(int j=0; j<keys.size(); j++){
          it = keys.begin();
          advance(it, j);
					if((*it).length() >= suffix.length()){
						if((*it).substr(0, suffix.length()).compare(suffix) == 0){
							suffix = (*it);
							j += rand() % 5;
						}
					}
				}
			}
		}
		return result;
	}
  