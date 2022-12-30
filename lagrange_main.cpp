#include <iostream>
#include <vector>
#include <tuple>
#include <cstdlib>

//made by re.013080000.

std::tuple<float, float> create_tuple()
{
	float a, b;

	std::cout << "P(a) = b : " << std::endl;
	std::cout << "a? : ";
	std::cin >> a;
	std::cout << "b? : ";
	std::cin >> b;

	return std::make_tuple(a, b);
}



void select_your_interpolation_points(std::vector< std::tuple<float, float> > &interpolation)
{
	int this_much;

	std::cout << "how much points do you want ? : ";
	std::cin >> this_much;

	for (int i = 0; i < this_much; i++)
	{
		interpolation.emplace_back(create_tuple());
		std::system("cls");
	}
}



float lagrange_theorem(std::vector< std::tuple<float, float> > &interpolation, float &a)
{
	float result = 0;
	float temp = 1;
	int number_of_elements = interpolation.size();
	for (int i = 0; i < number_of_elements; i++)
	{
		//std::cout << std::get<0>(interpolation[i]) << ", " << std::get<1>(interpolation[i]) << std::endl;
		for (int j = 0; j < number_of_elements; j++)
		{
			if (i != j)
			{
				temp *= (a - std::get<0>(interpolation[j])) / (std::get<0>(interpolation[i]) - std::get<0>(interpolation[j]));
			}	
		}
		result += temp * std::get<1>(interpolation[i]);
		temp = 1;
	}

	return result;
}



int main() //find 'b' (y axis) from a single point 'a' (x axis) put by the user after selected the known points - using Lagrange theorem
{
	std::vector< std::tuple<float, float> > interpolation; //<a, b> from P(a) = b
	select_your_interpolation_points(interpolation);
	
	float a;
	std::cout << "What point 'a' do you want to know the image 'b' where P(a) = b ? : ";
	std::cin >> a;

	float b = lagrange_theorem(interpolation, a);

	std::cout << "The result is : " << b << std::endl;

	return 0;
}
