///////////////////////////////////////////////////////////////////////////////
// singleton.h
// author: haoxingeng
///////////////////////////////////////////////////////////////////////////////

#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include "noncopyable.h"
#include "pthread.h"

template<typename T>
class singleton : noncopyable
{
public:
	static T& instance()
	{
		pthread_once(&once_, &singleton::init);
		return *instance_;
	}
protected:
	singleton() {}
	~singleton() {}
private:
	static void init()
	{
		instance_ = new T();
	}
private:
	static T* instance_;
	static pthread_once_t once_;
};

template<typename T> T* singleton<T>::instance_ = NULL;
template<typename T> pthread_once_t singleton<T>::once_ = PTHREAD_ONCE_INIT;

#endif
