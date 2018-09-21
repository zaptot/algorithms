#include <iostream>
#include <ctime>
#include <map>
#include <vector>
using namespace std;


void print(vector<tuple<int, string>> arr);
int findName(vector<tuple<int, string>> arr, string name);
vector<int> makeArrayAssociations(vector<tuple<int, string>> arr1, vector<tuple<int, string>> arr2);
void fillTuple(vector<tuple<int, string>>& arr1, vector<tuple<int, string>>& arr2);
void sort(vector<tuple<int, string>> & arr, long start, long end, vector<int> assotiations, vector<tuple<int, string>> & arr2);
void join(vector<int> & assotiations, vector<tuple<int, string>>& arr);


int main() {
    srand(time(NULL));
    vector<tuple<int, string>> arr1, arr2;
    vector<int> assotiations;
    fillTuple(arr1, arr2);
    assotiations = makeArrayAssociations(arr1, arr2);
    join(assotiations, arr2);
    sort(arr1, 0, arr1.size() - 1, assotiations, arr2);
    print(arr1);
    cout<<endl;
    print(arr2);
    return 0;
}


void print(vector<tuple<int, string>> arr){
    cout<<"[";
    for(int i = 0; i < arr.size(); i++){
        cout<<"("<<get<0>(arr[i])<<", "<<get<1>(arr[i])<<")";
        if(i+1<arr.size()){
            cout<<","<<endl;
        }
    }
    cout<<"]"<<endl;
}


void sort(vector<tuple<int, string>> & arr, long start, long end, vector<int> assotiations, vector<tuple<int, string>> & arr2){
    int i = start, j = end;
    int tmp;
    int pivot = get<0>(arr[(start + end) / 2]);
    while (i <= j) {
        while (get<0>(arr[i]) < pivot)
            i++;
        while (get<0>(arr[j]) > pivot)
            j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            if(assotiations[i] > -1 && assotiations[j] > -1){
                swap(arr2[assotiations[i]], arr2[assotiations[j]]);
            }
            i++;
            j--;
        }
    };

    if (start < j)
        sort(arr, start, j, assotiations, arr2);
    if (i < end)
        sort(arr, i, end, assotiations, arr2);
}


void fillTuple(vector<tuple<int, string>> &arr1, vector<tuple<int, string>> &arr2){
    string names[] = {"a","b","c","d","e","f","j","k", "l", "m", "n", "o"};
    int size2 = 12;
    for(int i = 0; i < size2; i++){
        if(rand() % 2){
            arr1.push_back(make_tuple(rand()%30+1, names[i]));
        }
        arr2.push_back(make_tuple(i, names[i]));
    }
}


int findName(vector<tuple<int, string>> arr, string name){
    for(int i = 0; i < arr.size(); i++){
        if(get<1>(arr[i]) == name) return i;
    }
    return -1;
}


vector<int> makeArrayAssociations(vector<tuple<int, string>> arr1, vector<tuple<int, string>> arr2){
    vector<int> res;
    for(int i = 0; i < arr1.size(); i++){
        res.push_back(findName(arr2, get<1>(arr1[i]))) ;
    }
    return res;
}


void join(vector<int> & assotiations, vector<tuple<int, string>>& arr){
    for(int i=1;i<assotiations.size();i++){
        for(int j=i; j>0 && assotiations[j-1]>assotiations[j];j--){
            swap(arr[assotiations[j-1]], arr[assotiations[j]]);
            swap(assotiations[j-1], assotiations[j]);
        }
    }
}
