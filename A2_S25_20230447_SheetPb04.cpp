#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class Set{
private:
    vector<T>items;

//Function to help checking if an item exists
    bool exists (const T& item) const{
        for(const T& i : items){
            if(i == item){
                return true;
            }
        }
        return false;
    }
public:

friend bool operator ==(const Set& set1 ,const Set& set2){
        if(set1.items.size() != set2.items.size()){
            return false;
        }

        for(size_t i = 0; i < set1.items.size(); i++){
            if(set1.items[i] != set2.items[i]){
                return false;
            }
        }

        return true;
    }

friend bool operator !=(const Set& set1 ,const Set& set2){
    return !(set1 == set2);
    }

//Add a new item to our set
    void add(const T& item){

        if(!exists(item)){

            for (int i = 0; i < items.size(); i++){
                if (item < items[i]){
                    items.insert(items.begin() + i, item);
                    return;
                }
            }

            items.push_back(item);
        }
    }

//Remove an existing item from our set
void remove(const T& item){
        for(auto it = items.begin(); it != items.end(); it++ ){
            if(*it == item){
                items.erase(it);
                return;
            }
        }
    }

//Return the number of items in the set
size_t size() const {
        return items.size();
    }

//Determine if an item is a member of the set
bool isMember(const T& item) const {
        return exists(item);
    }

// Return a pointer to a dynamically created array containing each item in the set
T* Arraying() const {
        T* array = new T [items.size()];
        for(size_t i = 0; i < items.size(); i++){
            array[i] = items [i];
        }
        return array;
    }

// Print the set items
void print() const {
        cout << "{ ";
        for(const T& item : items){
            cout << item <<" ";
        }
        cout <<"}"<<endl;
    }
};

int main() {

    //Int set
    Set<int> intSet;
    intSet.add(1);
    intSet.add(2);
    intSet.add(3);
    intSet.add(1);
    intSet.print();

    intSet.remove(2);
    intSet.print();

    cout << "Size: " << intSet.size() << endl;
    cout << "Is 3 a member? " << (intSet.isMember(3) ? "Yes" : "No") << endl;

    int* intArray = intSet.Arraying();
    for (size_t i = 0; i < intSet.size(); ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;
    delete[] intArray;

    // String set
    Set<string> stringSet;
    stringSet.add("hello");
    stringSet.add("world");
    stringSet.add("hello");
    stringSet.print();

    //Double set
    Set<double> s1, s2;
    s1.add(1.5);
    s1.add(3.6);
    s1.add(2.2);
    s2.add(1.5);
    s2.add(2.2);
    s2.add(3.6);

//Overload == testing
    if (s1 == s2)
        cout << "Sets are equal" << endl;

    return 0;
}
