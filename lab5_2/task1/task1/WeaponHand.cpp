//#include "Specific.cpp"
template <typename T>


class WeaponHand
{
private:
	T lhand;
	T rhand;
public:
	WeaponHand(T lhandType, T rhandType) : lhand(lhandType), rhand(rhandType) {};

	T getlhandType()
	{
		return lhand;
	}
	T getrhandType()
	{
		return rhand;
	}
	void setlhandType(T type)
	{
		lhand = type;
	}
	void setrhandType(T type)
	{
		rhand = type;
	}
};