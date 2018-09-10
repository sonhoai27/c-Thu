#pragma once

template <class T> class LIST
{
private: 
	T number;
public:
	LIST(T n){
		number = n;
	};
	~LIST(void){};
	T getT(){
		return number;
	}
};

