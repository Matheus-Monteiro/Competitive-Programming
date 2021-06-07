const int OO = 0x3f3f3f3f;

struct Stack {
    vector<int> s, smax = {-OO}, smin = {OO};
    void push(int x) {
        s.push_back(x);
        smax.push_back(max(smax.back(), x));
        smin.push_back(min(smin.back(), x));
    }
    int pop() {
        int x = s.back();
        s.pop_back();
        smax.pop_back();
        smin.pop_back();
        return x;
    }
    int min_() {
        return smin.back();
    }
    int max_() {
        return smax.back();
    }
    bool empty() {
        return s.empty();
    }
};

Stack s1, s2;

void push(int x) {
    s2.push(x);
}

void pop() {
    if(s1.empty()) {
        while(!s2.empty())
            s1.push(s2.pop());
    }
    s1.pop();
}

int min_() {
    return min(s1.min_(), s2.min_());
}

int max_() {
    return max(s1.max_(), s2.max_());
}
