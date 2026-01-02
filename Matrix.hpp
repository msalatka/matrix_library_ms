template <typename T>
class Matrix {
public:
    virtual ~Matrix() = default;

    virtual size_t rows() const = 0;
    virtual size_t cols() const = 0;

    virtual T& at(size_t r, size_t c) = 0;
    virtual const T& at(size_t r, size_t c) const = 0;
};
