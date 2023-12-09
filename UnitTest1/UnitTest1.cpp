#include "pch.h"
#include "CppUnitTest.h"
#include "/Users/daad3/source/repos/OPPO_minitask/Time.h"
#include "/Users/daad3/source/repos/OPPO_minitask/Time.cpp"
#include "/Users/daad3/source/repos/OPPO_minitask/Menu.h"
#include "/Users/daad3/source/repos/OPPO_minitask/Menu.cpp"
#include <iostream>
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(ValidFormatTime)
		{
			std::vector<std::string> Cases
			{
				"12:00",
				"1:00",
				"01:00"
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Time::ValidateTime(Cases[i]);
				Assert::IsTrue(result);
			}
		}

		TEST_METHOD(InvalidFormatTime)
		{
			std::vector<std::string> Cases
			{
				"60:240",
				"ab:cd",
				"nigger"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Time::InvalidTime(Cases[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatName)
		{
			std::vector<std::string> Cases
			{
				"Вкусняшка",
				"Чай_Улун",
				"Пельмени",
				"Каша_за_5_минут",
				"Бедный_Еврей"
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Menu::ValidateName(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatName)
		{
			std::vector<std::string> Cases
			{
				"@Вкусняшка",
				"19:84",
				"nigger"

			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Menu::InvalidName(Cases[i]); 
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidFormatPrice)
		{
			std::vector<double> Cases
			{
				23.0,
				1.5,
				0.001,
				11.9
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				bool result = Menu::ValidatePrice(Cases[i]);
				Assert::IsTrue(result);
			}
		}
		TEST_METHOD(InvalidFormatPrice)
		{
			std::vector<double> Cases
			{
				-1.5,
				-23.65
			};
			for (int i = 0; i < Cases.size(); i++)
			{
				try
				{
					Menu::InvalidPrice(Cases[i]); 
					Assert::Fail();
				}
				catch (std::runtime_error& e)
				{
					return;
				}
			}
		}
		TEST_METHOD(ValidTestMenu)
		{
			std::istringstream input("\"Булочка_с_маком\" 10.5 02:00");
			std::string str_name = "\"Булочка_с_маком\"";
			Menu menu;
			menu.ReadMenu(input);
			Assert::AreEqual(str_name, menu.GetName());
			Assert::AreEqual(10.5, menu.GetPrice());
			Time time;
			time = menu.GetMenuTime();
			Assert::AreEqual(2, static_cast<int>(time.GetHours()));
			Assert::AreEqual(0, static_cast<int>(time.GetMinutes()));
		}
		TEST_METHOD(InvalidTestMenu)
		{
			std::vector<std::string> cases
			{
				"1231 13123.1 3213 1 fadasd",
				"aaad 131 vdvs a1",
				"da312 das 123"
			};
			for (int i = 0; i < cases.size(); i++)
			{
				std::istringstream input(cases[i]);
				try
				{
					Menu menu;
					menu.ReadMenu(input);
					throw std::runtime_error("Error in runtime");
				}
				catch (const std::runtime_error& e)
				{
					std::cerr << "Error Message: " << e.what() << std::endl;
				}
			}
		}
		TEST_METHOD(ValidMenuWrite)
		{
			std::istringstream input("\"Крошка_картошка\" 12.25 12:00");
			Menu menu;
			menu.ReadMenu(input);
			std::ostringstream expected_output;
			expected_output << "Название блюда: " << menu.GetName() << std::endl;
			expected_output << "Цена: " << menu.GetPrice() << std::endl;
			Time menu_time = menu.GetMenuTime();
			menu_time.WriteTime(expected_output);
			std::ostringstream actual_output;
			menu.WriteMenu(actual_output);
			Assert::AreEqual(expected_output.str(), actual_output.str());
		}

		TEST_METHOD(ValidTimeWrite)
		{
			std::istringstream input("12:00");
			Time menu_time;
			menu_time.ReadTime(input);
			std::ostringstream expected_output;
			expected_output << "Время приготовления: " << menu_time.GetHours() << ":" << menu_time.GetMinutes() << std::endl;
			std::ostringstream actual_output;
			menu_time.WriteTime(actual_output);
			Assert::AreEqual(expected_output.str(), actual_output.str());
		}
	};
}
