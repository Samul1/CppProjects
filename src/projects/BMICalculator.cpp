#include<iostream>
/*
	Author: Samul1

	- BMI calculator
	- weight(kg) / height * height(m)
	- Underweight < 18.5
	- Normal weight 18.5 - 24.9
	- Overweight > 25
	- This calculator won't work on bodybuilders or other people who have a huge amount of muscle!
*/
void main()
{
	float weight = 0;											// Kilogram
	float height = 0;											// meter
	float bmi = 0;												// bmi

	std::cout << ":::     BMI Calculator (metric)     :::" << std::endl;	// Title
	std::cout << ":::BMI >     25      = Overweight   :::" << std::endl;	// Some info for user
	std::cout << ":::BMI = 18.6 - 24.9 = Normalweight :::" << std::endl;	// about weight range
	std::cout << ":::BMI <     18.5    = Underweight  :::" << std::endl;
	std::cout << " " << std::endl;											// Space

	std::cout << "Weight (kg): ";											// Ask weight
	std::cin >> weight;
	std::cout << "Height (m): ";											// Ask height
	std::cin >> height;

	bmi = weight / (height * height);										// Calculate bmi

	if (bmi < 18.5)																		// Check if bmi is less than 18.5.
		std::cout << "You are underweight! You should put on some mass!" << std::endl;
	else if (bmi > 25)																	// Check if bmi is greater than 25.
		std::cout << "You are overweight! You should lose some mass!" << std::endl;
	else
		std::cout << "You are normal weight! Keep doing what you are doing!" << std::endl;

	std::cout << "Your bmi is: " << bmi << std::endl;
	system("pause>0");
}