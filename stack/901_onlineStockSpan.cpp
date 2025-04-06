#include <stack>
#include <utility> // for std::pair

class StockSpanner {
public:
    /**
     * Constructor initializes the StockSpanner.
     * The stack will store pairs of (stock_price, span).
     */
    StockSpanner() {
        // Nothing needed in constructor as the stack is empty at start
    }
    
    /**
     * Calculates the stock span for the given price.
     *
     * The "stock span" is defined as the number of consecutive days 
     * (including today) the stock price was less than or equal to today’s price.
     *
     * @param price The stock price for the current day.
     * @return The span (number of consecutive days including today).
     */
    int next(int price) {
        int days = 1;

        // While the stack is not empty and the top element's price is less than or equal to current price
        // Pop it and accumulate its span (number of days it dominated before)
        while (!this->descending_stack.empty() && this->descending_stack.top().first <= price) {
            days += this->descending_stack.top().second;
            this->descending_stack.pop();
        }

        // Push the current price and its total span onto the stack
        this->descending_stack.push(std::make_pair(price, days));

        // Return the computed span
        return days;
    }
    
private:
    /**
     * Stack to maintain a decreasing sequence of stock prices.
     * Each element in the stack is a pair: (stock_price, span)
     * - stock_price: the price at a previous day
     * - span: how many days this price "dominated" over previous lower prices
     */
    std::stack<std::pair<int, int>> descending_stack;
};

/**
 * Usage:
 * StockSpanner* obj = new StockSpanner();
 * int span = obj->next(price);
 */
