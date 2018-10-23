#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__


#include <memory>
#include <thread>
#include <functional>
#include <mutex>
#include <iostream>
#include <vector>


using namespace std;

class iwork
{

public:

	virtual void perform()
	{
	};
	virtual ~iwork() {};
};



class safethread
{
public:
	shared_ptr<thread> th;

	safethread(std::function<void()> f)
	{
		th.reset(new thread(f));
	};
	~safethread()
	{
		if (th != nullptr)
		{
			th->detach();
		}
	};


};


class threadpool
{
protected:
	bool running;
	size_t maxallowed;

	std::vector<shared_ptr<iwork> > works;
	std::vector<shared_ptr<safethread>> threads;
	std::vector<shared_ptr<safethread>> deadthreads;

	mutex mtx_dthreads;
	mutex mtx_threads;
	mutex mtx_works;

	void handleworks();
public:

	void queue(shared_ptr<iwork> work);
	void stop();

	threadpool();
	virtual ~threadpool();
};


#endif