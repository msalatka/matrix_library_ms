template <typename T>
class Matrix {
public:
    virtual ~Matrix() = default;

    virtual size_t rows() const = 0;
    virtual size_t columns() const = 0;

};
