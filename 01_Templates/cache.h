#pragma once
#include <utility>
#include <iostream>
#include <map>
#include <tuple>
#include <functional>
#include <string>
using namespace std;

template<typename Result, typename ...Args>

class Cache {
private:
    map<tuple<Args...>, Result> m;
    function<Result(Args...)> f;

public:
    Cache(function<Result(Args...)> _f) :f{ _f } {}
    Result find(Args... args) {
        auto t = make_tuple(args...);
        auto ft = m.find(t);
        if (ft != m.end()) {
            cout << "has already exist"<<endl;
            return m[t];
        }
        Result r = f(forward<Args...>(args...));
        m.insert(pair<tuple<Args...>, Result>(t, r));
        return r;
    }
};

string getElementImpl(string const& s) {
    return s + " was passed";
}

string getElement(string const& row) {
    static Cache<string, string> cache(&getElementImpl);
    return cache.find(row);
}
