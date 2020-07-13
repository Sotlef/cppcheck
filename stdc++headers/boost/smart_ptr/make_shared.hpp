#pragma once
#include <boost/smart_ptr/shared_ptr.hpp>

namespace boost {
  // T is not an array
  template<class T, class... Args>
    shared_ptr<T> make_shared(Args&&... args) noexcept(false);
  template<class T, class A, class... Args>
    shared_ptr<T> allocate_shared(const A& a, Args&&... args);

  // T is an array of unknown bounds
  template<class T>
    shared_ptr<T> make_shared(std::size_t n) noexcept(false);
  template<class T, class A>
    shared_ptr<T> allocate_shared(const A& a, std::size_t n);

  // T is an array of known bounds
  template<class T>
    shared_ptr<T> make_shared() noexcept(false);
  template<class T, class A>
    shared_ptr<T> allocate_shared(const A& a);

  // T is an array of unknown bounds
  template<class T> shared_ptr<T>
    make_shared(std::size_t n, const std::remove_extent_t<T>& v) noexcept(false);
  template<class T, class A> shared_ptr<T>
    allocate_shared(const A& a, std::size_t n, const std::remove_extent_t<T>& v);

  // T is an array of known bounds
  template<class T>
    shared_ptr<T> make_shared(const std::remove_extent_t<T>& v) noexcept(false);
  template<class T, class A>
    shared_ptr<T> allocate_shared(const A& a, const std::remove_extent_t<T>& v);

  // T is not an array of unknown bounds
  template<class T>
    shared_ptr<T> make_shared_noinit() noexcept(false);
  template<class T, class A>
    shared_ptr<T> allocate_shared_noinit(const A& a);

  // T is an array of unknown bounds
  template<class T>
    shared_ptr<T> make_shared_noinit(std::size_t n) noexcept(false);
  template<class T, class A>
    shared_ptr<T> allocate_shared_noinit(const A& a, std::size_t n);
}