#ifndef myVector_hpp
#define myVector_hpp

class myVector{
    public:
        myVector();
        void initJustSize(unsigned);
        void initWithElem(unsigned, int);
        ~myVector();
        void pushBack(int);
        void popBack();
        void insert(unsigned, int);
        void erase(unsigned);
        unsigned getSize() const;
        int& operator[](unsigned);
        const int& operator[](unsigned) const;
        unsigned find(int) const;
       
    private:
        unsigned size;
        unsigned capacity;
        int* data;
};

#endif
