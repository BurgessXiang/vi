// Copyright (c) Glyn Matthews 2011-2016
// Copyright 2012 Dean Michael Berris <dberris@google.com>
// Copyright 2012 Google, Inc.
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file
 * \brief Defines stream overloads for the uri class.
 */

#ifndef NETWORK_URI_URI_IO_INC
#define NETWORK_URI_URI_IO_INC

#include <zce/uri/config.hpp>
#include <zce/uri/uri.hpp>
#include <iosfwd>

namespace zce {
#if !defined(NETWORK_URI_MSVC)
template <typename CharT, class CharTraits = std::char_traits<CharT> >
std::basic_ostream<CharT, CharTraits> &operator<<(
    std::basic_ostream<CharT, CharTraits> &os, const uri &uri_) {
  return os << uri_.to_string<CharT, CharTraits>();
}

template <typename CharT, class CharTraits = std::char_traits<CharT> >
std::basic_istream<CharT, CharTraits> &operator>>(
    std::basic_istream<CharT, CharTraits> &is, uri &uri_) {
  std::basic_string<CharT, CharTraits> uri_string;
  is >> uri_string;
  uri_ = uri(uri_string);
  return is;
}
#else
inline std::ostream &operator<<(std::ostream &os, const uri &uri_) {
  return os << uri_.string();
}

inline std::wostream &operator<<(std::wostream &os, const uri &uri_) {
  return os << uri_.wstring();
}

inline std::istream &operator>>(std::istream &is, uri &uri_) {
  std::string uri_string;
  is >> uri_string;
  uri_ = uri(uri_string);
  return is;
}

inline std::wistream &operator>>(std::wistream &is, uri &uri_) {
  std::wstring uri_string;
  is >> uri_string;
  uri_ = uri(uri_string);
  return is;
}
#endif  // !defined(NETWORK_URI_MSVC)

}  // namespace zce

#endif  // NETWORK_URI_URI_IO_INC
