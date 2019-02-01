#include <sstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
#include <fstream>
#include <array>
#include <vector>
int main() {
	std::stringstream str;
	str.str(R"(Tomato .45 Carrot .15 Melon 1.17 Grapes .03)");
	if (!str)
		return -1;
	std::vector<std::pair<std::string, double>> products;
	do {
		std::string name;
		double price;
		str >> name >> price;
		if (!str)
			break;
		products.push_back({ name, price });
	} while (true);
	std::vector<std::pair<size_t, size_t>> basket;
	for (size_t i = 0; i < products.size(); ++i)
		basket.push_back({ i, 0 });
	do {
		std::cout << "Menu: (pick 0 to finish)" << std::endl;
		for (size_t i = 0; i < products.size(); ++i)
			std::cout << i + 1 << ": " << products[i].first << "\t" << products[i].second << "$" << std::endl;
		std::cout << "> " << std::flush;
		size_t choice;
		std::cin >> choice;
	if (choice == 0)
			break;
		else if (choice > products.size())
			continue;
	size_t quantity;
		std::cin >> quantity;
	basket[choice - 1].second += quantity;
	} while (true);
	double discount = 0.2;
	double subtotal = 0;
	for (auto &item : basket) {
		auto product = products[item.first];
		subtotal += product.second * item.second;
	double itemTotal = product.second * item.second;
		subtotal += itemTotal;
		std::cout << product.first << " x " << item.second << "(" << product.second << ") .. " << itemTotal << std::endl;
	if (item.second == 0)
			discount = 0;
	}double tax = 0.825;
	std::cout << "Savings .. " << subtotal * discount << "\n"
		<< "Tax (" << tax << ") .. " << (subtotal * (1 - discount)) * tax << "\n"
		<< "Total .. " << (subtotal * (1 - discount)) * (1 - tax) << "\n"
		<< std::endl;
}

