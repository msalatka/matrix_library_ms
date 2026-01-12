template<typename T>
class DenseMatrix : public Matrix<DenseMatrix<T>, T> {
public:
    DenseMatrix(size_t rows, size_t cols)
        : Matrix<DenseMatrix<T>, T>(rows, cols),
          data_(rows * cols) {}

    T& operator()(size_t r, size_t c) {
        return data_[r * this->cols_ + c];
    }

    const T& operator()(size_t r, size_t c) const {
        return data_[r * this->cols_ + c];
    }

private:
    std::vector<T> data_;
};