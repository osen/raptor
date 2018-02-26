#ifndef ZERO_INITIALIZED_H
#define ZERO_INITIALIZED_H

template<class T>
class zero_initialized
{
private:
  T m_data;

public:
  zero_initialized() : m_data(0) { }
    
  T& operator=(const T& t)
  {
    m_data = t;
    return m_data;
  }

/*
  T& operator=(T& t)
  {
    m_data = t;
    return m_data;
  }
*/

  T& data() { return m_data ; }

  operator const T&() const
  {
    return m_data;
  }

  operator T&()
  {
    return m_data;
  }

  T& operator->()
  {
    return m_data;
  }

/*
  const T& operator->() const
  {
    return m_data;
  }
*/

};

#endif
