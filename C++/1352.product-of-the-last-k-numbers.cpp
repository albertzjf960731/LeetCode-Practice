/*
 * @lc app=leetcode id=1352 lang=cpp
 *
 * [1352] Product of the Last K Numbers
 */
#include<vector>
using namespace std;

// @lc code=start
class ProductOfNumbers {
private:
    vector<long> products{1};
    
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if (num == 0) 
            products = {1};
        else 
            products.push_back(products.back() * num) ;
    }
    
    int getProduct(int k) {
        int n = products.size();
        if (k < n) 
            return products.back() / products[n-1-k];
        else
            return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
// @lc code=end

