#pragma once
template<typename T>
class Singleton
{
private:

	static T* mInstance;

public:

	Singleton(const Singleton<T>& other) = delete;

	static T* Get()
	{
		if (mInstance == nullptr)
			mInstance = new T();

		return mInstance;
	}

	static void Destroy()
	{
		delete mInstance;
		mInstance = nullptr;
	}

protected:
	Singleton()
	{
	}
};
