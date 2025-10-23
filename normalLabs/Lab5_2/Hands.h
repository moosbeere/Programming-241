#pragma once

template<typename TLeft, typename TRight>
class Hands {
private:
	TLeft LeftHand;
	TRight RightHand;
public:
	Hands(TLeft left, TRight right) : LeftHand(left), RightHand(right) {}
	TLeft getLeftHand();
	void setLeftHand(TLeft left);

	TRight getRightHand();
	void setRightHand(TRight right);

	void printHands();
};

template<typename TLeft, typename TRight>
TLeft Hands<TLeft, TRight>::getLeftHand() { return LeftHand; }

template<typename TLeft, typename TRight>
TRight Hands<TLeft, TRight>::getRightHand() { return RightHand; }

template<typename TLeft, typename TRight>
void Hands<TLeft, TRight>::setLeftHand(TLeft newLeft) { LeftHand = newLeft; }

template<typename TLeft, typename TRight>
void Hands<TLeft, TRight>::setRightHand(TRight newRight) { RightHand = newRight; }

template<typename TLeft, typename TRight>
void Hands<TLeft, TRight>::printHands() { cout << "Левая рука: " << LeftHand << ", Правая рука: " << RightHand << endl; }
