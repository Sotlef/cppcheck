#pragma once
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>

namespace boost {

  template<class T> class enable_shared_from_this {
  private:

    // exposition only
    weak_ptr<T> weak_this_;

  protected:

    enable_shared_from_this() = default;
    ~enable_shared_from_this() = default;

    enable_shared_from_this(const enable_shared_from_this&) noexcept;
    enable_shared_from_this& operator=(const enable_shared_from_this&) noexcept;

  public:

    shared_ptr<T> shared_from_this() noexcept(false);
    shared_ptr<T const> shared_from_this() const noexcept(false);

    weak_ptr<T> weak_from_this() noexcept;
    weak_ptr<T const> weak_from_this() const noexcept;
  }
}