#include <optional>
#include <stdexcept>
#include <print>
#include <string>

template<typename T, typename E>
class Result {
    private:
        std::optional<T> value_;
        std::optional<E> error_;

    public:
        // Constructors
        Result(T value) : value_(value), error_(std::nullopt) {}
        Result(E error) : value_(std::nullopt), error_(error) {}

        // Checkers
        bool is_ok() const { return !error_.has_value(); }
        bool is_err() const { return error_.has_value(); }

        // Unwrap (hard fail)
        T unwrap() const {
            if (error_.has_value()) {
                throw std::runtime_error(*error_);
            }
            return *value_;
        }

        // Map function for pipelines
        template<typename Func>
            auto map(Func f) const -> Result<decltype(f(*value_)), E> {
                if (is_err()) return Result<decltype(f(*value_)), E>(*error_);
                return Result<decltype(f(*value_)), E>(f(*value_));
            }

        // Optional: operator overload for pipeline (like Rust ?)
        template<typename Func>
            auto operator| (Func f) const -> decltype(f(*value_)) {
                if (is_err()) return *this; // short-circuit
                return f(*value_);
            }
};

template<typename T, typename E>
Result<T,E> Ok(T value) {
    return Result<T,E>(value);
}

template<typename T, typename E>
Result<T,E> Err(E error) {
    return Result<T,E>(error);
}

Result<int, std::string> parseInt(const std::string& s) {
    try {
        return Ok<int, std::string>(std::stoi(s));
    } catch (std::exception e) {
        return Err<int, std::string>(std::string("Invalid int: ") + e.what());
    }
}

int double_it(int foo) { return foo * 2; }

int main() {
    auto res = parseInt("83").map(double_it);
    if (res.is_ok()) std::println("Value doubled: {}", res.unwrap());
    else std::println("Error: {}", res.unwrap());

    auto res2 = parseInt("foo").map(double_it);
    if (res2.is_ok()) std::println("Value doubled: {}", res2.unwrap());
    else std::println("Error: {}", res2.unwrap());
}

